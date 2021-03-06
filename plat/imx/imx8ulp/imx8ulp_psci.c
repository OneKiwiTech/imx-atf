/*
 * Copyright 2021 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdbool.h>

#include <arch.h>
#include <arch_helpers.h>
#include <common/debug.h>
#include <drivers/arm/gicv3.h>
#include <lib/mmio.h>
#include <lib/psci/psci.h>

#include <plat_imx8.h>
#include <upower_soc_defs.h>
#include <upower_api.h>

#define CORE_PWR_STATE(state) ((state)->pwr_domain_state[MPIDR_AFFLVL0])
#define CLUSTER_PWR_STATE(state) ((state)->pwr_domain_state[MPIDR_AFFLVL1])
#define SYSTEM_PWR_STATE(state) ((state)->pwr_domain_state[PLAT_MAX_PWR_LVL])

#define PMIC_CFG(v, m, msk)		\
	{				\
		.volt = (v),		\
		.mode = (m), 		\
		.mode_msk = (msk),	\
	}

#define PAD_CFG(c, r, t)		\
	{				\
		.pad_close = (c),	\
		.pad_reset = (r),	\
		.pad_tqsleep = (t)	\
	}

#define BIAS_CFG(m, n, p, mbias)	\
	{				\
		.dombias_cfg = {	\
			.mode = (m),	\
			.rbbn = (n),	\
			.rbbp = (p),	\
		},			\
		.membias_cfg = {mbias},	\
	}

#define SWT_BOARD(swt_on, msk)	\
	{			\
		.on = (swt_on),	\
		.mask = (msk),	\
	}

#define SWT_MEM(a, p, m)	\
	{			\
		.array = (a),	\
		.perif = (p),	\
		.mask = (m),	\
	}

static int imx_pwr_set_cpu_entry(unsigned int cpu, unsigned int entry)
{
	mmio_write_32(IMX_SIM1_BASE + 0x5c + 0x4 * cpu, entry);

	/* set update bit */
	mmio_write_32(IMX_SIM1_BASE + 0x8, mmio_read_32(IMX_SIM1_BASE + 0x8) | BIT_32(24 + cpu));
	/* wait for ack */
	while (!(mmio_read_32(IMX_SIM1_BASE + 0x8) & BIT_32(26 + cpu)))
		;

	/* clear update bit */
	mmio_write_32(IMX_SIM1_BASE + 0x8, mmio_read_32(IMX_SIM1_BASE + 0x8) & ~BIT_32(24 + cpu));
	/* clear ack bit */
	mmio_write_32(IMX_SIM1_BASE + 0x8, mmio_read_32(IMX_SIM1_BASE + 0x8) | BIT_32(26 + cpu));

	return 0;
}

int imx_pwr_domain_on(u_register_t mpidr)
{
	unsigned int cpu = MPIDR_AFFLVL0_VAL(mpidr);

	imx_pwr_set_cpu_entry(cpu, BL31_BASE);

	mmio_write_32(IMX_CMC1_BASE + 0x18, 0x3f);
	mmio_write_32(IMX_CMC1_BASE + 0x50 + 0x4 * cpu, 0);

	/* enable wku wakeup for idle */
	mmio_write_32(IMX_SIM1_BASE + 0x3c + 0x4 * cpu, 0xffffffff);

	return PSCI_E_SUCCESS;
}

void imx_pwr_domain_on_finish(const psci_power_state_t *target_state)
{
	plat_gic_pcpu_init();
	plat_gic_cpuif_enable();
}

int imx_validate_ns_entrypoint(uintptr_t ns_entrypoint)
{
	return PSCI_E_SUCCESS;
}

