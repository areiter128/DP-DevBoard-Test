/*  
 * File:  main.c
 * Author: M91406
 * Comments:
 *    Example program for master and slave core with a simple handshake.
 *    Both core use the same peripheral libraries to set up peripherals.
 */

/* *****************************************************************************************************
 *      ___       _     __  __     ____  ____    ___   _   _  _   _  ____  
 *     |_ _|     / \   |  \/  |   / ___||  _ \  / _ \ | \ | || | | |/ ___| 
 *      | |     / _ \  | |\/| |  | |    | |_) || | | ||  \| || | | |\___ \ 
 *      | |    / ___ \ | |  | |  | |___ |  _ < | |_| || |\  || |_| | ___) |
 *     |___|  /_/   \_\|_|  |_|   \____||_| \_\ \___/ |_| \_| \___/ |____/ 
 *                                                                         
 * *****************************************************************************************************/
/* Cronus is the slave core                                                                           */
/**
  Section: Included Files
*/
#include "main.h"
#include "mcal.h"

#define LEDTGLCNT   3000
volatile uint16_t ledtglcnt = 0;

#define SFT     (volatile uint16_t) 3
#define NORM    (volatile uint16_t) 15
#define ADCMAX  (volatile uint16_t) 32768 // ( = 4096 << SFT )
/*
                         Main application
 */
int main(void)
{
    volatile TxCON_CONTROL_REGISTER_t tmr;
    volatile uint32_t period, dc_dummy;
    volatile int16_t fres = 0;
    volatile uint16_t mstr_mailbox_dummy = 0;

    fres = init_FRC_Defaults(CPU_SPEED_100_MIPS);
    init_AUXCLK_500MHz();

    TP45_INIT_OUTPUT;
    TP47_INIT_OUTPUT;
    
    tmr.flags.tcs = TCS_INTERNAL;
    tmr.flags.tckps = TCKPS_DIV_1_to_1;
    tmr.flags.tecs = TECS_TCY;
    tmr.flags.tsidl = TSIDL_CONTINUE;
    tmr.flags.tsync = TSYNC_NONE;
    tmr.flags.tmwip = TMWIP_COMPLETE;
    tmr.flags.tmwdis = TMWDIS_DISABLED;
    tmr.flags.tgate = TGATE_DISABLED;
    tmr.flags.prwip = PRWIP_COMPLETE;
    tmr.flags.ton = TON_ENABLED;

    period = MAIN_LOOP_TICK_PERIOD;
    gstmr_init_timer16b(1, tmr, period, 0);

    initialize_hspwm(1); // Configure PWM
    hspwm_enable_pwm(1, 1);    
    hspwm_ovr_release(1);
    
    CORCONbits.IF = 0; // set Fractional multiplies
    
    while (1)
    {
        // Add your application code
        while(!_T1IF);
        _T1IF = 0;
        
        // Update duty cycle for P1 value
        dc_dummy = MASTER_TO_SLAVE_P1_MAILBOX;              // Read RHEA Message
        dc_dummy <<= SFT;     // normalize input to Q16
        dc_dummy *= ADCMAX;   
        dc_dummy >>= NORM;
        dc_dummy *= PWM_PERIOD;
        dc_dummy >>= NORM;
        if (dc_dummy < PWM_DUTY_CYCLE_MINIMUM) dc_dummy = PWM_DUTY_CYCLE_MINIMUM;
        else if (dc_dummy > PWM_DUTY_CYCLE_MAXIMUM) dc_dummy = PWM_DUTY_CYCLE_MAXIMUM;
        PG1DC = (volatile uint16_t)dc_dummy;
        
        dc_dummy = MASTER_TO_SLAVE_P2_MAILBOX;              // Read RHEA Message
        dc_dummy <<= SFT;     // normalize input to Q16
        dc_dummy *= ADCMAX;   
        dc_dummy >>= NORM;
        dc_dummy *= PWM_PERIOD;
        dc_dummy >>= NORM;
        if (dc_dummy < PWM_DUTY_CYCLE_MINIMUM) dc_dummy = PWM_DUTY_CYCLE_MINIMUM;
        else if (dc_dummy > PWM_DUTY_CYCLE_MAXIMUM) dc_dummy = PWM_DUTY_CYCLE_MAXIMUM;
        PG1TRIGB = (volatile uint16_t)dc_dummy;
        
        
        PG1STATbits.UPDREQ = 1;
        
        mstr_mailbox_dummy = MASTER_TO_SLAVE_STATUS_MAILBOX;    // Read RHEA Message 
        SLAVE_TO_MASTER_STATUS_MAILBOX = mstr_mailbox_dummy;    // Loop back RHEA Message 
        
    }
    return 1; 
}

/**
 End of File
*/
