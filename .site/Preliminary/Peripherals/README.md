## Peripherals: What we can and cannot blink through either the PL or the PS unit.

This started as an attempt to blink MIO through PL, but that's not possible..

## Summary: MIO and EMIO can only be used through the PS.

### PL
There  is a schematic page named `Z720_PL`, showing the available, to the PL unit, pins.

These are called `IO_*`.


### PS
There  is a schematic page named `Z720_PS`, showing the available, to the PL unit, pins.

These are called `PS_DDR_*` and `PS_MIO_*`.

They can also be seen under `FIXED_IO` and `DDR` entries inside the  `I/O Ports` [tab] (after opening "Elaborate Design").

### EMIO

I think EMIO serves as sharing PL's pins with PS.

(I'm a bit unsure of the following, but):

* Enable EMIO
* Make the [new] GPIO port external.
* Choose PL pins for the [new] GPIO (external) bus. (Through "I/O Ports" (Open "Elaborate Design")).


### Use cases
The following are only accessible from the PS:

* Buttton(`MIO50`)
* user LED1/LED2 (`MIO0`/`MIO9`)
* CAN [pins] (`MIO14`/`MIO15`)

## References
* [MIO and EMIO Configuration for Zynq-7000](https://www.xilinx.com/video/soc/mio-emio-configuration-zynq-7000.html) (*video*)
* [Z-turn Board V2 schematic](https://www.myirtech.com/download/Zynq7000/zturnv2Schematic.pdf) (*pdf*)
* ["Can I use MIO pins to route PL external ports? (without involving the PS)"](https://community.element14.com/products/devtools/avnetboardscommunity/avnetboard-forums/f/ultra96-hardware-design/52992/can-i-use-mio-pins-to-route-pl-external-ports-without-involving-the-ps/209609) (*forum*)
* [Zynq-7000 All Programmable SoC: Concepts, Tools, and Techniques (CTT) A Hands-On Guide to Effective Embedded System Design](https://docs.xilinx.com/v/u/en-US/ug873-zynq-ctt) (*pdf*)