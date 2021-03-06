// SPDX-License-Identifier: BSD-3-Clause
/*
 * FlexSpi Registers & Bits definition.
 * Copyright 2019-2020 NXP
 */
#ifndef _FSPI_H_
#define _FSPI_H_

#ifndef __ASSEMBLER__
#include <lib/mmio.h>

#ifdef NXP_FSPI_BE
#define fspi_in32(a)		bswap32(mmio_read_32((uintptr_t)(a)))
#define fspi_out32(a, v)	mmio_write_32((uintptr_t)(a), bswap32(v))
#elif defined(NXP_FSPI_LE)
#define fspi_in32(a)		mmio_read_32((uintptr_t)(a))
#define fspi_out32(a, v)	mmio_write_32((uintptr_t)(a), v)
#else
#error Please define FSPI register endianness
#endif

#endif

/* All LE so not swap needed */
#define FSPI_IPDATA_SWAP		0
#define FSPI_AHBDATA_SWAP		0

#define CONFIG_FSPI_FASTREAD		1

#define FSPI_BYTES_PER_KBYTES		0x400
#define FLASH_NUM			1

#define fspiREAD_SEQ_ID			0
#define fspiWREN_SEQ_ID			1
#define fspiWRITE_SEQ_ID		2
#define fspiSE_SEQ_ID			3
#define fspiRDSR_SEQ_ID			4
#define fspiBE_SEQ_ID			5
#define fspiFASTREAD_SEQ_ID		6
#define fspiSE_4K_SEQ_ID		7


/*
 * LUT register layout:
 *
 *  ---------------------------------------------------
 *  | INSTR1 | PAD1 | OPRND1 | INSTR0 | PAD0 | OPRND0 |
 *  ---------------------------------------------------
 *
 *    INSTR_SHIFT- 10, PAD_SHIFT - 8, OPRND_SHIFT -0
 */
#define FSPI_INSTR_OPRND0_SHIFT		0
#define FSPI_INSTR_OPRND0(x)		(x << FSPI_INSTR_OPRND0_SHIFT)
#define FSPI_INSTR_PAD0_SHIFT		8
#define FSPI_INSTR_PAD0(x)		((x) << FSPI_INSTR_PAD0_SHIFT)
#define FSPI_INSTR_OPCODE0_SHIFT	10
#define FSPI_INSTR_OPCODE0(x)		((x) << FSPI_INSTR_OPCODE0_SHIFT)
#define FSPI_INSTR_OPRND1_SHIFT		16
#define FSPI_INSTR_OPRND1(x)		((x) << FSPI_INSTR_OPRND1_SHIFT)
#define FSPI_INSTR_PAD1_SHIFT		24
#define FSPI_INSTR_PAD1(x)		((x) << FSPI_INSTR_PAD1_SHIFT)
#define FSPI_INSTR_OPCODE1_SHIFT	26
#define FSPI_INSTR_OPCODE1(x)		((x) << FSPI_INSTR_OPCODE1_SHIFT)



/* Instruction set for the LUT register. */
#define LUT_STOP			0x00
#define LUT_CMD				0x01
#define LUT_ADDR			0x02
#define LUT_CADDR_SDR			0x03
#define LUT_MODE			0x04
#define LUT_MODE2			0x05
#define LUT_MODE4			0x06
#define LUT_MODE8			0x07
#define LUT_NXP_WRITE			0x08
#define LUT_NXP_READ			0x09

#define LUT_LEARN_SDR			0x0A
#define LUT_DATSZ_SDR			0x0B
#define LUT_DUMMY			0x0C
#define LUT_DUMMY_RWDS_SDR		0x0D
#define LUT_JMP_ON_CS			0x1F
#define LUT_CMD_DDR			0x21
#define LUT_ADDR_DDR			0x22
#define LUT_CADDR_DDR			0x23
#define LUT_MODE_DDR			0x24
#define LUT_MODE2_DDR			0x25
#define LUT_MODE4_DDR			0x26
#define LUT_MODE8_DDR			0x27
#define LUT_WRITE_DDR			0x28
#define LUT_READ_DDR			0x29
#define LUT_LEARN_DDR			0x2A
#define LUT_DATSZ_DDR			0x2B
#define LUT_DUMMY_DDR			0x2C
#define LUT_DUMMY_RWDS_DDR		0x2D


