# Hellow World // Preliminaries

# Phase 0: Preparing the PL(Logic design)

As per [Petalinux Reference: Ch3: Configuring a Hardware Platform for Linux][reference], in order for our `.xsa` to be compatible with Linux, some requirements must be met: (unverified):  
(You can [probably] just take the default Zynq IP, [onto your Block Design\]).  

* [unused\] TTC (Triple Timer Counter)
* UART (UART1)
* QSPI
* SD
* DDR (?)
* (Ethernet)

---

# Part 1: Installation

## Downloading

Two things need to be downloaded from the download page:

* The [petalinux][petalinux] [installer], and
* the [BSP][petalinux] (Board Support Package) (for the z-turn platform (i.e. for Zynq7000))
    * The proper(ZC702) BSP can be chosen according the [respective] [ZC702][ZC702] and [ZC706][ZC706] pages

---

## Installing on unsupported OS(Gentoo). (Skip if supported(Ubuntu)).

[Current] **Method**: Chrooting [from our OS to Ubuntu]

(Future **goal**: Building Petalinux on **Gentoo**)

* **Install** [the supported version of] [**`Ubuntu`**][Ubuntu] (e.g.: version: LTS) on a partition.
* **Chroot** onto it:

Example script:

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

* `$ source /etc/profile`
* and Install the necessary packages:
    * The necessary packages can be estimated using these methods:
        * The [petalinux dependencies script][plnx], and
        * the [packages list spreadsheet][xlsx]
            * e.g.: `$ apt-get install iproute2 gawk python3 build-essential gcc git make net-tools libncurses5-dev tftpd zlib1g-dev libssl-dev flex bison libselinux1 gnupg wget git-core diffstat chrpath socat xterm autoconf libtool tar unzip texinfo zlib1g-dev gcc-multilib automake screen pax gzip cpio python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev pylint libtinfo5`
* Fix `/bin/sh` to point to `/bin/bash`:  
  `$ dpkg-reconfigure dash`

---

### Troubleshooting

* *Locale* problem:
    * Install: `$ apt install locales`
    * reconfigure: `$ dpkg-reconfigure locales`  
      Sest `en_US.UTF-8`

---

# Part 2: Configuration & Building

(From within `Ubuntu` (*chroot*)).  
[Login as a normal user. E.g.: `$ su - my_username`\].

* Run the installer: `$ ./petalinux-v2023.2-10121855-installer.run --dir petalinux/ --platform "arm"`
    * Where:
    * `--dir`: Destination directory
    * `--platform`: Limit to `Zynq 7000`
* Source the "environment": `$ source petalinux/settings.sh`
    * (This will ease access to commands of the form: `petalinux-*`)
* Create a project: `$ petalinux-create --type project --source xilinx-zc702-v2023.2-10140544.bsp`
* Enter: `$ cd xilinx-zc702-2023.2`
* Import configuration: `$ petalinux-config --get-hw-description design_1_wrapper.xsa --silentconfig`
* Build: `$ petalinux-build`

Images should be under `petalinux/xilinx-zc702-v2023.2/linux/?`

---

# FIXME: chagning xsa: mrproper + configure

---

#### ~~Extra: (cache)~~:

~~You might want to keep [and transfer\] the downloaded files at `petalinux/xilinx-zc702-v2023.2/build/{downloa,ss?}` for future, different, configurations. DANGER~~

#### Troubleshooting

* Some fixed through reinstalling
* Do not mix different Petalinux and BSP
* [Petalinux 2023.2 known issues](https://support.xilinx.com/s/article/000035572) (*site*)
---

## Referencies

* UG1144: [PetaLinux Tools Documentation: Reference Guide](https://www.xilinx.com/support/documentation/sw_manuals/xilinx2020_1/ug1144-petalinux-tools-reference-guide.pdf) (*pdf*)  
  UG1144: [Online version](https://docs.xilinx.com/r/en-US/ug1144-petalinux-tools-reference-guide/Overview) (*site*)

---

<How can these be made visible?>

[reference]: https://www.xilinx.com/support/documentation/sw_manuals/xilinx2020_1/ug1144-petalinux-tools-reference-guide.pdf "Petalinux Reference"
[petalinux]: https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/embedded-design-tools.html "Petalinux installer"
[ZC702]: https://www.xilinx.com/products/boards-and-kits/ek-z7-zc702-g.html "ZC702 Evaluation Kit"
[ZC706]: https://www.xilinx.com/products/boards-and-kits/ek-z7-zc706-g.html "ZC706 Evaluation Kit"
[plnx]: https://support.xilinx.com/s/article/73296 "Petalinux Dependencies Script"
[xlsx]: https://support.xilinx.com/s/article/000035572 "Packages list (excel)"
[Ubuntu]: https://ubuntu.com/download/server#downloads "Ubuntu LTS"
