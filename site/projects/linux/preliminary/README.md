# 🌷Linux(Preliminaries)🌌

Necessary steps for Linux in Zynq.

---

## [Ensuring\] Vivado [output(`.xsa`)\] compatibility

As per [reference], certain processor features must be enabled. Namely:

* "One Triple Timer Counter (**TTC**) (required)".
* "**External memory** controller with at least 512 MB of memory (required)".
* "**UART** for serial console (required)".
* "Non-volatile memory, for example, **QSPI** flash and **SD**/MMC. This memory is optional, but only the JTAG boot can work".
* "**Ethernet** (optional, essential for network access)".

(Simply re-adding the "**Zynq**" component, should be sufficient).  
(Re-export (including bitstream) afterwards).

---

### Example(Block Design):
![](images/block_design.jpg "Block design with added components.")

---

## Petalinux installation

* Download the [petalinux] installer  
  (Although there was a [BSP][bsp] (initial cconfiguration) for z-turn, it's quite old (2018 vs 2023)).
* In order to install it, a [supported][Ubuntu] OS (Ubuntu) is required.

### Unsupported OS(Gentoo)

One method is to `chroot` into a supported OS: e.g.: [Ubuntu LTS][Ubuntu], thus regular installation, on a partition, is needed.  
In order to chroot into it, I use the following script:  
```bash
#!/bin/bash
DEST=/path/to/Ubuntu/mountpoint
cd "$DEST"
cp --dereference /etc/resolv.conf etc/
for i in dev sys run;
do
        mount --rbind /$i $i
        mount --make-rslave $i
done
# mount --bind /var/tftp tftpboot
# mount --make-rslave tftpboot
mount -t tmpfs none tmp
mount -t proc /proc proc
# #### ######## #### #### ######## #### #
chroot . /bin/bash -l                                                                                                                                                                                                                          
umount -l *
```

---

### Inside the `chroot` jail 🏛️(Preparation):

After chrooting:

* `$ source /etc/profile`
* Fix `/bin/sh` to point to `/bin/bash`:  
  `$ dpkg-reconfigure dash`
* Install the necessary packages, either through
    * the [petalinux dependencies script][plnx], or by consulting
    * the [packages list spreadsheet][xlsx]
    * Example command:  
      `$ apt-get install iproute2 gawk python3 build-essential gcc git make net-tools libncurses5-dev tftpd zlib1g-dev libssl-dev flex bison libselinux1 gnupg wget git-core diffstat chrpath socat xterm autoconf libtool tar unzip texinfo zlib1g-dev gcc-multilib automake screen pax gzip cpio python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev pylint libtinfo5`
* (Ensure the proper locale(e.g.: en_US.UTF-8) is set: `$ locale`)
    * (`$ apt install locales`)
    * (`$ dpkg-reconfigure locales` and set a proper(UTF-8) one)

---

## 🏛️(Petalinux instalation):

* Normal user: `$ su - my_username`
* `$ ./petalinux-v2023.2-10121855-installer.run --dir path/to/dest/petalinux/ --platform "arm"`  
  (limiting to `arm` may help reduce the size)
* (`$ cd petalinux`)
* `$ source settings.sh`  
  (opens access to commands like: `petalinux-*`)

---

## Next: [Creating a project](Project.md)

---

## Various troubleshooting from the internet:

* Do not mix different Petalinux and BSP

---

## Referencies

* UG1144: [PetaLinux Tools Documentation: Reference Guide](https://docs.xilinx.com/r/en-US/ug1144-petalinux-tools-reference-guide/Overview) (*site*)

---

<!-- How can these [anchors\] be made visible? -->

[reference]: https://docs.xilinx.com/r/en-US/ug1144-petalinux-tools-reference-guide/Overview "Petalinux Reference"
[petalinux]: https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/embedded-design-tools.html "Petalinux installer"
[bsp]: https://d.myirtech.com/Z-turn-board/
[plnx]: https://support.xilinx.com/s/article/73296 "Petalinux Dependencies Script"
[xlsx]: https://support.xilinx.com/s/article/000035572 "Packages list (excel)"
[Ubuntu]: https://ubuntu.com/download/server#downloads "Ubuntu LTS"
