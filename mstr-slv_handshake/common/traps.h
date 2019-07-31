/***************************************************************************************************
* � 2006 Microchip Technology Inc.
*
* FileName:        traps.c
* Dependencies:    Header file traps.h
* Processor:       dsPIC33FJxxx/dsPIC33EPxxx
* Compiler:        MPLAB� C30 v3.00 or MPLAB� X16 v1.20 or higher
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Incorporated ("Microchip") retains all ownership and intellectual property 
* rights in the code accompanying this message and in all derivatives hereto.  You may use this 
* code, and any derivatives created by any person or entity by or on your behalf, exclusively with 
* Microchip's proprietary products.  Your acceptance and/or use of this code constitutes agreement 
* to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER EXPRESS, 
* IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, 
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH 
* MICROCHIP'S PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER IN CONTRACT, 
* WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), STRICT LIABILITY, INDEMNITY, 
* CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, PUNITIVE, EXEMPLARY, INCIDENTAL OR 
* CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE CODE, 
* HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
* FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
* IN ANY WAY RELATED TO THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP 
* SPECIFICALLY TO HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and determining its suitability.  
* Microchip has no obligation to modify, test, certify, or support the code.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*	Date		Autor				Company	Version	Comments
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* 03/09/2006	D. Settu			MCHP	1.0		First Release
* 10/07/2009	Andreas Reiter		HPC		1.1		added a header file and a default trap handler
*													routine for better integration
* 07/19/2016	Andreas Reiter		MCHP	1.2		Added data structure for trap monitoring
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
*
* 1. This file contains trap service routines (handlers) for hardware exceptions generated by 
*	 the dsPIC33F device.
*
* 2. All trap service routines in this file simply ensure that device continuously executes code 
*	 within the trap service routine. Users may modify the basic framework provided here to suit 
*	 to the needs of their application.
*
***************************************************************************************************/

#ifndef _GLOBAL_TRAPS_H_
#define _GLOBAL_TRAPS_H_

// Device header file
#include <xc.h>
#include <stdint.h>
		
// =================================================================================================
//
//	DMA ERROR TRAP SUPPORT
//
// =================================================================================================

// Compile-switch determine if DMA is supported on selected device
#ifdef DMA1CON
  #define TRAP_DMA_SUPPORT			1		// Device supports DMA
#else
  #define TRAP_DMA_SUPPORT			0		// Device does not support DMA
#endif
									

// =================================================================================================
//
//	DEFINING TRAP-ID FOR PRIMARY AND SECONDARY EXCEPTION VECTORS
//
// =================================================================================================


typedef enum
{
	TRAP_OSCILLATOR_FAIL		= 0x0001,	// Trap ID for primary exception vector
	TRAP_ADDRESS_ERROR			= 0x0002,	// Trap ID for primary exception vector
	TRAP_STACK_ERROR			= 0x0004,	// Trap ID for primary exception vector
	TRAP_MATH_ERROR				= 0x0008,	// Trap ID for primary exception vector
	TRAP_DMA_ERROR				= 0x0010,	// Trap ID for primary exception vector

    TRAP_SOFT_TRAP_ERROR        = 0x0020,   // Trap ID for generic soft trap exception vector
    TRAP_HARD_TRAP_ERROR        = 0x0040,   // Trap ID for generic hard trap exception vector
    TRAP_RESERVED_TRAP_5_ERROR  = 0x0080,   // Trap ID for generic exception vector
    TRAP_RESERVED_TRAP_7_ERROR  = 0x0080,   // Trap ID for generic exception vector

	TRAP_ALT_OSCILLATOR_FAIL	= 0x0100,	// Trap ID for alternate exception vector
	TRAP_ALT_ADDRESS_ERROR		= 0x0200,	// Trap ID for alternate exception vector
	TRAP_ALT_STACK_ERROR		= 0x0400,	// Trap ID for alternate exception vector
	TRAP_ALT_MATH_ERROR			= 0x0800,	// Trap ID for alternate exception vector
	TRAP_ALT_DMA_ERROR			= 0x1000,	// Trap ID for alternate exception vector

    TRAP_ALT_SOFT_TRAP_ERROR    = 0x2000,   // Trap ID for alternate generic soft trap exception vector
    TRAP_ALT_HARD_TRAP_ERROR    = 0x4000,   // Trap ID for alternate generic hard trap exception vector
        
	TRAP_RESET_MSK				= 0x7F1F	// Bit Mask to filter used bits only

}TRAP_ID_e;


// =================================================================================================
//
//	DATA STRUCTURE USED TO TRACE TRAP OCCURENCES
//
// =================================================================================================


typedef struct
{
    volatile unsigned OVAERR    :1; // Bit #0:  Accumulator A Overflow Trap Flag bit
    volatile unsigned OVBERR    :1; // Bit #1:  Accumulator B Overflow Trap Flag bit
    volatile unsigned COVAERR   :1; // Bit #2:  Accumulator A Catastrophic Overflow Trap Flag bit
    volatile unsigned COVBERR   :1; // Bit #3:  Accumulator B Catastrophic Overflow Trap Flag bit
    volatile unsigned SFTACERR  :1; // Bit #4:  Shift Accumulator Error Status bit
    volatile unsigned DIV0ERR   :1; // Bit #5:  Divide-by-Zero Error Status bit
    volatile unsigned MATHERR   :1; // Bit #6:  Math Error Status bit
    volatile unsigned ADDRERR   :1; // Bit #7:  Address Error Trap Status bit
    volatile unsigned STKERR    :1; // Bit #8:  Stack Error Trap Status bit
    volatile unsigned OSCFAIL   :1; // Bit #9:  Oscillator Failure Trap Status bit
    volatile unsigned SWTRAP    :1; // Bit #10: Software Trap Status bit
    volatile unsigned NAE       :1; // Bit #11: NVM Address Error Soft Trap Status bit
    volatile unsigned DOOVR     :1; // Bit #12: DO Stack Overflow Soft Trap Status bit
    volatile unsigned APLL      :1; // Bit #13: Auxiliary PLL Loss of Lock Soft Trap Status bit
    volatile unsigned SGHT      :1; // Bit #14: Software Generated Hard Trap Status bit
    volatile unsigned DMACERR   :1; // Bit #15: DMA Trap Status bit
}__attribute__((packed))TRAP_FLAG_IDENTIFIER_t;

