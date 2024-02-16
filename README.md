## Z-turn-Board-V2-Diary
Z-turn is a [cheap] chinese board featuring a Zynq processor that incorporates not only a PS but also a PL unit.

(My board has a Zynq7020 with a a dual core Arm & 80K LUTs (?)).

### Repository goals:
* #### 0: [Preliminary: Boot process](.site/Preliminary:_Boot_process/README.md)
* #### 1: [PL only: Standalone](.site/projects/PL_only:_Standalone/README.md)
* #### 2: [PS only: Standalone](.site/projects/PS_only:_Standalone/README.md)
* #### 3: [PS & PL: Standalone: Independent units](.site/projects/PS_&_PL:_Standalone:_Independent_units/README.md)
* #### *: [PS & PL: Standalone: PS reads PL](.site/projects/PS_&_PL:_Standalone:_PS_reads_PL/README.md)
* #### *: [PS & PL: Standalone: PL reads PS](.site/projects/PS_&_PL:_Standalone:_PL_reads_PS/README.md)
* #### *: [PS & PL: Linux: Independent units](.site/projects/PS_&_PL:_Linux:_Independent_units/README.md)
* #### *: [PS & PL: Linux: PS Reads PL](.site/projects/PS_&_PL:_Linux:_PS_Reads_PL/README.md)
* #### *: [PS & PL: Linux: PL Reads PS](.site/projects/PS_&_PL:_Linux:_PL_Reads_PS/README.md)

## Gotta blink 'em all! Blinkemall! 🧶🧶

* Beginner friendly: VHDL & Vivado.
* [Current] Goal: Linux w/ FPGA cooperation.

## Programming "Hellow World!"

* [Getting started] Video seem to have moved to [FPGA Developer](https://www.youtube.com/watch?v=fVrcUiYxe7M)

* default platform clock (chinese: https://blog.csdn.net/yihuajack/article/details/120714268)

Step1:
remove extraneous components. Leave 1 clock
step2: new platform project
standalone
step 3:
linux: new application project
step 4:
vhdl + linux:

## Notes

* IO-planner
* xic: No need to download updates. Run `xic` from [].

## References

* youtube: [Zynq boot procedure](https://www.youtube.com/watch?v=bGgPLgnntRk)
    * FSBL (first stage bootloader) > check SD/NAND/.. > init PS > program PL (bitstream) > jump
* Video
* [Z-turn Board Tutorial Book](https://www.myirtech.com/soft.asp?id=969)
* error: https://blog.csdn.net/yihuajack/article/details/120714268
* https://www.youtube.com/watch?v=FujoiUMhRdQ&t=394s
* 

## Go to: [Adding board](Adding_board.md)
## Go to: [Problems](Problems.md)