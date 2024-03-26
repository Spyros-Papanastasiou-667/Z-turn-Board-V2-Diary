## Zynq @ Z-turn-Board-V2-Diary

[Z-turn](https://www.myirtech.com/list.asp?id=708) is a [cheap] chinese board featuring a [Zynq](https://www.xilinx.com/products/silicon-devices/soc/zynq-7000.html) processor. ([Overview:pdf](https://www.myirtech.com/download/Zynq7000/Z-turnBoardV2.pdf)).  
![](site/images/preview.gif "Board blinking LEDs")  
(Zynqs incorporate both a PL and a PS unit).  
(My board has Zynq7020 with a dual core Arm & 80K logic cells).  
I'll try to keep this repo "Beginner Friendly".. (This is **NOT a tutorial**: Corrections on each, next, chapter 😏).  
I prefer a top-down approach.  
* (Versions): Vitis/Vivado @ 2023.2.2

---

### Goals: Gotta blink 'em all, Blinkemall!! 🧶🧶

* #### 0: Preliminary:
    * [Boot process](site/Preliminary/Boot_process/README.md)
    * [Adding the board](site/Preliminary/Adding_the_board/README.md)
    * ~~[Advanced: Creating a custom module](site/Preliminary/Module/README.md)~~
    * [Peripherals: MIO](site/Preliminary/Peripherals/README.md)
* #### 1: Standalone:
    * Chapter 1: [PL](site/projects/standalone/PL/README.md)  
      Next([Vitis](site/projects/standalone/PL/Vitis.md))
    * Chapter 2: [PL&PS // asynced // polling](site/projects/standalone/PL&PS.asynced/README.md)  
      Next([GPIO](site/projects/standalone/PL&PS.asynced/README.md))
    * Chapter 3: [PL&PS // asynced // interrupt](site/projects/standalone/PL&PS.asynced.interrupt/README.md)
    * Chapter 4: [PL&PS // synced(AXI) // interrupt](site/projects/standalone/PL&PS.synced/README.md)  
      Next([Code](site/projects/standalone/PL&PS.synced/code.md))
    * ~~Chapter X: [`BOOT.bin`@`QSPI`(SPI@Flash)](site/projects/standalone/qspi/README.md)~~
* #### 2: Linux:
    * Chapter 0: [Preliminaries](site/projects/linux/preliminary/README.md): Installation & building  
      Next([Creating a project](site/projects/linux/preliminary/Project.md))
    * Chapter 1: [Hellow World](site/projects/linux/hellow_world/README.md)  
      Next([Linux part](site/projects/linux/hellow_world/Code.md))
    * Chapter 2: [Linux GPIO](site/projects/linux/gpio/README.md): LEDs w/ PL(CLK)  
      Next: [PS(BUTTON) 2 PL](site/projects/linux/gpio/part2.md)
* #### Goals:
    * DMA?

---

### ([Various problems and solutions](Problems.md))

---

### Notes

* IO-planner
* xic: No need to download updates. Run `xic` from [].

---

### References

* [Getting Started with the MYIR Z-turn](https://www.youtube.com/watch?v=fVrcUiYxe7M) (moved from ?? to FPGA Developer).
* [Z-turn Board Tutorial Book](https://www.myirtech.com/soft.asp?id=969) (don't know how I found that)!
* Original [source code](https://d.myirtech.com/Z-turn-board/)
* unsure: https://www.youtube.com/watch?v=FujoiUMhRdQ
* [schematic](https://www.myirtech.com/download/Zynq7000/zturnv2Schematic.pdf) (*pdf*)
* [Device Tree Source](https://devicetree-specification.readthedocs.io/en/latest/chapter6-source-language.html) (`.dts?`) reference (*site*)

---

### Extra: Tools used:
* OS: Linux([Gentoo](https://www.gentoo.org/))
* Markdown editor: [ReText](https://github.com/retext-project/retext)
* Serial monitors: [picocom](https://github.com/npat-efault/picocom) and [CuteCom](https://gitlab.com/cutecom/cutecom)
* [Vivado] Export [diagram] to `svg`: `$ write_bd_layout -force -format svg -verbose /tmp/design.svg`
* Markdown [syntax](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax) (*github*)  
Stack overflow [tricks](https://stackoverflow.com/editing-help) (*stack*)  
[Mastering Markdown](https://roachhd.gitbooks.io/master-markdown/content/) (*gitbook*)
---
