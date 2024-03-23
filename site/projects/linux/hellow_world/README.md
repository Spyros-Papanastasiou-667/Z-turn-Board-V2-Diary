# Assuming [preliminaries](../preliminary/README.md)

# 🌷 Blinking through Linux 🌌

## Vivado part:

* Check for various warnings under 'Platform Setup'
* With respect to PL 2 PS interrupts, add an `AXI Interrupt Controller` between the GPIO_CLK interrupt and the Zynq_IRQ:
    * (Also set the interrupt controller's output, to "single"):
* (Adding a [NOT](https://en.wikipedia.org/wiki/NOT_gate) gate clarifies the **button**'s [active state](https://en.wikipedia.org/wiki/Logic_level#Active_state)).

![](images/block.diagram.svg "block diagram")

This should be enough for the PL(LEDs) to blink.

## Next: [Linux part](Code.md)