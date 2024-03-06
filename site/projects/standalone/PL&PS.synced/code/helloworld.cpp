/******************************************************************************
* Copyright (C) 2023 Advanced Micro Devices, Inc. All Rights Reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/
/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

extern "C"
{
    #include <stdio.h>
    #include <xil_printf.h>
    #include "platform.h"
}
#include "blink.h"

int main()
{
    init_platform();

    print("Hello World\n");
    print("Successfully ran Hello World application\n");
    blink();
    cleanup_platform();
    return 0;
}
