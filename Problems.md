# Vitis:

---

## ERROR: `libssl.so.10` missing
* Solution: Run `vitis` using:
    * `$ Exec=env LD_LIBRARY_PATH=/path/to/Vitis/2023.2/tps/lnx64/cmake-3.24.2/libs/Ubuntu:$LD_LIBRARY_PATH /path/to/Vitis/2023.2/bin/vitis`
* (Source: [AUR[Vitis]@Archlinux](https://aur.archlinux.org/packages/vitis))

---

## ERROR: Segmentation fault: ([question@Xilinx](https://support.xilinx.com/s/question/0D54U00006alPtOSAU/segmentation-fault-invoking-xsct-indirectly-using-the-xsct-script-in-vitis-bin-folder-resolved)):

## Command:
> /path/to/Vitis/2023.2/bin/unwrapped/lnx64.o/rlwrap -rc -b "(){}[],+= & ^%$#@"";|\\" -f /path/to/Vitis/2023.2/scripts/xsdb/xsdb/cmdlist -H /home/.xsdbcmdhistory /path/to/Vitis/2023.2/bin/loader -exec rdi_xsdb -n -interactive /home/.Xilinx/Vitis/2023.2/.vitisng/temp_xsct_launch_script.tcl

## Solution:
* Replace `rlwrap` with system's:
    * `$ rm /path/to/Vitis/2023.2/bin/unwrapped/lnx64.o/rlwrap`
    * `$ install rlwrap`
    * `$ ln -s /usr/bin/rlwrap /path/to/Vitis/2023.2/bin/unwrapped/lnx64.o/rlwrap`

---

## EXTRA: Dependencies:
* `xlsclients`

---

## ERROR: Could not read hardware specifications
* Vitis cannot open [generated] `.xsa` directly.. ([Question@Xilinx](https://support.xilinx.com/s/question/0D52E00006hpRchSAE/flash-memory-programming-issue-in-vitis-20211-could-not-read-hardware-specification)).

## Solution
* [In Vitis], Create new component/platform, incorporating the generated `.xsa`

---

# Vivado:

---

## ERROR: No default clock is selected
* Limit to single clock under: `Block_design/Platform_setup`
* Ref: [chinese site](https://blog.csdn.net/yihuajack/article/details/120714268)

---

## https://support.xilinx.com/s/question/0D52E00006hpUdBSAU/packagename-is-not-compiled-in-library-xildefaultlib?language=en_US&t=1710006878232

---

difference in simulations: behavioural vs post-synthesys:

add appropriate signals to process' sensitivity list

---

# Petalinux:

---

## ERROR: Board stuck at boot:
## Solution: Ensure 'bitstream' was included when `$ petalinux-package`