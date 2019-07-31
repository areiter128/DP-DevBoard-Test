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

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SDB_GLOBAL_DEFINES_H
#define	SDB_GLOBAL_DEFINES_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>

typedef struct {

    volatile uint16_t tick_period;
    volatile uint16_t stat_led_period_default;
    volatile uint16_t stat_led_period_fault;

} MAIN_LOOP_SETTINGS_t;
extern volatile MAIN_LOOP_SETTINGS_t main_loop;

typedef struct {
    volatile unsigned : 8;                                   // Bit 0-7:  (reserved))
    volatile unsigned : 8;                                   // Bit 8-15: (reserved))
}SYSTEM_STATUS_BITS_t;

typedef union {
    volatile uint16_t value;
    volatile SYSTEM_STATUS_BITS_t flags;
} SYSTEM_STATUS_t;


typedef struct {

    volatile SYSTEM_STATUS_BITS_t status;
    
    volatile uint16_t ctrl_pwm_min;
    volatile uint16_t ctrl_pwm_max;

    volatile uint16_t period;
    volatile uint16_t phase;
    volatile uint16_t initial_duty_ratio;
    volatile uint16_t dead_time_rising;
    volatile uint16_t dead_time_falling;

    volatile uint16_t v_P1;
    volatile uint16_t v_P2;
    
    volatile bool     adc_active;
    volatile bool     pwm_started;
    
}APPLICATION_SETTINGS_t;
extern volatile APPLICATION_SETTINGS_t application;

#endif	/* SDB_GLOBAL_DEFINES_H */

