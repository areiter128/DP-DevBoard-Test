/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

/* !!! I AM THE SLAVE PROGRAM !!! */

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>

#include "syscfg_globals.h"
#include "mcal.h"

#ifndef SDBC_SLAVE_MAIN_H
#define	SDBC_SLAVE_MAIN_H

#define MASTER_TO_SLAVE_STATUS_MAILBOX      SI1MBX0D
#define SLAVE_TO_MASTER_STATUS_MAILBOX      SI1MBX8D

#define MASTER_TO_SLAVE_P1_MAILBOX          SI1MBX1D
#define MASTER_TO_SLAVE_P2_MAILBOX          SI1MBX2D

/* user settings */
#define CPU_PERFORMANCE 	C_100MIPS	// Device speed selection (MIPS40, MIPS50, MIPS60, MIPS70)
#define USE_EXTERNAL_OSC    0   // 0: use internal FRC oscillator, 1: use external oscillator
#if (USE_EXTERNAL_OSC == 1)
    EXT_OSC_FREQ        8000000         // Specify frequency of the external oscillator in [Hz]
#endif

/* Main Loop Configuration */
#define MAIN_LOOP_TICK_PERIOD       9999   // 100usec tick rate @ 100 MIPS

/* PWM Settings */
#define PWM_PERIOD                  8000   // = 500 kHz switching frequency
#define PWM_DUTY_RATIO              (uint16_t)(PWM_PERIOD >> 2)   // = 300 kHz // 10000 = 400 kHz switching frequency
#define PWM_PHASE                   0       // Phase Shift
#define DEAD_TIME_RISING_EDGE       200
#define DEAD_TIME_FALLING_EDGE      360

#define PWM_DUTY_CYCLE_MINIMUM      (uint16_t)(0.01 * (float)PWM_PERIOD)
#define PWM_DUTY_CYCLE_MAXIMUM      (uint16_t)(0.98 * (float)PWM_PERIOD)

/* local prototypes */
extern void initialize_oscillator(void);
extern void initialize_gpio(void);
extern void initialize_timer(void);
extern void initialize_hspwm(uint16_t channel);

#endif	/* SDBC_SLAVE_MAIN_H */

