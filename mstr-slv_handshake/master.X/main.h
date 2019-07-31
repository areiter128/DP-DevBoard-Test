
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "syscfg_globals.h"
#include "mcal.h"

#ifndef SDBC_MAIN_H
#define	SDBC_MAIN_H


#define MASTER_TO_SLAVE_DUTY_RATIO_MAILBOX  MSI1MBX0D
#define SLAVE_TO_MASTER_DUTY_RATIO_MAILBOX  MSI1MBX8D

#define MASTER_TO_SLAVE_P1_MAILBOX          MSI1MBX1D
#define MASTER_TO_SLAVE_P2_MAILBOX          MSI1MBX2D

#define LED_BLINKRATE_VOLTAGE_OFFSET        1000

/* user settings */
#define CPU_PERFORMANCE 	C_90MIPS	// Device speed selection (MIPS40, MIPS50, MIPS60, MIPS70)
#define USE_EXTERNAL_OSC    0   // 0: use internal FRC oscillator, 1: use external oscillator
#if (USE_EXTERNAL_OSC == 1)
    EXT_OSC_FREQ        8000000         // Specify frequency of the external oscillator in [Hz]
#endif

/* compile switches for debugging */
#define SLAVE_PROJECT_PRESENT   1


/* Main Loop Configuration */
#define MAIN_LOOP_TICK_PERIOD       8999    // 100usec tick rate @ 90 MIPS

/* PWM Settings */
#define PWM_PERIOD                  13333 // 11428   // 300 kHz switching frequency
#define PWM_DUTY_RATIO              (uint16_t)(PWM_PERIOD >> 2)   // = 300 kHz // 10000 = 400 kHz switching frequency
#define PWM_PHASE                   0       // Phase Shift
#define DEAD_TIME_RISING_EDGE       200
#define DEAD_TIME_FALLING_EDGE      360

#define PWM_DUTY_CYCLE_MINIMUM      (uint16_t)(0.05 * (float)PWM_PERIOD)
#define PWM_DUTY_CYCLE_MAXIMUM      (uint16_t)(0.95 * (float)PWM_PERIOD)
    
#define VOUT_PWM_PROPAGATION_DELAY  240
#define VOUT_ADC_TRIGGER_OFFSET     (uint16_t)((PWM_PERIOD >> 1) + VOUT_PWM_PROPAGATION_DELAY)

extern volatile APPLICATION_SETTINGS_t application;

// global function declarations
extern void initialize_gpio(void);
extern void initialize_oscillator(void);
extern void initialize_gpio(void);
extern void initialize_timer(void);
extern void initialize_hspwm(uint16_t channel);
extern void initialize_hsadc(void);

#endif	/* SDBC_MAIN_H */

