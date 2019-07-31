/**
  SLAVE1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    slave1.c

  @Summary
    This is the generated driver implementation file for the SLAVE1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for SLAVE1.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.85
        Device            :  dsPIC33CH128MP506
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.35
        MPLAB 	          :  MPLAB X v5.05
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/


/**
  Section: Included Files
*/
#include <xc.h>
#include "mcal.h"

#if(SLAVE_PROJECT_PRESENT == 1)

#include "slave1.h"
#include <libpic30.h>
#include "slave.h"

#define SLAVE_IMAGE     slave
#define SLAVE_NUMBER    1


/**
 Section: Driver Interface Function Definitions
*/
void SLAVE1_Initialize()
{
    //SRSTIE disabled; SLVEN disabled; MSTIRQ disabled; RFITSEL Trigger data valid interrupt when 1st FIFO entry is written by Slave; STMIACK disabled; 
    MSI1CON = 0x00;	
    //WFEN enabled; RFEN enabled; 
    MSI1FIFOCS = 0x8080;	


}

void SLAVE1_Start()
{
    _start_slave();
}

void SLAVE1_Program()               
{
    _program_slave(SLAVE_NUMBER,0,SLAVE_IMAGE);
}
 
void SLAVE1_InterruptRequestGenerate()
{
    MSI1CONbits.MSTIRQ = 1;
}

bool SLAVE1_IsInterruptRequestAcknowledged()
{
    return(MSI1STATbits.MTSIACK);
    
}

void SLAVE1_InterruptRequestComplete()
{
    MSI1CONbits.MSTIRQ = 0;
}
 
bool SLAVE1_IsInterruptRequested()
{
    return(MSI1STATbits.STMIRQ);
}

void SLAVE1_InterruptRequestAcknowledge()
{
    MSI1CONbits.STMIACK = 1;
}

void SLAVE1_InterruptRequestAcknowledgeComplete()
{
    MSI1CONbits.STMIACK = 0;
}
 
SLAVE_RESET_CAUSE SLAVE1_GetResetCause()
{
    SLAVE_RESET_CAUSE resetCause;
    
    if(MSI1STATbits.SLVWDRST)
    {
        resetCause = SLAVE_RESET_CAUSE_WATCHDOG;
    }
    else
    {
        resetCause = SLAVE_RESET_CAUSE_UNSPECIFIED;
    }
    
    return resetCause;
}

void SLAVE1_ResetCauseClear(SLAVE_RESET_CAUSE resetCause)
{
    switch(resetCause)
    {
        case SLAVE_RESET_CAUSE_WATCHDOG :   MSI1STATbits.SLVWDRST = 0;
                                            break;
        default                         :
                                            break;
    }
}
 
SLAVE_SYSTEM_STATUS SLAVE1_SystemStatusGet()
{
    SLAVE_SYSTEM_STATUS systemStatus = SLAVE_SYSTEM_STATUS_RUNNING;
    
    if(MSI1STATbits.SLVWDRST)
    {
        systemStatus = SLAVE_SYSTEM_STATUS_IN_RESET;
    }
    else
    {
        switch(MSI1STATbits.SLVPWR)
        {
            case 0: systemStatus = SLAVE_SYSTEM_STATUS_NOT_IN_LOW_POWER_MODE;
                    break;
            case 1: systemStatus = SLAVE_SYSTEM_STATUS_IDLE;
                    break;
            case 2: systemStatus = SLAVE_SYSTEM_STATUS_SLEEP;
                    break;
            default:systemStatus = SLAVE_SYSTEM_STATUS_RUNNING;
                    break;             
        }
    }
    return systemStatus;
}

uint16_t SLAVE1_Read(uint16_t *pData, uint16_t wordCount)
{
    uint16_t readCountStatus = 0;
    
    while(wordCount)
    {
        if(MSI1FIFOCSbits.RFEMPTY != 1)
        {
            *pData++ = MRSWFDATA;
            wordCount--;
            readCountStatus++;
        }
        else
        {
            break;
        }
    }
    return readCountStatus;   
}

uint16_t SLAVE1_Write(uint16_t *pData, uint16_t wordCount)
{
    uint16_t writeCountStatus = 0;
    
    while(wordCount)
    {
        if(MSI1FIFOCSbits.WFFULL != 1)
        {
            MWSRFDATA = *pData++;
            wordCount--;
            writeCountStatus++;
        }
        else
        {
            break;
        }
    }
    return writeCountStatus;
}

#endif






