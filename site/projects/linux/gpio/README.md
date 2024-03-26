### Assuming [Hellow World](../hellow_world/README.md)

# Part 1: LEDs w/ PL(CLK)

---

## GPIO(test)

There is a list of [drivers] for linux. As per the [gpio] driver, let's test the:

* USER_LED1(0)
* USER_LED2(9)
* SW1(50)

Let's identify the GPIOChip:  
Looking at `/sys/class/gpio`:
```bash
root@spyros:~# cd /sys/class/gpio/
root@spyros:/sys/class/gpio# grep . */*
gpiochip1022/base:1022
gpiochip1022/label:41210000.gpio
gpiochip1022/ngpio:1
gpiochip1023/base:1023
gpiochip1023/label:41200000.gpio
gpiochip1023/ngpio:1
gpiochip904/base:904
gpiochip904/label:zynq_gpio
gpiochip904/ngpio:118
```

Apparently, `gpiochip904` will contain the PS(GPIO). As per the [driver][gpio]:

* `904`: defines the base
* `118`: defines the amount

Thus, our PS(GPIO) pins are from 904 + 0 to 904 + 118.  
[From previous chapters\], We need MIO(**0, 9 and 50**):  
**Export** the pins: Fix the **directions**:

* `$ echo $((904 + 0)) > export`
    * `$ echo out > gpio$((904 + 0))/direction`
* `$ echo $((904 + 9)) > export`
    * `$ echo out > gpio$((904 + 9))/direction`
* `$ echo $((904 + 50)) > export`

(The remaining 1022/1023 gpios are AXI(button in) and AXI(CLK out). They both work).

---

# Crude notes

* rename nets and elements. Changes for dts (components).
* dtc -I fs /sys/firmware/devicetree/base
* &gpio0 (LEDs)
* /usr/src/linux/uapi/linux/input/input-event-codes.h
    * include file 
* reference to root
* /dev/input/by-path/platform-buttons-event (hexdump) < evtest
* build essential
* CONFIG_nano https://support.xilinx.com/s/question/0D52E00006xnpfBSAQ/add-nano-editor-to-petalinux-20202?language=en_US
* evtest button
* ~~IMAGE_INSTALL_append = "kernel-devsrc"~~ vitis
* merge downloads (w/ .done)
* first-boot checklist

troubleshooting

* error fetching (gitlab rename) (take git) (build keep done delete .git)

---

## Interrupt from PL(downscaled CLK)

Let's try to handle AXI(CLK out) as an interrupt.

---

# Next: Part 2: [PS(BUTTON) 2 PL](part2.md)

---

## Referencies

* [Linux Drivers](https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18841873/Linux+Drivers) (GPIO, interrupt controler) (*wiki*)

---

[drivers]: https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18841873/Linux+Drivers
[gpio]: https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18842398/Linux+GPIO+Driver