typedef struct
{
	volatile unsigned VECNUM:8;	// Bit #0-7:   Pending Interrupt Number List
	volatile unsigned ILR	:4;	// Bit #8-11:  New Interrupt Priority Level
	volatile unsigned		:1;	// Bit #12: Reserved
	volatile unsigned		:1;	// Bit #13: Reserved
	volatile unsigned       :1;	// Bit #14: Reserved
	volatile unsigned       :1;	// Bit #15: Reserved
}__attribute__((packed))INTERRUPT_CONTROL_REGISTER_BIT_FIELD_t;

typedef union 
{
	volatile uint16_t reg_block;
	volatile INTERRUPT_CONTROL_REGISTER_BIT_FIELD_t flags;
}INTERRUPT_CONTROL_REGISTER_t;


typedef struct
{
	volatile unsigned por	:1;	// Bit #0:  Power-on Reset Flag bit
	volatile unsigned bor	:1;	// Bit #1:  Brown-out Reset Flag bit
	volatile unsigned idle	:1;	// Bit #2:  Wake-up from Idle Flag bit
	volatile unsigned sleep	:1;	// Bit #3:  Wake-up from Sleep Flag bit
	volatile unsigned wdto	:1;	// Bit #4:  Watchdog Timer Time-out Flag bit
	volatile unsigned swdten:1;	// Bit #5:  Software Enable/Disable of WDT bit
	volatile unsigned swr	:1;	// Bit #6:  Software Reset Flag (Instruction) bit
	volatile unsigned extr	:1;	// Bit #7:  External Reset Pin (MCLR) bit
	volatile unsigned vregs	:1;	// Bit #8:  Voltage Regulator Standby During Sleep bit
	volatile unsigned cm    :1;	// Bit #9:  Configuration Mismatch Flag bit
	volatile unsigned		:1;	// Bit #10: Reserved
	volatile unsigned vregsf:1;	// Bit #11: Flash Voltage Regulator Standby During Sleep bit
	volatile unsigned		:1;	// Bit #12: Reserved
	volatile unsigned		:1;	// Bit #13: Reserved
	volatile unsigned iopuwr:1;	// Bit #14: Illegal Opcode or Uninitialized W Access Reset Flag bit
	volatile unsigned trapr :1;	// Bit #15: Trap Reset Flag bit
}__attribute__((packed))RESET_CONTROL_REGISTER_BIT_FIELD_t;

typedef union 
{
	volatile uint16_t reg_block;
	volatile RESET_CONTROL_REGISTER_BIT_FIELD_t flags;
}RESET_CONTROL_REGISTER_t;

typedef struct
{
	volatile uint16_t count;
	volatile TRAP_ID_e trap_id;
    volatile TRAP_FLAG_IDENTIFIER_t trap_flags;
	volatile RESET_CONTROL_REGISTER_t rcon_reg;
    volatile INTERRUPT_CONTROL_REGISTER_t inttreg;
}TRAP_LOGGER_t;

 //extern TRAP_LOGGER_t __attribute__((__persistent__))traplog; // data structure used as buffer for trap monitoring
extern volatile TRAP_LOGGER_t traplog; // data structure used as buffer for trap monitoring

// =================================================================================================
//
//	PROTOTYPES
//
// =================================================================================================
extern int init_SoftTraps(unsigned int accumulator_a_overflow_trap_enable, 
                unsigned int accumulator_b_overflow_trap_enable, 
                unsigned int accumulator_catastrophic_overflow_trap_enable);

extern void GetTrapStatus();
extern void DefaultTrapHandler(TRAP_ID_e trap_id);

extern void __attribute__((__interrupt__)) _HardTrapError(void);
extern void __attribute__((__interrupt__)) _SoftTrapError(void);

extern void __attribute__((__interrupt__)) _OscillatorFail(void);
extern void __attribute__((__interrupt__)) _AddressError(void);
extern void __attribute__((__interrupt__)) _StackError(void);
extern void __attribute__((__interrupt__)) _MathError(void);

#if (TRAP_DMA_SUPPORT == 1)
  #if defined (_DMACError)
    extern void __attribute__((__interrupt__)) _DMACError(void);
  #endif
#endif

 
#if __XC16_VERSION < 1030
// Compile switch dealing with the changed support of alternate interrupt vectors between
// versions v.1.29 and 1.30  
  
extern void __attribute__((interrupt, no_auto_psv)) _AltHardTrapError(void);
extern void __attribute__((interrupt, no_auto_psv)) _AltSoftTrapError(void);

extern void __attribute__((__interrupt__)) _AltOscillatorFail(void);
extern void __attribute__((__interrupt__)) _AltAddressError(void);
extern void __attribute__((__interrupt__)) _AltStackError(void);
extern void __attribute__((__interrupt__)) _AltMathError(void);

#if (TRAP_DMA_SUPPORT == 1)
  extern void __attribute__((__interrupt__)) _AltDMACError(void);
#endif

#endif
  
#endif
  