void imx_pwr_domain_off(const psci_power_state_t *target_state)
{
	unsigned int cpu = MPIDR_AFFLVL0_VAL(read_mpidr_el1());

	plat_gic_cpuif_disable();

	/* disable wakeup */
	mmio_write_32(IMX_SIM1_BASE + 0x3c + 0x4 * cpu, 0);

	/* set core power mode to PD */
	mmio_write_32(IMX_CMC1_BASE + 0x50 + 0x4 * cpu, 0x3);
}
/* APD power mode config */
ps_apd_pwr_mode_cfgs_t apd_pwr_mode_cfgs = {
	[ADMA_PWR_MODE] = {
		.swt_board_offs = 0x120,
		.swt_mem_offs = 0x128,
		.pmic_cfg = PMIC_CFG(0x23, 0x0, 0x2),
		.pad_cfg = PAD_CFG(0x0, 0x0, 0x0deb7a00),
		.bias_cfg = BIAS_CFG(0x0, 0x2, 0x2, 0x0),
	},

	[ACT_PWR_MODE] = {
		.swt_board_offs = 0x110,
		.swt_mem_offs = 0x118,
		.pmic_cfg = PMIC_CFG(0x23, 0x2, 0x2),
		.pad_cfg = PAD_CFG(0x0, 0x0, 0x0deb7a00),
		.bias_cfg = BIAS_CFG(0x0, 0x2, 0x2, 0x0),
	},
};

/* APD power switch config */
ps_apd_swt_cfgs_t apd_swt_cfgs = {
	[ADMA_PWR_MODE] = {
		.swt_board[0] = SWT_BOARD(0x74, 0x7c),
		.swt_mem[0] = SWT_MEM(0x0001fffd, 0x0001fffd, 0x1fffd),
		.swt_mem[1] = SWT_MEM(0x0, 0x0, 0x0),
	},

	[ACT_PWR_MODE] = {
		.swt_board[0] = SWT_BOARD(0x74, 0x7c),
		.swt_mem[0] = SWT_MEM(0x0001fffd, 0x0001fffd, 0x1fffd),
		.swt_mem[1] = SWT_MEM(0x0, 0x0, 0x0),
	},
};

struct ps_pwr_mode_cfg_t *pwr_sys_cfg = (struct ps_pwr_mode_cfg_t *)UPWR_DRAM_SHARED_BASE_ADDR;

void imx_set_pwr_mode_cfg(abs_pwr_mode_t mode)
{
	if ( mode >= NUM_PWR_MODES)
		return;

	/* apd power mode config */
	memcpy(&pwr_sys_cfg->ps_apd_pwr_mode_cfg[mode], &apd_pwr_mode_cfgs[mode],
		 sizeof(struct ps_apd_pwr_mode_cfg_t));

	/* apd power switch config */
	memcpy(&pwr_sys_cfg->ps_apd_swt_cfg[mode], &apd_swt_cfgs[mode], sizeof(swt_config_t));
}

void imx_domain_suspend(const psci_power_state_t *target_state)
{
	unsigned int cpu = MPIDR_AFFLVL0_VAL(read_mpidr_el1());

	if (is_local_state_off(CORE_PWR_STATE(target_state))) {
		plat_gic_cpuif_disable();
		imx_pwr_set_cpu_entry(cpu, BL31_BASE);
		/* core put into power down */
		mmio_write_32(IMX_CMC1_BASE + 0x50 + 0x4 * cpu, 0x3);
		/* FIXME config wakeup interrupt in WKPU */
		mmio_write_32(IMX_SIM1_BASE + 0x3c + 0x4 * cpu, 0x7fffffe3);
	} else {
		/* for core standby/retention mode */
		mmio_write_32(IMX_CMC1_BASE + 0x50 + 0x4 * cpu, 0x1);
		mmio_write_32(IMX_SIM1_BASE + 0x3c + 0x4 * cpu, 0x7fffffe3);
		dsb();
		write_scr_el3(read_scr_el3() | SCR_FIQ_BIT);
		isb();
	}

	if (!is_local_state_run(CLUSTER_PWR_STATE(target_state))) {
		/* TODO imx_set_wakeup() based on GIC config*/

		/*
		 * just for sleep mode for now, need to update to
		 * support more mode, same for suspend finish call back.
		 */
		mmio_write_32(IMX_CMC1_BASE + 0x10, 0x1);
		mmio_write_32(IMX_CMC1_BASE + 0x20, 0x1);
	}

	/* TODO, may need to add more system level config here */
	if (is_local_state_off(SYSTEM_PWR_STATE(target_state))) {
		/*
		 * low power mode config info used by upower
		 * to do low power mode transition.
		 */
		imx_set_pwr_mode_cfg(ADMA_PWR_MODE);
		imx_set_pwr_mode_cfg(ACT_PWR_MODE);
	}
}

