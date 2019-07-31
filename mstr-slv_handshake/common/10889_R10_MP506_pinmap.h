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
 * File:        10889_R10_MP506_pinmap.h
 * Device:		dsPIC33CH512MP506
 * Author:      M91406
 * Comments:    Hardware abstraction layer for dsPIC33CH128MP506 daughter card revision 3.0
 * Board No:    10889
 * Revision history: 1.0    (initial release)
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _10889_R10_MP506_PINMAP_H
#define	_10889_R10_MP506_PINMAP_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>

// Generic defines
#ifndef PINDIR_INPUT
    #define PINDIR_INPUT 1
#endif
#ifndef PINDIR_OUTPUT
    #define PINDIR_OUTPUT 0
#endif
#ifndef PINSTATE_HIGH
    #define PINSTATE_HIGH 1
#endif
#ifndef PINSTATE_LOW
    #define PINSTATE_LOW 0
#endif

#ifndef LED_ON
    #define LED_ON 0
#endif
#ifndef LED_OFF
    #define LED_OFF 1
#endif

#ifndef PINCFG_OPEN_DRAIN
    #define PINCFG_OPEN_DRAIN 1
#endif
#ifndef PINCFG_PUSH_PULL
    #define PINCFG_PUSH_PULL 0
#endif

#ifndef PINDIR_INPUT
    #define PINDIR_INPUT 1
#endif
#ifndef PINDIR_OUTPUT
    #define PINDIR_OUTPUT 0
#endif
#ifndef PINSTATE_HIGH
    #define PINSTATE_HIGH 1
#endif
#ifndef PINSTATE_LOW
    #define PINSTATE_LOW 0
#endif

#ifndef LED_ON
    #define LED_ON 0
#endif
#ifndef LED_OFF
    #define LED_OFF 1
#endif

#ifndef PINCFG_OPEN_DRAIN
    #define PINCFG_OPEN_DRAIN 1
#endif
#ifndef PINCFG_PUSH_PULL
    #define PINCFG_PUSH_PULL 0
#endif

