## [(source code)](code)

Continuing on from [PL&PS // asynced // interrupt](../PL&PS.asynced.interrupt/README.md)..

## Outline

### Enabling GPIO(PS) interrupts(Button)

```cpp
ConfigPtr = XGpioPs_LookupConfig(XPAR_XGPIOPS_0_BASEADDR);      // Needed by next command(initialization)
                                                                // `xparameters.h`
XGpioPs_CfgInitialize(&gpio, ConfigPtr, ConfigPtr->BaseAddr);
XGpioPs_SetDirectionPin(&gpio, BUTTON_pin, INPUT);
XGpioPs_SetIntrTypePin(&gpio, BUTTON_pin, XGPIOPS_IRQ_TYPE_EDGE_BOTH);  // `xgpiops.h`: "Trigger types"
XGpioPs_SetCallbackHandler(
    &gpio,
    static_cast<void*>(&gpio),
    PSHandler);                                                 // Link [our] handler
XSetupInterruptSystem( // The new "SDT" (System Device Tree) method (?)
    &gpio, 
    reinterpret_cast<void*>(&XGpioPs_IntrHandler),              // (Cast needed for C++ compatibility)
                                                                // Link to *system*'s [handler](https://xilinx.github.io/embeddedsw.github.io/gpiops/doc/html/api/group__gpiops.html#gafd0478d095fee0db04a29b43436306ef).
                                                                // Quote: "It checks the interrupt status registers of all 
                                                                //          the banks to determine the actual bank in which an 
                                                                //          interrupt has been triggered. It then calls the 
                                                                //          upper layer callback handler set by the function 
                                                                //          XGpioPs_SetBankHandler()"
    ConfigPtr->IntrId, 
    ConfigPtr->IntrParent, 
    XINTERRUPT_DEFAULT_PRIORITY);
    XGpioPs_IntrEnablePin(&gpio, BUTTON_pin);                   // Enable interruptt
```

#### Handler(PS)

```cpp
XGpioPs_IntrDisablePin(&gpio, BUTTON_pin);  // (Failsafe)
XGpioPs_ReadPin(&gpio, BUTTON_pin);         // Read state(0/1)
XGpioPs_IntrClearPin(&gpio, BUTTON_pin);    // (Ignore remaining "presses").
XGpioPs_IntrEnablePin(&gpio, BUTTON_pin);   // (Enable(Failsafe))
```

### Enabling GPIO(PL) interrupts(CLK_out)

```cpp
XGpio_Initialize(&gpioCLK, XPAR_XGPIO_0_BASEADDR);    // `xparameters.h`: 0/1/.. according to Vivado's Block Design.
// XGpio_SetDataDirection(&gpioCLK, CHANNEL, INPUT);
ConfigPtr = XGpio_LookupConfig(XPAR_XGPIO_0_BASEADDR);  // (Needed by next command)
XSetupInterruptSystem(
    &gpioCLK,
    reinterpret_cast<void*>(&PLHandlerCLK),           // (Cast needed for C++ compatibility)
                                                      // Link, *our* handler.
    ConfigPtr->IntrId,
    ConfigPtr->IntrParent,
    XINTERRUPT_DEFAULT_PRIORITY);
XGpio_InterruptGlobalEnable(&gpioCLK);                // (?)
XGpio_InterruptEnable(&gpioCLK, CHANNEL);             // Enable
```

#### Handler(PL)

```cpp
XGpio_InterruptDisable(&PL::gpioCLK, PL::CHANNEL);  // (Failsafe)
XGpio_InterruptClear(&PL::gpioCLK, PL::CHANNEL);    // (Clear pending)
XGpio_InterruptEnable(&PL::gpioCLK, PL::CHANNEL);   // (Enable(Failsafe))
```

## Details