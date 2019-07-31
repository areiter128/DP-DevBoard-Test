/*LICENSE *****************************************************************************************
 *
 * Software License Agreement
 *
 * Copyright (R) 2012 Microchip Technology Inc.  All rights reserved. Microchip licenses to you the
 * right to use, modify, copy and distribute Software only when embedded on a Microchip 
 * microcontroller or digital signal controller, which is integrated into your product or third 
 * party product (pursuant to the sublicense terms in the accompanying license agreement).
 *
 * You should refer to the license agreement accompanying this Software for additional information 
 * regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR 
 * IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR 
 * OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT  
 * LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS  
 * OR LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY  
 * THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *
 * ***********************************************************************************************/

// Device header file
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#include "p33SMPS_hspwm_c.h"


/*@@p33MP_hspwm.c
 * ************************************************************************************************
 * Summary:
 * Driver file for the dsPIC33FxxMP-PWM SFRs
 *
 * Description:
 * The SMPS PWM module offers a large number of registers and configuration options. This additional
 * driver file contains initialization routines for all required settings.
 * ***********************************************************************************************/


/*@@hspwm_init_complementary_pwm
 * ************************************************************************************************
 * Summary:
 * Resets the IO control configuration of all PWM output pins
 *
 * Parameters:
 *	(none)
 * 
 * Description:
 * The PWM output pin configuration enables PWMxH/PWMxL outputs by default. This routine
 * sets them into GPIO mode, effectively disabling the PWM outputs.
 * ***********************************************************************************************/

uint16_t hspwm_init_independent_pwm(
            uint16_t idx, 
            REGBLK_PCLK_CONFIG_t regPCLK, 
            REGBLK_PGxCH_CONFIG_t regPGxCON, 
            REGBLK_PGxEVT_CONFIG_t regPGxEVT,
            REGBLK_PGxIO_CONFIG_t regPGxIOCON, 
            REGBLK_PGxDEAD_TIME_t regPGxDT
    )
{
    
    volatile uint16_t *regptr16;
    volatile uint32_t *regptr32;
    volatile uint16_t reg_offset;

    // write clock configuration
    regptr16 = (volatile uint16_t*) &PCLKCON;
    *regptr16 = (regPCLK.value & REG_PCLKCON_VALID_DATA_WRITE_MASK);
    
    // write PWM channel configuration
    reg_offset = (idx-1) * ((volatile uint16_t)&PG2CONL - (volatile uint16_t)&PG1CONL);
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1CONL + reg_offset);
    *regptr32 = (regPGxCON.value & REG_PGxCON_VALID_DATA_WRITE_MASK);

    // write PWM channel event configuration
    reg_offset = (idx-1) * ((volatile uint16_t)&PG2EVTL - (volatile uint16_t)&PG1EVTL);
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1EVTL + reg_offset);
    *regptr32 = (regPGxEVT.value & REG_PGxEVT_VALID_DATA_WRITE_MASK);

    // write IO configuration
    reg_offset = (idx-1) * ((volatile uint16_t)&PG2IOCONL - (volatile uint16_t)&PG1IOCONL);
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1IOCONL + reg_offset);
    *regptr32 = (regPGxIOCON.value & REG_PGxIOCON_VALID_DATA_WRITE_MASK);

    // write dead time
    reg_offset = (idx-1) * ((volatile uint16_t)&PG2DTL - (volatile uint16_t)&PG1DTL);
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1DTL + reg_offset);
    *regptr32 = (regPGxDT.value & REG_PGxDT_VALID_DATA_WRITE_MASK);
    
    return(1);

}

uint16_t hspwm_init_pwm_timing(uint16_t idx, uint16_t regPGxPER, uint16_t regPGxDC, uint16_t regPGxPHASE)
{
    
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;

    // write PWM channel configuration
    reg_offset = (idx-1) * ((volatile uint16_t)&PG2PER - (volatile uint16_t)&PG1PER);
    regptr16 = (volatile uint16_t*)((volatile uint8_t*)&PG1PER + reg_offset);
    *regptr16 = regPGxPER;

    // write IO configuration
    reg_offset = (idx-1) * ((volatile uint16_t)&PG2DC - (volatile uint16_t)&PG1DC);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1DC + reg_offset);
    *regptr16 = regPGxDC;

    // write dead time
    reg_offset = (idx-1) * ((volatile uint16_t)&PG2PHASE - (volatile uint16_t)&PG1PHASE);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1PHASE + reg_offset);
    *regptr16 = regPGxPHASE;
    
    return(1);

}

uint16_t hspwm_enable_pwm(uint16_t channel, bool wait_for_hres)
{

    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;
    volatile uint16_t timeout=0;
    
    if(wait_for_hres)
    {
        while((PCLKCONbits.HRRDY == PCLKCON_HRRDY_WAIT) && 
          (PCLKCONbits.HRERR == PCLKCON_HRERR_NO_ERROR) && 
            (timeout++ < 5000))
            {
                Nop();
                Nop();
                Nop();
            }

        if(timeout >= 5000) // if High Resolution Ready Bit has not been set
        { return(0); }      // skip ENABLE and return failure code

    }

    reg_offset = (channel-1) * ((volatile uint16_t)&PG2CONL - (volatile uint16_t)&PG1CONL);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1CONL + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = reg_buf | REG_PGCON_ON_PWM_ENABLED;
    
    return((*regptr16 & REG_PGCON_ON_PWM_ENABLED) >> 15);

}

uint16_t hspwm_disable_pwm(uint16_t channel)
{

    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;

    reg_offset = (channel-1) * ((volatile uint16_t)&PG2CONL - (volatile uint16_t)&PG1CONL);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1CONL + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = reg_buf & REG_PGCON_ON_PWM_RESET;
    
    return(1-((*regptr16 & REG_PGCON_ON_PWM_ENABLED) >> 15));

}

uint16_t hspwm_ovr_hold(uint16_t channel)
{
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;

    reg_offset = (channel-1) * ((volatile uint16_t)&PG2IOCONL - (volatile uint16_t)&PG1IOCONL);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1IOCONL + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = reg_buf | REG_IOCON_OVREN_COMP_SET;
    
    return(1);
}


uint16_t hspwm_ovr_release(uint16_t channel)
{
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;

    reg_offset = (channel-1) * ((volatile uint16_t)&PG2IOCONL - (volatile uint16_t)&PG1IOCONL);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1IOCONL + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = reg_buf & REG_IOCON_OVREN_COMP_RESET;
    
    return(1);
}

/* *****************************************************************************************************
 * *****************************************************************************************************/

