# Chapter 4

## "PL&PS // synced(AXI) // interrupt (w/o interrupt controller)"

### Goal:
* Blink RGB(PL)
* Blink LED 1,2 (PS(CLK(PL)))
* Pause with Button(PS)
    * (Pause RGB(PL) with Button(PS))

### Premature errors
* #### Update code(Vitis) with new Design(Vivado):

![](images/xsa.1.jpg)

![](images/xsa.2.jpg)

![](images/xsa.3.jpg)

![](images/xsa.4.jpg)

### Our new [final] design

![](images/block.design.svg)

#### Changes:

* We're exporting CLK_out(1:100e6)
    * We'll need it to sync the LED1(PS) and LED2(PS)
* Importing Button(PS)
* The method is `AXI`. `AXI` helps communicate between PL and PS. Share ports/memory/etc..

#### Interrupts

* PS acts on Button(PS) and sends output to PL(AXI)
* PL calculates CLK_out(PL) and sends input to the PS(AXI)
* CLK_out syncs LED1(PS) and LED2(PS) by acting as an interrupt(IRQ)
    * IMPORTANT: I failed using an interrupt controller, and have, thus, fed, the interrupt, directly to IRQ(Zynq).
    * (I suppose, an interrupt controller is needed between AXI(CLK_out) and Zynq(IRQ)).
* Notes:
    * GPIO(axi_gpio_#) naming is important. The ID, helps choose the GPIO(I/O) in the PS.

![](images/gpio.1.jpg "img:gpio_in")

![](images/gpio.2.jpg "img:gpio_out")

![](images/irq.jpg "img:irq")

![](images/axi.jpg "(img:axi)")

## test

rename to `.cpp`

set mastere AXI

XPAR_XGPIO_1_BASEADDR per diagram
now using system device tree (SDT) based flow, info: https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/2743468485/Porting+embeddedsw+components+to+system+device+tree+SDT+based+flow

interrupt controller
interrupt_controller:edge_trigger
~~always enable interrupts last~~
the order of commands is important with interrupts

* set default gpio(button) value to 1(not pressed)
* 0xFFFFFFFF for button

XGpio GpioCLK;
Status = XGpio_Initialize(&GpioCLK, XGPIO_AXI_BASEADDRESS);
XGPIOPS_IRQ_TYPE_EDGE_BOTH
channel 1 in all cases
XGpio_SetDataDirection(&GpioButton, 1, 0);  // 0/1 ~ output/input

bits are '0' in both cases img:[0:0] 

## References:
* [ZYNQ for beginners: programming and connecting the PS and PL | Part 1](https://youtu.be/_odNhKOZjEo) (*youtube*)
* [ZYNQ for beginners: programming and connecting the PS and PL | Part 2](https://youtu.be/AOy5l36DroY) (*youtube*)
* [AXI gpio standalone driver](https://github.com/Xilinx/embeddedsw/tree/master/XilinxProcessorIPLib/drivers/gpio) (*github*)
* [Baremetal Drivers and Libraries](https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18841745/Baremetal+Drivers+and+Libraries) (*wiki*)
* [examples](https://github.com/Xilinx/embeddedsw/tree/master/XilinxProcessorIPLib/drivers/gpio/examples) (*github*)
* gpio [API](https://xilinx.github.io/embeddedsw.github.io/gpio/doc/html/api/group__gpio.html) (*API*)
* Error: [Can't find xgpio.h](https://support.xilinx.com/s/question/0D52E00006hpTGBSA2/cant-find-xgpioh-xtmrctrh?language=en_US) (*Xilinx*)
* [`XGpioPs_IntrClear()` examples](https://cpp.hotexamples.com/examples/-/-/XGpioPs_IntrClear/cpp-xgpiops_intrclear-function-examples.html)
* Offtopic: [IRQs](https://youtu.be/luD2y81pD8s) (*youtube*)
* [Interrupts AXI GPIO and AXI Timer ECE 699: Lecture 5](https://people-ece.vse.gmu.edu/coursewebpages/ECE/ECE699_SW_HW/S16/viewgraphs/ECE699_lecture_5.pdf) (*pdf*)
* [GIC vs AXI Interrupt Controller](https://community.element14.com/technologies/fpga-group/f/forum/50536/gic-vs-axi-interrupt-controller/195430) (*forum*)