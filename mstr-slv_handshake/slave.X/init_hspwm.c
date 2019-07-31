/*
 * File:   init_hspwm.c
 * Author: M91406
 *
 * Created on October 16, 2018, 11:03 AM
 */


#include <xc.h>
#include "main.h"


/* === Initialize HSPWM ===================================================== */
void initialize_hspwm(uint16_t channel)
{

    volatile REGBLK_PGxDEAD_TIME_t dtcon;
    volatile REGBLK_PGxIO_CONFIG_t iocon;
    volatile REGBLK_PGxCH_CONFIG_t pgcon;
    volatile REGBLK_PCLK_CONFIG_t pclkcon;
    volatile REGBLK_PGxEVT_CONFIG_t pgevt;
    
    volatile uint16_t phs_sft=0;
    Nop();
    Nop();
    Nop();

    // configure PWM module clock
    pclkcon.PCLKCON.MCLKSEL = PCLKCON_MCLKSEL_AFPLLO;
    pclkcon.PCLKCON.LOCK = PCLKCON_LOCK_UNLOCKED;
    pclkcon.PCLKCON.DIVSEL = PCLKCON_DIVSEL_DIV_2;

    
    // configure PWM channel
    pgcon.PGxCON.CLKSEL = PGCON_CLKSEL_BY_MCLKSEL;
    pgcon.PGxCON.MODSEL = PGCON_MODSEL_INDEPENDENT_EDGE_DUAL_OUT; 
    pgcon.PGxCON.MSTEN = PGCON_MSTEN_NO_BROADCAST;
    pgcon.PGxCON.TRGCNT = PGCON_TRGCNT_1_PWM_CYCLES;
    pgcon.PGxCON.HREN = PGCON_HREN_HIGH_RES;
    
    pgcon.PGxCON.MPERSEL = PGCON_MPERSEL_INDEPENDENT;
    pgcon.PGxCON.MPHSEL = PGCON_MPHSEL_INDEPENDENT;
    pgcon.PGxCON.MDCSEL = PGCON_MDCSEL_INDEPENDENT;
    pgcon.PGxCON.UPDMOD = PGCON_UPDMOD_IMMEDIATE; // PGCON_UPDMOD_SLV_SOC;
    pgcon.PGxCON.TRGMOD = PGCON_TRGMOD_SINGLE;
    pgcon.PGxCON.SOCS = PGCON_SOCS_LOCAL_EOC;

    // configure events
    
    pgevt.PGxEVT.ADTR1EN1 = PGEVT_ADTR1EN1_PGxTRIGA_DISABLED;
    pgevt.PGxEVT.ADTR1EN2 = PGEVT_ADTR1EN2_PGxTRIGB_DISABLED;
    pgevt.PGxEVT.ADTR1EN3 = PGEVT_ADTR1EN3_PGxTRIGC_DISABLED;
    
    pgevt.PGxEVT.ADTR1OFS = PGEVT_ADTR1OFS_OFFSET_EVENTS_0; // create trigger event every cycle
    pgevt.PGxEVT.ADTR1PS  = PGEVT_ADTR1PS_POSTSCALE_1; // create trigger events without post scaler
    
    pgevt.PGxEVT.ADTR2EN1 = PGEVT_ADTR2EN1_PGxTRIGA_DISABLED;
    pgevt.PGxEVT.ADTR2EN2 = PGEVT_ADTR2EN2_PGxTRIGB_ENABLED;
    pgevt.PGxEVT.ADTR2EN3 = PGEVT_ADTR2EN3_PGxTRIGC_DISABLED;

    pgevt.PGxEVT.SIEN = PGEVT_SIEN_DISABLED;
    pgevt.PGxEVT.CLIEN = PGEVT_CLIEN_DISABLED;
    pgevt.PGxEVT.FFIEN = PGEVT_FFIEN_DISABLED;
    pgevt.PGxEVT.FLTIEN = PGEVT_FLTIEN_DISABLED;
    
    pgevt.PGxEVT.UPDTRG = PGEVT_UPDTRG_UPDATE_BIT; // PGEVT_UPDTRG_PGxDC;
    pgevt.PGxEVT.IEVTSEL  = PGEVT_IEVTSEL_NONE;   // PWM interrupts disabled => using ADC interrupts
    
    pgevt.PGxEVT.PGTRGSEL = PGEVT_PGTRGSEL_EOC; 
    
    // configure PWM IOs
    iocon.PGxIOCON.CLMOD = IOCON_CLMOD_DISABLED;
    iocon.PGxIOCON.OVRDAT = IOCON_OVRDAT_LOW_LOW;
    iocon.PGxIOCON.OVRENH = IOCON_OVRENx_ENABLED;
    iocon.PGxIOCON.OVRENL = IOCON_OVRENx_ENABLED;
    iocon.PGxIOCON.OSYNC = IOCON_OSYNC_PWM;
    
    iocon.PGxIOCON.DBDAT = IOCON_DBDAT_LOW_LOW;
    iocon.PGxIOCON.CLDAT = IOCON_CLDAT_LOW_LOW;
    iocon.PGxIOCON.FLTDAT = IOCON_FLTDAT_LOW_LOW;
    iocon.PGxIOCON.FFDAT = IOCON_FFDAT_LOW_LOW;
    
    iocon.PGxIOCON.CAPSRC = IOCON_CAPSRC_NONE;
    iocon.PGxIOCON.DTCMPSEL = IOCON_DTCMPSEL_PCI_SYNC;
    iocon.PGxIOCON.PMOD = IOCON_PMOD_INDEPENDENT;
    iocon.PGxIOCON.PENH = IOCON_PENx_PGx;
    iocon.PGxIOCON.PENL = IOCON_PENx_PGx;
    iocon.PGxIOCON.POLH = IOCON_POLx_ACTIVE_HIGH;
    iocon.PGxIOCON.POLL = IOCON_POLx_ACTIVE_HIGH;

    // configure dead times
//    dtcon.value = 0x00C80118; // causes internal compiler error with XC v1.35 
    dtcon.PGxDT.DT_RISING = DEAD_TIME_RISING_EDGE; // sdbc_bata.dead_time_rising;    
    dtcon.PGxDT.DT_FALLING = DEAD_TIME_FALLING_EDGE; //sdbc_bata.dead_time_falling;
    
    // write configuration
    hspwm_init_independent_pwm(channel, pclkcon, pgcon, pgevt, iocon, dtcon);
    hspwm_init_pwm_timing(channel, PWM_PERIOD, PWM_DUTY_RATIO, PWM_PHASE);
    
    switch(channel)
    {
        case 1:
            phs_sft = 0;
            break;
        case 2:
            phs_sft = 0;
            break;
        case 3:
            phs_sft = (PWM_PERIOD >> 1);
            break;
    }
    
    MPER = PWM_PERIOD;
    MDC = (MPER-400);
    MPHASE = 0;
    hspwm_init_pwm_timing(channel, PWM_PERIOD, PWM_DUTY_CYCLE_MINIMUM, phs_sft);
    
    Nop();
    Nop();
    Nop();
    
    // PWM is running and is triggering the ADC, but is not producing output signals
//    if(hspwm_enable_pwm(channel, pgcon.PGxCON.HREN))
//    {
////        hspwm_ovr_release(channel);
//
//        Nop();  // breakpoint option to check PWM status after configuration
//        Nop();
//        Nop();
//        
//    }
                
    return;
}