#define FSPI_NOR_CMD_READ		0x03
#define FSPI_NOR_CMD_READ_4B		0x13
#define FSPI_NOR_CMD_FASTREAD		0x0b
#define FSPI_NOR_CMD_FASTREAD_4B	0x0c
#define FSPI_NOR_CMD_PP			0x02
#define FSPI_NOR_CMD_PP_4B		0x12
#define FSPI_NOR_CMD_WREN		0x06
#define FSPI_NOR_CMD_SE_64K		0xd8
#define FSPI_NOR_CMD_SE_64K_4B		0xdc
#define FSPI_NOR_CMD_SE_4K		0x20
#define FSPI_NOR_CMD_SE_4K_4B		0x21
#define FSPI_NOR_CMD_BE			0x60
#define FSPI_NOR_CMD_RDSR		0x05
#define FSPI_NOR_CMD_WREN_STOP		0x04

#define FSPI_LUT_STOP			0x00
#define FSPI_LUT_CMD			0x01
#define FSPI_LUT_ADDR			0x02

#define FSPI_LUT_PAD1			0
#define FSPI_LUT_PAD2			1
#define FSPI_LUT_PAD4			2
#define FSPI_LUT_PAD8			3

#define FSPI_LUT_ADDR24BIT		0x18
#define FSPI_LUT_ADDR32BIT		0x20

#define FSPI_LUT_WRITE			0x08
#define FSPI_LUT_READ			0x09
#define FSPI_DUMMY_SDR			0x0c

/* TODO Check size if functional*/
#define FSPI_RX_IPBUF_SIZE		0x200	/*  64*64 bits  */
#define FSPI_TX_IPBUF_SIZE		0x400	/* 128*64 bits */

#define FSPI_RX_MAX_AHBBUF_SIZE		0x800 /* 256 * 64bits */
#define FSPI_TX_MAX_AHBBUF_SIZE		0x40  /* 8 * 64bits   */

#define FSPI_LUTREG_OFFSET			0x200ul

#define FSPI_MAX_TIMEOUT_AHBCMD		0xFFU
#define FSPI_MAX_TIMEOUT_IPCMD		0xFF
#define FSPI_SER_CLK_DIV		0x04
#define FSPI_HSEN			0
#define FSPI_ENDCFG_BE64		0x01
#define FSPI_ENDCFG_BE32		0x03
#define FSPI_ENDCFG_LE32		0x02
#define FSPI_ENDCFG_LE64		0x0

#define MASK_24BIT_ADDRESS		0x00ffffff
#define MASK_32BIT_ADDRESS		0xffffffff

/* Registers used by the driver */
#define FSPI_MCR0			0x0ul
#define FSPI_MCR0_AHB_TIMEOUT(x)	((x) << 24)
#define FSPI_MCR0_IP_TIMEOUT(x)		((x) << 16)
#define FSPI_MCR0_LEARN_EN		BIT(15)
#define FSPI_MCR0_SCRFRUN_EN		BIT(14)
#define FSPI_MCR0_OCTCOMB_EN		BIT(13)
#define FSPI_MCR0_DOZE_EN		BIT(12)
#define FSPI_MCR0_HSEN			BIT(11)
#define FSPI_MCR0_SERCLKDIV		BIT(8)
#define FSPI_MCR0_ATDF_EN		BIT(7)
#define FSPI_MCR0_ARDF_EN		BIT(6)
#define FSPI_MCR0_RXCLKSRC(x)		((x) << 4)
#define FSPI_MCR0_END_CFG(x)		((x) << 2)
#define FSPI_MCR0_MDIS			BIT(1)
#define FSPI_MCR0_SWRST			BIT(0)

