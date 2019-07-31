/*
 * File:   init_gpio.c
 * Author: M91406
 *
 * Created on October 16, 2018, 10:58 AM
 */


#include <xc.h>
#include "main.h"

/* === Initialize GPIOs ===================================================== */
void initialize_gpio(void)
{
    // Reset analog functions
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;

    // Initialize debugging functions
    DBGLED_INIT_OUTPUT;     // ON-PIM DEBUG-LED
    LED_RD_INIT_OUTPUT;
    LED_GN_INIT_OUTPUT;
    
    TP39_INIT_OUTPUT;
    
    TP06_INIT_ANALOG;
    TP12_INIT_ANALOG;
    
    return;
}
