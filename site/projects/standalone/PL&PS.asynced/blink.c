#include "xparameters.h"
#include "xgpiops.h"
#include <math.h>

#define	XGPIOPS_BASEADDR	XPAR_XGPIOPS_0_BASEADDR

// Blink all(LEDs, CAN, Button(input))
// -
int blink (void)
{
    // --------------------------------------------------------- //
    // -                                                       - //
    // =                 Initialization [area]                 = //
    // -                                                       - //
    // --------------------------------------------------------- //
    XGpioPs Gpio;
	XGpioPs_Config* ConfigPtr = XGpioPs_LookupConfig(XGPIOPS_BASEADDR);
    int Status = XGpioPs_CfgInitialize(&Gpio, ConfigPtr, ConfigPtr->BaseAddr);
	if (Status != XST_SUCCESS) {
		return __LINE__;
	}
    
    // -------------------------------------------------------- //
    // -                                                      - //
    // =                 Configuration [area]                 = //
    // -                                                      - //
    // -------------------------------------------------------- //
    const u32 BUTTON = 50;
    const u32 LED1 = 0;
    const u32 LED2 = 9;
    u32 LED_state = 0;
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
    // -                                                  - //
    // =                 Execution [area]                 = //
    // -                                                  - //
    // ---------------------------------------------------- //
    while (1)   // TODO: Interrupt [instead of polling]
    {
        static u32 button;    // Read data

        // Read button
        // -
        button = XGpioPs_ReadPin(&Gpio, BUTTON);

        xil_printf("Button(%d)\n", button);

        // If not paused
        //      Button is inversed. (Probably pull-up(?)).
        //      0: Paused
        //      1: Resumed
        // -
        if (button != 0)
        {
            // Alternante LEDs
            //      LED1 takes the previous value [of LED_state]
            // -
            XGpioPs_WritePin(&Gpio, LED1, LED_state);

            if (LED_state == 0)
            {
                LED_state = 1;
            }
            else
            {
                LED_state = 0;
            }

            // Alternante LEDs
            //      LED2 takes the new value [of LED_state]
            // -
            XGpioPs_WritePin(&Gpio, LED2, LED_state);   // T.N.: Sorry.. I'd prefer `C++`'s: `boolean` 🙃..

            // Delay (for around the same amount as the PL, i.e.: asynchronously).
            // -
            for (int i = 0; i < pow(2, 27 - 1); ++i) // Primitive downscaler to ~ 1Hz // TODO: I'd prefer C++: `constexpr uint32_t freq = pow(2, 27 - 1);`
            {
                // wait //
            }
        }
        else
        {
            // Pause blinking. (Button is pressed). //
        }
    }

    // ---------------------------------------- //
    // =                 Exit                 = //
    // ---------------------------------------- //
    return XST_SUCCESS;
}