#if defined (__P33SMPS_CH_MSTR__)

	#define CLKI_TRIS    TRISBbits.TRISB0 // GPIO direction register bit
	#define CLKI_WR      LATBbits.LATB0 // GPIO port latch register bit
	#define CLKI_RD      PORTBbits.RB0 // GPIO port register bit
	#define CLKI_ODC     ODCBbits.ODCB0 // GPIO port open drain configuration register bit
	#define CLKI_CNPU    CNPUBbits.CNPUB0 // GPIO port pull-up resistor register bit
	#define CLKI_CNPD    CNPDBbits.CNPDB0 // GPIO port pull-down resistor register bit
	#define CLKI_CNEN0   CNEN0Bbits.CNEN0B0 // GPIO port change notification Enable register bit
	#define CLKI_CNSTAT  CNSTATBbits.CNSTATB0 // GPIO port change notification Status register bit
	#define CLKI_CNEN1   CNEN1Bbits.CNEN1B0 // GPIO port change notification Edge Select Enable register bit
	#define CLKI_CNF     CNFBbits.CNFB0 // GPIO port change notification flag bit register bit
	#define CLKI_RP      32 // Number of Remappable Pin
	#define CLKI_SET     { asm volatile ("bset _LATB, #0 \n"); }
	#define CLKI_CLEAR   { asm volatile ("bclr _LATB, #0 \n"); }
	#define CLKI_TOGGLE  { asm volatile ("btg  _LATB, #0 \n"); }
	#define CLKI_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define CLKI_ANSEL   _ANSELB0 // analog/digital pin configuration register bit
	#define CLKI_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define CLKI_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define CLKI_ADC_AN_INPUT 5   // ANx input pin number
	#define CLKI_ADCBUF  ADCBUF5 // ADC buffer register for this input
	#define CLKI_ADC_ANIE ADIELbits.IE5
	#define CLKI_ADC_ANEIE ADEIELbits.EIEN5
	#define CLKI_ADC_IF   _ADCAN5IF // interrupt flag bit
	#define CLKI_ADC_IE   _ADCAN5IE // interrupt enable bit
	#define CLKI_ADC_IP   _ADCAN5IP // interrupt priority for this analog input
	#define CLKI_ADC_RDY  _AN5RDY // ADC buffer ready bit
	#define _CLKI_ADC_Interrupt _ADCAN5Interrupt
	#define CLKI_INIT_ANALOG	{CLKI_ANSEL = 1; CLKI_WR = PINSTATE_HIGH; CLKI_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define CLKI_INIT_OUTPUT  {CLKI_WR = PINSTATE_LOW; CLKI_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define CLKI_INIT_INPUT   {CLKI_WR = PINSTATE_HIGH; CLKI_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DBGLED_TRIS    TRISDbits.TRISD15 // GPIO direction register bit
	#define DBGLED_WR      LATDbits.LATD15 // GPIO port latch register bit
	#define DBGLED_RD      PORTDbits.RD15 // GPIO port register bit
	#define DBGLED_ODC     ODCDbits.ODCD15 // GPIO port open drain configuration register bit
	#define DBGLED_CNPU    CNPUDbits.CNPUD15 // GPIO port pull-up resistor register bit
	#define DBGLED_CNPD    CNPDDbits.CNPDD15 // GPIO port pull-down resistor register bit
	#define DBGLED_CNEN0   CNEN0Dbits.CNEN0D15 // GPIO port change notification Enable register bit
	#define DBGLED_CNSTAT  CNSTATDbits.CNSTATD15 // GPIO port change notification Status register bit
	#define DBGLED_CNEN1   CNEN1Dbits.CNEN1D15 // GPIO port change notification Edge Select Enable register bit
	#define DBGLED_CNF     CNFDbits.CNFD15 // GPIO port change notification flag bit register bit
	#define DBGLED_SET     { asm volatile ("bset _LATD, #15 \n"); }
	#define DBGLED_CLEAR   { asm volatile ("bclr _LATD, #15 \n"); }
	#define DBGLED_TOGGLE  { asm volatile ("btg  _LATD, #15 \n"); }
	#define DBGLED_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DBGLED_INIT_OUTPUT  {DBGLED_WR = PINSTATE_LOW; DBGLED_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DBGLED_INIT_INPUT   {DBGLED_WR = PINSTATE_HIGH; DBGLED_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define S1MCLR1_TRIS    TRISBbits.TRISB7 // GPIO direction register bit
	#define S1MCLR1_WR      LATBbits.LATB7 // GPIO port latch register bit
	#define S1MCLR1_RD      PORTBbits.RB7 // GPIO port register bit
	#define S1MCLR1_ODC     ODCBbits.ODCB7 // GPIO port open drain configuration register bit
	#define S1MCLR1_CNPU    CNPUBbits.CNPUB7 // GPIO port pull-up resistor register bit
	#define S1MCLR1_CNPD    CNPDBbits.CNPDB7 // GPIO port pull-down resistor register bit
	#define S1MCLR1_CNEN0   CNEN0Bbits.CNEN0B7 // GPIO port change notification Enable register bit
	#define S1MCLR1_CNSTAT  CNSTATBbits.CNSTATB7 // GPIO port change notification Status register bit
	#define S1MCLR1_CNEN1   CNEN1Bbits.CNEN1B7 // GPIO port change notification Edge Select Enable register bit
	#define S1MCLR1_CNF     CNFBbits.CNFB7 // GPIO port change notification flag bit register bit
	#define S1MCLR1_RP      39 // Number of Remappable Pin
	#define S1MCLR1_SET     { asm volatile ("bset _LATB, #7 \n"); }
	#define S1MCLR1_CLEAR   { asm volatile ("bclr _LATB, #7 \n"); }
	#define S1MCLR1_TOGGLE  { asm volatile ("btg  _LATB, #7 \n"); }
	#define S1MCLR1_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define S1MCLR1_ANSEL   _ANSELB7 // analog/digital pin configuration register bit
	#define S1MCLR1_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define S1MCLR1_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define S1MCLR1_ADC_AN_INPUT 9   // ANx input pin number
	#define S1MCLR1_ADCBUF  ADCBUF9 // ADC buffer register for this input
	#define S1MCLR1_ADC_ANIE ADIELbits.IE9
	#define S1MCLR1_ADC_ANEIE ADEIELbits.EIEN9
	#define S1MCLR1_ADC_IF   _ADCAN9IF // interrupt flag bit
	#define S1MCLR1_ADC_IE   _ADCAN9IE // interrupt enable bit
	#define S1MCLR1_ADC_IP   _ADCAN9IP // interrupt priority for this analog input
	#define S1MCLR1_ADC_RDY  _AN9RDY // ADC buffer ready bit
	#define _S1MCLR1_ADC_Interrupt _ADCAN9Interrupt
	#define S1MCLR1_INIT_ANALOG	{S1MCLR1_ANSEL = 1; S1MCLR1_WR = PINSTATE_HIGH; S1MCLR1_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define S1MCLR1_INIT_OUTPUT  {S1MCLR1_WR = PINSTATE_LOW; S1MCLR1_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define S1MCLR1_INIT_INPUT   {S1MCLR1_WR = PINSTATE_HIGH; S1MCLR1_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define S1PGC1_TRIS    TRISBbits.TRISB9 // GPIO direction register bit
	#define S1PGC1_WR      LATBbits.LATB9 // GPIO port latch register bit
	#define S1PGC1_RD      PORTBbits.RB9 // GPIO port register bit
	#define S1PGC1_ODC     ODCBbits.ODCB9 // GPIO port open drain configuration register bit
	#define S1PGC1_CNPU    CNPUBbits.CNPUB9 // GPIO port pull-up resistor register bit
	#define S1PGC1_CNPD    CNPDBbits.CNPDB9 // GPIO port pull-down resistor register bit
	#define S1PGC1_CNEN0   CNEN0Bbits.CNEN0B9 // GPIO port change notification Enable register bit
	#define S1PGC1_CNSTAT  CNSTATBbits.CNSTATB9 // GPIO port change notification Status register bit
	#define S1PGC1_CNEN1   CNEN1Bbits.CNEN1B9 // GPIO port change notification Edge Select Enable register bit
	#define S1PGC1_CNF     CNFBbits.CNFB9 // GPIO port change notification flag bit register bit
	#define S1PGC1_RP      41 // Number of Remappable Pin
	#define S1PGC1_SET     { asm volatile ("bset _LATB, #9 \n"); }
	#define S1PGC1_CLEAR   { asm volatile ("bclr _LATB, #9 \n"); }
	#define S1PGC1_TOGGLE  { asm volatile ("btg  _LATB, #9 \n"); }
	#define S1PGC1_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define S1PGC1_ANSEL   _ANSELB9 // analog/digital pin configuration register bit
	#define S1PGC1_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define S1PGC1_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define S1PGC1_ADC_AN_INPUT 11   // ANx input pin number
	#define S1PGC1_ADCBUF  ADCBUF11 // ADC buffer register for this input
	#define S1PGC1_ADC_ANIE ADIELbits.IE11
	#define S1PGC1_ADC_ANEIE ADEIELbits.EIEN11
	#define S1PGC1_ADC_IF   _ADCAN11IF // interrupt flag bit
	#define S1PGC1_ADC_IE   _ADCAN11IE // interrupt enable bit
	#define S1PGC1_ADC_IP   _ADCAN11IP // interrupt priority for this analog input
	#define S1PGC1_ADC_RDY  _AN11RDY // ADC buffer ready bit
	#define _S1PGC1_ADC_Interrupt _ADCAN11Interrupt
	#define S1PGC1_INIT_ANALOG	{S1PGC1_ANSEL = 1; S1PGC1_WR = PINSTATE_HIGH; S1PGC1_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define S1PGC1_INIT_OUTPUT  {S1PGC1_WR = PINSTATE_LOW; S1PGC1_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define S1PGC1_INIT_INPUT   {S1PGC1_WR = PINSTATE_HIGH; S1PGC1_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define S1PGD1_TRIS    TRISBbits.TRISB8 // GPIO direction register bit
	#define S1PGD1_WR      LATBbits.LATB8 // GPIO port latch register bit
	#define S1PGD1_RD      PORTBbits.RB8 // GPIO port register bit
	#define S1PGD1_ODC     ODCBbits.ODCB8 // GPIO port open drain configuration register bit
	#define S1PGD1_CNPU    CNPUBbits.CNPUB8 // GPIO port pull-up resistor register bit
	#define S1PGD1_CNPD    CNPDBbits.CNPDB8 // GPIO port pull-down resistor register bit
	#define S1PGD1_CNEN0   CNEN0Bbits.CNEN0B8 // GPIO port change notification Enable register bit
	#define S1PGD1_CNSTAT  CNSTATBbits.CNSTATB8 // GPIO port change notification Status register bit
	#define S1PGD1_CNEN1   CNEN1Bbits.CNEN1B8 // GPIO port change notification Edge Select Enable register bit
	#define S1PGD1_CNF     CNFBbits.CNFB8 // GPIO port change notification flag bit register bit
	#define S1PGD1_RP      40 // Number of Remappable Pin
	#define S1PGD1_SET     { asm volatile ("bset _LATB, #8 \n"); }
	#define S1PGD1_CLEAR   { asm volatile ("bclr _LATB, #8 \n"); }
	#define S1PGD1_TOGGLE  { asm volatile ("btg  _LATB, #8 \n"); }
	#define S1PGD1_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define S1PGD1_ANSEL   _ANSELB8 // analog/digital pin configuration register bit
	#define S1PGD1_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define S1PGD1_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define S1PGD1_ADC_AN_INPUT 10   // ANx input pin number
	#define S1PGD1_ADCBUF  ADCBUF10 // ADC buffer register for this input
	#define S1PGD1_ADC_ANIE ADIELbits.IE10
	#define S1PGD1_ADC_ANEIE ADEIELbits.EIEN10
	#define S1PGD1_ADC_IF   _ADCAN10IF // interrupt flag bit
	#define S1PGD1_ADC_IE   _ADCAN10IE // interrupt enable bit
	#define S1PGD1_ADC_IP   _ADCAN10IP // interrupt priority for this analog input
	#define S1PGD1_ADC_RDY  _AN10RDY // ADC buffer ready bit
	#define _S1PGD1_ADC_Interrupt _ADCAN10Interrupt
	#define S1PGD1_INIT_ANALOG	{S1PGD1_ANSEL = 1; S1PGD1_WR = PINSTATE_HIGH; S1PGD1_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define S1PGD1_INIT_OUTPUT  {S1PGD1_WR = PINSTATE_LOW; S1PGD1_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define S1PGD1_INIT_INPUT   {S1PGD1_WR = PINSTATE_HIGH; S1PGD1_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP03_TRIS    TRISBbits.TRISB2 // GPIO direction register bit
	#define TP03_WR      LATBbits.LATB2 // GPIO port latch register bit
	#define TP03_RD      PORTBbits.RB2 // GPIO port register bit
	#define TP03_ODC     ODCBbits.ODCB2 // GPIO port open drain configuration register bit
	#define TP03_CNPU    CNPUBbits.CNPUB2 // GPIO port pull-up resistor register bit
	#define TP03_CNPD    CNPDBbits.CNPDB2 // GPIO port pull-down resistor register bit
	#define TP03_CNEN0   CNEN0Bbits.CNEN0B2 // GPIO port change notification Enable register bit
	#define TP03_CNSTAT  CNSTATBbits.CNSTATB2 // GPIO port change notification Status register bit
	#define TP03_CNEN1   CNEN1Bbits.CNEN1B2 // GPIO port change notification Edge Select Enable register bit
	#define TP03_CNF     CNFBbits.CNFB2 // GPIO port change notification flag bit register bit
	#define TP03_RP      34 // Number of Remappable Pin
	#define TP03_SET     { asm volatile ("bset _LATB, #2 \n"); }
	#define TP03_CLEAR   { asm volatile ("bclr _LATB, #2 \n"); }
	#define TP03_TOGGLE  { asm volatile ("btg  _LATB, #2 \n"); }
	#define TP03_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define TP03_ANSEL   _ANSELB2 // analog/digital pin configuration register bit
	#define TP03_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define TP03_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define TP03_ADC_AN_INPUT 7   // ANx input pin number
	#define TP03_ADCBUF  ADCBUF7 // ADC buffer register for this input
	#define TP03_ADC_ANIE ADIELbits.IE7
	#define TP03_ADC_ANEIE ADEIELbits.EIEN7
	#define TP03_ADC_IF   _ADCAN7IF // interrupt flag bit
	#define TP03_ADC_IE   _ADCAN7IE // interrupt enable bit
	#define TP03_ADC_IP   _ADCAN7IP // interrupt priority for this analog input
	#define TP03_ADC_RDY  _AN7RDY // ADC buffer ready bit
	#define _TP03_ADC_Interrupt _ADCAN7Interrupt
	#define TP03_INIT_ANALOG	{TP03_ANSEL = 1; TP03_WR = PINSTATE_HIGH; TP03_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define TP03_INIT_OUTPUT  {TP03_WR = PINSTATE_LOW; TP03_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP03_INIT_INPUT   {TP03_WR = PINSTATE_HIGH; TP03_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP04_TRIS    TRISCbits.TRISC7 // GPIO direction register bit
	#define TP04_WR      LATCbits.LATC7 // GPIO port latch register bit
	#define TP04_RD      PORTCbits.RC7 // GPIO port register bit
	#define TP04_ODC     ODCCbits.ODCC7 // GPIO port open drain configuration register bit
	#define TP04_CNPU    CNPUCbits.CNPUC7 // GPIO port pull-up resistor register bit
	#define TP04_CNPD    CNPDCbits.CNPDC7 // GPIO port pull-down resistor register bit
	#define TP04_CNEN0   CNEN0Cbits.CNEN0C7 // GPIO port change notification Enable register bit
	#define TP04_CNSTAT  CNSTATCbits.CNSTATC7 // GPIO port change notification Status register bit
	#define TP04_CNEN1   CNEN1Cbits.CNEN1C7 // GPIO port change notification Edge Select Enable register bit
	#define TP04_CNF     CNFCbits.CNFC7 // GPIO port change notification flag bit register bit
	#define TP04_RP      55 // Number of Remappable Pin
	#define TP04_SET     { asm volatile ("bset _LATC, #7 \n"); }
	#define TP04_CLEAR   { asm volatile ("bclr _LATC, #7 \n"); }
	#define TP04_TOGGLE  { asm volatile ("btg  _LATC, #7 \n"); }
	#define TP04_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define TP04_ANSEL   _ANSELC7 // analog/digital pin configuration register bit
	#define TP04_ADCCORE  // index starts from zero, last index indicated shared adC core
	#define TP04_IS_SHARED_CORE 0 // AN input is routed to a dedicated or shared ACD core
	#define TP04_ADC_AN_INPUT 15   // ANx input pin number
	#define TP04_ADCBUF  ADCBUF15 // ADC buffer register for this input
	#define TP04_ADC_ANIE ADIELbits.IE15
	#define TP04_ADC_ANEIE ADEIELbits.EIEN15
	#define TP04_ADC_IF   _ADCAN15IF // interrupt flag bit
	#define TP04_ADC_IE   _ADCAN15IE // interrupt enable bit
	#define TP04_ADC_IP   _ADCAN15IP // interrupt priority for this analog input
	#define TP04_ADC_RDY  _AN15RDY // ADC buffer ready bit
	#define _TP04_ADC_Interrupt _ADCAN15Interrupt
	#define TP04_INIT_ANALOG	{TP04_ANSEL = 1; TP04_WR = PINSTATE_HIGH; TP04_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define TP04_INIT_OUTPUT  {TP04_WR = PINSTATE_LOW; TP04_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP04_INIT_INPUT   {TP04_WR = PINSTATE_HIGH; TP04_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP05_TRIS    TRISCbits.TRISC0 // GPIO direction register bit
	#define TP05_WR      LATCbits.LATC0 // GPIO port latch register bit
	#define TP05_RD      PORTCbits.RC0 // GPIO port register bit
	#define TP05_ODC     ODCCbits.ODCC0 // GPIO port open drain configuration register bit
	#define TP05_CNPU    CNPUCbits.CNPUC0 // GPIO port pull-up resistor register bit
	#define TP05_CNPD    CNPDCbits.CNPDC0 // GPIO port pull-down resistor register bit
	#define TP05_CNEN0   CNEN0Cbits.CNEN0C0 // GPIO port change notification Enable register bit
	#define TP05_CNSTAT  CNSTATCbits.CNSTATC0 // GPIO port change notification Status register bit
	#define TP05_CNEN1   CNEN1Cbits.CNEN1C0 // GPIO port change notification Edge Select Enable register bit
	#define TP05_CNF     CNFCbits.CNFC0 // GPIO port change notification flag bit register bit
	#define TP05_RP      48 // Number of Remappable Pin
	#define TP05_SET     { asm volatile ("bset _LATC, #0 \n"); }
	#define TP05_CLEAR   { asm volatile ("bclr _LATC, #0 \n"); }
	#define TP05_TOGGLE  { asm volatile ("btg  _LATC, #0 \n"); }
	#define TP05_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define TP05_ANSEL   _ANSELC0 // analog/digital pin configuration register bit
	#define TP05_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define TP05_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define TP05_ADC_AN_INPUT 12   // ANx input pin number
	#define TP05_ADCBUF  ADCBUF12 // ADC buffer register for this input
	#define TP05_ADC_ANIE ADIELbits.IE12
	#define TP05_ADC_ANEIE ADEIELbits.EIEN12
	#define TP05_ADC_IF   _ADCAN12IF // interrupt flag bit
	#define TP05_ADC_IE   _ADCAN12IE // interrupt enable bit
	#define TP05_ADC_IP   _ADCAN12IP // interrupt priority for this analog input
	#define TP05_ADC_RDY  _AN12RDY // ADC buffer ready bit
	#define _TP05_ADC_Interrupt _ADCAN12Interrupt
	#define TP05_INIT_ANALOG	{TP05_ANSEL = 1; TP05_WR = PINSTATE_HIGH; TP05_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define TP05_INIT_OUTPUT  {TP05_WR = PINSTATE_LOW; TP05_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP05_INIT_INPUT   {TP05_WR = PINSTATE_HIGH; TP05_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP06_TRIS    TRISCbits.TRISC2 // GPIO direction register bit
	#define TP06_WR      LATCbits.LATC2 // GPIO port latch register bit
	#define TP06_RD      PORTCbits.RC2 // GPIO port register bit
	#define TP06_ODC     ODCCbits.ODCC2 // GPIO port open drain configuration register bit
	#define TP06_CNPU    CNPUCbits.CNPUC2 // GPIO port pull-up resistor register bit
	#define TP06_CNPD    CNPDCbits.CNPDC2 // GPIO port pull-down resistor register bit
	#define TP06_CNEN0   CNEN0Cbits.CNEN0C2 // GPIO port change notification Enable register bit
	#define TP06_CNSTAT  CNSTATCbits.CNSTATC2 // GPIO port change notification Status register bit
	#define TP06_CNEN1   CNEN1Cbits.CNEN1C2 // GPIO port change notification Edge Select Enable register bit
	#define TP06_CNF     CNFCbits.CNFC2 // GPIO port change notification flag bit register bit
	#define TP06_RP      50 // Number of Remappable Pin
	#define TP06_SET     { asm volatile ("bset _LATC, #2 \n"); }
	#define TP06_CLEAR   { asm volatile ("bclr _LATC, #2 \n"); }
	#define TP06_TOGGLE  { asm volatile ("btg  _LATC, #2 \n"); }
	#define TP06_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define TP06_ANSEL   _ANSELC2 // analog/digital pin configuration register bit
	#define TP06_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define TP06_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define TP06_ADC_AN_INPUT 14   // ANx input pin number
	#define TP06_ADCBUF  ADCBUF14 // ADC buffer register for this input
	#define TP06_ADC_ANIE ADIELbits.IE14
	#define TP06_ADC_ANEIE ADEIELbits.EIEN14
	#define TP06_ADC_IF   _ADCAN14IF // interrupt flag bit
	#define TP06_ADC_IE   _ADCAN14IE // interrupt enable bit
	#define TP06_ADC_IP   _ADCAN14IP // interrupt priority for this analog input
	#define TP06_ADC_RDY  _AN14RDY // ADC buffer ready bit
	#define _TP06_ADC_Interrupt _ADCAN14Interrupt
	#define TP06_INIT_ANALOG	{TP06_ANSEL = 1; TP06_WR = PINSTATE_HIGH; TP06_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define TP06_INIT_OUTPUT  {TP06_WR = PINSTATE_LOW; TP06_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP06_INIT_INPUT   {TP06_WR = PINSTATE_HIGH; TP06_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP08_TRIS    TRISCbits.TRISC3 // GPIO direction register bit
	#define TP08_WR      LATCbits.LATC3 // GPIO port latch register bit
	#define TP08_RD      PORTCbits.RC3 // GPIO port register bit
	#define TP08_ODC     ODCCbits.ODCC3 // GPIO port open drain configuration register bit
	#define TP08_CNPU    CNPUCbits.CNPUC3 // GPIO port pull-up resistor register bit
	#define TP08_CNPD    CNPDCbits.CNPDC3 // GPIO port pull-down resistor register bit
	#define TP08_CNEN0   CNEN0Cbits.CNEN0C3 // GPIO port change notification Enable register bit
	#define TP08_CNSTAT  CNSTATCbits.CNSTATC3 // GPIO port change notification Status register bit
	#define TP08_CNEN1   CNEN1Cbits.CNEN1C3 // GPIO port change notification Edge Select Enable register bit
	#define TP08_CNF     CNFCbits.CNFC3 // GPIO port change notification flag bit register bit
	#define TP08_RP      51 // Number of Remappable Pin
	#define TP08_SET     { asm volatile ("bset _LATC, #3 \n"); }
	#define TP08_CLEAR   { asm volatile ("bclr _LATC, #3 \n"); }
	#define TP08_TOGGLE  { asm volatile ("btg  _LATC, #3 \n"); }
	#define TP08_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP08_INIT_OUTPUT  {TP08_WR = PINSTATE_LOW; TP08_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP08_INIT_INPUT   {TP08_WR = PINSTATE_HIGH; TP08_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP09_TRIS    TRISDbits.TRISD11 // GPIO direction register bit
	#define TP09_WR      LATDbits.LATD11 // GPIO port latch register bit
	#define TP09_RD      PORTDbits.RD11 // GPIO port register bit
	#define TP09_ODC     ODCDbits.ODCD11 // GPIO port open drain configuration register bit
	#define TP09_CNPU    CNPUDbits.CNPUD11 // GPIO port pull-up resistor register bit
	#define TP09_CNPD    CNPDDbits.CNPDD11 // GPIO port pull-down resistor register bit
	#define TP09_CNEN0   CNEN0Dbits.CNEN0D11 // GPIO port change notification Enable register bit
	#define TP09_CNSTAT  CNSTATDbits.CNSTATD11 // GPIO port change notification Status register bit
	#define TP09_CNEN1   CNEN1Dbits.CNEN1D11 // GPIO port change notification Edge Select Enable register bit
	#define TP09_CNF     CNFDbits.CNFD11 // GPIO port change notification flag bit register bit
	#define TP09_SET     { asm volatile ("bset _LATD, #11 \n"); }
	#define TP09_CLEAR   { asm volatile ("bclr _LATD, #11 \n"); }
	#define TP09_TOGGLE  { asm volatile ("btg  _LATD, #11 \n"); }
	#define TP09_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP09_INIT_OUTPUT  {TP09_WR = PINSTATE_LOW; TP09_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP09_INIT_INPUT   {TP09_WR = PINSTATE_HIGH; TP09_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP10_TRIS    TRISCbits.TRISC1 // GPIO direction register bit
	#define TP10_WR      LATCbits.LATC1 // GPIO port latch register bit
	#define TP10_RD      PORTCbits.RC1 // GPIO port register bit
	#define TP10_ODC     ODCCbits.ODCC1 // GPIO port open drain configuration register bit
	#define TP10_CNPU    CNPUCbits.CNPUC1 // GPIO port pull-up resistor register bit
	#define TP10_CNPD    CNPDCbits.CNPDC1 // GPIO port pull-down resistor register bit
	#define TP10_CNEN0   CNEN0Cbits.CNEN0C1 // GPIO port change notification Enable register bit
	#define TP10_CNSTAT  CNSTATCbits.CNSTATC1 // GPIO port change notification Status register bit
	#define TP10_CNEN1   CNEN1Cbits.CNEN1C1 // GPIO port change notification Edge Select Enable register bit
	#define TP10_CNF     CNFCbits.CNFC1 // GPIO port change notification flag bit register bit
	#define TP10_RP      49 // Number of Remappable Pin
	#define TP10_SET     { asm volatile ("bset _LATC, #1 \n"); }
	#define TP10_CLEAR   { asm volatile ("bclr _LATC, #1 \n"); }
	#define TP10_TOGGLE  { asm volatile ("btg  _LATC, #1 \n"); }
	#define TP10_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define TP10_ANSEL   _ANSELC1 // analog/digital pin configuration register bit
	#define TP10_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define TP10_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define TP10_ADC_AN_INPUT 13   // ANx input pin number
	#define TP10_ADCBUF  ADCBUF13 // ADC buffer register for this input
	#define TP10_ADC_ANIE ADIELbits.IE13
	#define TP10_ADC_ANEIE ADEIELbits.EIEN13
	#define TP10_ADC_IF   _ADCAN13IF // interrupt flag bit
	#define TP10_ADC_IE   _ADCAN13IE // interrupt enable bit
	#define TP10_ADC_IP   _ADCAN13IP // interrupt priority for this analog input
	#define TP10_ADC_RDY  _AN13RDY // ADC buffer ready bit
	#define _TP10_ADC_Interrupt _ADCAN13Interrupt
	#define TP10_INIT_ANALOG	{TP10_ANSEL = 1; TP10_WR = PINSTATE_HIGH; TP10_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define TP10_INIT_OUTPUT  {TP10_WR = PINSTATE_LOW; TP10_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP10_INIT_INPUT   {TP10_WR = PINSTATE_HIGH; TP10_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP11_TRIS    TRISAbits.TRISA2 // GPIO direction register bit
	#define TP11_WR      LATAbits.LATA2 // GPIO port latch register bit
	#define TP11_RD      PORTAbits.RA2 // GPIO port register bit
	#define TP11_ODC     ODCAbits.ODCA2 // GPIO port open drain configuration register bit
	#define TP11_CNPU    CNPUAbits.CNPUA2 // GPIO port pull-up resistor register bit
	#define TP11_CNPD    CNPDAbits.CNPDA2 // GPIO port pull-down resistor register bit
	#define TP11_CNEN0   CNEN0Abits.CNEN0A2 // GPIO port change notification Enable register bit
	#define TP11_CNSTAT  CNSTATAbits.CNSTATA2 // GPIO port change notification Status register bit
	#define TP11_CNEN1   CNEN1Abits.CNEN1A2 // GPIO port change notification Edge Select Enable register bit
	#define TP11_CNF     CNFAbits.CNFA2 // GPIO port change notification flag bit register bit
	#define TP11_SET     { asm volatile ("bset _LATA, #2 \n"); }
	#define TP11_CLEAR   { asm volatile ("bclr _LATA, #2 \n"); }
	#define TP11_TOGGLE  { asm volatile ("btg  _LATA, #2 \n"); }
	#define TP11_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define TP11_ANSEL   _ANSELA2 // analog/digital pin configuration register bit
	#define TP11_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define TP11_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define TP11_ADC_AN_INPUT 2   // ANx input pin number
	#define TP11_ADCBUF  ADCBUF2 // ADC buffer register for this input
	#define TP11_ADC_ANIE ADIELbits.IE2
	#define TP11_ADC_ANEIE ADEIELbits.EIEN2
	#define TP11_ADC_IF   _ADCAN2IF // interrupt flag bit
	#define TP11_ADC_IE   _ADCAN2IE // interrupt enable bit
	#define TP11_ADC_IP   _ADCAN2IP // interrupt priority for this analog input
	#define TP11_ADC_RDY  _AN2RDY // ADC buffer ready bit
	#define _TP11_ADC_Interrupt _ADCAN2Interrupt
	#define TP11_INIT_ANALOG	{TP11_ANSEL = 1; TP11_WR = PINSTATE_HIGH; TP11_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define TP11_INIT_OUTPUT  {TP11_WR = PINSTATE_LOW; TP11_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP11_INIT_INPUT   {TP11_WR = PINSTATE_HIGH; TP11_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP12_TRIS    TRISAbits.TRISA3 // GPIO direction register bit
	#define TP12_WR      LATAbits.LATA3 // GPIO port latch register bit
	#define TP12_RD      PORTAbits.RA3 // GPIO port register bit
	#define TP12_ODC     ODCAbits.ODCA3 // GPIO port open drain configuration register bit
	#define TP12_CNPU    CNPUAbits.CNPUA3 // GPIO port pull-up resistor register bit
	#define TP12_CNPD    CNPDAbits.CNPDA3 // GPIO port pull-down resistor register bit
	#define TP12_CNEN0   CNEN0Abits.CNEN0A3 // GPIO port change notification Enable register bit
	#define TP12_CNSTAT  CNSTATAbits.CNSTATA3 // GPIO port change notification Status register bit
	#define TP12_CNEN1   CNEN1Abits.CNEN1A3 // GPIO port change notification Edge Select Enable register bit
	#define TP12_CNF     CNFAbits.CNFA3 // GPIO port change notification flag bit register bit
	#define TP12_SET     { asm volatile ("bset _LATA, #3 \n"); }
	#define TP12_CLEAR   { asm volatile ("bclr _LATA, #3 \n"); }
	#define TP12_TOGGLE  { asm volatile ("btg  _LATA, #3 \n"); }
	#define TP12_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define TP12_ANSEL   _ANSELA3 // analog/digital pin configuration register bit
	#define TP12_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define TP12_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define TP12_ADC_AN_INPUT 3   // ANx input pin number
	#define TP12_ADCBUF  ADCBUF3 // ADC buffer register for this input
	#define TP12_ADC_ANIE ADIELbits.IE3
	#define TP12_ADC_ANEIE ADEIELbits.EIEN3
	#define TP12_ADC_IF   _ADCAN3IF // interrupt flag bit
	#define TP12_ADC_IE   _ADCAN3IE // interrupt enable bit
	#define TP12_ADC_IP   _ADCAN3IP // interrupt priority for this analog input
	#define TP12_ADC_RDY  _AN3RDY // ADC buffer ready bit
	#define _TP12_ADC_Interrupt _ADCAN3Interrupt
	#define TP12_INIT_ANALOG	{TP12_ANSEL = 1; TP12_WR = PINSTATE_HIGH; TP12_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define TP12_INIT_OUTPUT  {TP12_WR = PINSTATE_LOW; TP12_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP12_INIT_INPUT   {TP12_WR = PINSTATE_HIGH; TP12_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP13_TRIS    TRISAbits.TRISA1 // GPIO direction register bit
	#define TP13_WR      LATAbits.LATA1 // GPIO port latch register bit
	#define TP13_RD      PORTAbits.RA1 // GPIO port register bit
	#define TP13_ODC     ODCAbits.ODCA1 // GPIO port open drain configuration register bit
	#define TP13_CNPU    CNPUAbits.CNPUA1 // GPIO port pull-up resistor register bit
	#define TP13_CNPD    CNPDAbits.CNPDA1 // GPIO port pull-down resistor register bit
	#define TP13_CNEN0   CNEN0Abits.CNEN0A1 // GPIO port change notification Enable register bit
	#define TP13_CNSTAT  CNSTATAbits.CNSTATA1 // GPIO port change notification Status register bit
	#define TP13_CNEN1   CNEN1Abits.CNEN1A1 // GPIO port change notification Edge Select Enable register bit
	#define TP13_CNF     CNFAbits.CNFA1 // GPIO port change notification flag bit register bit
	#define TP13_SET     { asm volatile ("bset _LATA, #1 \n"); }
	#define TP13_CLEAR   { asm volatile ("bclr _LATA, #1 \n"); }
	#define TP13_TOGGLE  { asm volatile ("btg  _LATA, #1 \n"); }
	#define TP13_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define TP13_ANSEL   _ANSELA1 // analog/digital pin configuration register bit
	#define TP13_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define TP13_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define TP13_ADC_AN_INPUT 1   // ANx input pin number
	#define TP13_ADCBUF  ADCBUF1 // ADC buffer register for this input
	#define TP13_ADC_ANIE ADIELbits.IE1
	#define TP13_ADC_ANEIE ADEIELbits.EIEN1
	#define TP13_ADC_IF   _ADCAN1IF // interrupt flag bit
	#define TP13_ADC_IE   _ADCAN1IE // interrupt enable bit
	#define TP13_ADC_IP   _ADCAN1IP // interrupt priority for this analog input
	#define TP13_ADC_RDY  _AN1RDY // ADC buffer ready bit
	#define _TP13_ADC_Interrupt _ADCAN1Interrupt
	#define TP13_INIT_ANALOG	{TP13_ANSEL = 1; TP13_WR = PINSTATE_HIGH; TP13_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define TP13_INIT_OUTPUT  {TP13_WR = PINSTATE_LOW; TP13_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP13_INIT_INPUT   {TP13_WR = PINSTATE_HIGH; TP13_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP14_TRIS    TRISAbits.TRISA4 // GPIO direction register bit
	#define TP14_WR      LATAbits.LATA4 // GPIO port latch register bit
	#define TP14_RD      PORTAbits.RA4 // GPIO port register bit
	#define TP14_ODC     ODCAbits.ODCA4 // GPIO port open drain configuration register bit
	#define TP14_CNPU    CNPUAbits.CNPUA4 // GPIO port pull-up resistor register bit
	#define TP14_CNPD    CNPDAbits.CNPDA4 // GPIO port pull-down resistor register bit
	#define TP14_CNEN0   CNEN0Abits.CNEN0A4 // GPIO port change notification Enable register bit
	#define TP14_CNSTAT  CNSTATAbits.CNSTATA4 // GPIO port change notification Status register bit
	#define TP14_CNEN1   CNEN1Abits.CNEN1A4 // GPIO port change notification Edge Select Enable register bit
	#define TP14_CNF     CNFAbits.CNFA4 // GPIO port change notification flag bit register bit
	#define TP14_SET     { asm volatile ("bset _LATA, #4 \n"); }
	#define TP14_CLEAR   { asm volatile ("bclr _LATA, #4 \n"); }
	#define TP14_TOGGLE  { asm volatile ("btg  _LATA, #4 \n"); }
	#define TP14_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define TP14_ANSEL   _ANSELA4 // analog/digital pin configuration register bit
	#define TP14_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define TP14_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define TP14_ADC_AN_INPUT 4   // ANx input pin number
	#define TP14_ADCBUF  ADCBUF4 // ADC buffer register for this input
	#define TP14_ADC_ANIE ADIELbits.IE4
	#define TP14_ADC_ANEIE ADEIELbits.EIEN4
	#define TP14_ADC_IF   _ADCAN4IF // interrupt flag bit
	#define TP14_ADC_IE   _ADCAN4IE // interrupt enable bit
	#define TP14_ADC_IP   _ADCAN4IP // interrupt priority for this analog input
	#define TP14_ADC_RDY  _AN4RDY // ADC buffer ready bit
	#define _TP14_ADC_Interrupt _ADCAN4Interrupt
	#define TP14_INIT_ANALOG	{TP14_ANSEL = 1; TP14_WR = PINSTATE_HIGH; TP14_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define TP14_INIT_OUTPUT  {TP14_WR = PINSTATE_LOW; TP14_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP14_INIT_INPUT   {TP14_WR = PINSTATE_HIGH; TP14_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP15_TRIS    TRISAbits.TRISA0 // GPIO direction register bit
	#define TP15_WR      LATAbits.LATA0 // GPIO port latch register bit
	#define TP15_RD      PORTAbits.RA0 // GPIO port register bit
	#define TP15_ODC     ODCAbits.ODCA0 // GPIO port open drain configuration register bit
	#define TP15_CNPU    CNPUAbits.CNPUA0 // GPIO port pull-up resistor register bit
	#define TP15_CNPD    CNPDAbits.CNPDA0 // GPIO port pull-down resistor register bit
	#define TP15_CNEN0   CNEN0Abits.CNEN0A0 // GPIO port change notification Enable register bit
	#define TP15_CNSTAT  CNSTATAbits.CNSTATA0 // GPIO port change notification Status register bit
	#define TP15_CNEN1   CNEN1Abits.CNEN1A0 // GPIO port change notification Edge Select Enable register bit
	#define TP15_CNF     CNFAbits.CNFA0 // GPIO port change notification flag bit register bit
	#define TP15_SET     { asm volatile ("bset _LATA, #0 \n"); }
	#define TP15_CLEAR   { asm volatile ("bclr _LATA, #0 \n"); }
	#define TP15_TOGGLE  { asm volatile ("btg  _LATA, #0 \n"); }
	#define TP15_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define TP15_ANSEL   _ANSELA0 // analog/digital pin configuration register bit
	#define TP15_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define TP15_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define TP15_ADC_AN_INPUT 0   // ANx input pin number
	#define TP15_ADCBUF  ADCBUF0 // ADC buffer register for this input
	#define TP15_ADC_ANIE ADIELbits.IE0
	#define TP15_ADC_ANEIE ADEIELbits.EIEN0
	#define TP15_ADC_IF   _ADCAN0IF // interrupt flag bit
	#define TP15_ADC_IE   _ADCAN0IE // interrupt enable bit
	#define TP15_ADC_IP   _ADCAN0IP // interrupt priority for this analog input
	#define TP15_ADC_RDY  _AN0RDY // ADC buffer ready bit
	#define _TP15_ADC_Interrupt _ADCAN0Interrupt
	#define TP15_INIT_ANALOG	{TP15_ANSEL = 1; TP15_WR = PINSTATE_HIGH; TP15_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define TP15_INIT_OUTPUT  {TP15_WR = PINSTATE_LOW; TP15_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP15_INIT_INPUT   {TP15_WR = PINSTATE_HIGH; TP15_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP16_TRIS    TRISDbits.TRISD10 // GPIO direction register bit
	#define TP16_WR      LATDbits.LATD10 // GPIO port latch register bit
	#define TP16_RD      PORTDbits.RD10 // GPIO port register bit
	#define TP16_ODC     ODCDbits.ODCD10 // GPIO port open drain configuration register bit
	#define TP16_CNPU    CNPUDbits.CNPUD10 // GPIO port pull-up resistor register bit
	#define TP16_CNPD    CNPDDbits.CNPDD10 // GPIO port pull-down resistor register bit
	#define TP16_CNEN0   CNEN0Dbits.CNEN0D10 // GPIO port change notification Enable register bit
	#define TP16_CNSTAT  CNSTATDbits.CNSTATD10 // GPIO port change notification Status register bit
	#define TP16_CNEN1   CNEN1Dbits.CNEN1D10 // GPIO port change notification Edge Select Enable register bit
	#define TP16_CNF     CNFDbits.CNFD10 // GPIO port change notification flag bit register bit
	#define TP16_SET     { asm volatile ("bset _LATD, #10 \n"); }
	#define TP16_CLEAR   { asm volatile ("bclr _LATD, #10 \n"); }
	#define TP16_TOGGLE  { asm volatile ("btg  _LATD, #10 \n"); }
	#define TP16_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP16_INIT_OUTPUT  {TP16_WR = PINSTATE_LOW; TP16_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP16_INIT_INPUT   {TP16_WR = PINSTATE_HIGH; TP16_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP17_TRIS    TRISDbits.TRISD12 // GPIO direction register bit
	#define TP17_WR      LATDbits.LATD12 // GPIO port latch register bit
	#define TP17_RD      PORTDbits.RD12 // GPIO port register bit
	#define TP17_ODC     ODCDbits.ODCD12 // GPIO port open drain configuration register bit
	#define TP17_CNPU    CNPUDbits.CNPUD12 // GPIO port pull-up resistor register bit
	#define TP17_CNPD    CNPDDbits.CNPDD12 // GPIO port pull-down resistor register bit
	#define TP17_CNEN0   CNEN0Dbits.CNEN0D12 // GPIO port change notification Enable register bit
	#define TP17_CNSTAT  CNSTATDbits.CNSTATD12 // GPIO port change notification Status register bit
	#define TP17_CNEN1   CNEN1Dbits.CNEN1D12 // GPIO port change notification Edge Select Enable register bit
	#define TP17_CNF     CNFDbits.CNFD12 // GPIO port change notification flag bit register bit
	#define TP17_SET     { asm volatile ("bset _LATD, #12 \n"); }
	#define TP17_CLEAR   { asm volatile ("bclr _LATD, #12 \n"); }
	#define TP17_TOGGLE  { asm volatile ("btg  _LATD, #12 \n"); }
	#define TP17_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP17_INIT_OUTPUT  {TP17_WR = PINSTATE_LOW; TP17_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP17_INIT_INPUT   {TP17_WR = PINSTATE_HIGH; TP17_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP18_TRIS    TRISCbits.TRISC6 // GPIO direction register bit
	#define TP18_WR      LATCbits.LATC6 // GPIO port latch register bit
	#define TP18_RD      PORTCbits.RC6 // GPIO port register bit
	#define TP18_ODC     ODCCbits.ODCC6 // GPIO port open drain configuration register bit
	#define TP18_CNPU    CNPUCbits.CNPUC6 // GPIO port pull-up resistor register bit
	#define TP18_CNPD    CNPDCbits.CNPDC6 // GPIO port pull-down resistor register bit
	#define TP18_CNEN0   CNEN0Cbits.CNEN0C6 // GPIO port change notification Enable register bit
	#define TP18_CNSTAT  CNSTATCbits.CNSTATC6 // GPIO port change notification Status register bit
	#define TP18_CNEN1   CNEN1Cbits.CNEN1C6 // GPIO port change notification Edge Select Enable register bit
	#define TP18_CNF     CNFCbits.CNFC6 // GPIO port change notification flag bit register bit
	#define TP18_RP      54 // Number of Remappable Pin
	#define TP18_SET     { asm volatile ("bset _LATC, #6 \n"); }
	#define TP18_CLEAR   { asm volatile ("bclr _LATC, #6 \n"); }
	#define TP18_TOGGLE  { asm volatile ("btg  _LATC, #6 \n"); }
	#define TP18_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP18_INIT_OUTPUT  {TP18_WR = PINSTATE_LOW; TP18_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP18_INIT_INPUT   {TP18_WR = PINSTATE_HIGH; TP18_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP20_TRIS    TRISBbits.TRISB1 // GPIO direction register bit
	#define TP20_WR      LATBbits.LATB1 // GPIO port latch register bit
	#define TP20_RD      PORTBbits.RB1 // GPIO port register bit
	#define TP20_ODC     ODCBbits.ODCB1 // GPIO port open drain configuration register bit
	#define TP20_CNPU    CNPUBbits.CNPUB1 // GPIO port pull-up resistor register bit
	#define TP20_CNPD    CNPDBbits.CNPDB1 // GPIO port pull-down resistor register bit
	#define TP20_CNEN0   CNEN0Bbits.CNEN0B1 // GPIO port change notification Enable register bit
	#define TP20_CNSTAT  CNSTATBbits.CNSTATB1 // GPIO port change notification Status register bit
	#define TP20_CNEN1   CNEN1Bbits.CNEN1B1 // GPIO port change notification Edge Select Enable register bit
	#define TP20_CNF     CNFBbits.CNFB1 // GPIO port change notification flag bit register bit
	#define TP20_RP      33 // Number of Remappable Pin
	#define TP20_SET     { asm volatile ("bset _LATB, #1 \n"); }
	#define TP20_CLEAR   { asm volatile ("bclr _LATB, #1 \n"); }
	#define TP20_TOGGLE  { asm volatile ("btg  _LATB, #1 \n"); }
	#define TP20_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define TP20_ANSEL   _ANSELB1 // analog/digital pin configuration register bit
	#define TP20_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define TP20_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define TP20_ADC_AN_INPUT 6   // ANx input pin number
	#define TP20_ADCBUF  ADCBUF6 // ADC buffer register for this input
	#define TP20_ADC_ANIE ADIELbits.IE6
	#define TP20_ADC_ANEIE ADEIELbits.EIEN6
	#define TP20_ADC_IF   _ADCAN6IF // interrupt flag bit
	#define TP20_ADC_IE   _ADCAN6IE // interrupt enable bit
	#define TP20_ADC_IP   _ADCAN6IP // interrupt priority for this analog input
	#define TP20_ADC_RDY  _AN6RDY // ADC buffer ready bit
	#define _TP20_ADC_Interrupt _ADCAN6Interrupt
	#define TP20_INIT_ANALOG	{TP20_ANSEL = 1; TP20_WR = PINSTATE_HIGH; TP20_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define TP20_INIT_OUTPUT  {TP20_WR = PINSTATE_LOW; TP20_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP20_INIT_INPUT   {TP20_WR = PINSTATE_HIGH; TP20_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP24_TRIS    TRISCbits.TRISC8 // GPIO direction register bit
	#define TP24_WR      LATCbits.LATC8 // GPIO port latch register bit
	#define TP24_RD      PORTCbits.RC8 // GPIO port register bit
	#define TP24_ODC     ODCCbits.ODCC8 // GPIO port open drain configuration register bit
	#define TP24_CNPU    CNPUCbits.CNPUC8 // GPIO port pull-up resistor register bit
	#define TP24_CNPD    CNPDCbits.CNPDC8 // GPIO port pull-down resistor register bit
	#define TP24_CNEN0   CNEN0Cbits.CNEN0C8 // GPIO port change notification Enable register bit
	#define TP24_CNSTAT  CNSTATCbits.CNSTATC8 // GPIO port change notification Status register bit
	#define TP24_CNEN1   CNEN1Cbits.CNEN1C8 // GPIO port change notification Edge Select Enable register bit
	#define TP24_CNF     CNFCbits.CNFC8 // GPIO port change notification flag bit register bit
	#define TP24_RP      56 // Number of Remappable Pin
	#define TP24_SET     { asm volatile ("bset _LATC, #8 \n"); }
	#define TP24_CLEAR   { asm volatile ("bclr _LATC, #8 \n"); }
	#define TP24_TOGGLE  { asm volatile ("btg  _LATC, #8 \n"); }
	#define TP24_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP24_INIT_OUTPUT  {TP24_WR = PINSTATE_LOW; TP24_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP24_INIT_INPUT   {TP24_WR = PINSTATE_HIGH; TP24_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP25_TRIS    TRISBbits.TRISB12 // GPIO direction register bit
	#define TP25_WR      LATBbits.LATB12 // GPIO port latch register bit
	#define TP25_RD      PORTBbits.RB12 // GPIO port register bit
	#define TP25_ODC     ODCBbits.ODCB12 // GPIO port open drain configuration register bit
	#define TP25_CNPU    CNPUBbits.CNPUB12 // GPIO port pull-up resistor register bit
	#define TP25_CNPD    CNPDBbits.CNPDB12 // GPIO port pull-down resistor register bit
	#define TP25_CNEN0   CNEN0Bbits.CNEN0B12 // GPIO port change notification Enable register bit
	#define TP25_CNSTAT  CNSTATBbits.CNSTATB12 // GPIO port change notification Status register bit
	#define TP25_CNEN1   CNEN1Bbits.CNEN1B12 // GPIO port change notification Edge Select Enable register bit
	#define TP25_CNF     CNFBbits.CNFB12 // GPIO port change notification flag bit register bit
	#define TP25_RP      44 // Number of Remappable Pin
	#define TP25_SET     { asm volatile ("bset _LATB, #12 \n"); }
	#define TP25_CLEAR   { asm volatile ("bclr _LATB, #12 \n"); }
	#define TP25_TOGGLE  { asm volatile ("btg  _LATB, #12 \n"); }
	#define TP25_CHANNEL   2
	#define TP25_PGxPER    PG2PER
	#define TP25_PGxPHASE  PG2PHASE
	#define TP25_PGxDC     PG2DC
	#define TP25_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP25_INIT_OUTPUT  {TP25_WR = PINSTATE_LOW; TP25_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP25_INIT_INPUT   {TP25_WR = PINSTATE_HIGH; TP25_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP26_TRIS    TRISDbits.TRISD14 // GPIO direction register bit
	#define TP26_WR      LATDbits.LATD14 // GPIO port latch register bit
	#define TP26_RD      PORTDbits.RD14 // GPIO port register bit
	#define TP26_ODC     ODCDbits.ODCD14 // GPIO port open drain configuration register bit
	#define TP26_CNPU    CNPUDbits.CNPUD14 // GPIO port pull-up resistor register bit
	#define TP26_CNPD    CNPDDbits.CNPDD14 // GPIO port pull-down resistor register bit
	#define TP26_CNEN0   CNEN0Dbits.CNEN0D14 // GPIO port change notification Enable register bit
	#define TP26_CNSTAT  CNSTATDbits.CNSTATD14 // GPIO port change notification Status register bit
	#define TP26_CNEN1   CNEN1Dbits.CNEN1D14 // GPIO port change notification Edge Select Enable register bit
	#define TP26_CNF     CNFDbits.CNFD14 // GPIO port change notification flag bit register bit
	#define TP26_SET     { asm volatile ("bset _LATD, #14 \n"); }
	#define TP26_CLEAR   { asm volatile ("bclr _LATD, #14 \n"); }
	#define TP26_TOGGLE  { asm volatile ("btg  _LATD, #14 \n"); }
	#define TP26_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP26_INIT_OUTPUT  {TP26_WR = PINSTATE_LOW; TP26_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP26_INIT_INPUT   {TP26_WR = PINSTATE_HIGH; TP26_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP27_TRIS    TRISBbits.TRISB13 // GPIO direction register bit
	#define TP27_WR      LATBbits.LATB13 // GPIO port latch register bit
	#define TP27_RD      PORTBbits.RB13 // GPIO port register bit
	#define TP27_ODC     ODCBbits.ODCB13 // GPIO port open drain configuration register bit
	#define TP27_CNPU    CNPUBbits.CNPUB13 // GPIO port pull-up resistor register bit
	#define TP27_CNPD    CNPDBbits.CNPDB13 // GPIO port pull-down resistor register bit
	#define TP27_CNEN0   CNEN0Bbits.CNEN0B13 // GPIO port change notification Enable register bit
	#define TP27_CNSTAT  CNSTATBbits.CNSTATB13 // GPIO port change notification Status register bit
	#define TP27_CNEN1   CNEN1Bbits.CNEN1B13 // GPIO port change notification Edge Select Enable register bit
	#define TP27_CNF     CNFBbits.CNFB13 // GPIO port change notification flag bit register bit
	#define TP27_RP      45 // Number of Remappable Pin
	#define TP27_SET     { asm volatile ("bset _LATB, #13 \n"); }
	#define TP27_CLEAR   { asm volatile ("bclr _LATB, #13 \n"); }
	#define TP27_TOGGLE  { asm volatile ("btg  _LATB, #13 \n"); }
	#define TP27_CHANNEL   2
	#define TP27_PGxPER    PG2PER
	#define TP27_PGxPHASE  PG2PHASE
	#define TP27_PGxDC     PG2DC
	#define TP27_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP27_INIT_OUTPUT  {TP27_WR = PINSTATE_LOW; TP27_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP27_INIT_INPUT   {TP27_WR = PINSTATE_HIGH; TP27_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP28_TRIS    TRISDbits.TRISD9 // GPIO direction register bit
	#define TP28_WR      LATDbits.LATD9 // GPIO port latch register bit
	#define TP28_RD      PORTDbits.RD9 // GPIO port register bit
	#define TP28_ODC     ODCDbits.ODCD9 // GPIO port open drain configuration register bit
	#define TP28_CNPU    CNPUDbits.CNPUD9 // GPIO port pull-up resistor register bit
	#define TP28_CNPD    CNPDDbits.CNPDD9 // GPIO port pull-down resistor register bit
	#define TP28_CNEN0   CNEN0Dbits.CNEN0D9 // GPIO port change notification Enable register bit
	#define TP28_CNSTAT  CNSTATDbits.CNSTATD9 // GPIO port change notification Status register bit
	#define TP28_CNEN1   CNEN1Dbits.CNEN1D9 // GPIO port change notification Edge Select Enable register bit
	#define TP28_CNF     CNFDbits.CNFD9 // GPIO port change notification flag bit register bit
	#define TP28_SET     { asm volatile ("bset _LATD, #9 \n"); }
	#define TP28_CLEAR   { asm volatile ("bclr _LATD, #9 \n"); }
	#define TP28_TOGGLE  { asm volatile ("btg  _LATD, #9 \n"); }
	#define TP28_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP28_INIT_OUTPUT  {TP28_WR = PINSTATE_LOW; TP28_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP28_INIT_INPUT   {TP28_WR = PINSTATE_HIGH; TP28_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP31_TRIS    TRISDbits.TRISD6 // GPIO direction register bit
	#define TP31_WR      LATDbits.LATD6 // GPIO port latch register bit
	#define TP31_RD      PORTDbits.RD6 // GPIO port register bit
	#define TP31_ODC     ODCDbits.ODCD6 // GPIO port open drain configuration register bit
	#define TP31_CNPU    CNPUDbits.CNPUD6 // GPIO port pull-up resistor register bit
	#define TP31_CNPD    CNPDDbits.CNPDD6 // GPIO port pull-down resistor register bit
	#define TP31_CNEN0   CNEN0Dbits.CNEN0D6 // GPIO port change notification Enable register bit
	#define TP31_CNSTAT  CNSTATDbits.CNSTATD6 // GPIO port change notification Status register bit
	#define TP31_CNEN1   CNEN1Dbits.CNEN1D6 // GPIO port change notification Edge Select Enable register bit
	#define TP31_CNF     CNFDbits.CNFD6 // GPIO port change notification flag bit register bit
	#define TP31_RP      70 // Number of Remappable Pin
	#define TP31_SET     { asm volatile ("bset _LATD, #6 \n"); }
	#define TP31_CLEAR   { asm volatile ("bclr _LATD, #6 \n"); }
	#define TP31_TOGGLE  { asm volatile ("btg  _LATD, #6 \n"); }
	#define TP31_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP31_INIT_OUTPUT  {TP31_WR = PINSTATE_LOW; TP31_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP31_INIT_INPUT   {TP31_WR = PINSTATE_HIGH; TP31_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP32_TRIS    TRISCbits.TRISC9 // GPIO direction register bit
	#define TP32_WR      LATCbits.LATC9 // GPIO port latch register bit
	#define TP32_RD      PORTCbits.RC9 // GPIO port register bit
	#define TP32_ODC     ODCCbits.ODCC9 // GPIO port open drain configuration register bit
	#define TP32_CNPU    CNPUCbits.CNPUC9 // GPIO port pull-up resistor register bit
	#define TP32_CNPD    CNPDCbits.CNPDC9 // GPIO port pull-down resistor register bit
	#define TP32_CNEN0   CNEN0Cbits.CNEN0C9 // GPIO port change notification Enable register bit
	#define TP32_CNSTAT  CNSTATCbits.CNSTATC9 // GPIO port change notification Status register bit
	#define TP32_CNEN1   CNEN1Cbits.CNEN1C9 // GPIO port change notification Edge Select Enable register bit
	#define TP32_CNF     CNFCbits.CNFC9 // GPIO port change notification flag bit register bit
	#define TP32_RP      57 // Number of Remappable Pin
	#define TP32_SET     { asm volatile ("bset _LATC, #9 \n"); }
	#define TP32_CLEAR   { asm volatile ("bclr _LATC, #9 \n"); }
	#define TP32_TOGGLE  { asm volatile ("btg  _LATC, #9 \n"); }
	#define TP32_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP32_INIT_OUTPUT  {TP32_WR = PINSTATE_LOW; TP32_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP32_INIT_INPUT   {TP32_WR = PINSTATE_HIGH; TP32_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP33_TRIS    TRISDbits.TRISD5 // GPIO direction register bit
	#define TP33_WR      LATDbits.LATD5 // GPIO port latch register bit
	#define TP33_RD      PORTDbits.RD5 // GPIO port register bit
	#define TP33_ODC     ODCDbits.ODCD5 // GPIO port open drain configuration register bit
	#define TP33_CNPU    CNPUDbits.CNPUD5 // GPIO port pull-up resistor register bit
	#define TP33_CNPD    CNPDDbits.CNPDD5 // GPIO port pull-down resistor register bit
	#define TP33_CNEN0   CNEN0Dbits.CNEN0D5 // GPIO port change notification Enable register bit
	#define TP33_CNSTAT  CNSTATDbits.CNSTATD5 // GPIO port change notification Status register bit
	#define TP33_CNEN1   CNEN1Dbits.CNEN1D5 // GPIO port change notification Edge Select Enable register bit
	#define TP33_CNF     CNFDbits.CNFD5 // GPIO port change notification flag bit register bit
	#define TP33_RP      69 // Number of Remappable Pin
	#define TP33_SET     { asm volatile ("bset _LATD, #5 \n"); }
	#define TP33_CLEAR   { asm volatile ("bclr _LATD, #5 \n"); }
	#define TP33_TOGGLE  { asm volatile ("btg  _LATD, #5 \n"); }
	#define TP33_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP33_INIT_OUTPUT  {TP33_WR = PINSTATE_LOW; TP33_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP33_INIT_INPUT   {TP33_WR = PINSTATE_HIGH; TP33_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP34_TRIS    TRISBbits.TRISB11 // GPIO direction register bit
	#define TP34_WR      LATBbits.LATB11 // GPIO port latch register bit
	#define TP34_RD      PORTBbits.RB11 // GPIO port register bit
	#define TP34_ODC     ODCBbits.ODCB11 // GPIO port open drain configuration register bit
	#define TP34_CNPU    CNPUBbits.CNPUB11 // GPIO port pull-up resistor register bit
	#define TP34_CNPD    CNPDBbits.CNPDB11 // GPIO port pull-down resistor register bit
	#define TP34_CNEN0   CNEN0Bbits.CNEN0B11 // GPIO port change notification Enable register bit
	#define TP34_CNSTAT  CNSTATBbits.CNSTATB11 // GPIO port change notification Status register bit
	#define TP34_CNEN1   CNEN1Bbits.CNEN1B11 // GPIO port change notification Edge Select Enable register bit
	#define TP34_CNF     CNFBbits.CNFB11 // GPIO port change notification flag bit register bit
	#define TP34_RP      43 // Number of Remappable Pin
	#define TP34_SET     { asm volatile ("bset _LATB, #11 \n"); }
	#define TP34_CLEAR   { asm volatile ("bclr _LATB, #11 \n"); }
	#define TP34_TOGGLE  { asm volatile ("btg  _LATB, #11 \n"); }
	#define TP34_CHANNEL   3
	#define TP34_PGxPER    PG3PER
	#define TP34_PGxPHASE  PG3PHASE
	#define TP34_PGxDC     PG3DC
	#define TP34_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP34_INIT_OUTPUT  {TP34_WR = PINSTATE_LOW; TP34_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP34_INIT_INPUT   {TP34_WR = PINSTATE_HIGH; TP34_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP35_TRIS    TRISBbits.TRISB14 // GPIO direction register bit
	#define TP35_WR      LATBbits.LATB14 // GPIO port latch register bit
	#define TP35_RD      PORTBbits.RB14 // GPIO port register bit
	#define TP35_ODC     ODCBbits.ODCB14 // GPIO port open drain configuration register bit
	#define TP35_CNPU    CNPUBbits.CNPUB14 // GPIO port pull-up resistor register bit
	#define TP35_CNPD    CNPDBbits.CNPDB14 // GPIO port pull-down resistor register bit
	#define TP35_CNEN0   CNEN0Bbits.CNEN0B14 // GPIO port change notification Enable register bit
	#define TP35_CNSTAT  CNSTATBbits.CNSTATB14 // GPIO port change notification Status register bit
	#define TP35_CNEN1   CNEN1Bbits.CNEN1B14 // GPIO port change notification Edge Select Enable register bit
	#define TP35_CNF     CNFBbits.CNFB14 // GPIO port change notification flag bit register bit
	#define TP35_RP      46 // Number of Remappable Pin
	#define TP35_SET     { asm volatile ("bset _LATB, #14 \n"); }
	#define TP35_CLEAR   { asm volatile ("bclr _LATB, #14 \n"); }
	#define TP35_TOGGLE  { asm volatile ("btg  _LATB, #14 \n"); }
	#define TP35_CHANNEL   1
	#define TP35_PGxPER    PG1PER
	#define TP35_PGxPHASE  PG1PHASE
	#define TP35_PGxDC     PG1DC
	#define TP35_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP35_INIT_OUTPUT  {TP35_WR = PINSTATE_LOW; TP35_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP35_INIT_INPUT   {TP35_WR = PINSTATE_HIGH; TP35_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP36_TRIS    TRISBbits.TRISB10 // GPIO direction register bit
	#define TP36_WR      LATBbits.LATB10 // GPIO port latch register bit
	#define TP36_RD      PORTBbits.RB10 // GPIO port register bit
	#define TP36_ODC     ODCBbits.ODCB10 // GPIO port open drain configuration register bit
	#define TP36_CNPU    CNPUBbits.CNPUB10 // GPIO port pull-up resistor register bit
	#define TP36_CNPD    CNPDBbits.CNPDB10 // GPIO port pull-down resistor register bit
	#define TP36_CNEN0   CNEN0Bbits.CNEN0B10 // GPIO port change notification Enable register bit
	#define TP36_CNSTAT  CNSTATBbits.CNSTATB10 // GPIO port change notification Status register bit
	#define TP36_CNEN1   CNEN1Bbits.CNEN1B10 // GPIO port change notification Edge Select Enable register bit
	#define TP36_CNF     CNFBbits.CNFB10 // GPIO port change notification flag bit register bit
	#define TP36_RP      42 // Number of Remappable Pin
	#define TP36_SET     { asm volatile ("bset _LATB, #10 \n"); }
	#define TP36_CLEAR   { asm volatile ("bclr _LATB, #10 \n"); }
	#define TP36_TOGGLE  { asm volatile ("btg  _LATB, #10 \n"); }
	#define TP36_CHANNEL   3
	#define TP36_PGxPER    PG3PER
	#define TP36_PGxPHASE  PG3PHASE
	#define TP36_PGxDC     PG3DC
	#define TP36_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP36_INIT_OUTPUT  {TP36_WR = PINSTATE_LOW; TP36_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP36_INIT_INPUT   {TP36_WR = PINSTATE_HIGH; TP36_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP37_TRIS    TRISDbits.TRISD4 // GPIO direction register bit
	#define TP37_WR      LATDbits.LATD4 // GPIO port latch register bit
	#define TP37_RD      PORTDbits.RD4 // GPIO port register bit
	#define TP37_ODC     ODCDbits.ODCD4 // GPIO port open drain configuration register bit
	#define TP37_CNPU    CNPUDbits.CNPUD4 // GPIO port pull-up resistor register bit
	#define TP37_CNPD    CNPDDbits.CNPDD4 // GPIO port pull-down resistor register bit
	#define TP37_CNEN0   CNEN0Dbits.CNEN0D4 // GPIO port change notification Enable register bit
	#define TP37_CNSTAT  CNSTATDbits.CNSTATD4 // GPIO port change notification Status register bit
	#define TP37_CNEN1   CNEN1Dbits.CNEN1D4 // GPIO port change notification Edge Select Enable register bit
	#define TP37_CNF     CNFDbits.CNFD4 // GPIO port change notification flag bit register bit
	#define TP37_RP      68 // Number of Remappable Pin
	#define TP37_SET     { asm volatile ("bset _LATD, #4 \n"); }
	#define TP37_CLEAR   { asm volatile ("bclr _LATD, #4 \n"); }
	#define TP37_TOGGLE  { asm volatile ("btg  _LATD, #4 \n"); }
	#define TP37_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP37_INIT_OUTPUT  {TP37_WR = PINSTATE_LOW; TP37_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP37_INIT_INPUT   {TP37_WR = PINSTATE_HIGH; TP37_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP38_TRIS    TRISBbits.TRISB15 // GPIO direction register bit
	#define TP38_WR      LATBbits.LATB15 // GPIO port latch register bit
	#define TP38_RD      PORTBbits.RB15 // GPIO port register bit
	#define TP38_ODC     ODCBbits.ODCB15 // GPIO port open drain configuration register bit
	#define TP38_CNPU    CNPUBbits.CNPUB15 // GPIO port pull-up resistor register bit
	#define TP38_CNPD    CNPDBbits.CNPDB15 // GPIO port pull-down resistor register bit
	#define TP38_CNEN0   CNEN0Bbits.CNEN0B15 // GPIO port change notification Enable register bit
	#define TP38_CNSTAT  CNSTATBbits.CNSTATB15 // GPIO port change notification Status register bit
	#define TP38_CNEN1   CNEN1Bbits.CNEN1B15 // GPIO port change notification Edge Select Enable register bit
	#define TP38_CNF     CNFBbits.CNFB15 // GPIO port change notification flag bit register bit
	#define TP38_RP      47 // Number of Remappable Pin
	#define TP38_SET     { asm volatile ("bset _LATB, #15 \n"); }
	#define TP38_CLEAR   { asm volatile ("bclr _LATB, #15 \n"); }
	#define TP38_TOGGLE  { asm volatile ("btg  _LATB, #15 \n"); }
	#define TP38_CHANNEL   1
	#define TP38_PGxPER    PG1PER
	#define TP38_PGxPHASE  PG1PHASE
	#define TP38_PGxDC     PG1DC
	#define TP38_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP38_INIT_OUTPUT  {TP38_WR = PINSTATE_LOW; TP38_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP38_INIT_INPUT   {TP38_WR = PINSTATE_HIGH; TP38_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP39_TRIS    TRISDbits.TRISD2 // GPIO direction register bit
	#define TP39_WR      LATDbits.LATD2 // GPIO port latch register bit
	#define TP39_RD      PORTDbits.RD2 // GPIO port register bit
	#define TP39_ODC     ODCDbits.ODCD2 // GPIO port open drain configuration register bit
	#define TP39_CNPU    CNPUDbits.CNPUD2 // GPIO port pull-up resistor register bit
	#define TP39_CNPD    CNPDDbits.CNPDD2 // GPIO port pull-down resistor register bit
	#define TP39_CNEN0   CNEN0Dbits.CNEN0D2 // GPIO port change notification Enable register bit
	#define TP39_CNSTAT  CNSTATDbits.CNSTATD2 // GPIO port change notification Status register bit
	#define TP39_CNEN1   CNEN1Dbits.CNEN1D2 // GPIO port change notification Edge Select Enable register bit
	#define TP39_CNF     CNFDbits.CNFD2 // GPIO port change notification flag bit register bit
	#define TP39_RP      66 // Number of Remappable Pin
	#define TP39_SET     { asm volatile ("bset _LATD, #2 \n"); }
	#define TP39_CLEAR   { asm volatile ("bclr _LATD, #2 \n"); }
	#define TP39_TOGGLE  { asm volatile ("btg  _LATD, #2 \n"); }
	#define TP39_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP39_INIT_OUTPUT  {TP39_WR = PINSTATE_LOW; TP39_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP39_INIT_INPUT   {TP39_WR = PINSTATE_HIGH; TP39_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP40_TRIS    TRISCbits.TRISC5 // GPIO direction register bit
	#define TP40_WR      LATCbits.LATC5 // GPIO port latch register bit
	#define TP40_RD      PORTCbits.RC5 // GPIO port register bit
	#define TP40_ODC     ODCCbits.ODCC5 // GPIO port open drain configuration register bit
	#define TP40_CNPU    CNPUCbits.CNPUC5 // GPIO port pull-up resistor register bit
	#define TP40_CNPD    CNPDCbits.CNPDC5 // GPIO port pull-down resistor register bit
	#define TP40_CNEN0   CNEN0Cbits.CNEN0C5 // GPIO port change notification Enable register bit
	#define TP40_CNSTAT  CNSTATCbits.CNSTATC5 // GPIO port change notification Status register bit
	#define TP40_CNEN1   CNEN1Cbits.CNEN1C5 // GPIO port change notification Edge Select Enable register bit
	#define TP40_CNF     CNFCbits.CNFC5 // GPIO port change notification flag bit register bit
	#define TP40_RP      53 // Number of Remappable Pin
	#define TP40_SET     { asm volatile ("bset _LATC, #5 \n"); }
	#define TP40_CLEAR   { asm volatile ("bclr _LATC, #5 \n"); }
	#define TP40_TOGGLE  { asm volatile ("btg  _LATC, #5 \n"); }
	#define TP40_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP40_INIT_OUTPUT  {TP40_WR = PINSTATE_LOW; TP40_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP40_INIT_INPUT   {TP40_WR = PINSTATE_HIGH; TP40_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP41_TRIS    TRISDbits.TRISD3 // GPIO direction register bit
	#define TP41_WR      LATDbits.LATD3 // GPIO port latch register bit
	#define TP41_RD      PORTDbits.RD3 // GPIO port register bit
	#define TP41_ODC     ODCDbits.ODCD3 // GPIO port open drain configuration register bit
	#define TP41_CNPU    CNPUDbits.CNPUD3 // GPIO port pull-up resistor register bit
	#define TP41_CNPD    CNPDDbits.CNPDD3 // GPIO port pull-down resistor register bit
	#define TP41_CNEN0   CNEN0Dbits.CNEN0D3 // GPIO port change notification Enable register bit
	#define TP41_CNSTAT  CNSTATDbits.CNSTATD3 // GPIO port change notification Status register bit
	#define TP41_CNEN1   CNEN1Dbits.CNEN1D3 // GPIO port change notification Edge Select Enable register bit
	#define TP41_CNF     CNFDbits.CNFD3 // GPIO port change notification flag bit register bit
	#define TP41_RP      67 // Number of Remappable Pin
	#define TP41_SET     { asm volatile ("bset _LATD, #3 \n"); }
	#define TP41_CLEAR   { asm volatile ("bclr _LATD, #3 \n"); }
	#define TP41_TOGGLE  { asm volatile ("btg  _LATD, #3 \n"); }
	#define TP41_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP41_INIT_OUTPUT  {TP41_WR = PINSTATE_LOW; TP41_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP41_INIT_INPUT   {TP41_WR = PINSTATE_HIGH; TP41_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP42_TRIS    TRISCbits.TRISC4 // GPIO direction register bit
	#define TP42_WR      LATCbits.LATC4 // GPIO port latch register bit
	#define TP42_RD      PORTCbits.RC4 // GPIO port register bit
	#define TP42_ODC     ODCCbits.ODCC4 // GPIO port open drain configuration register bit
	#define TP42_CNPU    CNPUCbits.CNPUC4 // GPIO port pull-up resistor register bit
	#define TP42_CNPD    CNPDCbits.CNPDC4 // GPIO port pull-down resistor register bit
	#define TP42_CNEN0   CNEN0Cbits.CNEN0C4 // GPIO port change notification Enable register bit
	#define TP42_CNSTAT  CNSTATCbits.CNSTATC4 // GPIO port change notification Status register bit
	#define TP42_CNEN1   CNEN1Cbits.CNEN1C4 // GPIO port change notification Edge Select Enable register bit
	#define TP42_CNF     CNFCbits.CNFC4 // GPIO port change notification flag bit register bit
	#define TP42_RP      52 // Number of Remappable Pin
	#define TP42_SET     { asm volatile ("bset _LATC, #4 \n"); }
	#define TP42_CLEAR   { asm volatile ("bclr _LATC, #4 \n"); }
	#define TP42_TOGGLE  { asm volatile ("btg  _LATC, #4 \n"); }
	#define TP42_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP42_INIT_OUTPUT  {TP42_WR = PINSTATE_LOW; TP42_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP42_INIT_INPUT   {TP42_WR = PINSTATE_HIGH; TP42_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP43_TRIS    TRISDbits.TRISD1 // GPIO direction register bit
	#define TP43_WR      LATDbits.LATD1 // GPIO port latch register bit
	#define TP43_RD      PORTDbits.RD1 // GPIO port register bit
	#define TP43_ODC     ODCDbits.ODCD1 // GPIO port open drain configuration register bit
	#define TP43_CNPU    CNPUDbits.CNPUD1 // GPIO port pull-up resistor register bit
	#define TP43_CNPD    CNPDDbits.CNPDD1 // GPIO port pull-down resistor register bit
	#define TP43_CNEN0   CNEN0Dbits.CNEN0D1 // GPIO port change notification Enable register bit
	#define TP43_CNSTAT  CNSTATDbits.CNSTATD1 // GPIO port change notification Status register bit
	#define TP43_CNEN1   CNEN1Dbits.CNEN1D1 // GPIO port change notification Edge Select Enable register bit
	#define TP43_CNF     CNFDbits.CNFD1 // GPIO port change notification flag bit register bit
	#define TP43_RP      65 // Number of Remappable Pin
	#define TP43_SET     { asm volatile ("bset _LATD, #1 \n"); }
	#define TP43_CLEAR   { asm volatile ("bclr _LATD, #1 \n"); }
	#define TP43_TOGGLE  { asm volatile ("btg  _LATD, #1 \n"); }
	#define TP43_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP43_INIT_OUTPUT  {TP43_WR = PINSTATE_LOW; TP43_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP43_INIT_INPUT   {TP43_WR = PINSTATE_HIGH; TP43_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP44_TRIS    TRISDbits.TRISD0 // GPIO direction register bit
	#define TP44_WR      LATDbits.LATD0 // GPIO port latch register bit
	#define TP44_RD      PORTDbits.RD0 // GPIO port register bit
	#define TP44_ODC     ODCDbits.ODCD0 // GPIO port open drain configuration register bit
	#define TP44_CNPU    CNPUDbits.CNPUD0 // GPIO port pull-up resistor register bit
	#define TP44_CNPD    CNPDDbits.CNPDD0 // GPIO port pull-down resistor register bit
	#define TP44_CNEN0   CNEN0Dbits.CNEN0D0 // GPIO port change notification Enable register bit
	#define TP44_CNSTAT  CNSTATDbits.CNSTATD0 // GPIO port change notification Status register bit
	#define TP44_CNEN1   CNEN1Dbits.CNEN1D0 // GPIO port change notification Edge Select Enable register bit
	#define TP44_CNF     CNFDbits.CNFD0 // GPIO port change notification flag bit register bit
	#define TP44_RP      64 // Number of Remappable Pin
	#define TP44_SET     { asm volatile ("bset _LATD, #0 \n"); }
	#define TP44_CLEAR   { asm volatile ("bclr _LATD, #0 \n"); }
	#define TP44_TOGGLE  { asm volatile ("btg  _LATD, #0 \n"); }
	#define TP44_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP44_INIT_OUTPUT  {TP44_WR = PINSTATE_LOW; TP44_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP44_INIT_INPUT   {TP44_WR = PINSTATE_HIGH; TP44_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP46_TRIS    TRISCbits.TRISC12 // GPIO direction register bit
	#define TP46_WR      LATCbits.LATC12 // GPIO port latch register bit
	#define TP46_RD      PORTCbits.RC12 // GPIO port register bit
	#define TP46_ODC     ODCCbits.ODCC12 // GPIO port open drain configuration register bit
	#define TP46_CNPU    CNPUCbits.CNPUC12 // GPIO port pull-up resistor register bit
	#define TP46_CNPD    CNPDCbits.CNPDC12 // GPIO port pull-down resistor register bit
	#define TP46_CNEN0   CNEN0Cbits.CNEN0C12 // GPIO port change notification Enable register bit
	#define TP46_CNSTAT  CNSTATCbits.CNSTATC12 // GPIO port change notification Status register bit
	#define TP46_CNEN1   CNEN1Cbits.CNEN1C12 // GPIO port change notification Edge Select Enable register bit
	#define TP46_CNF     CNFCbits.CNFC12 // GPIO port change notification flag bit register bit
	#define TP46_RP      60 // Number of Remappable Pin
	#define TP46_SET     { asm volatile ("bset _LATC, #12 \n"); }
	#define TP46_CLEAR   { asm volatile ("bclr _LATC, #12 \n"); }
	#define TP46_TOGGLE  { asm volatile ("btg  _LATC, #12 \n"); }
	#define TP46_CHANNEL   4
	#define TP46_PGxPER    PG4PER
	#define TP46_PGxPHASE  PG4PHASE
	#define TP46_PGxDC     PG4DC
	#define TP46_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP46_INIT_OUTPUT  {TP46_WR = PINSTATE_LOW; TP46_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP46_INIT_INPUT   {TP46_WR = PINSTATE_HIGH; TP46_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP48_TRIS    TRISCbits.TRISC13 // GPIO direction register bit
	#define TP48_WR      LATCbits.LATC13 // GPIO port latch register bit
	#define TP48_RD      PORTCbits.RC13 // GPIO port register bit
	#define TP48_ODC     ODCCbits.ODCC13 // GPIO port open drain configuration register bit
	#define TP48_CNPU    CNPUCbits.CNPUC13 // GPIO port pull-up resistor register bit
	#define TP48_CNPD    CNPDCbits.CNPDC13 // GPIO port pull-down resistor register bit
	#define TP48_CNEN0   CNEN0Cbits.CNEN0C13 // GPIO port change notification Enable register bit
	#define TP48_CNSTAT  CNSTATCbits.CNSTATC13 // GPIO port change notification Status register bit
	#define TP48_CNEN1   CNEN1Cbits.CNEN1C13 // GPIO port change notification Edge Select Enable register bit
	#define TP48_CNF     CNFCbits.CNFC13 // GPIO port change notification flag bit register bit
	#define TP48_RP      61 // Number of Remappable Pin
	#define TP48_SET     { asm volatile ("bset _LATC, #13 \n"); }
	#define TP48_CLEAR   { asm volatile ("bclr _LATC, #13 \n"); }
	#define TP48_TOGGLE  { asm volatile ("btg  _LATC, #13 \n"); }
	#define TP48_CHANNEL   4
	#define TP48_PGxPER    PG4PER
	#define TP48_PGxPHASE  PG4PHASE
	#define TP48_PGxDC     PG4DC
	#define TP48_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP48_INIT_OUTPUT  {TP48_WR = PINSTATE_LOW; TP48_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP48_INIT_INPUT   {TP48_WR = PINSTATE_HIGH; TP48_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP50_TRIS    TRISDbits.TRISD7 // GPIO direction register bit
	#define TP50_WR      LATDbits.LATD7 // GPIO port latch register bit
	#define TP50_RD      PORTDbits.RD7 // GPIO port register bit
	#define TP50_ODC     ODCDbits.ODCD7 // GPIO port open drain configuration register bit
	#define TP50_CNPU    CNPUDbits.CNPUD7 // GPIO port pull-up resistor register bit
	#define TP50_CNPD    CNPDDbits.CNPDD7 // GPIO port pull-down resistor register bit
	#define TP50_CNEN0   CNEN0Dbits.CNEN0D7 // GPIO port change notification Enable register bit
	#define TP50_CNSTAT  CNSTATDbits.CNSTATD7 // GPIO port change notification Status register bit
	#define TP50_CNEN1   CNEN1Dbits.CNEN1D7 // GPIO port change notification Edge Select Enable register bit
	#define TP50_CNF     CNFDbits.CNFD7 // GPIO port change notification flag bit register bit
	#define TP50_RP      71 // Number of Remappable Pin
	#define TP50_SET     { asm volatile ("bset _LATD, #7 \n"); }
	#define TP50_CLEAR   { asm volatile ("bclr _LATD, #7 \n"); }
	#define TP50_TOGGLE  { asm volatile ("btg  _LATD, #7 \n"); }
	#define TP50_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP50_INIT_OUTPUT  {TP50_WR = PINSTATE_LOW; TP50_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP50_INIT_INPUT   {TP50_WR = PINSTATE_HIGH; TP50_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP51_TRIS    TRISBbits.TRISB4 // GPIO direction register bit
	#define TP51_WR      LATBbits.LATB4 // GPIO port latch register bit
	#define TP51_RD      PORTBbits.RB4 // GPIO port register bit
	#define TP51_ODC     ODCBbits.ODCB4 // GPIO port open drain configuration register bit
	#define TP51_CNPU    CNPUBbits.CNPUB4 // GPIO port pull-up resistor register bit
	#define TP51_CNPD    CNPDBbits.CNPDB4 // GPIO port pull-down resistor register bit
	#define TP51_CNEN0   CNEN0Bbits.CNEN0B4 // GPIO port change notification Enable register bit
	#define TP51_CNSTAT  CNSTATBbits.CNSTATB4 // GPIO port change notification Status register bit
	#define TP51_CNEN1   CNEN1Bbits.CNEN1B4 // GPIO port change notification Edge Select Enable register bit
	#define TP51_CNF     CNFBbits.CNFB4 // GPIO port change notification flag bit register bit
	#define TP51_RP      36 // Number of Remappable Pin
	#define TP51_SET     { asm volatile ("bset _LATB, #4 \n"); }
	#define TP51_CLEAR   { asm volatile ("bclr _LATB, #4 \n"); }
	#define TP51_TOGGLE  { asm volatile ("btg  _LATB, #4 \n"); }
	#define TP51_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP51_INIT_OUTPUT  {TP51_WR = PINSTATE_LOW; TP51_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP51_INIT_INPUT   {TP51_WR = PINSTATE_HIGH; TP51_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP52_TRIS    TRISDbits.TRISD8 // GPIO direction register bit
	#define TP52_WR      LATDbits.LATD8 // GPIO port latch register bit
	#define TP52_RD      PORTDbits.RD8 // GPIO port register bit
	#define TP52_ODC     ODCDbits.ODCD8 // GPIO port open drain configuration register bit
	#define TP52_CNPU    CNPUDbits.CNPUD8 // GPIO port pull-up resistor register bit
	#define TP52_CNPD    CNPDDbits.CNPDD8 // GPIO port pull-down resistor register bit
	#define TP52_CNEN0   CNEN0Dbits.CNEN0D8 // GPIO port change notification Enable register bit
	#define TP52_CNSTAT  CNSTATDbits.CNSTATD8 // GPIO port change notification Status register bit
	#define TP52_CNEN1   CNEN1Dbits.CNEN1D8 // GPIO port change notification Edge Select Enable register bit
	#define TP52_CNF     CNFDbits.CNFD8 // GPIO port change notification flag bit register bit
	#define TP52_SET     { asm volatile ("bset _LATD, #8 \n"); }
	#define TP52_CLEAR   { asm volatile ("bclr _LATD, #8 \n"); }
	#define TP52_TOGGLE  { asm volatile ("btg  _LATD, #8 \n"); }
	#define TP52_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP52_INIT_OUTPUT  {TP52_WR = PINSTATE_LOW; TP52_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP52_INIT_INPUT   {TP52_WR = PINSTATE_HIGH; TP52_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP53_TRIS    TRISBbits.TRISB6 // GPIO direction register bit
	#define TP53_WR      LATBbits.LATB6 // GPIO port latch register bit
	#define TP53_RD      PORTBbits.RB6 // GPIO port register bit
	#define TP53_ODC     ODCBbits.ODCB6 // GPIO port open drain configuration register bit
	#define TP53_CNPU    CNPUBbits.CNPUB6 // GPIO port pull-up resistor register bit
	#define TP53_CNPD    CNPDBbits.CNPDB6 // GPIO port pull-down resistor register bit
	#define TP53_CNEN0   CNEN0Bbits.CNEN0B6 // GPIO port change notification Enable register bit
	#define TP53_CNSTAT  CNSTATBbits.CNSTATB6 // GPIO port change notification Status register bit
	#define TP53_CNEN1   CNEN1Bbits.CNEN1B6 // GPIO port change notification Edge Select Enable register bit
	#define TP53_CNF     CNFBbits.CNFB6 // GPIO port change notification flag bit register bit
	#define TP53_RP      38 // Number of Remappable Pin
	#define TP53_SET     { asm volatile ("bset _LATB, #6 \n"); }
	#define TP53_CLEAR   { asm volatile ("bclr _LATB, #6 \n"); }
	#define TP53_TOGGLE  { asm volatile ("btg  _LATB, #6 \n"); }
	#define TP53_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP53_INIT_OUTPUT  {TP53_WR = PINSTATE_LOW; TP53_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP53_INIT_INPUT   {TP53_WR = PINSTATE_HIGH; TP53_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP54_TRIS    TRISDbits.TRISD13 // GPIO direction register bit
	#define TP54_WR      LATDbits.LATD13 // GPIO port latch register bit
	#define TP54_RD      PORTDbits.RD13 // GPIO port register bit
	#define TP54_ODC     ODCDbits.ODCD13 // GPIO port open drain configuration register bit
	#define TP54_CNPU    CNPUDbits.CNPUD13 // GPIO port pull-up resistor register bit
	#define TP54_CNPD    CNPDDbits.CNPDD13 // GPIO port pull-down resistor register bit
	#define TP54_CNEN0   CNEN0Dbits.CNEN0D13 // GPIO port change notification Enable register bit
	#define TP54_CNSTAT  CNSTATDbits.CNSTATD13 // GPIO port change notification Status register bit
	#define TP54_CNEN1   CNEN1Dbits.CNEN1D13 // GPIO port change notification Edge Select Enable register bit
	#define TP54_CNF     CNFDbits.CNFD13 // GPIO port change notification flag bit register bit
	#define TP54_SET     { asm volatile ("bset _LATD, #13 \n"); }
	#define TP54_CLEAR   { asm volatile ("bclr _LATD, #13 \n"); }
	#define TP54_TOGGLE  { asm volatile ("btg  _LATD, #13 \n"); }
	#define TP54_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP54_INIT_OUTPUT  {TP54_WR = PINSTATE_LOW; TP54_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP54_INIT_INPUT   {TP54_WR = PINSTATE_HIGH; TP54_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP55_TRIS    TRISBbits.TRISB5 // GPIO direction register bit
	#define TP55_WR      LATBbits.LATB5 // GPIO port latch register bit
	#define TP55_RD      PORTBbits.RB5 // GPIO port register bit
	#define TP55_ODC     ODCBbits.ODCB5 // GPIO port open drain configuration register bit
	#define TP55_CNPU    CNPUBbits.CNPUB5 // GPIO port pull-up resistor register bit
	#define TP55_CNPD    CNPDBbits.CNPDB5 // GPIO port pull-down resistor register bit
	#define TP55_CNEN0   CNEN0Bbits.CNEN0B5 // GPIO port change notification Enable register bit
	#define TP55_CNSTAT  CNSTATBbits.CNSTATB5 // GPIO port change notification Status register bit
	#define TP55_CNEN1   CNEN1Bbits.CNEN1B5 // GPIO port change notification Edge Select Enable register bit
	#define TP55_CNF     CNFBbits.CNFB5 // GPIO port change notification flag bit register bit
	#define TP55_RP      37 // Number of Remappable Pin
	#define TP55_SET     { asm volatile ("bset _LATB, #5 \n"); }
	#define TP55_CLEAR   { asm volatile ("bclr _LATB, #5 \n"); }
	#define TP55_TOGGLE  { asm volatile ("btg  _LATB, #5 \n"); }
	#define TP55_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP55_INIT_OUTPUT  {TP55_WR = PINSTATE_LOW; TP55_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP55_INIT_INPUT   {TP55_WR = PINSTATE_HIGH; TP55_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP56_TRIS    TRISBbits.TRISB3 // GPIO direction register bit
	#define TP56_WR      LATBbits.LATB3 // GPIO port latch register bit
	#define TP56_RD      PORTBbits.RB3 // GPIO port register bit
	#define TP56_ODC     ODCBbits.ODCB3 // GPIO port open drain configuration register bit
	#define TP56_CNPU    CNPUBbits.CNPUB3 // GPIO port pull-up resistor register bit
	#define TP56_CNPD    CNPDBbits.CNPDB3 // GPIO port pull-down resistor register bit
	#define TP56_CNEN0   CNEN0Bbits.CNEN0B3 // GPIO port change notification Enable register bit
	#define TP56_CNSTAT  CNSTATBbits.CNSTATB3 // GPIO port change notification Status register bit
	#define TP56_CNEN1   CNEN1Bbits.CNEN1B3 // GPIO port change notification Edge Select Enable register bit
	#define TP56_CNF     CNFBbits.CNFB3 // GPIO port change notification flag bit register bit
	#define TP56_RP      35 // Number of Remappable Pin
	#define TP56_SET     { asm volatile ("bset _LATB, #3 \n"); }
	#define TP56_CLEAR   { asm volatile ("bclr _LATB, #3 \n"); }
	#define TP56_TOGGLE  { asm volatile ("btg  _LATB, #3 \n"); }
	#define TP56_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define TP56_ANSEL   _ANSELB3 // analog/digital pin configuration register bit
	#define TP56_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define TP56_IS_SHARED_CORE 1 // AN input is routed to a dedicated or shared ACD core
	#define TP56_ADC_AN_INPUT 8   // ANx input pin number
	#define TP56_ADCBUF  ADCBUF8 // ADC buffer register for this input
	#define TP56_ADC_ANIE ADIELbits.IE8
	#define TP56_ADC_ANEIE ADEIELbits.EIEN8
	#define TP56_ADC_IF   _ADCAN8IF // interrupt flag bit
	#define TP56_ADC_IE   _ADCAN8IE // interrupt enable bit
	#define TP56_ADC_IP   _ADCAN8IP // interrupt priority for this analog input
	#define TP56_ADC_RDY  _AN8RDY // ADC buffer ready bit
	#define _TP56_ADC_Interrupt _ADCAN8Interrupt
	#define TP56_INIT_ANALOG	{TP56_ANSEL = 1; TP56_WR = PINSTATE_HIGH; TP56_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define TP56_INIT_OUTPUT  {TP56_WR = PINSTATE_LOW; TP56_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP56_INIT_INPUT   {TP56_WR = PINSTATE_HIGH; TP56_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define UART_RX_TRIS    TRISCbits.TRISC15 // GPIO direction register bit
	#define UART_RX_WR      LATCbits.LATC15 // GPIO port latch register bit
	#define UART_RX_RD      PORTCbits.RC15 // GPIO port register bit
	#define UART_RX_ODC     ODCCbits.ODCC15 // GPIO port open drain configuration register bit
	#define UART_RX_CNPU    CNPUCbits.CNPUC15 // GPIO port pull-up resistor register bit
	#define UART_RX_CNPD    CNPDCbits.CNPDC15 // GPIO port pull-down resistor register bit
	#define UART_RX_CNEN0   CNEN0Cbits.CNEN0C15 // GPIO port change notification Enable register bit
	#define UART_RX_CNSTAT  CNSTATCbits.CNSTATC15 // GPIO port change notification Status register bit
	#define UART_RX_CNEN1   CNEN1Cbits.CNEN1C15 // GPIO port change notification Edge Select Enable register bit
	#define UART_RX_CNF     CNFCbits.CNFC15 // GPIO port change notification flag bit register bit
	#define UART_RX_RP      63 // Number of Remappable Pin
	#define UART_RX_SET     { asm volatile ("bset _LATC, #15 \n"); }
	#define UART_RX_CLEAR   { asm volatile ("bclr _LATC, #15 \n"); }
	#define UART_RX_TOGGLE  { asm volatile ("btg  _LATC, #15 \n"); }
	#define UART_RX_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define UART_RX_INIT_OUTPUT  {UART_RX_WR = PINSTATE_LOW; UART_RX_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define UART_RX_INIT_INPUT   {UART_RX_WR = PINSTATE_HIGH; UART_RX_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define UART_TX_TRIS    TRISCbits.TRISC14 // GPIO direction register bit
	#define UART_TX_WR      LATCbits.LATC14 // GPIO port latch register bit
	#define UART_TX_RD      PORTCbits.RC14 // GPIO port register bit
	#define UART_TX_ODC     ODCCbits.ODCC14 // GPIO port open drain configuration register bit
	#define UART_TX_CNPU    CNPUCbits.CNPUC14 // GPIO port pull-up resistor register bit
	#define UART_TX_CNPD    CNPDCbits.CNPDC14 // GPIO port pull-down resistor register bit
	#define UART_TX_CNEN0   CNEN0Cbits.CNEN0C14 // GPIO port change notification Enable register bit
	#define UART_TX_CNSTAT  CNSTATCbits.CNSTATC14 // GPIO port change notification Status register bit
	#define UART_TX_CNEN1   CNEN1Cbits.CNEN1C14 // GPIO port change notification Edge Select Enable register bit
	#define UART_TX_CNF     CNFCbits.CNFC14 // GPIO port change notification flag bit register bit
	#define UART_TX_RP      62 // Number of Remappable Pin
	#define UART_TX_SET     { asm volatile ("bset _LATC, #14 \n"); }
	#define UART_TX_CLEAR   { asm volatile ("bclr _LATC, #14 \n"); }
	#define UART_TX_TOGGLE  { asm volatile ("btg  _LATC, #14 \n"); }
	#define UART_TX_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define UART_TX_INIT_OUTPUT  {UART_TX_WR = PINSTATE_LOW; UART_TX_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define UART_TX_INIT_INPUT   {UART_TX_WR = PINSTATE_HIGH; UART_TX_TRIS = PINDIR_INPUT;} // initialization macro for digital input

