/*
 * File:   init_hspwm.c
 * Author: M91406
 *
 * Created on October 16, 2018, 11:03 AM
 */


#include <xc.h>
#include "main.h"
#include "mcal.h"

/* === Initialize HSPWM ===================================================== */
void initialize_hspwm(uint16_t channel)
{
 
    volatile REGBLK_PGxDEAD_TIME_t dtcon;
    volatile REGBLK_PGxIO_CONFIG_t iocon;
    volatile REGBLK_PGxCH_CONFIG_t pgcon;
    volatile REGBLK_PCLK_CONFIG_t pclkcon;
    volatile REGBLK_PGxEVT_CONFIG_t pgevt;
    
    Nop();
    Nop();
    Nop();

    // configure PWM module clock
    pclkcon.PCLKCON.LOCK = PCLKCON_LOCK_UNLOCKED;       // write-protected registers remain unlocked for direct writes without overhead
    pclkcon.PCLKCON.MCLKSEL = PCLKCON_MCLKSEL_AFPLLO;   // select auxiliary PLL output (500 MHz)
    pclkcon.PCLKCON.DIVSEL = PCLKCON_DIVSEL_DIV_2;      // select smallest clock divider
    
    // configure PWM channel
    pgcon.PGxCON.CLKSEL = PGCON_CLKSEL_BY_MCLKSEL;      // clock selection is MASTER CLOCK selection
    pgcon.PGxCON.MODSEL = PGCON_MODSEL_INDEPENDENT_EDGE; // Independent edge aligned PWM
    pgcon.PGxCON.TRGCNT = PGCON_TRGCNT_1_PWM_CYCLES;    // PWM generator produces one PWM cycle after being triggered
    pgcon.PGxCON.HREN = PGCON_HREN_HIGH_RES;            // high resolution mode is enabled

    pgcon.PGxCON.MPERSEL = PGCON_MPERSEL_INDEPENDENT;   // PWM generator uses its independent period register
    pgcon.PGxCON.MPHSEL = PGCON_MPHSEL_INDEPENDENT;     // PWM generator uses its independent phase register
    pgcon.PGxCON.MDCSEL = PGCON_MDCSEL_INDEPENDENT;     // PWM generator uses its independent duty cycle register
    pgcon.PGxCON.MSTEN = PGCON_MSTEN_NO_BROADCAST;      // Master period is not producing a broadcast of triggers
    pgcon.PGxCON.UPDMOD = PGCON_UPDMOD_IMMEDIATE;       // PWM generator values are updated immediately after being written
    pgcon.PGxCON.TRGMOD = PGCON_TRGMOD_REPEAT;          // PWM generator triggers are repeated
    pgcon.PGxCON.SOCS = PGCON_SOCS_LOCAL_EOC;           // START OF CYCLE is triggered by END OF CYCLE

    // configure PWM IOs
    iocon.PGxIOCON.CLMOD = IOCON_CLMOD_DISABLED;        // Current Limit Mode is disabled
    iocon.PGxIOCON.OVRDAT = IOCON_OVRDAT_LOW_LOW;       // Output state of PWMxH/PWMxH while in OVERRIDE mode
    iocon.PGxIOCON.OVRENH = IOCON_OVRENx_ENABLED;       // OVERRIDE mode enabled for pin PWMxH
    iocon.PGxIOCON.OVRENL = IOCON_OVRENx_ENABLED;       // OVERRIDE mode enabled for pin PWMxL
    iocon.PGxIOCON.OSYNC = IOCON_OSYNC_PWM;             // OVERRIDE SET/RELEASE is synchronized to PWM waveform
    
    iocon.PGxIOCON.DBDAT = IOCON_DBDAT_LOW_LOW;         // Output state of PWMxH/PWMxH while in DEBUG mode
    iocon.PGxIOCON.CLDAT = IOCON_CLDAT_LOW_LOW;         // Output state of PWMxH/PWMxH while in CURRENT LIMIT mode
    iocon.PGxIOCON.FLTDAT = IOCON_FLTDAT_LOW_LOW;       // Output state of PWMxH/PWMxH while in FAULT mode
    iocon.PGxIOCON.FFDAT = IOCON_FFDAT_LOW_LOW;         // Output state of PWMxH/PWMxH while in FEED FORWARD mode
    
    iocon.PGxIOCON.CAPSRC = IOCON_CAPSRC_NONE;          // No PWM cCAPTURE source selected
    iocon.PGxIOCON.DTCMPSEL = IOCON_DTCMPSEL_PCI_SYNC;  // 
    iocon.PGxIOCON.PMOD = IOCON_PMOD_COMPLEMENTARY;
    iocon.PGxIOCON.PENH = IOCON_PENx_GPIO;
    iocon.PGxIOCON.PENL = IOCON_PENx_GPIO;
    iocon.PGxIOCON.POLH = IOCON_POLx_ACTIVE_HIGH;
    iocon.PGxIOCON.POLL = IOCON_POLx_ACTIVE_HIGH;
    
    iocon.PGxIOCON.SWAP = IOCON_SWAP_DISABLED; 
    // configure dead times
    // dtcon.value = 0x00C80118; // causes internal compiler error with XC v1.35 
    dtcon.PGxDT.DT_RISING = application.dead_time_rising;    
    dtcon.PGxDT.DT_FALLING = application.dead_time_falling;

    // configure events
    pgevt.PGxEVT.ADTR1EN1 = PGEVT_ADTR1EN1_PGxTRIGA_ENABLED;    // ADC Trigger #1 A output is enabled => trigger #1 to ADC
    pgevt.PGxEVT.ADTR1EN2 = PGEVT_ADTR1EN2_PGxTRIGB_DISABLED;   // ADC Trigger #1 B output is enabled => trigger #2 to ADC
    pgevt.PGxEVT.ADTR1EN3 = PGEVT_ADTR1EN3_PGxTRIGC_DISABLED;   // ADC Trigger #1 C output is disabled
    
    pgevt.PGxEVT.ADTR1OFS = PGEVT_ADTR1OFS_OFFSET_EVENTS_0; // create trigger event without offset (from the first cycle)
    pgevt.PGxEVT.ADTR1PS  = PGEVT_ADTR1PS_POSTSCALE_1; // create trigger events without post scaler (every cycle)
    
    pgevt.PGxEVT.ADTR2EN1 = PGEVT_ADTR2EN1_PGxTRIGA_DISABLED;   // ADC Trigger #2 A output is disabled
    pgevt.PGxEVT.ADTR2EN2 = PGEVT_ADTR2EN2_PGxTRIGB_DISABLED;    // ADC Trigger #2 B output is enabled
    pgevt.PGxEVT.ADTR2EN3 = PGEVT_ADTR2EN3_PGxTRIGC_DISABLED;   // ADC Trigger #2 B output is disabled

    pgevt.PGxEVT.SIEN = PGEVT_SIEN_DISABLED;    // Sync interrupt is disabled
    pgevt.PGxEVT.CLIEN = PGEVT_CLIEN_DISABLED;  // Current-limit interrupt is disabled
    pgevt.PGxEVT.FFIEN = PGEVT_FFIEN_DISABLED;  // Feed-forward interrupt is disabled
    pgevt.PGxEVT.FLTIEN = PGEVT_FLTIEN_DISABLED; // Fault interrupt is disabled
    
    pgevt.PGxEVT.PGTRGSEL = PGEVT_PGTRGSEL_EOC; // PWM generator produces a trigger at EOC for self-triggering
    pgevt.PGxEVT.UPDTRG = PGEVT_UPDTRG_PGxDC; // Update PWM values when a new duty cycle is written
    pgevt.PGxEVT.IEVTSEL  = PGEVT_IEVTSEL_NONE;   // PWM interrupts disabled => using ADC interrupts
    
    PWMEVTAbits.EVTAOEN = PWMEVTy_EVTyOEN_ENABLE;
    PWMEVTAbits.EVTAPOL = PWMEVTy_EVTyPOL_ACTIVE_HIGH;
    PWMEVTAbits.EVTASTRD = PWMEVTy_EVTySTRD_8CLK_STRECH;
    PWMEVTAbits.EVTASYNC = PWMEVTy_EVTySYNC_NO_SYNC;
    PWMEVTAbits.EVTAPGS = PWMEVTy_EVTyPGS_PG1;
    PWMEVTAbits.EVTASEL = PWMEVTy_EVTySEL_PGTRGSEL;

    PWMEVTB = 0;
    PWMEVTC = 0;
    PWMEVTD = 0;
    PWMEVTE = 0;
    PWMEVTF = 0;

    
    // write configuration
    hspwm_init_independent_pwm(channel, pclkcon, pgcon, pgevt, iocon, dtcon);
    hspwm_init_pwm_timing(channel, application.period, PWM_DUTY_CYCLE_MINIMUM, application.phase);
  
    Nop();
    Nop();
    Nop();
    

    return;
}

