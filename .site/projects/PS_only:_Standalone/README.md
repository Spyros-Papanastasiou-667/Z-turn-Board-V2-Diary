Assuming you understand: [PL only: Standalone](../PL_only:_Standalone/README.md)..

# PS only: Standalone

(As per "[PL only: Standalone](../PL_only:_Standalone/README.md)"), We'll blink:

* CAN: 2 bits
* User leds: 1 and 2s
* User Button: (input only)

## We will need our exported platform from [PL only: Standalone](../PL_only:_Standalone/README.md)

## Starting Vitis with [our [standalone (OS)] platform]:
![](images/vitis.1.jpg "block diagram")

![](images/vitis.2.jpg "standalone OS")

![](images/vitis.3.jpg "vitis has platform")

## Let's add a "Hellow World" application. (Not a "Linux Hellow World")!
![](images/vitis.4.jpg "hellow_world.1")

![](images/vitis.5.jpg "hellow_world.2")

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