#elif defined (__P33SMPS_CH_SLV1__)

	#define TP45_TRIS    TRISCbits.TRISC10 // GPIO direction register bit
	#define TP45_WR      LATCbits.LATC10 // GPIO port latch register bit
	#define TP45_RD      PORTCbits.RC10 // GPIO port register bit
	#define TP45_ODC     ODCCbits.ODCC10 // GPIO port open drain configuration register bit
	#define TP45_CNPU    CNPUCbits.CNPUC10 // GPIO port pull-up resistor register bit
	#define TP45_CNPD    CNPDCbits.CNPDC10 // GPIO port pull-down resistor register bit
	#define TP45_CNEN0   CNEN0Cbits.CNEN0C10 // GPIO port change notification Enable register bit
	#define TP45_CNSTAT  CNSTATCbits.CNSTATC10 // GPIO port change notification Status register bit
	#define TP45_CNEN1   CNEN1Cbits.CNEN1C10 // GPIO port change notification Edge Select Enable register bit
	#define TP45_CNF     CNFCbits.CNFC10 // GPIO port change notification flag bit register bit
	#define TP45_RP      58 // Number of Remappable Pin
	#define TP45_SET     { asm volatile ("bset _LATC, #10 \n"); }
	#define TP45_CLEAR   { asm volatile ("bclr _LATC, #10 \n"); }
	#define TP45_TOGGLE  { asm volatile ("btg  _LATC, #10 \n"); }
	#define TP45_CHANNEL   1
	#define TP45_PGxPER    PG1PER
	#define TP45_PGxPHASE  PG1PHASE
	#define TP45_PGxDC     PG1DC
	#define TP45_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP45_INIT_OUTPUT  {TP45_WR = PINSTATE_LOW; TP45_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP45_INIT_INPUT   {TP45_WR = PINSTATE_HIGH; TP45_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define TP47_TRIS    TRISCbits.TRISC11 // GPIO direction register bit
	#define TP47_WR      LATCbits.LATC11 // GPIO port latch register bit
	#define TP47_RD      PORTCbits.RC11 // GPIO port register bit
	#define TP47_ODC     ODCCbits.ODCC11 // GPIO port open drain configuration register bit
	#define TP47_CNPU    CNPUCbits.CNPUC11 // GPIO port pull-up resistor register bit
	#define TP47_CNPD    CNPDCbits.CNPDC11 // GPIO port pull-down resistor register bit
	#define TP47_CNEN0   CNEN0Cbits.CNEN0C11 // GPIO port change notification Enable register bit
	#define TP47_CNSTAT  CNSTATCbits.CNSTATC11 // GPIO port change notification Status register bit
	#define TP47_CNEN1   CNEN1Cbits.CNEN1C11 // GPIO port change notification Edge Select Enable register bit
	#define TP47_CNF     CNFCbits.CNFC11 // GPIO port change notification flag bit register bit
	#define TP47_RP      59 // Number of Remappable Pin
	#define TP47_SET     { asm volatile ("bset _LATC, #11 \n"); }
	#define TP47_CLEAR   { asm volatile ("bclr _LATC, #11 \n"); }
	#define TP47_TOGGLE  { asm volatile ("btg  _LATC, #11 \n"); }
	#define TP47_CHANNEL   1
	#define TP47_PGxPER    PG1PER
	#define TP47_PGxPHASE  PG1PHASE
	#define TP47_PGxDC     PG1DC
	#define TP47_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define TP47_INIT_OUTPUT  {TP47_WR = PINSTATE_LOW; TP47_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define TP47_INIT_INPUT   {TP47_WR = PINSTATE_HIGH; TP47_TRIS = PINDIR_INPUT;} // initialization macro for digital input

#endif


#endif	/* _10889_R10_MP506_PINMAP_H */