void imx_domain_suspend_finish(const psci_power_state_t *target_state)
{
	unsigned int cpu = MPIDR_AFFLVL0_VAL(read_mpidr_el1());

	if (is_local_state_off(SYSTEM_PWR_STATE(target_state))) {
		/* TODO reverse setting for system level */
	}

	if (!is_local_state_run(CLUSTER_PWR_STATE(target_state))) {
		mmio_write_32(IMX_CMC1_BASE + 0x20, 0x0);
		mmio_write_32(IMX_CMC1_BASE + 0x10, 0x0);
	}

	/* clear core's LPM setting */
	mmio_write_32(IMX_CMC1_BASE + 0x50 + 0x4 * cpu, 0x0);
	mmio_write_32(IMX_SIM1_BASE + 0x3c + 0x4 * cpu, 0x0);

	if (is_local_state_off(CORE_PWR_STATE(target_state))) {
		plat_gic_cpuif_enable();
	} else {
		dsb();
		write_scr_el3(read_scr_el3() & (~SCR_FIQ_BIT));
		isb();
	}
}

void __dead2 imx8ulp_pwr_domain_pwr_down_wfi(const psci_power_state_t *target_state)
{
	while (1)
		wfi();
}

void __dead2 imx8ulp_system_reset(void)
{
	imx_pwr_set_cpu_entry(0, 0x1000);

	mmio_write_32(IMX_WDOG3_BASE + 0x4, 0xd928c520);
	while ((mmio_read_32(IMX_WDOG3_BASE) & 0x800) == 0)
		;
	mmio_write_32(IMX_WDOG3_BASE + 0x8, 0x10);
	mmio_write_32(IMX_WDOG3_BASE, 0x21a3);

	while (true)
		;
}

int imx_validate_power_state(unsigned int power_state,
			 psci_power_state_t *req_state)
{
	int pwr_lvl = psci_get_pstate_pwrlvl(power_state);
	int pwr_type = psci_get_pstate_type(power_state);

	if (pwr_lvl > PLAT_MAX_PWR_LVL)
		return PSCI_E_INVALID_PARAMS;

	if (pwr_type == PSTATE_TYPE_STANDBY) {
		CORE_PWR_STATE(req_state) = PLAT_MAX_RET_STATE;
		CLUSTER_PWR_STATE(req_state) = PLAT_MAX_RET_STATE;
	}

	/* No power down state support */
	if (pwr_type == PSTATE_TYPE_POWERDOWN)
		return PSCI_E_INVALID_PARAMS;

	return PSCI_E_SUCCESS;
}

void imx_get_sys_suspend_power_state(psci_power_state_t *req_state)
{
	unsigned int i;

	for (i = IMX_PWR_LVL0; i <= PLAT_MAX_PWR_LVL; i++)
		req_state->pwr_domain_state[i] = PLAT_POWER_DOWN_OFF_STATE;
}

/* TODO */
void __dead2 imx_system_off(void)
{
	wfi();

	ERROR("power off failed.\n");
	panic();
}

static const plat_psci_ops_t imx_plat_psci_ops = {
	.pwr_domain_on = imx_pwr_domain_on,
	.pwr_domain_on_finish = imx_pwr_domain_on_finish,
	.validate_ns_entrypoint = imx_validate_ns_entrypoint,
	.system_off = imx_system_off,
	.system_reset = imx8ulp_system_reset,
	.pwr_domain_off = imx_pwr_domain_off,
	.pwr_domain_suspend = imx_domain_suspend,
	.pwr_domain_suspend_finish = imx_domain_suspend_finish,
	.get_sys_suspend_power_state = imx_get_sys_suspend_power_state,
	.validate_power_state = imx_validate_power_state,
	.pwr_domain_pwr_down_wfi = imx8ulp_pwr_domain_pwr_down_wfi,
};

int plat_setup_psci_ops(uintptr_t sec_entrypoint,
			const plat_psci_ops_t **psci_ops)
{
	imx_mailbox_init(sec_entrypoint);
	*psci_ops = &imx_plat_psci_ops;

	mmio_write_32(IMX_CMC1_BASE + 0x18, 0x3f);
	mmio_write_32(IMX_SIM1_BASE + 0x3c, 0xffffffff);

	return 0;
}
