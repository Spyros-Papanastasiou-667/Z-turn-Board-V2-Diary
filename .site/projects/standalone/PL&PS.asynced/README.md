Assuming you understand the previous, [PL](../PL/README.md), part..

"**Standalone**" is the type of OS that will run on the PS. Alteratives are "**FreeRTOS**" and "**Linux**".

# PL&PS // asynced // polling

(As per "[PL](../PL/README.md)"), We'll blink:

* ~~CAN: 2 bits~~
* User leds: 1 and 2s
* User Button: (input only)

---

## We need a similar platform to the [PL](../PL/README.md) one, but without disabling all the peripherals. (We probably need UART1 and USB)..

![](images/vitis.0.jpg "block design")

![](images/block.design.svg)

![](images/vitis.2.jpg "standalone OS")

![](images/vitis.3.jpg "vitis has platform")

---

## Let's add a "Hellow World" application. (Not a "Linux Hellow World")!
![](images/vitis.4.jpg "hellow_world.1")

![](images/vitis.5.jpg "hellow_world.2")

---

## Pins:

### ~~CAN: MIO{14,15}~~

![](images/can.schem.1.jpg "can 1")

![](images/can.schem.2.jpg "can 1.b")

### Oops: CAN not be 😝!

![](images/can.3.jpg "can not be")

### LED: 1,2: MIO{0,9}

![](images/led.schem.1.jpg "led 1")

![](images/led.schem.2.jpg "led 1.b")

### Button: MIO{50}

![](images/button.schem.1.jpg "button")

![](images/button.schem.2.jpg "button.b")

---

## Releasing the pins:

## ~~Bound pins: CAN0~~

### Vivado:

![](images/pins.1.jpg "bound pins")

![](images/pins.2.jpg "bound_pins.b")

### ~~Releasing `CAN0`~~

![](images/pins.3.jpg "releasing CAN0")

---

## [Identifying] USB/UART dependency:
![](images/usb.jpg "UART1 dependency")

---

## Phase 2: [PS GPIO](GPIO.md)

---