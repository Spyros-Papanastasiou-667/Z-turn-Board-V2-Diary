#include "PL.h"
#include "PS.h"
extern "C"
{
    #include <xparameters.h>        // XPAR_XGPIO_0_BASEADDR definition
    #include <xgpio.h>              // XGpio type
    #include <xgpiops.h>            // XGpioPs_WritePin() function
    #include <xinterrupt_wrap.h>    // XINTERRUPT_DEFAULT_PRIORITY definition
}

// [Class [static] variable] Instantiation (?)
// -
XGpio PL::gpioButton;
XGpio PL::gpioCLK;

// ------------------------------------------------------ //
// -                                                    - //
// =                 PL class [related]                 = //
// -                                                    - //
// ------------------------------------------------------ //
PL::PL ()
{
    static bool started = false;

    if (not started)
    {
        started = true;

        start_gpio();
        setup_pins();
        setup_CLK_interrupt();
        xil_printf("PL(constructor) finished!\n");
    }
}

void PL::start_gpio ()
{
    int status;
    // -------------------------------- //
    // =            Button            = //
    // -------------------------------- //
    status = XGpio_Initialize(&gpioButton, GPIO_BASEADDR_BUTTON);
    if (status != XST_SUCCESS)
    {
        xil_printf("ERROR: XGpio_Initialize: %s(%d)\n", __FILE__, __LINE__);
    }

    status = XGpio_SelfTest(&gpioButton);
    if (status != XST_SUCCESS)
    {
        xil_printf("ERROR: XGpio_SelfTest: %s(%d)\n", __FILE__, __LINE__);
    }
    // ----------------------------- //
    // =            CLK            = //
    // ----------------------------- //
    status = XGpio_Initialize(&gpioCLK, GPIO_BASEADDR_CLK);
    if (status != XST_SUCCESS)
    {
        xil_printf("ERROR: XGpio_Initialize: %s(%d)\n", __FILE__, __LINE__);
    }

    status = XGpio_SelfTest(&gpioCLK);
    if (status != XST_SUCCESS)
    {
        xil_printf("ERROR: XGpio_SelfTest: %s(%d)\n", __FILE__, __LINE__);
    }
}

void PL::setup_pins ()
{
    // ------------------------ //
    // =        Button        = //
    // ------------------------ //
    XGpio_SetDataDirection(&gpioButton, CHANNEL, OUTPUT);

    // --------------------- //
    // =        CLK        = //
    // --------------------- //
    XGpio_SetDataDirection(&gpioCLK, CHANNEL, INPUT);
}

void PL::setup_CLK_interrupt ()
{
    int status;
    auto ConfigPtr = XGpio_LookupConfig(GPIO_BASEADDR_CLK);
    if (ConfigPtr == nullptr)
    {
        xil_printf("ERROR: XGpio_LookupConfig: %s(%d)\n", __FILE__, __LINE__);
    }

    status = XSetupInterruptSystem(
        &gpioCLK,
        reinterpret_cast<void*>(&PLHandlerCLK),  // Cast needed for C++ compatibility
        ConfigPtr->IntrId,
        ConfigPtr->IntrParent,
        XINTERRUPT_DEFAULT_PRIORITY);
    if (status != XST_SUCCESS)
    {
        xil_printf("ERROR: XGpio_Initialize: %s(%d): %d\n", __FILE__, __LINE__, status);
    }
}

void PL::enable_interrupts ()
{
    enable_CLK_interrupt();
    // enable_button_interrupt();
}

void PL::enable_CLK_interrupt ()
{
    XGpio_InterruptGlobalEnable(&gpioCLK);
    XGpio_InterruptEnable(&gpioCLK, CHANNEL);
    xil_printf("DBG: CLK(value(%d) enabled(0x%x) status(0x%x))\n", 
        XGpio_DiscreteRead(&gpioCLK, CHANNEL),
        XGpio_InterruptGetEnabled(&gpioCLK),
        XGpio_InterruptGetStatus(&gpioCLK));
    xil_printf("PL(interrupt) started..\n");
}

void PL::setButton (const bool& state)
{
    XGpio_DiscreteWrite(&PL::gpioButton, PL::CHANNEL, state);
}

// --------------------------------------------------- //
// -                                                 - //
// =                 PL(CLK) handler                 = //
// -                                                 - //
// --------------------------------------------------- //
// Info:
//      Triggers on both RISING and FALLING edge
// Description:
//      Alternates LEDs 1 and 2
//      Pauses on PS(Button)
// -
void PL::PLHandlerCLK (void* CallBackRef)
{
    // Failsafe
    // -
    XGpio_InterruptDisable(&PL::gpioCLK, PL::CHANNEL);

    // Alternative method. Retrieving info within parameters
    // -
    // XGpio* Gpio = reinterpret_cast<XGpio*>(CallBackRef);

    // -------------------------------------------------- //
    // =                 Blink PS(LEDs)                 = //
    // -------------------------------------------------- //
    auto CLK = XGpio_DiscreteRead(&PL::gpioCLK, PL::CHANNEL);
    xil_printf("DBG: CLK(%d)\n", CLK);
    if (not PS::button_pressed())   // If not paused(0)
    {
        // LED1 = not LED2
        // -
        PS::setLED1(CLK);
        PS::setLED2(not CLK);
    }

    // --------------------------------------------------- //
    // =                 Clear interrupt                 = //
    // --------------------------------------------------- //
	XGpio_InterruptClear(&PL::gpioCLK, PL::CHANNEL);
    XGpio_InterruptEnable(&PL::gpioCLK, PL::CHANNEL);
}
