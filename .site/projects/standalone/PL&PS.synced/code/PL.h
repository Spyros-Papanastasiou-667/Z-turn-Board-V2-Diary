#pragma once
extern "C"
{
    #include <xil_types.h>  // u32 type
    #include <xgpio.h>      // XGpio type
}
#include "PS.h"

// -------------------------------------------------------------- //
// -                                                            - //
// =                    PL(GPIO) abstraction                    = //
// -                                                            - //
// -------------------------------------------------------------- //
// Description:
// -
class PL
{
public:
    // Constants
    // -
    static constexpr auto CHANNEL = 1; // We're currently using single-channel, AXI GPIO. 

    // Variables
    // -
    static XGpio gpioButton;

    PL ();

    // Delay interrupt activations in case if cyclic [class] dependencies
    // -
    static void enable_interrupts ();
    static void enable_CLK_interrupt ();
    static void enable_button_interrupt ();

    static void setButton (const bool& state);

private:
    // Constants
    // -
    // IMPORTANT: IDs(#) according to [Vivado's] Block Design
    // -
    static constexpr auto GPIO_BASEADDR_BUTTON = XPAR_XGPIO_1_BASEADDR;
    static constexpr auto GPIO_BASEADDR_CLK = XPAR_XGPIO_0_BASEADDR;
    static constexpr bool INPUT = not PS::INPUT;
    static constexpr bool OUTPUT = not PS::OUTPUT;
    static constexpr bool HIGH = true;
    static constexpr bool LOW = not HIGH;

    // Variables
    // -
    static XGpio gpioCLK;

    // Initialization functions
    // -
    static void start_gpio ();
    static void setup_pins ();
    static void setup_CLK_interrupt ();

    // Handlers
    // -
    static void PLHandlerCLK (void* CallBackRef);
};
