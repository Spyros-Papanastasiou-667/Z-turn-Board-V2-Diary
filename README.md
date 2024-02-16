## Z-turn-Board-V2-Diary
Z-turn is a [cheap] chinese board featuring a Zynq processor that incorporates not only a PS but also a PL unit.

(My board has a Zynq7020 with a a dual core Arm & 80K LUTs (?)).

### Repository goals:
* #### 0: [Preliminary: Boot process](.site/projects/Preliminary: Boot process.md)
* #### 1: [PL only: Standalone](.site/projects/PL_only:_Standalone)
* #### 2: [PS only: Standalone](.site/projects/PS only: Standalone.md)
* #### 3: [PS & PL: Standalone: Independent units](.site/projects/PS & PL: Standalone: Independent units.md)
* #### *: [PS & PL: Standalone: PS reads PL](.site/projects/PS & PL: Standalone: PS reads PL.md)
* #### *: [PS & PL: Standalone: PL reads PS](.site/projects/PS & PL: Standalone: PL reads PS.md)
* #### *: [PS & PL: Linux: Independent units](.site/projects/PS & PL: Linux: Independent units.md)
* #### *: [PS & PL: Linux: PS Reads PL](.site/projects/PS & PL: Linux: PS Reads PL.md)
* #### *: [PS & PL: Linux: PL Reads PS](.site/projects/PS & PL: Linux: PL Reads PS.md)
* #### *: [Test](.site/test)

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