#define FSPI_MCR0_AHBGRANTWAIT_SHIFT	24
#define FSPI_MCR0_AHBGRANTWAIT_MASK	(0xFFU << FSPI_MCR0_AHBGRANTWAIT_SHIFT)
#define FSPI_MCR0_IPGRANTWAIT_SHIFT	16
#define FSPI_MCR0_IPGRANTWAIT_MASK	(0xFF << FSPI_MCR0_IPGRANTWAIT_SHIFT)
#define FSPI_MCR0_HSEN_SHIFT		11
#define FSPI_MCR0_HSEN_MASK		(1 << FSPI_MCR0_HSEN_SHIFT)
#define FSPI_MCR0_SERCLKDIV_SHIFT	8
#define FSPI_MCR0_SERCLKDIV_MASK	(7 << FSPI_MCR0_SERCLKDIV_SHIFT)
#define FSPI_MCR0_ENDCFG_SHIFT		2
#define FSPI_MCR0_ENDCFG_MASK		(3 << FSPI_MCR0_ENDCFG_SHIFT)
#define FSPI_MCR0_RXCLKSRC_SHIFT	4
#define FSPI_MCR0_RXCLKSRC_MASK		(3 << FSPI_MCR0_RXCLKSRC_SHIFT)

#define FSPI_MCR1			0x04
#define FSPI_MCR1_SEQ_TIMEOUT(x)	((x) << 16)
#define FSPI_MCR1_AHB_TIMEOUT(x)	(x)

#define FSPI_MCR2			0x08
#define FSPI_MCR2_IDLE_WAIT(x)		((x) << 24)
#define FSPI_MCR2_SAMEDEVICEEN		BIT(15)
#define FSPI_MCR2_CLRLRPHS		BIT(14)
#define FSPI_MCR2_ABRDATSZ		BIT(8)
#define FSPI_MCR2_ABRLEARN		BIT(7)
#define FSPI_MCR2_ABR_READ		BIT(6)
#define FSPI_MCR2_ABRWRITE		BIT(5)
#define FSPI_MCR2_ABRDUMMY		BIT(4)
#define FSPI_MCR2_ABR_MODE		BIT(3)
#define FSPI_MCR2_ABRCADDR		BIT(2)
#define FSPI_MCR2_ABRRADDR		BIT(1)
#define FSPI_MCR2_ABR_CMD		BIT(0)

#define FSPI_AHBCR			0x0c
#define FSPI_AHBCR_RDADDROPT		BIT(6)
#define FSPI_AHBCR_PREF_EN		BIT(5)
#define FSPI_AHBCR_BUFF_EN		BIT(4)
#define FSPI_AHBCR_CACH_EN		BIT(3)
#define FSPI_AHBCR_CLRTXBUF		BIT(2)
#define FSPI_AHBCR_CLRRXBUF		BIT(1)
#define FSPI_AHBCR_PAR_EN		BIT(0)

#define FSPI_INTEN			0x10
#define FSPI_INTEN_SCLKSBWR		BIT(9)
#define FSPI_INTEN_SCLKSBRD		BIT(8)
#define FSPI_INTEN_DATALRNFL		BIT(7)
#define FSPI_INTEN_IPTXWE		BIT(6)
#define FSPI_INTEN_IPRXWA		BIT(5)
#define FSPI_INTEN_AHBCMDERR		BIT(4)
#define FSPI_INTEN_IPCMDERR		BIT(3)
#define FSPI_INTEN_AHBCMDGE		BIT(2)
#define FSPI_INTEN_IPCMDGE		BIT(1)
#define FSPI_INTEN_IPCMDDONE		BIT(0)

#define FSPI_INTR			0x14
#define FSPI_INTR_SCLKSBWR		BIT(9)
#define FSPI_INTR_SCLKSBRD		BIT(8)
#define FSPI_INTR_DATALRNFL		BIT(7)
#define FSPI_INTR_IPTXWE		BIT(6)
#define FSPI_INTR_IPRXWA		BIT(5)
#define FSPI_INTR_AHBCMDERR		BIT(4)
#define FSPI_INTR_IPCMDERR		BIT(3)
#define FSPI_INTR_AHBCMDGE		BIT(2)
#define FSPI_INTR_IPCMDGE		BIT(1)
#define FSPI_INTR_IPCMDDONE		BIT(0)

