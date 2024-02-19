## Preliminary: Boot process: Outline:

### Description
The z-turn board can be booted from either:

* the SD card
* or the QSPI (?) [onboard] flash

I'll only cope with the first method, (I couldn't find [external] access to the QSPI's pins :'(..

### Boot from the SD card:
* (Set the appropriate jumpers: J1:J2: OFF:ON)
* Create a FAT32 partition.
    * (TODO: FAT16, boot flag).
* Transfer the [generated] `BOOT.bin`.

### Create the `BOOT.bin` file.
* This file will hold at least:
    * The FSBL[First stage boot loader] that will load the remaining parts, either into the PL or the PS unit.
        * (I.e., yes, :), the SD card will be used to program the FPGA).
* And any or both of the following:
    * The bitstream (for the FPGA)
    * The [PS] application part (e.g. a serial(USB) "Hellow World").
        * (++Linux)

#### Outline:
* Vivado:
    * (Block design)
        * (Zynq)
        * (Entity)
* Vitis:
    * (Platform)
        * (Our FPGA code along with the FSBL(Bootloader)
    * (Application)
        * (A [USB] "Hellow World" perhaps along with an FSBL(Bootloader))
* Vitis:
    * Boot image:
        * Partitions:
            * FSBL (either from the "Platform" or (perhaps (?)) from the "Application")
            * bitstream (from the "Platform")
            * elf (from the "Application")
        *  Creates a `BOOT.bin`
* Copy the boot image to an SD card (into a FAT32 partition)

### Reference:
* Youtube: [ZYNQ training Boot from Zedboard from SD card #08](https://youtu.be/bGgPLgnntRk)