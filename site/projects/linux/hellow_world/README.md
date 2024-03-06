# Assuming [preliminaries](../preliminary/README.md)
# Blinking through Linux

## Vivado part:

* After adding the necessary parts to the `Zynq` component, check for various warnings under 'Platform Setup'
* With respect to PL2PS interrupts, add an `AXI Interrupt Controller` between the GPIO_CLK interrupt the the Zynq_IRQ:
    * (Also set the interrupt controller's output, to "single"):

![](images/block_diagram "block diagram")

## Petalinux part:

* After exporting the relevant `.xsa` file from vivado, create a project, configure and build.
* (Include the bitstream when packages, otherwise it may get **stuck at boot**).
* FIXME: Sorry: There are two bitstream locations, with the following assumptions:
    * `images/linux/system.bit` created (?) after `$ petalinux-build`, and
    * `project-spec/hw-description/design_1_wrapper.bit` after (?) `$ petalinux-config`.
    * (The latter should be fine/updated in all cases).

## Next: [Vitis: Hellow World](Code.md) under linux