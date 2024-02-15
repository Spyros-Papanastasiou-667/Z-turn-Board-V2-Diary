# Z-turn-Board-V2-Diary

* Newbie friendly: VHDL + Vivado.
* [Current] Goal: Linux + FPGA cooperation.

# Adding z-turn board to vivado:

* clone `stv0g`'s repository:
    * $ git clone [https://github.com/stv0g/zturn-stuff.git](https://github.com/stv0g/zturn-stuff)
* Inform Vivado of a new "board's definitions"'s location:
    * Through the TCL command line:
        * `$ set_param board.repoPaths /path/to/stv0g\'s/zturn-stuff`
            * WARN: Without spaces!
* ## Other boards:
    * $ git clone [https://github.com/Xilinx/XilinxBoardStore.git](https://github.com/Xilinx/XilinxBoardStore/)
    * (TCL command line):
        * `$ set_param board.repoPaths /path/to/XilinxBoardStore`
            * WARN: Without spaces!
* ## Notes:
    * Although these changes are not permanent, a new project defined on a new board, will retain the board configuration/files.
    * Alternatively, you can add them [(probably) permanently] through the GUI: ![image](.site/board_repos.gui.jpg "<image:Adding board repositories through the GUI>")
        * WARN: Without spaces!

# Programming "Hellow World!"

* [Getting started] Video seem to have moved to [FPGA Developer](https://www.youtube.com/watch?v=fVrcUiYxe7M)

# Notes

* IO-planner

# References

* Video
* pdf
* error: https://blog.csdn.net/yihuajack/article/details/120714268

# Vitis' Linux (Gentoo) problems:

## Segmentation fault: ([question@Xilinx](https://support.xilinx.com/s/question/0D54U00006alPtOSAU/segmentation-fault-invoking-xsct-indirectly-using-the-xsct-script-in-vitis-bin-folder-resolved)):

### Command:
> /path/to/Vitis/2023.2/bin/unwrapped/lnx64.o/rlwrap -rc -b "(){}[],+= & ^%$#@"";|\\" -f /path/to/Vitis/2023.2/scripts/xsdb/xsdb/cmdlist -H /home/.xsdbcmdhistory /path/to/Vitis/2023.2/bin/loader -exec rdi_xsdb -n -interactive /home/.Xilinx/Vitis/2023.2/.vitisng/temp_xsct_launch_script.tcl

### Solution:
* Replace `rlwrap` with system's:
    * `$ rm /path/to/Vitis/2023.2/bin/unwrapped/lnx64.o/rlwrap`
    * `$ install rlwrap`
    * `$ ln -s /usr/bin/rlwrap /path/to/Vitis/2023.2/bin/unwrapped/lnx64.o/rlwrap`

## `libssl.so.10` missing

### Solution

* Remove `cmake` folders @ `/path/to/Vitis/2023.2/tps/lnx64/cmake*`.
* Install `cmake`.
* Remove `libstdc++*` @ `/path/to/Vitis/2023.2/lib/lnx64.o/Default/libstdc++*`

## Other dependencies

* Install `xlsclients`