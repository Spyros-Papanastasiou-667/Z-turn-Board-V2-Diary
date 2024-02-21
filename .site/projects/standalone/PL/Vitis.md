## Blink all [possible].
## Phase 2 [Vitis]

### Outline

* Open workspace.
* Create new platform, from our exported `.xsa` which included the bitstream
    * (Exported is the bootloader also).
    * Use our exported `.xsa` for our new platform.
    * ("Standalone" is fine for our needs).
       * ("Generate Boot artifacts" if there is a choice).
   * Build
* "Create Boot Image"
    * Set `.bif` location
    * Add [[boot] image] partitons
        * Bootloader: It's already been built at step "Build", [probably] due to "Generate Boot Artifacts" option.
        * Bitstream (our vhdl code ;)
* Format an SD card to `FAT32`. And paste, the generated `BOOT.bin`, there.
* (Proper jumpers need to be set, on the "Z-turn board": J1/J2: OPEN/CLOSED).
* (TODO: Check: FAT16?: Boot flag?).

### Steps

#### Open workspace. (I.e., open a folder through vitis, to be used as workspace). --

#### New platform
![img: new](images/vitis/new.jpg)

#### Use [the generated] `.xsa`
![img: xsa](images/vitis/xsa.jpg)

#### Standalone (i.e., not linux)
![img: standalone](images/vitis/standalone.jpg)

#### Build
![img: build](images/vitis/build.jpg)

#### "Create Boot Image"
![img: boot](images/vitis/boot.jpg)

#### Set `.bif` location
![img: bif](images/vitis/bif.jpg)

#### Add partitions
![img: partitions](images/vitis/partitions.jpg)

#### Bootloader (FSBL)
![img: Bootloader](images/vitis/bootloader.jpg)

#### Bitstream (VHDL)
![img: Bitstream](images/vitis/bitstream.jpg)

### Final [state]
![img: Final](images/vitis/final.jpg)

## Notes:

After each "platform export" [from vivado], one needs to update the `.xsa` file:

![img: Update `.xsa`](images/vitis/xsa.2.jpg)

And rebuild..

## [Problems](../../../Problems.md).

## My [`BOOT.bin`](BOOT.bin)