#define FSPI_LUTKEY			0x18
#define FSPI_LUTKEY_VALUE		0x5AF05AF0

#define FSPI_LCKCR			0x1C

#define FSPI_LCKER_LOCK			0x1
#define FSPI_LCKER_UNLOCK		0x2

#define FSPI_BUFXCR_INVALID_MSTRID	0xE
#define FSPI_AHBRX_BUF0CR0		0x20
#define FSPI_AHBRX_BUF1CR0		0x24
#define FSPI_AHBRX_BUF2CR0		0x28
#define FSPI_AHBRX_BUF3CR0		0x2C
#define FSPI_AHBRX_BUF4CR0		0x30
#define FSPI_AHBRX_BUF5CR0		0x34
#define FSPI_AHBRX_BUF6CR0		0x38
#define FSPI_AHBRX_BUF7CR0		0x3C

#define FSPI_AHBRXBUF0CR7_PREF		BIT(31)

#define FSPI_AHBRX_BUF0CR1		0x40
#define FSPI_AHBRX_BUF1CR1		0x44
#define FSPI_AHBRX_BUF2CR1		0x48
#define FSPI_AHBRX_BUF3CR1		0x4C
#define FSPI_AHBRX_BUF4CR1		0x50
#define FSPI_AHBRX_BUF5CR1		0x54
#define FSPI_AHBRX_BUF6CR1		0x58
#define FSPI_AHBRX_BUF7CR1		0x5C

#define FSPI_FLSHA1CR0			0x60
#define FSPI_FLSHA2CR0			0x64
#define FSPI_FLSHB1CR0			0x68
#define FSPI_FLSHB2CR0			0x6C
#define FSPI_FLSHXCR0_SZ_KB		10
#define FSPI_FLSHXCR0_SZ(x)		((x) >> FSPI_FLSHXCR0_SZ_KB)

#define FSPI_FLSHA1CR1			0x70
#define FSPI_FLSHA2CR1			0x74
#define FSPI_FLSHB1CR1			0x78
#define FSPI_FLSHB2CR1			0x7C
#define FSPI_FLSHXCR1_CSINTR(x)		((x) << 16)
#define FSPI_FLSHXCR1_CAS(x)		((x) << 11)
#define FSPI_FLSHXCR1_WA		BIT(10)
#define FSPI_FLSHXCR1_TCSH(x)		((x) << 5)
#define FSPI_FLSHXCR1_TCSS(x)		(x)

#define FSPI_FLSHXCR1_TCSH_SHIFT	5
#define FSPI_FLSHXCR1_TCSH_MASK		(0x1F << FSPI_FLSHXCR1_TCSH_SHIFT)
#define FSPI_FLSHXCR1_TCSS_SHIFT	0
#define FSPI_FLSHXCR1_TCSS_MASK		(0x1F << FSPI_FLSHXCR1_TCSS_SHIFT)

#define FSPI_FLSHA1CR2			0x80
#define FSPI_FLSHA2CR2			0x84
#define FSPI_FLSHB1CR2			0x88
#define FSPI_FLSHB2CR2			0x8C
#define FSPI_FLSHXCR2_CLRINSP		BIT(24)
#define FSPI_FLSHXCR2_AWRWAIT		BIT(16)
#define FSPI_FLSHXCR2_AWRSEQN_SHIFT	13
#define FSPI_FLSHXCR2_AWRSEQI_SHIFT	8
#define FSPI_FLSHXCR2_ARDSEQN_SHIFT	5
#define FSPI_FLSHXCR2_ARDSEQI_SHIFT	0

#define FSPI_IPCR0			0xA0

#define FSPI_IPCR1			0xA4
#define FSPI_IPCR1_IPAREN		BIT(31)
#define FSPI_IPCR1_SEQNUM_SHIFT		24
#define FSPI_IPCR1_SEQID_SHIFT		16
#define FSPI_IPCR1_IDATSZ(x)		(x)

#define FSPI_IPCMD			0xB0
#define FSPI_IPCMD_TRG			BIT(0)


/* IP Command Register */
#define FSPI_IPCMD_TRG_SHIFT		0
#define FSPI_IPCMD_TRG_MASK		(1 << FSPI_IPCMD_TRG_SHIFT)

