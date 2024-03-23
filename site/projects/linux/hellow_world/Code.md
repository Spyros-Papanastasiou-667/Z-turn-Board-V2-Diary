# Linux Hellow World!

---

## Intrermission: sdk(necessary files for Vitis)

In order for Vitis' **application** to compile, the necessary **libraries** need to be installed. This can be done from Petalinux:

* `$ petalinux-build --sdk`
* `$ petalinux-package --sysroot --dir /path/to/empty/destination/sysroot`  
  ^ (this will populate `sysroot` with `/lib`).

---

## Platform

Create a new platform with "linux" as the operating system.  
(Alternatively, expand an old platform with a "new domain").  
Also: No need for "boot artifacts":

![](images/platform.jpg)

* Link the petalinux `.bif` file, located either at petalinux's: `my_project/images/linux` directory (FIXME: After config?) or the `tftp/dest` (if a `tftpserver` was used).
* Link the "pre-built image directory" (either `my_project/images/linux` or `tftp/dest`).
* Build [the platform\].

![](images/platform.parameters.jpg)

### FIXME: Prebuilt fsbl ?: No

---

## Application

* Create a new application from templates(Linux Hellow World) (under `File/New Component/From Examples`).
* Set the `sysroot` directory (previously generated through `petalinux`(`--sdk`)) to the (inner) `sysroot/sysroots/*-gnueabi` folder:
* Build [the application\].
    * Note the generated `.elf` file[!\].

![](images/sysroot.jpg)

---

## [Take Five](https://en.wikipedia.org/wiki/Take_Five) 🎹🎷🎷🎶

From this point on, the `hellow_world.elf` file can be [copied to, and\] run from any partition on the SD card.

---

## Troubleshooting

* [Newly created [Linux\]\] Domain [at previous [standalone\] platform\] [is\] not visible: Restarting [Vitis\] might work.

---

## Referencies

* [Building and Debugging Linux Applications for Zynq-7000 SoCs](https://xilinx.github.io/Embedded-Design-Tutorials/docs/2023.1/build/html/docs/Introduction/Zynq7000-EDT/4-linux-for-zynq.html) (*site*)
* [Creating a Linux user application in Vitis on a Zynq UltraScale Device](https://support.xilinx.com/s/article/1141772)

---

[reference]: https://docs.xilinx.com/r/en-US/ug1144-petalinux-tools-reference-guide/Overview "Petalinux Reference"