# i.MX ARM Trusted Firmware

## Download Toolchain
- `cd`
- `mkdir toolchain`
- `cd toolchain`
- `wget -c https://releases.linaro.org/components/toolchain/binaries/7.3-2018.05/aarch64-linux-gnu/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu.tar.xz`
- `tar -xvf gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu.tar.xz`

## Get and Build the ARM Trusted firmware
- `git clone https://github.com/km-tek/imx-atf.git`
- `cd imx-atf`
- `export CROSS_COMPILE=~/toolchain/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-`
- `make PLAT=imx8mq bl31` (NXP i.MX8MQ EVK board)
- `cp build/imx8mq/release/bl31.bin $(uboot-build-dir)` (copy **bl31.bin** to uboot folder)

## Reference
- https://github.com/km-tek/uboot-imx/blob/lf_v2021.04/doc/board/freescale/imx8mq_evk.rst