#define FSPI_INTR_IPRXWA_SHIFT		5
#define FSPI_INTR_IPRXWA_MASK		(1 << FSPI_INTR_IPRXWA_SHIFT)

#define FSPI_INTR_IPCMDDONE_SHIFT	0
#define FSPI_INTR_IPCMDDONE_MASK	(1 << FSPI_INTR_IPCMDDONE_SHIFT)

#define FSPI_INTR_IPTXWE_SHIFT		6
#define FSPI_INTR_IPTXWE_MASK		(1 << FSPI_INTR_IPTXWE_SHIFT)

#define FSPI_IPTXFSTS_FILL_SHIFT	0
#define FSPI_IPTXFSTS_FILL_MASK		(0xFF << FSPI_IPTXFSTS_FILL_SHIFT)

#define FSPI_IPCR1_ISEQID_SHIFT		16
#define FSPI_IPCR1_ISEQID_MASK		(0x1F << FSPI_IPCR1_ISEQID_SHIFT)

#define FSPI_IPRXFSTS_FILL_SHIFT	0
#define FSPI_IPRXFSTS_FILL_MASK		(0xFF << FSPI_IPRXFSTS_FILL_SHIFT)

#define FSPI_DLPR			0xB4

#define FSPI_IPRXFCR			0xB8
#define FSPI_IPRXFCR_CLR		BIT(0)
#define FSPI_IPRXFCR_DMA_EN		BIT(1)
#define FSPI_IPRXFCR_WMRK(x)		((x) << 2)

#define FSPI_IPTXFCR			0xBC
#define FSPI_IPTXFCR_CLR		BIT(0)
#define FSPI_IPTXFCR_DMA_EN		BIT(1)
#define FSPI_IPTXFCR_WMRK(x)		((x) << 2)

#define FSPI_DLLACR			0xC0
#define FSPI_DLLACR_OVRDEN		BIT(8)

#define FSPI_DLLBCR			0xC4
#define FSPI_DLLBCR_OVRDEN		BIT(8)

#define FSPI_STS0			0xE0
#define FSPI_STS0_DLPHB(x)		((x) << 8)
#define FSPI_STS0_DLPHA(x)		((x) << 4)
#define FSPI_STS0_CMD_SRC(x)		((x) << 2)
#define FSPI_STS0_ARB_IDLE		BIT(1)
#define FSPI_STS0_SEQ_IDLE		BIT(0)

#define FSPI_STS1			0xE4
#define FSPI_STS1_IP_ERRCD(x)		((x) << 24)
#define FSPI_STS1_IP_ERRID(x)		((x) << 16)
#define FSPI_STS1_AHB_ERRCD(x)		((x) << 8)
#define FSPI_STS1_AHB_ERRID(x)		(x)

#define FSPI_AHBSPNST			0xEC
#define FSPI_AHBSPNST_DATLFT(x)		((x) << 16)
#define FSPI_AHBSPNST_BUFID(x)		((x) << 1)
#define FSPI_AHBSPNST_ACTIVE		BIT(0)

#define FSPI_IPRXFSTS			0xF0
#define FSPI_IPRXFSTS_RDCNTR(x)		((x) << 16)
#define FSPI_IPRXFSTS_FILL(x)		(x)

#define FSPI_IPTXFSTS			0xF4
#define FSPI_IPTXFSTS_WRCNTR(x)		((x) << 16)
#define FSPI_IPTXFSTS_FILL(x)		(x)

#define FSPI_NOR_SR_WIP_SHIFT		(0)
#define FSPI_NOR_SR_WIP_MASK		(1 << FSPI_NOR_SR_WIP_SHIFT)

#define FSPI_RFDR			0x100
#define FSPI_TFDR			0x180

#define FSPI_LUT_BASE			0x200
#define FSPI_LUT_OFFSET			(SEQID_LUT * 4 * 4)
#define FSPI_LUT_REG(idx) \
	(FSPI_LUT_BASE + FSPI_LUT_OFFSET + (idx) * 4)


/* register map end */

#endif
