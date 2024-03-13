#include "PS.h"
#include "PL.h"
extern "C"
{
    #include <xil_types.h>          // u32 type
    #include <xgpiops.h>            // XGpioPs type
    // #include <xgpio.h>              // XGpio_DiscreteWrite() functioin
    #include <xinterrupt_wrap.h>    // XINTERRUPT_DEFAULT_PRIORITY definition
}
#include <cassert>

// [Class [static] variable] Instantiation (?)
// -
XGpioPs PS::gpio;
bool PS::button_released = true;

// ------------------------------------------------------------ //
// -                                                          - //
// =                    PS class [related]                    = //
// -                                                          - //
// ------------------------------------------------------------ //
PS::PS ()
{
    static bool started = false;
    
    if (not started)
    {
        started = true;

        auto config = start_gpio();
        setup_pins();
        setup_button_interrupt(config);
        xil_printf("PS(constructor) finished!\n");
    }
}

XGpioPs_Config* PS::start_gpio ()
{
    int status;
    auto ConfigPtr = XGpioPs_LookupConfig(GPIO_BASEADDR);
    if (ConfigPtr == nullptr)
    {
        xil_printf("ERROR: XGpioPs_LookupConfig: %s(%d)\n", __FILE__, __LINE__);
    }

    status = XGpioPs_CfgInitialize(&gpio, ConfigPtr, ConfigPtr->BaseAddr);
    if (status != XST_SUCCESS)
    {
        xil_printf("ERROR: XGpioPs_CfgInitialize: %s(%d)\n", __FILE__, __LINE__);
    }

    status = XGpioPs_SelfTest(&gpio);
    if (status != XST_SUCCESS)
    {
        xil_printf("ERROR: XGpioPs_SelfTest: %s(%d)\n", __FILE__, __LINE__);
    }

    return ConfigPtr;
}

void PS::setup_pins ()
{
    // ---------------------- //
    // =        LEDs        = //
    // ---------------------- //
    XGpioPs_SetDirectionPin(&gpio, LED1_pin, OUTPUT);
    XGpioPs_SetDirectionPin(&gpio, LED2_pin, OUTPUT);
    XGpioPs_SetOutputEnablePin(&gpio, LED1_pin, ENABLE);
    XGpioPs_SetOutputEnablePin(&gpio, LED2_pin, ENABLE);
    XGpioPs_WritePin(&gpio, LED1_pin, 1);
    XGpioPs_WritePin(&gpio, LED2_pin, 1);

    // ------------------------ //
    // =        Button        = //
    // ------------------------ //
    XGpioPs_SetDirectionPin(&gpio, BUTTON_pin, INPUT);
}

void PS::setup_button_interrupt (XGpioPs_Config* ConfigPtr)
{
    int status;
    XGpioPs_SetIntrTypePin(&gpio, BUTTON_pin, XGPIOPS_IRQ_TYPE_EDGE_BOTH);
	XGpioPs_SetCallbackHandler(
        &gpio,
        static_cast<void*>(&gpio),
        PSHandler);
    
    status = XSetupInterruptSystem(
        &gpio, 
        reinterpret_cast<void*>(&XGpioPs_IntrHandler),  // Cast needed for C++ compatibility 
        ConfigPtr->IntrId, 
        ConfigPtr->IntrParent, 
        XINTERRUPT_DEFAULT_PRIORITY);
    if (status != XST_SUCCESS)
    {
        xil_printf("ERROR: XSetupInterruptSystem: %s(%d)\n", __FILE__, __LINE__);
    }
}

void PS::enable_button_interrupt ()
{
    XGpioPs_IntrEnablePin(&gpio, BUTTON_pin);
    xil_printf("PS(interrupt) started..\n");
}

void PS::setLED1 (const bool& state)
{
    setLED(1, state);
}

void PS::setLED2 (const bool& state)
{
    setLED(2, state);
}

bool PS::button_pressed ()
{
    return not button_released;
}

void PS::setLED(const uint8_t& id, const bool& state)
{
    assert(id == 1 or id == 2); // FIXME
    XGpioPs_WritePin(&gpio, LED_pin[id - 1], state);
}

// Description:
//      Sends state [to PL] on both RISING and FALLING [edge]
// -
void PS::PSHandler (void* CallBackRef, u32 Bank, u32 Status)
{
    // Trying to debounce [by disabling it].
    // -
    XGpioPs_IntrDisablePin(&gpio, BUTTON_pin);

    // Alternative method. Retrieving info within parameters
    // -
    // XGpioPs* Gpio = reinterpret_cast<XGpioPs*>(CallBackRef);

    // ----------------------------------------------------- //
    // =                 Send button to PL                 = //
    // ----------------------------------------------------- //
    button_released = XGpioPs_ReadPin(&gpio, BUTTON_pin);
    xil_printf("DBG▷ button(%d)\n", button_released);
    PL::setButton(button_released);

    // -------------------------------------------------------------------- //
    // =                 Clear pending interrupt [clones]                 = //
    // -------------------------------------------------------------------- //
    XGpioPs_IntrClearPin(&gpio, BUTTON_pin);
    XGpioPs_IntrEnablePin(&gpio, BUTTON_pin);   // Trying to debounce [by disabling interrupt].
}
