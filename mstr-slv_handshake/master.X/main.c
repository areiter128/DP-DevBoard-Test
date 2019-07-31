/*  
 * File:  main.c
 * Author: M91406
 * Comments:
 *    Example program for master and slave core with a simple handshake.
 *    Both core use the same peripheral libraries to set up peripherals.
 */


/* *****************************************************************************************************
 *      ___       _     __  __    ____   _   _  _____     _    
 *     |_ _|     / \   |  \/  |  |  _ \ | | | || ____|   / \   
 *      | |     / _ \  | |\/| |  | |_) || |_| ||  _|    / _ \  
 *      | |    / ___ \ | |  | |  |  _ < |  _  || |___  / ___ \ 
 *     |___|  /_/   \_\|_|  |_|  |_| \_\|_| |_||_____|/_/   \_\
 *                                                             
 * *****************************************************************************************************/
/* Rhea is the master core                                                                           */
/**
  Section: Included Files
*/
#include <xc.h>
#include <p33SMPS_plib.h>
#include "main.h"
#include "mcal.h"

#if(SLAVE_PROJECT_PRESENT == 1)
//    #include "p33SMPS_slave_core.h"
    #include <libpic30.h>
    #include "slave.h"
    #define SLAVE_IMAGE     slave
    #define SLAVE_NUMBER    1
#endif

#define LEDTGLCNT           3000
#define LEDTGLCNT_FAST      1000
uint16_t ledtglcnt = 0, dbgled_toggle = 0;
uint16_t ledtglcnt_rd = 0, ledtglcnt_gn = 0;
uint16_t ledt_rd_toggle = 0, ledt_gn_toggle = 0;
#define STARTUP_DELAY 5000
void delay_100usec(volatile uint16_t repeat_cnt);

/*
                         Main application
 */
volatile APPLICATION_SETTINGS_t application;

volatile uint16_t pdc_dummy = 0;

