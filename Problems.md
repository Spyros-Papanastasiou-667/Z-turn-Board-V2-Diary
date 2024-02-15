## Vitis' Linux (Gentoo) problems:

### ERROR: Segmentation fault: ([question@Xilinx](https://support.xilinx.com/s/question/0D54U00006alPtOSAU/segmentation-fault-invoking-xsct-indirectly-using-the-xsct-script-in-vitis-bin-folder-resolved)):

#### Command:
> /path/to/Vitis/2023.2/bin/unwrapped/lnx64.o/rlwrap -rc -b "(){}[],+= & ^%$#@"";|\\" -f /path/to/Vitis/2023.2/scripts/xsdb/xsdb/cmdlist -H /home/.xsdbcmdhistory /path/to/Vitis/2023.2/bin/loader -exec rdi_xsdb -n -interactive /home/.Xilinx/Vitis/2023.2/.vitisng/temp_xsct_launch_script.tcl

#### Solution:
* Replace `rlwrap` with system's:
    * `$ rm /path/to/Vitis/2023.2/bin/unwrapped/lnx64.o/rlwrap`
    * `$ install rlwrap`
    * `$ ln -s /usr/bin/rlwrap /path/to/Vitis/2023.2/bin/unwrapped/lnx64.o/rlwrap`

### ERROR: `libssl.so.10` missing

#### Solution

* Remove `cmake` folders @ `/path/to/Vitis/2023.2/tps/lnx64/cmake*`.
* Install `cmake`.
* Remove `libstdc++*` @ `/path/to/Vitis/2023.2/lib/lnx64.o/Default/libstdc++*`

### WARN: Other dependencies

* Install `xlsclients`

## Go to: [README](README.md)