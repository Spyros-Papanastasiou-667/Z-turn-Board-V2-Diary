Assuming you understand: [PL only: Standalone](../PL_only:_Standalone/README.md)..

# PL only: Standalone

(As per "[PL only: Standalone](../PL_only:_Standalone/README.md)"), We'll blink:

* CAN: 2 bits
* User leds: 1 and 2s
* User Button: (input only)

## Pins:

### CAN: MIO{14,15}
![](images/can.schem.1.jpg "can 1")

![](images/can.schem.2.jpg "can 1.b")

### LED: 1,2: MIO{0,9}
![](images/led.schem.1.jpg "led 1")

![](images/led.schem.2.jpg "led 1.b")

### Button: MIO{50}
![](images/button.schem.1.jpg "button")

![](images/button.schem.2.jpg "button.b")

## Releasing the pins:
## Which are [already] bound [to other functions]? (CAN is).
### Vivado:
![](images/pins.1.jpg "bound pins")

![](images/pins.2.jpg "bound_pins.b")
### Releasing `CAN0`
![](images/pins.3.jpg "releasing CAN0")


