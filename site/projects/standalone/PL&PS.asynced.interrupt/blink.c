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