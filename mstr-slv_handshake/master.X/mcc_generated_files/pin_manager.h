/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
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

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>

/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RD15, high using LATD15.

  @Description
    Sets the GPIO pin, RD15, high using LATD15.

  @Preconditions
    The RD15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD15 high (1)
    DBGLED_SetHigh();
    </code>

*/
#define DBGLED_SetHigh()          _LATD15 = 1
/**
  @Summary
    Sets the GPIO pin, RD15, low using LATD15.

  @Description
    Sets the GPIO pin, RD15, low using LATD15.

  @Preconditions
    The RD15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD15 low (0)
    DBGLED_SetLow();
    </code>

*/
#define DBGLED_SetLow()           _LATD15 = 0
/**
  @Summary
    Toggles the GPIO pin, RD15, using LATD15.

  @Description
    Toggles the GPIO pin, RD15, using LATD15.

  @Preconditions
    The RD15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD15
    DBGLED_Toggle();
    </code>

*/
#define DBGLED_Toggle()           _LATD15 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD15.

  @Description
    Reads the value of the GPIO pin, RD15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD15
    postValue = DBGLED_GetValue();
    </code>

*/
#define DBGLED_GetValue()         _RD15
/**
  @Summary
    Configures the GPIO pin, RD15, as an input.

  @Description
    Configures the GPIO pin, RD15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD15 as an input
    DBGLED_SetDigitalInput();
    </code>

*/
#define DBGLED_SetDigitalInput()  _TRISD15 = 1
/**
  @Summary
    Configures the GPIO pin, RD15, as an output.

  @Description
    Configures the GPIO pin, RD15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD15 as an output
    DBGLED_SetDigitalOutput();
    </code>

*/
#define DBGLED_SetDigitalOutput() _TRISD15 = 0

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the dsPIC33CH128MP506
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize (void);

#endif