int main(void)
{

    volatile uint16_t i=0;
    volatile TxCON_CONTROL_REGISTER_t tmr;
    volatile uint32_t period;
    volatile int16_t fres=0;
    
    volatile uint16_t mstr_mailbox_dummy = 0;
    
    // wait for the supply voltage to stabilize
    for(i=0xffff; i>0; i--);    
    for(i=0xffff; i>0; i--);
    for(i=0xffff; i>0; i--);
    for(i=0xffff; i>0; i--);

    // initialize GPIOs immediately to set up auxiliary power start up 
    initialize_gpio();

    // initialize oscillator    
    init_FRCOSC( CLKDIV_FRCDIVN_1, OSCTUN_TUN_PLUS_2 );
    
    fres = init_FRC_Defaults(CPU_SPEED_90_MIPS);
    fres = init_AUXCLK_500MHz();

    
    // set up scheduler timer
    tmr.flags.tcs = TCS_INTERNAL;
    tmr.flags.tckps = TCKPS_DIV_1_to_1;
    tmr.flags.tecs = TECS_TCY;
    tmr.flags.tsidl = TSIDL_CONTINUE;
    tmr.flags.tsync = TSYNC_NONE;
    tmr.flags.tmwip = TMWIP_COMPLETE;
    tmr.flags.tmwdis = TMWDIS_ENABLED;
    tmr.flags.tgate = TGATE_DISABLED;
    tmr.flags.prwip = PRWIP_COMPLETE;
    tmr.flags.ton = TON_ENABLED;

    period = MAIN_LOOP_TICK_PERIOD;
    gstmr_init_timer16b(1, tmr, period, 0);

    // Peripheral Configuration
    application.period = PWM_PERIOD; // n x 250 ps (e.g. 20,000 = ~250 kHz)
    application.initial_duty_ratio = PWM_DUTY_RATIO;
    application.dead_time_rising = DEAD_TIME_RISING_EDGE; // n x 250 ps (e.g. 200 = 50 ns)
    application.dead_time_falling = DEAD_TIME_FALLING_EDGE; // n x 250 ps (e.g. 320 = 80 ns)
    application.ctrl_pwm_min = PWM_DUTY_CYCLE_MINIMUM;
    application.ctrl_pwm_max = PWM_DUTY_CYCLE_MAXIMUM;

    #if(SLAVE_PROJECT_PRESENT == 1)

    // initialize_Slave();
//    MSI1CON = 0x00;	//SRSTIE disabled; SLVEN disabled; MSTIRQ disabled; RFITSEL Trigger data valid interrupt when 1st FIFO entry is written by Slave; STMIACK disabled; 
//    MSI1FIFOCS = 0x0000;	//WFEN enabled; RFEN enabled; 

    _program_slave(SLAVE_NUMBER, 0, SLAVE_IMAGE);    
    _start_slave();

    #endif

   // initialize mailboxes for direct CASTOR-POLLUX communication
    MASTER_TO_SLAVE_DUTY_RATIO_MAILBOX = 0x0000;
    SLAVE_TO_MASTER_DUTY_RATIO_MAILBOX = 0x0000;
    MASTER_TO_SLAVE_P1_MAILBOX = 0x0000;
    MASTER_TO_SLAVE_P2_MAILBOX = 0x0000;
     
    initialize_hspwm(1);    // Configure VOUT PWM
    initialize_hsadc();
    hspwm_enable_pwm(1, 1);
    
    while (1)
    {
        // Add your application code
        while(!_T1IF);
        _T1IF = 0;

        TP39_TOGGLE;

        if(SWITCH_RD == SWITCH_OPEN)
        { dbgled_toggle = LEDTGLCNT; }
        else
        { dbgled_toggle = LEDTGLCNT_FAST; }
        
        if (ledtglcnt++ > dbgled_toggle)
        { 
            ledtglcnt = 0; 
            DBGLED_TOGGLE;
        }

        if (ledtglcnt_rd++ > ledt_rd_toggle)
        { 
            if ((1900 < application.v_P2) && (application.v_P2 < 2150))
            { ledtglcnt_rd = 0; LED_RD_WR = BRD_LED_ON; }
            else
            { ledtglcnt_rd = 0; LED_RD_TOGGLE; }
        }

        if (ledtglcnt_gn++ > ledt_gn_toggle)
        { 
            if ((1900 < application.v_P1) && (application.v_P1 < 2150))
            { ledtglcnt_gn = 0; LED_GN_WR = BRD_LED_ON; }
            else
            { ledtglcnt_gn = 0; LED_GN_TOGGLE; }
        }
        
        MASTER_TO_SLAVE_DUTY_RATIO_MAILBOX = mstr_mailbox_dummy++;  // Set Rhea message (incrementing counter)


    }
    return 1; 
}


/* =================================================================================================== */
/* Voltage mode controller of VRM bus is driven from the VOUT Feedback ISR */
/* =================================================================================================== */
void __attribute__((__interrupt__, auto_psv, context)) _TP06_ADC_Interrupt() 
{	

    // read most recent data
    application.adc_active = true;  // set ISR monitoring flag bits
    application.v_P1 = TP06_ADCBUF; // publishing VOUT voltage
    application.v_P2 = TP12_ADCBUF; // publishing DC-LINK voltage

    MASTER_TO_SLAVE_P1_MAILBOX = application.v_P1;
    MASTER_TO_SLAVE_P2_MAILBOX = application.v_P2;

    ledt_rd_toggle = (LED_BLINKRATE_VOLTAGE_OFFSET + (application.v_P2));
    ledt_gn_toggle = (LED_BLINKRATE_VOLTAGE_OFFSET + (application.v_P1));
    
    // Clear ISR flag bits
	TP06_ADC_IF = 0;	// Clear interrupt flag bit

	return;

}


void delay_100usec(volatile uint16_t repeat_cnt)
{
volatile uint16_t delay_cnt = 0, timeout = 0;

    while (delay_cnt++ < repeat_cnt)
    {
        // Add your application code
        while((!_T1IF) && (timeout < 0xfff0));
        _T1IF = 0;
    }

    return;
}

/**
 End of File
*/

