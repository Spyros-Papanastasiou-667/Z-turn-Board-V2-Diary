# Hellow World // Preliminaries

# Part 1: Installation. ([Part 2: Building](#part-2))

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

* Petalinux requirements [script](#referencies).
* 

---

## Referencies

* [plnx-env-setup.sh](https://support.xilinx.com/s/article/73296?language=en_US) petalinux dependencies script (*site*)
* UG1144: [PetaLinux Tools Documentation: Reference Guide](https://www.xilinx.com/support/documentation/sw_manuals/xilinx2020_1/ug1144-petalinux-tools-reference-guide.pdf) (*pdf*)  
UG1144: [Online version](https://docs.xilinx.com/r/en-US/ug1144-petalinux-tools-reference-guide/Overview) (*site*)
---

# Part 2: Building [Petalinux] ([Part 1: Installation](#part-1))

---