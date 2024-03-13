#pragma once
extern "C"
{
    #include "xparameters.h"        // XPAR_XGPIOPS_0_BASEADDR definition
    #include "xgpiops.h"            // XGpioPs type
}

// -------------------------------------------------------------- //
// -                                                            - //
// =                    PS(GPIO) abstraction                    = //
// -                                                            - //
// -------------------------------------------------------------- //
// Description:
// -
class PS
{
public:
    // Constants
    // -
    static constexpr bool INPUT = 0;
    static constexpr bool OUTPUT = 1;
    // Variables
    // -

    PS ();

    // Delay interrupt activations in case if cyclic [class] dependencies
    // -
    static void enable_button_interrupt ();
    static void setLED1 (const bool& state);
    static void setLED2 (const bool& state);
    static bool button_pressed ();

private:
    // Constants
    // -
    static constexpr auto GPIO_BASEADDR = XPAR_XGPIOPS_0_BASEADDR;
    static constexpr bool DISABLE = 0;
    static constexpr bool ENABLE = 1;
    static constexpr u32 LED_pin[2] = {0, 9};
    static constexpr auto LED1_pin = LED_pin[0];
    static constexpr auto LED2_pin = LED_pin[1];
    static constexpr u32 BUTTON_pin = 50;

    // Variables
    // -
    static XGpioPs gpio;
    static bool button_released;

    // Initialization functions
    // -
    static XGpioPs_Config* start_gpio ();
    static void setup_pins ();
    static void setLED(const uint8_t& id, const bool& state);
    static void setup_button_interrupt (XGpioPs_Config* ConfigPtr);

    // Handlers
    // -
    static void PSHandler (void* CallBackRef, u32 Bank, u32 Status);
};