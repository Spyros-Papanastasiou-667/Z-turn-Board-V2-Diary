Assuming you've read the [PL&PS // asynced // polling](../PL&PS.asynced/README.md) part..

Interrupts: Info:

* They pause the processor, to run the `handler()`.
* Usually, variables and handler need to be **`static`**..
* Dangers of cyclic [interrupt] dependencies (**priority**). One interrupt may **hang** the others.
* Same **handler** may trigger for multiple pins. **Differentiation** within handler may be needed.

---

## PL&PS // asynced // interrupt

## General procedure

```c
#include "xinterrupt_wrap.h"                                            // Include the header
// XScuGic Intc;                                                        // Create an iterrupt controller (?)
XGpioPs_SetIntrTypePin(&Gpio, BUTTON, XGPIOPS_IRQ_TYPE_EDGE_FALLING);   // Set PIN as interrupt
XGpioPs_SetCallbackHandler(&Gpio, (void*) &Gpio, IntrHandler);          // Link handler
XGpioPs_IntrEnablePin(&Gpio, BUTTON);                                   // Enable interrupt
Status = XSetupInterruptSystem(&Gpio,
                               &XGpioPs_IntrHandler,
                               ConfigPtr->IntrId,
                               ConfigPtr->IntrParent,
                               XINTERRUPT_DEFAULT_PRIORITY);            // (?)
```

---

## Code:
### [`blink.h`](blink.h):
```c
// Define a constant to avoid multiple inclusion [of this file].
// -
#ifndef BLINK
#define BLINK

// Blink all(LEDs, CAN, Button(input))
// -
int blink (void);

#endif
```

### [`blink.c`](blink.c):
```c
#include "xparameters.h"
#include "xgpiops.h"
#include "xinterrupt_wrap.h"
#include <math.h>

#define	XGPIOPS_BASEADDR	XPAR_XGPIOPS_0_BASEADDR
#define GPIO_BANK	        XGPIOPS_BANK0

const u32 LED1 = 0;
const u32 LED2 = 9;

static XGpioPs Gpio;
static void IntrHandler(void *CallBackRef, u32 Bank, u32 Status);

// Blink all(LEDs, CAN, Button(input))
// -
int blink (void)
{
    // --------------------------------------------------------- //
    // -                                                       - //
    // =                 Initialization [area]                 = //
    // -                                                       - //
    // --------------------------------------------------------- //
	XGpioPs_Config* ConfigPtr = XGpioPs_LookupConfig(XGPIOPS_BASEADDR);
    int Status = XGpioPs_CfgInitialize(&Gpio, ConfigPtr, ConfigPtr->BaseAddr);
	if (Status != XST_SUCCESS)
    {
		return __LINE__;
	}
    // ---------------------------------------------------- //
    // =                 Interrupt [part]                 = //
    // ---------------------------------------------------- //
    // XScuGic Intc;
    
    // -------------------------------------------------------- //
    // -                                                      - //
    // =                 Configuration [area]                 = //
    // -                                                      - //
    // -------------------------------------------------------- //
    const u32 BUTTON = 50;
    // Set output
    // -
    XGpioPs_SetDirectionPin(&Gpio, LED1, 1);
    XGpioPs_SetDirectionPin(&Gpio, LED2, 1);
    XGpioPs_SetOutputEnablePin(&Gpio, LED1, 1);
    XGpioPs_SetOutputEnablePin(&Gpio, LED2, 1);
    // Set input
    // -
    XGpioPs_SetDirectionPin(&Gpio, BUTTON, 0);
    // ---------------------------------------------------- //
    // =                 Interrupt [part]                 = //
    // ---------------------------------------------------- //
    XGpioPs_SetIntrTypePin(&Gpio, BUTTON, XGPIOPS_IRQ_TYPE_EDGE_FALLING);
    XGpioPs_SetCallbackHandler(&Gpio, (void*) &Gpio, IntrHandler);
    XGpioPs_IntrEnablePin(&Gpio, BUTTON);
    Status = XSetupInterruptSystem(&Gpio, &XGpioPs_IntrHandler, ConfigPtr->IntrId, ConfigPtr->IntrParent, XINTERRUPT_DEFAULT_PRIORITY);
    if (Status != XST_SUCCESS)
    {
		return __LINE__;
	}
    // ---------------------------------------------------- //
    // -                                                  - //
    // =                 Execution [area]                 = //
    // -                                                  - //
    // ---------------------------------------------------- //

    // Beauty of interrupts 🌌👺🥶😶‍🌫️😇 //

    // ---------------------------------------- //
    // =                 Exit                 = //
    // ---------------------------------------- //
    return XST_SUCCESS;
}

static void IntrHandler(void* CallBackRef, u32 Bank, u32 Status)
{
    static u32 prev_state = 1, state = 0;

    // ------------------------------------------------ //
    // =                 Change state                 = //
    // ------------------------------------------------ //
    prev_state = state;
    if (state == 0)
    {
        state = 1;
    }
    else
    {
        state = 0;
    }

    // LED1 = not LED2
    // -
    XGpioPs_WritePin(&Gpio, LED1, prev_state);
    XGpioPs_WritePin(&Gpio, LED2, state);   // T.N.: I prefer `C++`'s `boolean` 🙃..
}
```

### Changes to [`helloworld.c`](helloworld.c):
```c
#include "blink.h"

blink();
```

---

## Notes:

* Don't feel **frightened** by the `button` not triggering all the times. It needs [wiki:debouncing](https://en.wikipedia.org/wiki/Switch#Contact_bounce) since it **overtriggers** 😉.

---

## References:
* [xgpiops_intr_example.c](https://github.com/Xilinx/embeddedsw/blob/master/XilinxProcessorIPLib/drivers/gpiops/examples/xgpiops_intr_example.c) (*github*)
* [XGpioPs_SetIntrType()](https://xilinx.github.io/embeddedsw.github.io/gpiops/doc/html/api/group__gpiops.html) (*API*)
* [API](https://xilinx.github.io/embeddedsw.github.io/gpiops/doc/html/api/group__gpiops.html) (*API*)
* [IrqType](https://xilinx.github.io/embeddedsw.github.io/gpiops/doc/html/api/xgpiops_8h.html) (*API*)