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
        Device            :  dsPIC33CH128MP506S1
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
    Sets the GPIO pin, RD13, high using LATD13.

  @Description
    Sets the GPIO pin, RD13, high using LATD13.

  @Preconditions
    The RD13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD13 high (1)
    DBGLED3_SetHigh();
    </code>

*/
#define DBGLED3_SetHigh()          _LATD13 = 1
/**
  @Summary
    Sets the GPIO pin, RD13, low using LATD13.

  @Description
    Sets the GPIO pin, RD13, low using LATD13.

  @Preconditions
    The RD13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD13 low (0)
    DBGLED3_SetLow();
    </code>

*/
#define DBGLED3_SetLow()           _LATD13 = 0
/**
  @Summary
    Toggles the GPIO pin, RD13, using LATD13.

  @Description
    Toggles the GPIO pin, RD13, using LATD13.

  @Preconditions
    The RD13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD13
    DBGLED3_Toggle();
    </code>

*/
#define DBGLED3_Toggle()           _LATD13 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD13.

  @Description
    Reads the value of the GPIO pin, RD13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD13
    postValue = DBGLED3_GetValue();
    </code>

*/
#define DBGLED3_GetValue()         _RD13
/**
  @Summary
    Configures the GPIO pin, RD13, as an input.

  @Description
    Configures the GPIO pin, RD13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD13 as an input
    DBGLED3_SetDigitalInput();
    </code>

*/
#define DBGLED3_SetDigitalInput()  _TRISD13 = 1
/**
  @Summary
    Configures the GPIO pin, RD13, as an output.

  @Description
    Configures the GPIO pin, RD13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD13 as an output
    DBGLED3_SetDigitalOutput();
    </code>

*/
#define DBGLED3_SetDigitalOutput() _TRISD13 = 0
/**
  @Summary
    Sets the GPIO pin, RD8, high using LATD8.

  @Description
    Sets the GPIO pin, RD8, high using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD8 high (1)
    DBGLED2_SetHigh();
    </code>

*/
#define DBGLED2_SetHigh()          _LATD8 = 1
/**
  @Summary
    Sets the GPIO pin, RD8, low using LATD8.

  @Description
    Sets the GPIO pin, RD8, low using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD8 low (0)
    DBGLED2_SetLow();
    </code>

*/
#define DBGLED2_SetLow()           _LATD8 = 0
/**
  @Summary
    Toggles the GPIO pin, RD8, using LATD8.

  @Description
    Toggles the GPIO pin, RD8, using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD8
    DBGLED2_Toggle();
    </code>

*/
#define DBGLED2_Toggle()           _LATD8 ^= 1
/**
  @Summary
    Reads the value of the GPIO pin, RD8.

  @Description
    Reads the value of the GPIO pin, RD8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD8
    postValue = DBGLED2_GetValue();
    </code>

*/
#define DBGLED2_GetValue()         _RD8
/**
  @Summary
    Configures the GPIO pin, RD8, as an input.

  @Description
    Configures the GPIO pin, RD8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD8 as an input
    DBGLED2_SetDigitalInput();
    </code>

*/
#define DBGLED2_SetDigitalInput()  _TRISD8 = 1
/**
  @Summary
    Configures the GPIO pin, RD8, as an output.

  @Description
    Configures the GPIO pin, RD8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD8 as an output
    DBGLED2_SetDigitalOutput();
    </code>

*/
#define DBGLED2_SetDigitalOutput() _TRISD8 = 0

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the dsPIC33CH128MP506S1
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
