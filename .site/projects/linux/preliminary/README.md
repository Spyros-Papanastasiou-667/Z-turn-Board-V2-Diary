# Hellow World // Preliminaries

# Part 1: Installation. ([Part 2: Building](#part-2))

## Downloading

Two things need to be downloaded from the download page:

* The [petalinux][petalinux] [installer], and
* the [BSP][petalinux] (Board Support Package) (for the z-turn platform (i.e. for Zynq7000))
    * The proper(ZC702) BSP can be chosen according the [respective] [ZC702][ZC702] and [ZC706][ZC706] pages

---

## Installing `Petalinux` under unsupported OS. (Skip if supported(Ubuntu)).

[Current] Method: Chrooting [from our OS to Ubuntu].

(Future goal: Building Petalinux on Gentoo)

### Install `Ubuntu` on a partition --

### Chroot onto it.

#### Example script:

```bash
#!/bin/bash
DEST=/mounted/Ubuntu
cd "$DEST"
cp --derference /etc/resolv.conf etc/
for i in dev sys;
do
        mount --rbind /$i $i
        mount --make-rslave $i
done
# mount --bind /var/tftp tftpboot
# mount --make-rslave tftpboot
mount -t tmpfs none tmp
mount -t proc /proc proc
# https://checkmk.com/linux-knowledge/calling-graphic-programs-chroot-environment
#                                                                                                                                                                                                                                              
# XDIR=/tmp/.X11-unix                                                                                                                                                                                                                            
# if [[ -d $XDIR ]]                                                                                                                                                                                                                              
# then                                                                                                                                                                                                                                           
#         mkdir -p ./$XDIR                                                                                                                                                                                                                       
#         mount --bind $XDIR ./$XDIR                                                                                                                                                                                                             
#         xhost + local:                                                                                                                                                                                                                         
# fi                                                                                                                                                                                                                                             
# -                                                                                                                                                                                                                                            
chroot . /bin/bash -l                                                                                                                                                                                                                          
umount -Rl "$DEST"/*
```

### Install necessary packages

Sources:

* Petalinux requirements [script][script].
* Petalinux requirements [script][^script].
* Petalinux requirements [script][script].
* 

---

## Referencies

[^1]: [Petalinux download page](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/embedded-design-tools.html) (*Xilinx*)

[^1]: [Petalinux download page](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/embedded-design-tools.html) (*Xilinx*)

[script]: [plnx-env-setup.sh](https://support.xilinx.com/s/article/73296?language=en_US) petalinux dependencies script (*site*)

[^script]: [plnx-env-setup.sh](https://support.xilinx.com/s/article/73296?language=en_US) petalinux dependencies script (*site*)

[script]: [plnx-env-setup.sh](https://support.xilinx.com/s/article/73296?language=en_US) petalinux dependencies script (*site*)
* UG1144: [PetaLinux Tools Documentation: Reference Guide](https://www.xilinx.com/support/documentation/sw_manuals/xilinx2020_1/ug1144-petalinux-tools-reference-guide.pdf) (*pdf*)  
UG1144: [Online version](https://docs.xilinx.com/r/en-US/ug1144-petalinux-tools-reference-guide/Overview) (*site*)

---

# Part 2: Building [Petalinux] ([Part 1: Installation](#part-1))

---

<How can these be made visible?>

[petalinux]: https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/embedded-design-tools.html "Petalinux installer"
[ZC702]: https://www.xilinx.com/products/boards-and-kits/ek-z7-zc702-g.html "ZC702 Evaluation Kit"
[ZC706]: https://www.xilinx.com/products/boards-and-kits/ek-z7-zc706-g.html "ZC706 Evaluation Kit"