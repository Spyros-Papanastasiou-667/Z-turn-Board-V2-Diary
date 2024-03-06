#include "Gpio.h"
#include "PS.h"
#include "PL.h"

Gpio::Gpio ()
{
    static bool started = false;

    if (not started)
    {
        started = true;
        
        PS ps;
        PL pl;
        pl.enable_interrupts();
        ps.enable_button_interrupt();
    }
}