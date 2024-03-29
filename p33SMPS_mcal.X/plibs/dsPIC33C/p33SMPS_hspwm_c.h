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

#ifndef _P33SMPS_SMPS_PWM_H_
#define _P33SMPS_SMPS_PWM_H_

#include <stdint.h>
#include <stdbool.h>

#include "../p33SMPS_devices.h"

/*@@p33MP_hspwm.h
 * ************************************************************************************************
 * Summary:
 * Header file with additional defines for the dsPIC33CH/CKxxMP-PWM SFRs
 *
 * Description:
 * The SMPS PWM module offers a large number of registers and configuration options. This additional
 * header file contains defines for all required settings. This additional
 * header file contains defines for all required bit-settings of all related registers.
 * This file is an additional header file on top of the generic device header file.
 * ***********************************************************************************************/


/*

typedef struct {
    volatile uint16_t PCLKCON;  // PWM CLOCK CONTROL REGISTER
    volatile uint16_t FSCL; // FREQUENCY SCALE REGISTER
    volatile uint16_t FSMINPER; // FREQUENCY SCALING MINIMUM PERIOD REGISTER
    volatile uint16_t MPHASE; // MASTER PHASE REGISTER
    volatile uint16_t MDC; // MASTER DUTY CYCLE REGISTER
    volatile uint16_t MPER; // MASTER PERIOD REGISTER
    volatile uint16_t CMBTRIGL; // COMBINATIONAL TRIGGER REGISTER LOW
    volatile uint16_t CMBTRIGH; // COMBINATIONAL TRIGGER REGISTER HIGH
    volatile uint16_t LOGCONy; // COMBINATORIAL PWM LOGIC CONTROL REGISTER y
    volatile uint16_t PWMEVTy; // PWM EVENT OUTPUT CONTROL REGISTER y
    volatile uint16_t LFSR; // LINEAR FEEDBACK SHIFT REGISTER
    
}HSPWM_C_TYPE_GENERIC_REGISTERS_t;

 */

#define PWM_OVERRIDE_ENABLE     1
#define PWM_OVERRIDE_DISABLE    0

/* ===========================================================================
 * PGxCONL/H: PWM GENERATOR x CONTROL REGISTER LOW/HIGH
 * ===========================================================================*/
#define REG_PCLKCON_VALID_DATA_WRITE_MASK 0xC133
#define REG_PCLKCON_VALID_DATA_READ_MASK  0xC133

#define REG_PCLKCON_MCLKSEL_AFPLLO     0b0000000000000011
#define REG_PCLKCON_MCLKSEL_FPLLO      0b0000000000000010
#define REG_PCLKCON_MCLKSEL_AFVCO_BY_2 0b0000000000000001
#define REG_PCLKCON_MCLKSEL_FOSC       0b0000000000000000

typedef enum {
    PCLKCON_MCLKSEL_AFPLLO = 0b11, // AFPLLO ? Auxiliary PLL post-divider output
    PCLKCON_MCLKSEL_FPLLO = 0b10, // FPLLO ? Primary PLL post-divider output
    PCLKCON_MCLKSEL_AFVCO_BY_2 = 0b01, // AFVCO/2 ? Auxiliary VCO/2
    PCLKCON_MCLKSEL_FOSC = 0b00 // FOSC
} PCLKCON_MCLKSEL_e; // PWM Master Clock Selection bits

#define REG_PCLKCON_DIVSEL_DIV_16 0b0000000000110000
#define REG_PCLKCON_DIVSEL_DIV_8  0b0000000000100000
#define REG_PCLKCON_DIVSEL_DIV_4  0b0000000000010000
#define REG_PCLKCON_DIVSEL_DIV_2  0b0000000000000000

typedef enum {
    PCLKCON_DIVSEL_DIV_16 = 0b11, // Divide ratio is 1:16
    PCLKCON_DIVSEL_DIV_8 = 0b10, // Divide ratio is 1:8
    PCLKCON_DIVSEL_DIV_4 = 0b01, // Divide ratio is 1:4
    PCLKCON_DIVSEL_DIV_2 = 0b00 // Divide ratio is 1:2
} PCLKCON_DIVSEL_e; // PWM Clock Divider Selection bits

#define REG_PCLKCON_LOCK_LOCKED   0b0000000100000000
#define REG_PCLKCON_LOCK_UNLOCKED 0b0000000000000000

typedef enum {
    PCLKCON_LOCK_LOCKED = 0b1, // Write-protected registers and bits are locked
    PCLKCON_LOCK_UNLOCKED = 0b0 // Write-protected registers and bits are unlocked
} PCLKCON_LOCK_e; // Register write-protection lock bit

#define REG_PCLKCON_HRERR_ERROR      0b0100000000000000
#define REG_PCLKCON_HRERR_NO_ERROR   0b0000000000000000

typedef enum {
    PCLKCON_HRERR_ERROR = 0b1, // An error has occurred; PWM signals will have limited resolution
    PCLKCON_HRERR_NO_ERROR = 0b0 // No error has occurred; PWM signals will have full resolution when HRRDY = 1
} PCLKCON_HRERR_e; // High-Resolution Error bit

#define REG_PCLKCON_HRRDY_READY  0b1000000000000000
#define REG_PCLKCON_HRRDY_WAIT   0b0000000000000000

typedef enum {
    PCLKCON_HRRDY_READY = 0b1, // The high-resolution circuitry is ready
    PCLKCON_HRRDY_WAIT = 0b0 // The high-resolution circuitry is not ready
} PCLKCON_HRRDY_e; // High-Resolution Ready bit

typedef struct {
    volatile PCLKCON_MCLKSEL_e MCLKSEL : 2; // PWM Master Clock Selection bits
    volatile unsigned : 2;
    volatile PCLKCON_DIVSEL_e DIVSEL : 2; // PWM Clock Divider Selection bits
    volatile unsigned : 2;
    volatile PCLKCON_LOCK_e LOCK : 1; // Register write protection Lock bit
    volatile unsigned : 5;
    volatile PCLKCON_HRERR_e HRERR : 1; // High-Resolution Error bit
    volatile PCLKCON_HRRDY_e HRRDY : 1; // High-Resolution Ready bit
} __attribute__((packed)) PCLKCON_t; // PWM CLOCK CONTROL REGISTER

typedef union {
    volatile uint16_t value; // 16-bit register direct write access
    volatile PCLKCON_t PCLKCON; // PWM CLOCK CONTROL REGISTER
} REGBLK_PCLK_CONFIG_t; // PWM CLOCK CONTROL REGISTER


/* ===========================================================================
 * PGxCONL/H: PWM GENERATOR x CONTROL REGISTER LOW/HIGH
 * ===========================================================================*/
#define REG_PGxCON_VALID_DATA_WRITE_MASK 0xEF4F879F
#define REG_PGxCON_VALID_DATA_READ_MASK  0xEF4F879F

#define REG_PGCON_MODSEL_DUAL_EDGE_CAM_DUAL_UPDT    0b0000000000000111
#define REG_PGCON_MODSEL_DUAL_EDGE_CAM_SNG_UPDT     0b0000000000000110
#define REG_PGCON_MODSEL_DBL_UPDATE_CAM             0b0000000000000101
#define REG_PGCON_MODSEL_CENTER_ALIGNED             0b0000000000000100
#define REG_PGCON_MODSEL_INDEPENDENT_EDGE_DUAL_OUT  0b0000000000000010
#define REG_PGCON_MODSEL_VARIABLE_PHASE             0b0000000000000001
#define REG_PGCON_MODSEL_INDEPENDENT_EDGE           0b0000000000000000

typedef enum {
    PGCON_MODSEL_DUAL_EDGE_CAM_DUAL_UPDT = 0b111, // Dual Edge Center-Aligned PWM mode (interrupt/register update twice per cycle)
    PGCON_MODSEL_DUAL_EDGE_CAM_SNG_UPDT = 0b110, // Dual Edge Center-Aligned PWM mode (interrupt/register update once per cycle)
    PGCON_MODSEL_DBL_UPDATE_CAM = 0b101, // Double-Update Center-Aligned PWM mode
    PGCON_MODSEL_CENTER_ALIGNED = 0b100, // Center-Aligned PWM mode
    PGCON_MODSEL_INDEPENDENT_EDGE_DUAL_OUT = 0b010, // Independent Edge PWM mode, dual output
    PGCON_MODSEL_VARIABLE_PHASE = 0b001, // Variable Phase PWM mode
    PGCON_MODSEL_INDEPENDENT_EDGE = 0b000 // Independent Edge PWM mode
} PGCON_MODSEL_e; // Mode Selection bits

#define REG_PGCON_CLKSEL_MSTR_FSCALE   0b0000000000011000
#define REG_PGCON_CLKSEL_MSTR_CLKDIV   0b0000000000010000
#define REG_PGCON_CLKSEL_BY_MCLKSEL    0b0000000000001000
#define REG_PGCON_CLKSEL_NONE          0b0000000000000000

typedef enum {
    PGCON_CLKSEL_MSTR_FSCALE = 0b11, // PWM Generator uses Master clock scaled by frequency scaling circuit
    PGCON_CLKSEL_MSTR_CLKDIV = 0b10, // PWM Generator uses Master clock divided by clock divider circuit
    PGCON_CLKSEL_BY_MCLKSEL = 0b01, // PWM Generator uses Master clock selected by the MCLKSEL<1:0> (PCLKCON<1:0>) control bits
    PGCON_CLKSEL_NONE = 0b00 // No clock selected, PWM Generator is in lowest power state (default)
} PGCON_CLKSEL_e; // Clock Selection bits


#define REG_PGCON_HREN_HIGH_RES   0b0000000010000000
#define REG_PGCON_HREN_STANDARD   0b0000000000000000

typedef enum {
    PGCON_HREN_HIGH_RES = 0b1, // PWM Generator x operates in High-Resolution mode
    PGCON_HREN_STANDARD = 0b0 // PWM Generator x operates in standard resolution
} PGCON_HREN_e; // PWM Generator x High-Resolution Enable bit

#define REG_PGCON_TRGCNT_8_PWM_CYCLES    0b0000011100000000
#define REG_PGCON_TRGCNT_7_PWM_CYCLES    0b0000011000000000
#define REG_PGCON_TRGCNT_6_PWM_CYCLES    0b0000010100000000
#define REG_PGCON_TRGCNT_5_PWM_CYCLES    0b0000010000000000
#define REG_PGCON_TRGCNT_4_PWM_CYCLES    0b0000001100000000
#define REG_PGCON_TRGCNT_3_PWM_CYCLES    0b0000001000000000
#define REG_PGCON_TRGCNT_2_PWM_CYCLES    0b0000000100000000
#define REG_PGCON_TRGCNT_1_PWM_CYCLES    0b0000000000000000

typedef enum {
    PGCON_TRGCNT_8_PWM_CYCLES = 0b111, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_7_PWM_CYCLES = 0b110, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_6_PWM_CYCLES = 0b101, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_5_PWM_CYCLES = 0b100, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_4_PWM_CYCLES = 0b011, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_3_PWM_CYCLES = 0b010, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_2_PWM_CYCLES = 0b001, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_1_PWM_CYCLES = 0b000 // PWM Generator produces 8 PWM cycles after triggered
} PGCON_TRGCNT_e; // Trigger Count Select bits


#define REG_PGCON_ON_PWM_ENABLED     0b1000000000000000
#define REG_PGCON_ON_PWM_DISABLED    0b0000000000000000
#define REG_PGCON_ON_PWM_RESET       0b0111111111111111

typedef enum {
    PGCON_ON_PWM_ENABLED = 0b1, // PWM Generator is enabled
    PGCON_ON_PWM_DISABLED = 0b0 // PWM Generator is disabled
} PGCON_ON_e; // PWM module enable bit


#define REG_PGCON_SOCS_TRG_PCISYNC  0b0000000000001111
#define REG_PGCON_SOCS_PWM4_8       0b0000000000000100
#define REG_PGCON_SOCS_PWM3_7       0b0000000000000011
#define REG_PGCON_SOCS_PWM2_6       0b0000000000000010
#define REG_PGCON_SOCS_PWM1_5       0b0000000000000001
#define REG_PGCON_SOCS_LOCAL_EOC    0b0000000000000000

typedef enum {
    PGCON_SOCS_TRG_PCISYNC = 0b1111, // TRIG bit or PCI Sync function only (no hardware trigger source is selected)
    PGCON_SOCS_PWM4_8 = 0b0100, // PWM4(8) PG1 or PG5 trigger output selected by PGTRGSEL<2:0> (PGxEVT<2:0>)
    PGCON_SOCS_PWM3_7 = 0b0011, // PWM3(7) PG1 or PG5 trigger output selected by PGTRGSEL<2:0> (PGxEVT<2:0>)
    PGCON_SOCS_PWM2_6 = 0b0010, // PWM2(6) PG1 or PG5 trigger output selected by PGTRGSEL<2:0> (PGxEVT<2:0>)
    PGCON_SOCS_PWM1_5 = 0b0001, // PWM1(5) PG1 or PG5 trigger output selected by PGTRGSEL<2:0> (PGxEVT<2:0>)
    PGCON_SOCS_LOCAL_EOC = 0b0000 // Local EOC ? PWM Generator is self-triggered
} PGCON_SOCS_e; // Start-of-Cycle Selection bits

#define REG_PGCON_TRGMOD_REPEAT     0b0000000001000000
#define REG_PGCON_TRGMOD_SINGLE     0b0000000000000000

typedef enum {
    PGCON_TRGMOD_REPEAT = 0b1, // PWM Generator operates in Retriggerable mode
    PGCON_TRGMOD_SINGLE = 0b0 // PWM Generator operates in Single Trigger mode
} PGCON_TRGMOD_e; // PWM Generator Trigger Mode Selection bit

#define REG_PGCON_UPDMOD_SLV_IMMEDIATE  0b0000001100000000
#define REG_PGCON_UPDMOD_SLV_SOC        0b0000001000000000
#define REG_PGCON_UPDMOD_IMMEDIATE      0b0000000100000000
#define REG_PGCON_UPDMOD_SOC            0b0000000000000000

typedef enum {
    PGCON_UPDMOD_SLV_IMMEDIATE = 0b011, // Slaved immediate update when MSTEN = 1 and UPDATE = 1
    PGCON_UPDMOD_SLV_SOC = 0b010, // Slaved SOC update at start of next PWM cycle when MSTEN = 1 and UPDATE = 1
    PGCON_UPDMOD_IMMEDIATE = 0b001, // Immediate update when UPDATE = 1
    PGCON_UPDMOD_SOC = 0b000 // SOC update at start of next PWM cycle
} PGCON_UPDMOD_e; // PWM Buffer Update Mode Selection bits

#define REG_PGCON_MSTEN_MASTER          0b0000100000000000
#define REG_PGCON_MSTEN_NO_BROADCAST    0b0000000000000000

typedef enum {
    PGCON_MSTEN_BROADCAST = 0b1, // PWM Generator broadcasts software set/clear of the UPDATE status bit and EOC signal to other PWM Generators
    PGCON_MSTEN_NO_BROADCAST = 0b0 // PWM Generator does not broadcast the UPDATE status bit state or EOC signal
} PGCON_MSTEN_e; // Master Update Enable bit

#define REG_PGCON_MPHSEL_MASTER          0b0010000000000000
#define REG_PGCON_MPHSEL_INDEPENDENT     0b0000000000000000

typedef enum {
    PGCON_MPHSEL_MASTER = 0b1, // PWM Generator uses the MPHASE register instead of PGxPHASE
    PGCON_MPHSEL_INDEPENDENT = 0b0 // PWM Generator uses the PGxPHASE register
} PGCON_MPHSEL_e; // Master Phase Register Select bit

#define REG_PGCON_MPERSEL_MASTER         0b0100000000000000
#define REG_PGCON_MPERSEL_INDEPENDENT    0b0000000000000000

typedef enum {
    PGCON_MPERSEL_MASTER = 0b1, // PWM Generator uses the MPER register instead of PGxPER
    PGCON_MPERSEL_INDEPENDENT = 0b0 // PWM Generator uses the PGxPER register
} PGCON_MPERSEL_e; // Master Period Register Select bit

#define REG_PGCON_MDCSEL_MASTER         0b1000000000000000
#define REG_PGCON_MDCSEL_INDEPENDENT    0b0000000000000000

typedef enum {
    PGCON_MDCSEL_MASTER = 0b1, // PWM Generator uses the MDC register instead of PGxDC
    PGCON_MDCSEL_INDEPENDENT = 0b0 // PWM Generator uses the PGxDC register
} PGCON_MDCSEL_e; // Master Duty Cycle Register Select bit

typedef struct {
    volatile PGCON_MODSEL_e MODSEL : 3; // Mode Selection bits
    volatile PGCON_CLKSEL_e CLKSEL : 2; // Clock Selection bits
    volatile unsigned : 2; // reserved
    volatile PGCON_HREN_e HREN : 1; // PWM Generator x High-Resolution Enable bit
    volatile PGCON_TRGCNT_e TRGCNT : 3; // Trigger Count Select bits
    volatile unsigned : 4; // reserved
    volatile PGCON_ON_e ON : 1; // PWM module enable bit

    volatile PGCON_SOCS_e SOCS : 4; // Start-of-Cycle Selection bits
    volatile unsigned : 2; // reserved
    volatile PGCON_TRGMOD_e TRGMOD : 2; // PWM Generator Trigger Mode Selection bit
    volatile PGCON_UPDMOD_e UPDMOD : 3; // PWM Buffer Update Mode Selection bits
    volatile PGCON_MSTEN_e MSTEN : 1; // Master Update Enable bit
    volatile unsigned : 1; // reserved
    volatile PGCON_MPHSEL_e MPHSEL : 1; // Master Phase Register Select bit
    volatile PGCON_MPERSEL_e MPERSEL : 1; // Master Period Register Select bit
    volatile PGCON_MDCSEL_e MDCSEL : 1; // Master Duty Cycle Register Select bit

} __attribute__((packed)) PGxCON_t;

typedef union {
    volatile uint32_t value;
    volatile PGxCON_t PGxCON;
} REGBLK_PGxCH_CONFIG_t;


/* ===========================================================================
 * PGxSTAT: PWM GENERATOR x STATUS REGISTER
 * ===========================================================================*/
#define REG_PGxSTAT_VALID_DATA_WRITE_MASK  0xF0E8
#define REG_PGxSTAT_VALID_DATA_READ_MASK   0xFF37
#define REG_PGxSTAT_VALID_DATA_RESET_MASK  0x0F17


#define REG_PGSTAT_TRIG_ACTIVE   0b0000000000000001
#define REG_PGSTAT_TRIG_NONE     0b0000000000000000

typedef enum {
    PGSTAT_TRIG_ACTIVE = 0b1, // PWM Generator is triggered and PWM cycle is in progress
    PGSTAT_TRIG_NONE = 0b0 // No PWM cycle is in progress
}PGSTAT_TRIG_t;     // PWM Trigger Status bit

#define REG_PGSTAT_CAHALF_2ND_CYCLE   0b0000000000000010
#define REG_PGSTAT_CAHALF_1ST_CYCLE   0b0000000000000000

typedef enum {
    PGSTAT_CAHALF_2ND_CYCLE = 0b1, // PWM Generator is in 2nd half of time base cycle
    PGSTAT_CAHALF_1ST_CYCLE = 0b0 // PWM Generator is in 1st half of time base cycle
}PGSTAT_CAHALF_t;     // Half Cycle Status bit (Center-Aligned modes only)

#define REG_PGSTAT_STEER_2ND_CYCLE    0b0000000000000100
#define REG_PGSTAT_STEER_1ST_CYCLE    0b0000000000000000

typedef enum {
    PGSTAT_STEER_2ND_CYCLE = 0b1, // PWM Generator is in 2nd cycle of Push-Pull mode
    PGSTAT_STEER_1ST_CYCLE = 0b0 // PWM Generator is in 1st cycle of Push-Pull mode
}PGSTAT_STEER_t;     // Output Steering Status bit (Push-Pull Output mode only)

#define REG_PGSTAT_UPDREQ_GO      0b0000000000001000
#define REG_PGSTAT_UPDREQ_STOP    0b0000000000000000

typedef enum {
    PGSTAT_UPDREQ_GO = 0b1, // User software writes a ?1? to this bit location to request a PWM Data register update
    PGSTAT_UPDREQ_STOP = 0b0 // The bit location always reads as ?0?. The UPDATE status bit will indicate ?1? when an update is pending.
}PGSTAT_UPDREQ_t;     // PWM Data Register Update Request bit

#define REG_PGSTAT_UPDATE_PENDING   0b0000000000010000
#define REG_PGSTAT_UPDATE_COMPLETE  0b0000000000000000

typedef enum {
    PGSTAT_UPDATE_GO = 0b1, // PWM Data register update is pending ? user Data registers are not writable
    PGSTAT_UPDATE_COMPLETE = 0b0 // No PWM Data register update is pending
}PGSTAT_UPDATE_t;     // PWM Data Register Update Status/Control bit

#define REG_PGSTAT_CAP_DATA_AVAILABLE 0b0000000000100000
#define REG_PGSTAT_CAP_NO_DATA        0b0000000000000000

typedef enum {
    PGSTAT_CAP_DATA_AVAILABLE = 0b1, // PWM Generator time base value has been captured in PGxCAP
    PGSTAT_CAP_NO_DATA = 0b0 // No capture has occurred
}PGSTAT_CAP_t;     // PWM time base capture status bit

#define REG_PGSTAT_TRSET_GO        0b0000000010000000
#define REG_PGSTAT_TRSET_STOP      0b0000000001000000
#define REG_PGSTAT_TRSET_NONE      0b0000000000000000

typedef enum {
    PGSTAT_TRSET_GO = 0b10, // User software writes a ?1? to this bit location to trigger a PWM Generator cycle 
    PGSTAT_TRSET_STOP = 0b01, // User software writes a ?1? to this bit location to stop a PWM Generator cycle 
    PGSTAT_TRSET_NONE = 0b00 // The bit location always reads as ?0?. The TRIG bit will indicate ?1? when the PWM Generator is triggered and ?0? when the PWM Generator is not triggered
}PGSTAT_TRSET_t;     // PWM Generator Software Trigger Set/Clear control bits

#define REG_PGSTAT_FFACT_ACTIVE    0b0000000100000000
#define REG_PGSTAT_FFACT_INACTIVE  0b0000000000000000

typedef enum {
    PGSTAT_FFACT_ACTIVE = 0b1, // PCI feed-forward output is active
    PGSTAT_FFACT_INACTIVE = 0b0 // PCI feed-forward output is inactive
}PGSTAT_FFACT_t;     // PCI feed-forward Status bit

#define REG_PGSTAT_CLACT_ACTIVE    0b0000001000000000
#define REG_PGSTAT_CLACT_INACTIVE  0b0000000000000000

typedef enum {
    PGSTAT_CLACT_ACTIVE = 0b1, // PCI current-limit output is active
    PGSTAT_CLACT_INACTIVE = 0b0 // PCI current-limit output is inactive
}PGSTAT_CLACT_t;     // PCI current-limit Status bit

#define REG_PGSTAT_FLTACT_ACTIVE    0b0000010000000000
#define REG_PGSTAT_FLTACT_INACTIVE  0b0000000000000000

typedef enum {
    PGSTAT_FLTACT_ACTIVE = 0b1, // PCI Fault output is active
    PGSTAT_FLTACT_INACTIVE = 0b0 // PCI Fault output is inactive
}PGSTAT_FLTACT_t;     // PCI Fault Status bit

#define REG_PGSTAT_SACT_ACTIVE    0b0000100000000000
#define REG_PGSTAT_SACT_INACTIVE  0b0000000000000000

typedef enum {
    PGSTAT_SACT_ACTIVE = 0b1, // PCI Sync output is active
    PGSTAT_SACT_INACTIVE = 0b0 // PCI Sync output is inactive
}PGSTAT_SACT_t;     // PCI Sync Status bit

#define REG_PGSTAT_FFEVT_ACTIVE   0b0001000000000000
#define REG_PGSTAT_FFEVT_NONE     0b0000000000000000

typedef enum {
    PGSTAT_FFEVT_ACTIVE = 0b1, // A PCI feed-forward event has occurred (rising edge on PCI feed-forward output or PCI feed-forward output is high when module is enabled)
    PGSTAT_FFEVT_NONE = 0b0 // No PCI feed-forward event has occurred
}PGSTAT_FFEVT_t;     // PCI Feed-Forward Active Status bit

#define REG_PGSTAT_CLEVT_ACTIVE   0b0010000000000000
#define REG_PGSTAT_CLEVT_NONE     0b0000000000000000

typedef enum {
    PGSTAT_CLEVT_ACTIVE = 0b1, // A PCI current-limit event has occurred (rising edge on PCI current-limit output or PCI current-limit output is high when module is enabled)
    PGSTAT_CLEVT_NONE = 0b0 // No PCI current-limit event has occurred
}PGSTAT_CLEVT_t;     // PCI Current-Limit Status bit

#define REG_PGSTAT_FLTEVT_ACTIVE  0b0100000000000000
#define REG_PGSTAT_FLTEVT_NONE    0b0000000000000000

typedef enum {
    PGSTAT_FLTEVT_ACTIVE = 0b1, // A PCI Fault event has occurred (rising edge on PCI Fault output or PCI Fault output is high when module is enabled)
    PGSTAT_FLTEVT_NONE = 0b0 // No PCI Fault event has occurred
}PGSTAT_FLTEVT_t;     // PCI Fault Active Status bit

#define REG_PGSTAT_SEVT_ACTIVE  0b1000000000000000
#define REG_PGSTAT_SEVT_NONE    0b0000000000000000

typedef enum {
    PGSTAT_SEVT_ACTIVE = 0b1, // A PCI Sync event has occurred (rising edge on PCI Sync output or PCI Sync output is high when module is enabled)
    PGSTAT_SEVT_NONE = 0b0 // No PCI Sync event has occurred
}PGSTAT_SEVT_t;     // PCI Sync Event bit

typedef struct {

    volatile PGSTAT_TRIG_t TRIG : 1; // PWM trigger status bit
    volatile PGSTAT_CAHALF_t CAHALF : 1; // Half Cycle Status bit (Center-Aligned modes only)
    volatile PGSTAT_STEER_t STEER : 1; // Output Steering Status bit (Push-Pull Output mode only)
    volatile PGSTAT_UPDREQ_t UPDREQ : 1; // PWM Data Register Update Request bit
    volatile PGSTAT_UPDATE_t UPDATE : 1; // PWM Data Register Update Status/Control bit
    volatile PGSTAT_CAP_t CAP : 1; // PWM time base capture status bit
    volatile PGSTAT_TRSET_t TRSET : 2; // PWM Generator Software Trigger Set/Clear control bits
    
    volatile PGSTAT_FFACT_t FFACT : 1; // PCI Fault Active Status bit
    volatile PGSTAT_CLACT_t CLACT : 1; // PCI Current-Limit Status bit
    volatile PGSTAT_FLTACT_t FLTACT : 1; // PCI Fault Status bit
    volatile PGSTAT_SACT_t SACT : 1; // PCI Sync Status bit
    volatile PGSTAT_FFEVT_t FFEVT : 1; // PCI Feed-Forward Active Status bit
    volatile PGSTAT_CLEVT_t CLEVT : 1; // PCI Current-Limit Status bit
    volatile PGSTAT_FLTEVT_t FLTEVT : 1; // PCI Fault Active Status bit
    volatile PGSTAT_SEVT_t SEVT : 1; // PCI Sync Event Status bit

} __attribute__((packed)) PGxSTAT_t;


typedef union {
    volatile uint16_t value;
    volatile PGxSTAT_t PGxSTAT;
} REGBLK_PGxCH_STATUS_t;

/* ===========================================================================
 * PGxIOCONL/H: PWM GENERATOR x I/O CONTROL REGISTER LOW/HIGH
 * ===========================================================================*/
#define REG_PGxIOCON_VALID_DATA_WRITE_MASK  0x713FFFFF
#define REG_PGxIOCON_VALID_DATA_READ_MASK  0x713FFFFF


#define REG_IOCON_CLMOD_ENABLED         0b1000000000000000
#define REG_IOCON_CLMOD_DISABLED        0b0000000000000000

typedef enum {
    IOCON_CLMOD_ENABLED = 0b1, // If PCI current limit is active, then the PWMxH and PWMxL output signals are inverted (bit flipping), and the CLDAT<1:0> bits are not used
    IOCON_CLMOD_DISABLED = 0b0 // If PCI current limit is active, then the CLDAT<1:0> bits define the PWM output levels
} IOCON_CLMOD_e; // Current-Limit Mode Select bit

#define REG_IOCON_SWAP_ENABLED          0b0100000000000000
#define REG_IOCON_SWAP_DISABLED         0b0000000000000000

typedef enum {
    IOCON_SWAP_ENABLED = 0b1, // The PWMxH signal is connected to the PWMxL pin and the PWMxL signal is connected to the PWMxH pin
    IOCON_SWAP_DISABLED = 0b0 // PWMxH/L signals are mapped to their respective pins
} IOCON_SWAP_e; // Swap PWM Signals to PWMxH and PWMxL Device Pins bit

#define REG_IOCON_OSYNC_UPDMOD          0b0000001000000000
#define REG_IOCON_OSYNC_IMMEDIATE       0b0000000100000000
#define REG_IOCON_OSYNC_PWM             0b0000000000000000

#define REG_IOCON_OVREN_COMP_SET        0b0011000000000000
#define REG_IOCON_OVREN_COMP_RESET      0b1100111111111111
#define REG_IOCON_OVREN_COMP_ENABLED    0b0011000000000000
#define REG_IOCON_OVREN_COMP_DISABLED   0b0000000000000000

#define REG_IOCON_OVRENH_ENABLED        0b0010000000000000
#define REG_IOCON_OVRENH_DISABLED       0b0000000000000000
#define REG_IOCON_OVRENL_ENABLED        0b0001000000000000
#define REG_IOCON_OVRENL_DISABLED       0b0000000000000000

typedef enum {
    IOCON_OVRENx_ENABLED = 0b1, // OVRDATx provides data for output on the PWMxX pin
    IOCON_OVRENx_DISABLED = 0b0 // PWM Generator provides data for the PWMxX pin
} IOCON_OVRENx_e; // Override Enable for PWMxH/PWMxL Pin bit

typedef enum {
    IOCON_OSYNC_UPDMOD = 0b10, // User output overrides via the OVRENH/L and OVRDAT<1:0> bits occur when specified by the UPDMOD<2:0> bits in the PGxCONH register
    IOCON_OSYNC_IMMEDIATE = 0b01, // User output overrides via the OVRENH/L and OVRDAT<1:0> bits occur immediately (as soon as possible)
    IOCON_OSYNC_PWM = 0b00 // User output overrides via the OVRENH/L and OVRDAT<1:0> bits are synchronized to the local PWM time base (next Start-of-Cycle)
} IOCON_OSYNC_e; // User Output Override Synchronization Control bits

#define REG_IOCON_OVRDAT_HIGH_HIGH      0b0000110000000000
#define REG_IOCON_OVRDAT_HIGH_LOW       0b0000100000000000
#define REG_IOCON_OVRDAT_LOW_HIGH       0b0000010000000000
#define REG_IOCON_OVRDAT_LOW_LOW        0b0000000000000000

typedef enum {
    IOCON_OVRDAT_HIGH_HIGH = 0b11, // Override state of PWMxH=HIGH, override state of PWMxL=HIGH
    IOCON_OVRDAT_HIGH_LOW = 0b10, // Override state of PWMxH=HIGH, override state of PWMxL=LOW
    IOCON_OVRDAT_LOW_HIGH = 0b01, // Override state of PWMxH=LOW, override state of PWMxL=HIGH
    IOCON_OVRDAT_LOW_LOW = 0b00 // Override state of PWMxH=LOW, override state of PWMxL=LOW
} IOCON_OVRDAT_e; /* Data for PWMxH/PWMxL Pins if Override is Enabled bits:
                                    * If OVERENH = 1, then OVRDAT1 provides data for PWMxH
                                    * If OVERENL = 1, then OVRDAT0 provides data for PWMxL */

#define REG_IOCON_FLTDAT_HIGH_HIGH      0b0000110000000000
#define REG_IOCON_FLTDAT_HIGH_LOW       0b0000100000000000
#define REG_IOCON_FLTDAT_LOW_HIGH       0b0000010000000000
#define REG_IOCON_FLTDAT_LOW_LOW        0b0000000000000000

typedef enum {
    IOCON_FLTDAT_HIGH_HIGH = 0b11, // Fault state of PWMxH=HIGH, Fault state of PWMxL=HIGH
    IOCON_FLTDAT_HIGH_LOW = 0b10, // Fault state of PWMxH=HIGH, Fault state of PWMxL=LOW
    IOCON_FLTDAT_LOW_HIGH = 0b01, // Fault state of PWMxH=LOW, Fault state of PWMxL=HIGH
    IOCON_FLTDAT_LOW_LOW = 0b00 // Fault state of PWMxH=LOW, Fault state of PWMxL=LOW
} IOCON_FLTDAT_e; /* Data for PWMxH/PWMxL Pins if Fault Event is Active bits:
                                    * If Fault is active, then FLTDAT1 provides data for PWMxH  
                                    * If Fault is active, then FLTDAT0 provides data for PWMxL */

#define REG_IOCON_CLDAT_HIGH_HIGH       0b0000110000000000
#define REG_IOCON_CLDAT_HIGH_LOW        0b0000100000000000
#define REG_IOCON_CLDAT_LOW_HIGH        0b0000010000000000
#define REG_IOCON_CLDAT_LOW_LOW         0b0000000000000000

typedef enum {
    IOCON_CLDAT_HIGH_HIGH = 0b11, // Current limit state of PWMxH=HIGH, Current limit state of PWMxL=HIGH
    IOCON_CLDAT_HIGH_LOW = 0b10, // Current limit state of PWMxH=HIGH, Current limit state of PWMxL=LOW
    IOCON_CLDAT_LOW_HIGH = 0b01, // Current limit state of PWMxH=LOW, Current limit state of PWMxL=HIGH
    IOCON_CLDAT_LOW_LOW = 0b00 // Current limit state of PWMxH=LOW, Current limit state of PWMxL=LOW
} IOCON_CLDAT_e; /* Data for PWMxH/PWMxL Pins if Current-Limit Event is Active bits:
                                    * If current limit is active, then CLDAT1 provides data for PWMxH  
                                    * If current limit is active, then CLDAT0 provides data for PWMxL */

#define REG_IOCON_FFDAT_HIGH_HIGH       0b0000110000000000
#define REG_IOCON_FFDAT_HIGH_LOW        0b0000100000000000
#define REG_IOCON_FFDAT_LOW_HIGH        0b0000010000000000
#define REG_IOCON_FFDAT_LOW_LOW         0b0000000000000000

typedef enum {
    IOCON_FFDAT_HIGH_HIGH = 0b11, // Feed-forward state of PWMxH=HIGH, Feed-forward state of PWMxL=HIGH
    IOCON_FFDAT_HIGH_LOW = 0b10, // Feed-forward state of PWMxH=HIGH, Feed-forward state of PWMxL=LOW
    IOCON_FFDAT_LOW_HIGH = 0b01, // Feed-forward state of PWMxH=LOW, Feed-forward state of PWMxL=HIGH
    IOCON_FFDAT_LOW_LOW = 0b00 // Feed-forward state of PWMxH=LOW, Feed-forward state of PWMxL=LOW
} IOCON_FFDAT_e; /* Data for PWMxH/PWMxL Pins if Feed-Forward Event is Active bits
                                    * If feed-forward is active, then FFDAT1 provides data for PWMxH
                                    * If feed-forward is active, then FFDAT0 provides data for PWMxL. */

#define REG_IOCON_DBDAT_HIGH_HIGH       0b0000110000000000
#define REG_IOCON_DBDAT_HIGH_LOW        0b0000100000000000
#define REG_IOCON_DBDAT_LOW_HIGH        0b0000010000000000
#define REG_IOCON_DBDAT_LOW_LOW         0b0000000000000000

typedef enum {
    IOCON_DBDAT_HIGH_HIGH = 0b11, // Debug mode state of PWMxH=HIGH, Debug mode state of PWMxL=HIGH
    IOCON_DBDAT_HIGH_LOW = 0b10, // Debug mode state of PWMxH=HIGH, Debug mode state of PWMxL=LOW
    IOCON_DBDAT_LOW_HIGH = 0b01, // Debug mode state of PWMxH=LOW, Debug mode state of PWMxL=HIGH
    IOCON_DBDAT_LOW_LOW = 0b00 // Debug mode state of PWMxH=LOW, Debug mode state of PWMxL=LOW
} IOCON_DBDAT_e; /* Data for PWMxH/PWMxL Pins if Debug Mode is Active and PTFRZ = 1 bits
                                    * If Debug mode is active and PTFRZ = 1, then DBDAT1 provides data for PWMxH
                                    * If Debug mode is active and PTFRZ = 1, then DBDAT0 provides data for PWMxL */

#define REG_IOCON_POLH_ACTIVE_HIGH  0b0000000000000000
#define REG_IOCON_POLH_ACTIVE_LOW   0b0000000000000010
#define REG_IOCON_POLL_ACTIVE_HIGH  0b0000000000000000
#define REG_IOCON_POLL_ACTIVE_LOW   0b0000000000000001

typedef enum {
    IOCON_POLx_ACTIVE_HIGH = 0b0, // Output pin is active-high
    IOCON_POLx_ACTIVE_LOW = 0b1 // Output pin is active-low
} IOCON_POLx_e; // PWMxL/PWMxH Output Polarity bit

#define REG_IOCON_PENH_PGx          0b0000000000001000
#define REG_IOCON_PENH_GPIO         0b0000000000000000
#define REG_IOCON_PENL_PGx          0b0000000000000100
#define REG_IOCON_PENL_GPIO         0b0000000000000000

typedef enum {
    IOCON_PENx_PGx = 0b1, // PWM Generator controls the PWMxL/PWMxH output pin
    IOCON_PENx_GPIO = 0b0 // PWMxX is normal GPIO
} IOCON_PENx_e; // PWMxL/PWMxH Output Port Enable bit

#define REG_IOCON_PMOD_PUSH_PULL        0b0000000000100000
#define REG_IOCON_PMOD_INDEPENDENT      0b0000000000010000
#define REG_IOCON_PMOD_COMPLEMENTARY    0b0000000000000000

typedef enum {
    IOCON_PMOD_PUSH_PULL = 0b10, // PWM Generator outputs operate in Push-Pull mode
    IOCON_PMOD_INDEPENDENT = 0b01, // PWM Generator outputs operate in Independent mode
    IOCON_PMOD_COMPLEMENTARY = 0b00 // PWM Generator outputs operate in Complementary mode
} IOCON_PMOD_e; // PWM Generator Output Mode Selection bits

#define REG_IOCON_DTCMPSEL_PCI_FEED_FORWARD   0b0000000100000000
#define REG_IOCON_DTCMPSEL_PCI_SYNC           0b0000000000000000

typedef enum {
    IOCON_DTCMPSEL_PCI_FEED_FORWARD = 0b1, // Dead-time compensation is controlled by PCI feed-forward limit logic
    IOCON_DTCMPSEL_PCI_SYNC = 0b0 // Dead-time compensation is controlled by PCI Sync logic
} IOCON_DTCMPSEL_e; // Dead-Time Compensation Select bit

#define REG_IOCON_CAPSRC_PCI_FAULT          0b0100000000000000
#define REG_IOCON_CAPSRC_PCI_CURRENT_LIMIT  0b0011000000000000
#define REG_IOCON_CAPSRC_PCI_FEED_FORWARD   0b0010000000000000
#define REG_IOCON_CAPSRC_PCI_SYNC           0b0001000000000000
#define REG_IOCON_CAPSRC_NONE               0b0000000000000000

typedef enum {
    IOCON_CAPSRC_PCI_FAULT = 0b100, // Capture time base value at assertion of selected PCI Fault signal
    IOCON_CAPSRC_PCI_CURRENT_LIMIT = 0b011, // Capture time base value at assertion of selected PCI current-limit signal
    IOCON_CAPSRC_PCI_FEED_FORWARD = 0b010, // Capture time base value at assertion of selected PCI feed-forward signal
    IOCON_CAPSRC_PCI_SYNC = 0b001, // Capture time base value at assertion of selected PCI Sync signal
    IOCON_CAPSRC_NONE = 0b000 // No hardware source selected for time base capture ? software only
} IOCON_CAPSRC_e; // Time Base Capture Source Selection bits

typedef struct {
    volatile IOCON_DBDAT_e DBDAT : 2; // Data for PWMxH/PWMxL Pins if Debug Mode is Active and PTFRZ = 1 bits
    volatile IOCON_FFDAT_e FFDAT : 2; // Data for PWMxH/PWMxL Pins if Feed-Forward Event is Active bits
    volatile IOCON_CLDAT_e CLDAT : 2; // Data for PWMxH/PWMxL Pins if Current-Limit Event is Active bits
    volatile IOCON_FLTDAT_e FLTDAT : 2; // Data for PWMxH/PWMxL Pins if Fault Event is Active bits
    volatile IOCON_OSYNC_e OSYNC : 2; // User Output Override Synchronization Control bits
    volatile IOCON_OVRDAT_e OVRDAT : 2; // Data for PWMxH/PWMxL Pins if Override is Enabled bits
    volatile IOCON_OVRENx_e OVRENL : 1; // User Override Enable for PWMxH Pin bit
    volatile IOCON_OVRENx_e OVRENH : 1; // User Override Enable for PWMxL Pin bit
    volatile IOCON_SWAP_e SWAP : 1; // Swap PWM Signals to PWMxH and PWMxL Device Pins bit
    volatile IOCON_CLMOD_e CLMOD : 1; // Current-Limit Mode Select bit

    volatile IOCON_POLx_e POLL : 1; // PWMxL Output Polarity bit
    volatile IOCON_POLx_e POLH : 1; // PWMxH Output Polarity bit
    volatile IOCON_PENx_e PENL : 1; // PWMxL Output Port Enable bit
    volatile IOCON_PENx_e PENH : 1; // PWMxH Output Port Enable bit
    volatile IOCON_PMOD_e PMOD : 2; // PWM Generator Output Mode Selection bits
    volatile unsigned : 2; // reserved
    volatile IOCON_DTCMPSEL_e DTCMPSEL : 1; // Dead-Time Compensation Select bit
    volatile unsigned : 3; // reserved
    volatile IOCON_CAPSRC_e CAPSRC : 3; // Time Base Capture Source Selection bits

} __attribute__((packed)) PGxIOCON_t;

typedef union {
    volatile uint32_t value;
    volatile PGxIOCON_t PGxIOCON;
} REGBLK_PGxIO_CONFIG_t;

/* ===========================================================================
 * PGxEVTx: PWM GENERATOR x EVENT REGISTER HIGH/LOW
 * ===========================================================================*/

#define REG_PGxEVT_VALID_DATA_WRITE_MASK  0xF3FFFF1F
#define REG_PGxEVT_VALID_DATA_READ_MASK   0xF3FFFF1F

#define REG_PGEVT_FLTIEN_ENABLED  0b1000000000000000 // Fault interrupt is enabled
#define REG_PGEVT_FLTIEN_DISABLED 0b0000000000000000 // Fault interrupt is disabled

typedef enum {
    PGEVT_FLTIEN_ENABLED  = 0b1, // Fault interrupt is enabled
    PGEVT_FLTIEN_DISABLED = 0b0  // Fault interrupt is disabled
}PGEVT_FLTIEN_e;  // PCI Fault Interrupt Enable bit

#define REG_PGEVT_CLIEN_ENABLED  0b0100000000000000 // Current-limit interrupt is enabled
#define REG_PGEVT_CLIEN_DISABLED 0b0000000000000000  // Current-limit interrupt is disabled

typedef enum {
    PGEVT_CLIEN_ENABLED  = 0b1, // Current-limit interrupt is enabled
    PGEVT_CLIEN_DISABLED = 0b0  // Current-limit interrupt is disabled
}PGEVT_CLIEN_e;  // PCI Current-limit Interrupt Enable bit

#define REG_PGEVT_FFIEN_ENABLED  0b0010000000000000 // Feed-forward interrupt is enabled
#define REG_PGEVT_FFIEN_DISABLED 0b0000000000000000  // Feed-forward interrupt is disabled

typedef enum {
    PGEVT_FFIEN_ENABLED  = 0b1, // Feed-forward interrupt is enabled
    PGEVT_FFIEN_DISABLED = 0b0  // Feed-forward interrupt is disabled
}PGEVT_FFIEN_e;  // PCI Feed-Forward Interrupt Enable bit

#define REG_PGEVT_SIEN_ENABLED  0b0001000000000000 // Sync interrupt is enabled
#define REG_PGEVT_SIEN_DISABLED 0b0000000000000000  // Sync interrupt is disabled

typedef enum {
    PGEVT_SIEN_ENABLED  = 0b1, // Sync interrupt is enabled
    PGEVT_SIEN_DISABLED = 0b0  // Sync interrupt is disabled
}PGEVT_SIEN_e;  // PCI Sync Interrupt Enable bit

#define REG_PGEVT_IEVTSEL_NONE     0b0000001100000000 // Time base interrupts are disabled (Sync, Fault, current-limit and feed-forward events can be independently enabled)
#define REG_PGEVT_IEVTSEL_ADCTR1   0b0000001000000000 // Interrupts CPU at ADC Trigger 1 event
#define REG_PGEVT_IEVTSEL_PGxTRIGA 0b0000000100000000 // Interrupts CPU at TRIGA compare event
#define REG_PGEVT_IEVTSEL_EOC      0b0000000000000000 // Interrupts CPU at EOC

typedef enum {
    PGEVT_IEVTSEL_NONE     = 0b11, // Time base interrupts are disabled (Sync, Fault, current-limit and feed-forward events can be independently enabled)
    PGEVT_IEVTSEL_ADCTR1   = 0b10, // Interrupts CPU at ADC Trigger 1 event
    PGEVT_IEVTSEL_PGxTRIGA = 0b01, // Interrupts CPU at TRIGA compare event
    PGEVT_IEVTSEL_EOC      = 0b00   // Interrupts CPU at EOC
}PGEVT_IEVTSEL_e;     // Interrupt Event Selection bits

#define REG_PGEVT_ADTR2EN3_PGxTRIGC_ENABLED  0b1 // PGxTRIGC register compare event is enabled as trigger source for ADC Trigger 2
#define REG_PGEVT_ADTR2EN3_PGxTRIGC_DISABLED 0b0 // PGxTRIGC register compare event is disabled as trigger source for ADC Trigger 2

typedef enum {
    PGEVT_ADTR2EN3_PGxTRIGC_ENABLED = 0b1, // PGxTRIGC register compare event is enabled as trigger source for ADC Trigger 2
    PGEVT_ADTR2EN3_PGxTRIGC_DISABLED = 0b0 // PGxTRIGC register compare event is disabled as trigger source for ADC Trigger 2
}PGEVT_ADTR2EN3_e;

#define REG_PGEVT_ADTR2EN2_PGxTRIGB_ENABLED  0b1 // PGxTRIGB register compare event is enabled as trigger source for ADC Trigger 2
#define REG_PGEVT_ADTR2EN2_PGxTRIGB_DISABLED 0b0 // PGxTRIGB register compare event is disabled as trigger source for ADC Trigger 2

typedef enum {
    PGEVT_ADTR2EN2_PGxTRIGB_ENABLED = 0b1, // PGxTRIGB register compare event is enabled as trigger source for ADC Trigger 2
    PGEVT_ADTR2EN2_PGxTRIGB_DISABLED = 0b0 // PGxTRIGB register compare event is disabled as trigger source for ADC Trigger 2
}PGEVT_ADTR2EN2_e;

#define REG_PGEVT_ADTR2EN1_PGxTRIGA_ENABLED 0b1 // PGxTRIGA register compare event is enabled as trigger source for ADC Trigger 2
#define REG_PGEVT_ADTR2EN1_PGxTRIGA_DISABLED 0b0 // PGxTRIGA register compare event is disabled as trigger source for ADC Trigger 2

typedef enum {
    PGEVT_ADTR2EN1_PGxTRIGA_ENABLED = 0b1, // PGxTRIGA register compare event is enabled as trigger source for ADC Trigger 2
    PGEVT_ADTR2EN1_PGxTRIGA_DISABLED = 0b0 // PGxTRIGA register compare event is disabled as trigger source for ADC Trigger 2
}PGEVT_ADTR2EN1_e;

#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_0	0b0000000000000000	//ADC trigger offset by 0 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_1	0b0000000000000001	//ADC trigger offset by 1 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_2	0b0000000000000010	//ADC trigger offset by 2 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_3	0b0000000000000011	//ADC trigger offset by 3 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_4	0b0000000000000100	//ADC trigger offset by 4 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_5	0b0000000000000101	//ADC trigger offset by 5 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_6	0b0000000000000110	//ADC trigger offset by 6 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_7	0b0000000000000111	//ADC trigger offset by 7 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_8	0b0000000000001000	//ADC trigger offset by 8 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_9	0b0000000000001001	//ADC trigger offset by 9 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_10	0b0000000000001010	//ADC trigger offset by 10 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_11	0b0000000000001011	//ADC trigger offset by 11 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_12	0b0000000000001100	//ADC trigger offset by 12 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_13	0b0000000000001101	//ADC trigger offset by 13 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_14	0b0000000000001110	//ADC trigger offset by 14 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_15	0b0000000000001111	//ADC trigger offset by 15 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_16	0b0000000000010000	//ADC trigger offset by 16 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_17	0b0000000000010001	//ADC trigger offset by 17 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_18	0b0000000000010010	//ADC trigger offset by 18 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_19	0b0000000000010011	//ADC trigger offset by 19 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_20	0b0000000000010100	//ADC trigger offset by 20 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_21	0b0000000000010101	//ADC trigger offset by 21 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_22	0b0000000000010110	//ADC trigger offset by 22 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_23	0b0000000000010111	//ADC trigger offset by 23 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_24	0b0000000000011000	//ADC trigger offset by 24 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_25	0b0000000000011001	//ADC trigger offset by 25 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_26	0b0000000000011010	//ADC trigger offset by 26 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_27	0b0000000000011011	//ADC trigger offset by 27 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_28	0b0000000000011100	//ADC trigger offset by 28 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_29	0b0000000000011101	//ADC trigger offset by 29 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_30	0b0000000000011110	//ADC trigger offset by 30 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_31	0b0000000000011111	//ADC trigger offset by 31 trigger events

typedef enum {
    PGEVT_ADTR1OFS_OFFSET_EVENTS_0	=	0b00000,	//ADC trigger offset by 0 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_1	=	0b00001,	//ADC trigger offset by 1 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_2	=	0b00010,	//ADC trigger offset by 2 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_3	=	0b00011,	//ADC trigger offset by 3 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_4	=	0b00100,	//ADC trigger offset by 4 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_5	=	0b00101,	//ADC trigger offset by 5 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_6	=	0b00110,	//ADC trigger offset by 6 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_7	=	0b00111,	//ADC trigger offset by 7 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_8	=	0b01000,	//ADC trigger offset by 8 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_9	=	0b01001,	//ADC trigger offset by 9 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_10	=	0b01010,	//ADC trigger offset by 10 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_11	=	0b01011,	//ADC trigger offset by 11 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_12	=	0b01100,	//ADC trigger offset by 12 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_13	=	0b01101,	//ADC trigger offset by 13 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_14	=	0b01110,	//ADC trigger offset by 14 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_15	=	0b01111,	//ADC trigger offset by 15 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_16	=	0b10000,	//ADC trigger offset by 16 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_17	=	0b10001,	//ADC trigger offset by 17 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_18	=	0b10010,	//ADC trigger offset by 18 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_19	=	0b10011,	//ADC trigger offset by 19 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_20	=	0b10100,	//ADC trigger offset by 20 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_21	=	0b10101,	//ADC trigger offset by 21 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_22	=	0b10110,	//ADC trigger offset by 22 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_23	=	0b10111,	//ADC trigger offset by 23 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_24	=	0b11000,	//ADC trigger offset by 24 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_25	=	0b11001,	//ADC trigger offset by 25 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_26	=	0b11010,	//ADC trigger offset by 26 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_27	=	0b11011,	//ADC trigger offset by 27 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_28	=	0b11100,	//ADC trigger offset by 28 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_29	=	0b11101,	//ADC trigger offset by 29 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_30	=	0b11110,	//ADC trigger offset by 30 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_31	=	0b11111 	//ADC trigger offset by 31 trigger events
}PGEVT_ADTR1OFS_e; // ADC Trigger 1 Offset Selection bits

#define REG_PGEVT_ADTR1PS_POSTSCALE_1   0b0000000000000000	//ADC Trigger PostScaler = 1:0
#define REG_PGEVT_ADTR1PS_POSTSCALE_2   0b0000100000000000	//ADC Trigger PostScaler = 1:1
#define REG_PGEVT_ADTR1PS_POSTSCALE_3   0b0001000000000000	//ADC Trigger PostScaler = 1:2
#define REG_PGEVT_ADTR1PS_POSTSCALE_4   0b0001100000000000	//ADC Trigger PostScaler = 1:3
#define REG_PGEVT_ADTR1PS_POSTSCALE_5   0b0010000000000000	//ADC Trigger PostScaler = 1:4
#define REG_PGEVT_ADTR1PS_POSTSCALE_6   0b0010100000000000	//ADC Trigger PostScaler = 1:5
#define REG_PGEVT_ADTR1PS_POSTSCALE_7   0b0011000000000000	//ADC Trigger PostScaler = 1:6
#define REG_PGEVT_ADTR1PS_POSTSCALE_8   0b0011100000000000	//ADC Trigger PostScaler = 1:7
#define REG_PGEVT_ADTR1PS_POSTSCALE_9   0b0100000000000000	//ADC Trigger PostScaler = 1:8
#define REG_PGEVT_ADTR1PS_POSTSCALE_10	0b0100100000000000	//ADC Trigger PostScaler = 1:9
#define REG_PGEVT_ADTR1PS_POSTSCALE_11	0b0101000000000000	//ADC Trigger PostScaler = 1:10
#define REG_PGEVT_ADTR1PS_POSTSCALE_12	0b0101100000000000	//ADC Trigger PostScaler = 1:11
#define REG_PGEVT_ADTR1PS_POSTSCALE_13	0b0110000000000000	//ADC Trigger PostScaler = 1:12
#define REG_PGEVT_ADTR1PS_POSTSCALE_14	0b0110100000000000	//ADC Trigger PostScaler = 1:13
#define REG_PGEVT_ADTR1PS_POSTSCALE_15	0b0111000000000000	//ADC Trigger PostScaler = 1:14
#define REG_PGEVT_ADTR1PS_POSTSCALE_16	0b0111100000000000	//ADC Trigger PostScaler = 1:15
#define REG_PGEVT_ADTR1PS_POSTSCALE_17	0b1000000000000000	//ADC Trigger PostScaler = 1:16
#define REG_PGEVT_ADTR1PS_POSTSCALE_18	0b1000100000000000	//ADC Trigger PostScaler = 1:17
#define REG_PGEVT_ADTR1PS_POSTSCALE_19	0b1001000000000000	//ADC Trigger PostScaler = 1:18
#define REG_PGEVT_ADTR1PS_POSTSCALE_20	0b1001100000000000	//ADC Trigger PostScaler = 1:19
#define REG_PGEVT_ADTR1PS_POSTSCALE_21	0b1010000000000000	//ADC Trigger PostScaler = 1:20
#define REG_PGEVT_ADTR1PS_POSTSCALE_22	0b1010100000000000	//ADC Trigger PostScaler = 1:21
#define REG_PGEVT_ADTR1PS_POSTSCALE_23	0b1011000000000000	//ADC Trigger PostScaler = 1:22
#define REG_PGEVT_ADTR1PS_POSTSCALE_24	0b1011100000000000	//ADC Trigger PostScaler = 1:23
#define REG_PGEVT_ADTR1PS_POSTSCALE_25	0b1100000000000000	//ADC Trigger PostScaler = 1:24
#define REG_PGEVT_ADTR1PS_POSTSCALE_26	0b1100100000000000	//ADC Trigger PostScaler = 1:25
#define REG_PGEVT_ADTR1PS_POSTSCALE_27	0b1101000000000000	//ADC Trigger PostScaler = 1:26
#define REG_PGEVT_ADTR1PS_POSTSCALE_28	0b1101100000000000	//ADC Trigger PostScaler = 1:27
#define REG_PGEVT_ADTR1PS_POSTSCALE_29	0b1110000000000000	//ADC Trigger PostScaler = 1:28
#define REG_PGEVT_ADTR1PS_POSTSCALE_30	0b1110100000000000	//ADC Trigger PostScaler = 1:29
#define REG_PGEVT_ADTR1PS_POSTSCALE_31	0b1111000000000000	//ADC Trigger PostScaler = 1:30
#define REG_PGEVT_ADTR1PS_POSTSCALE_32	0b1111100000000000	//ADC Trigger PostScaler = 1:31

typedef enum {
    PGEVT_ADTR1PS_POSTSCALE_1	 =	0b00000,	//ADC Trigger PostScaler = 1:0
    PGEVT_ADTR1PS_POSTSCALE_2	 =	0b00001,	//ADC Trigger PostScaler = 1:1
    PGEVT_ADTR1PS_POSTSCALE_3	 =	0b00010,	//ADC Trigger PostScaler = 1:2
    PGEVT_ADTR1PS_POSTSCALE_4	 =	0b00011,	//ADC Trigger PostScaler = 1:3
    PGEVT_ADTR1PS_POSTSCALE_5	 =	0b00100,	//ADC Trigger PostScaler = 1:4
    PGEVT_ADTR1PS_POSTSCALE_6	 =	0b00101,	//ADC Trigger PostScaler = 1:5
    PGEVT_ADTR1PS_POSTSCALE_7	 =	0b00110,	//ADC Trigger PostScaler = 1:6
    PGEVT_ADTR1PS_POSTSCALE_8	 =	0b00111,	//ADC Trigger PostScaler = 1:7
    PGEVT_ADTR1PS_POSTSCALE_9	 =	0b01000,	//ADC Trigger PostScaler = 1:8
    PGEVT_ADTR1PS_POSTSCALE_10 =	0b01001,	//ADC Trigger PostScaler = 1:9
    PGEVT_ADTR1PS_POSTSCALE_11 =	0b01010,	//ADC Trigger PostScaler = 1:10
    PGEVT_ADTR1PS_POSTSCALE_12 =	0b01011,	//ADC Trigger PostScaler = 1:11
    PGEVT_ADTR1PS_POSTSCALE_13 =	0b01100,	//ADC Trigger PostScaler = 1:12
    PGEVT_ADTR1PS_POSTSCALE_14 =	0b01101,	//ADC Trigger PostScaler = 1:13
    PGEVT_ADTR1PS_POSTSCALE_15 =	0b01110,	//ADC Trigger PostScaler = 1:14
    PGEVT_ADTR1PS_POSTSCALE_16 =	0b01111,	//ADC Trigger PostScaler = 1:15
    PGEVT_ADTR1PS_POSTSCALE_17 =	0b10000,	//ADC Trigger PostScaler = 1:16
    PGEVT_ADTR1PS_POSTSCALE_18 =	0b10001,	//ADC Trigger PostScaler = 1:17
    PGEVT_ADTR1PS_POSTSCALE_19 =	0b10010,	//ADC Trigger PostScaler = 1:18
    PGEVT_ADTR1PS_POSTSCALE_20 =	0b10011,	//ADC Trigger PostScaler = 1:19
    PGEVT_ADTR1PS_POSTSCALE_21 =	0b10100,	//ADC Trigger PostScaler = 1:20
    PGEVT_ADTR1PS_POSTSCALE_22 =	0b10101,	//ADC Trigger PostScaler = 1:21
    PGEVT_ADTR1PS_POSTSCALE_23 =	0b10110,	//ADC Trigger PostScaler = 1:22
    PGEVT_ADTR1PS_POSTSCALE_24 =	0b10111,	//ADC Trigger PostScaler = 1:23
    PGEVT_ADTR1PS_POSTSCALE_25 =	0b11000,	//ADC Trigger PostScaler = 1:24
    PGEVT_ADTR1PS_POSTSCALE_26 =	0b11001,	//ADC Trigger PostScaler = 1:25
    PGEVT_ADTR1PS_POSTSCALE_27 =	0b11010,	//ADC Trigger PostScaler = 1:26
    PGEVT_ADTR1PS_POSTSCALE_28 =	0b11011,	//ADC Trigger PostScaler = 1:27
    PGEVT_ADTR1PS_POSTSCALE_29 =	0b11100,	//ADC Trigger PostScaler = 1:28
    PGEVT_ADTR1PS_POSTSCALE_30 =	0b11101,	//ADC Trigger PostScaler = 1:29
    PGEVT_ADTR1PS_POSTSCALE_31 =	0b11110,	//ADC Trigger PostScaler = 1:30
    PGEVT_ADTR1PS_POSTSCALE_32 =	0b11111 	//ADC Trigger PostScaler = 1:31
}PGEVT_ADTR1PS_e;  // ADC Trigger 1 Post-Scaler Selection bits


#define REG_PGEVT_ADTR1EN3_PGxTRIGC_ENABLED  0b0000010000000000 // PGxTRIGC register compare event is enabled as trigger source for ADC Trigger 1
#define REG_PGEVT_ADTR1EN3_PGxTRIGC_DISABLED 0b0000000000000000  // PGxTRIGC register compare event is disabled as trigger source for ADC Trigger 1

typedef enum {
    PGEVT_ADTR1EN3_PGxTRIGC_ENABLED = 0b1, // PGxTRIGC register compare event is enabled as trigger source for ADC Trigger 3
    PGEVT_ADTR1EN3_PGxTRIGC_DISABLED = 0b0  // PGxTRIGC register compare event is disabled as trigger source for ADC Trigger 3
}PGEVT_ADTR1EN3_e;  // ADC Trigger 3 Source is PGxTRIGC Compare Event Enable bit
    
#define REG_PGEVT_ADTR1EN2_PGxTRIGB_ENABLED  0b0000001000000000 // PGxTRIGB register compare event is enabled as trigger source for ADC Trigger 1
#define REG_PGEVT_ADTR1EN2_PGxTRIGB_DISABLED 0b0000000000000000  // PGxTRIGB register compare event is disabled as trigger source for ADC Trigger 1

typedef enum {
    PGEVT_ADTR1EN2_PGxTRIGB_ENABLED = 0b1, // PGxTRIGB register compare event is enabled as trigger source for ADC Trigger 2
    PGEVT_ADTR1EN2_PGxTRIGB_DISABLED = 0b0  // PGxTRIGB register compare event is disabled as trigger source for ADC Trigger 2
}PGEVT_ADTR1EN2_e;  // ADC Trigger 2 Source is PGxTRIGB Compare Event Enable bit
    
#define REG_PGEVT_ADTR1EN1_PGxTRIGA_ENABLED  0b0000000100000000 // PGxTRIGA register compare event is enabled as trigger source for ADC Trigger 1
#define REG_PGEVT_ADTR1EN1_PGxTRIGA_DISABLED 0b0000000000000000  // PGxTRIGA register compare event is disabled as trigger source for ADC Trigger 1

typedef enum {
    PGEVT_ADTR1EN1_PGxTRIGA_ENABLED = 0b1, // PGxTRIGA register compare event is enabled as trigger source for ADC Trigger 1
    PGEVT_ADTR1EN1_PGxTRIGA_DISABLED = 0b0  // PGxTRIGA register compare event is disabled as trigger source for ADC Trigger 1
}PGEVT_ADTR1EN1_e;  // ADC Trigger 1 Source is PGxTRIGA Compare Event Enable bit
    
#define REG_PGEVT_UPDTRG_PGxTRIGA   0b0000000000011000 // A write of the PGxTRIGA register automatically sets the UPDATE bit
#define REG_PGEVT_UPDTRG_PGxPHASE   0b0000000000010000 // A write of the PGxPHASE register automatically sets the UPDATE bit
#define REG_PGEVT_UPDTRG_PGxDC      0b0000000000001000 // A write of the PGxDC register automatically sets the UPDATE bit
#define REG_PGEVT_UPDTRG_UPDATE_BIT 0b0000000000000000  // User must set the UPDATE bit (PGxSTAT<4>) manually

typedef enum {
    PGEVT_UPDTRG_PGxTRIGA = 0b11, // A write of the PGxTRIGA register automatically sets the UPDATE bit
    PGEVT_UPDTRG_PGxPHASE = 0b10, // A write of the PGxPHASE register automatically sets the UPDATE bit
    PGEVT_UPDTRG_PGxDC = 0b01, // A write of the PGxDC register automatically sets the UPDATE bit
    PGEVT_UPDTRG_UPDATE_BIT = 0b00 // User must set the UPDATE bit (PGxSTAT<4>) manually
}PGEVT_UPDTRG_e;  // Update Trigger Select bits

#define REG_PGEVT_PGTRGSEL_PGxTRIGC 0b0000000000000011 // PGxTRIGC compare event is the PWM Generator trigger
#define REG_PGEVT_PGTRGSEL_PGxTRIGB 0b0000000000000010 // PGxTRIGB compare event is the PWM Generator trigger
#define REG_PGEVT_PGTRGSEL_PGxTRIGA 0b0000000000000001 // PGxTRIGA compare event is the PWM Generator trigger
#define REG_PGEVT_PGTRGSEL_EOC      0b0000000000000000 // EOC event is the PWM Generator trigger

typedef enum {
    PGEVT_PGTRGSEL_PGxTRIGC = 0b011, // PGxTRIGC compare event is the PWM Generator trigger
    PGEVT_PGTRGSEL_PGxTRIGB = 0b010, // PGxTRIGB compare event is the PWM Generator trigger
    PGEVT_PGTRGSEL_PGxTRIGA = 0b001, // PGxTRIGA compare event is the PWM Generator trigger
    PGEVT_PGTRGSEL_EOC = 0b000 // EOC event is the PWM Generator trigger
}PGEVT_PGTRGSEL_e;   // PWM Generator Trigger Output Selection bits

typedef struct {
    
    volatile PGEVT_PGTRGSEL_e PGTRGSEL : 3; // PWM Generator Trigger Output Selection bits(1)
    volatile PGEVT_UPDTRG_e UPDTRG : 2;     // Update Trigger Select bits
    volatile unsigned : 3;            // reserved
    volatile PGEVT_ADTR1EN1_e ADTR1EN1 : 1; // ADC Trigger 1 Source is PGxTRIGA Compare Event Enable bit
    volatile PGEVT_ADTR1EN2_e ADTR1EN2 : 1; // ADC Trigger 2 Source is PGxTRIGB Compare Event Enable bit
    volatile PGEVT_ADTR1EN3_e ADTR1EN3 : 1; // ADC Trigger 3 Source is PGxTRIGC Compare Event Enable bit
    volatile PGEVT_ADTR1PS_e  ADTR1PS : 5;  // ADC Trigger 1 Post-Scaler Selection bits
    
    volatile PGEVT_ADTR1OFS_e ADTR1OFS : 5; // ADC Trigger 1 Offset Selection bits
    volatile PGEVT_ADTR2EN1_e ADTR2EN1 : 1; // ADC Trigger 2 Source is PGxTRIGA Compare Event Enable bit
    volatile PGEVT_ADTR2EN2_e ADTR2EN2 : 1; // ADC Trigger 2 Source is PGxTRIGA Compare Event Enable bit
    volatile PGEVT_ADTR2EN3_e ADTR2EN3 : 1; // ADC Trigger 2 Source is PGxTRIGA Compare Event Enable bit
    volatile PGEVT_IEVTSEL_e IEVTSEL : 2;   // Interrupt Event Selection bits
    volatile unsigned : 2;            // reserved
    volatile PGEVT_SIEN_e SIEN : 1;         // PCI Sync Interrupt Enable bit
    volatile PGEVT_FFIEN_e FFIEN: 1;        // PCI Feed-Forward Interrupt Enable bit
    volatile PGEVT_CLIEN_e CLIEN: 1;        // PCI Current-Limit Interrupt Enable bit
    volatile PGEVT_FLTIEN_e FLTIEN: 1;      // PCI Fault Interrupt Enable bit
    
}PGxEVT_t;

typedef union {
    volatile uint32_t value;
    volatile PGxEVT_t PGxEVT;
}REGBLK_PGxEVT_CONFIG_t;


/* ===========================================================================
 * PWMEVTy: PWM EVENT OUTPUT CONTROL REGISTER y (y=A, B, C, D ,E or F)
 * ===========================================================================*/
#define REG_PWMEVTy_VALID_DATA_WRITE_MASK 0xF0F7
#define REG_PWMEVTy_VALID_DATA_READ_MASK 0xF0F7

#define REG_PWMEVTy_EVTyPGS_PG8 0b0000000000000111 // PG8 is event source
#define REG_PWMEVTy_EVTyPGS_PG7 0b0000000000000110 // PG7 is event source
#define REG_PWMEVTy_EVTyPGS_PG6 0b0000000000000101 // PG6 is event source
#define REG_PWMEVTy_EVTyPGS_PG5 0b0000000000000100 // PG5 is event source
#define REG_PWMEVTy_EVTyPGS_PG4 0b0000000000000011 // PG4 is event source
#define REG_PWMEVTy_EVTyPGS_PG3 0b0000000000000010 // PG3 is event source
#define REG_PWMEVTy_EVTyPGS_PG2 0b0000000000000001 // PG2 is event source
#define REG_PWMEVTy_EVTyPGS_PG1 0b0000000000000000 // PG1 is event source

typedef enum {
    PWMEVTy_EVTyPGS_PG8 = 0b111, // PG8 is event source
    PWMEVTy_EVTyPGS_PG7 = 0b110, // PG7 is event source
    PWMEVTy_EVTyPGS_PG6 = 0b101, // PG6 is event source
    PWMEVTy_EVTyPGS_PG5 = 0b100, // PG5 is event source
    PWMEVTy_EVTyPGS_PG4 = 0b011, // PG4 is event source
    PWMEVTy_EVTyPGS_PG3 = 0b010, // PG3 is event source
    PWMEVTy_EVTyPGS_PG2 = 0b001, // PG2 is event source
    PWMEVTy_EVTyPGS_PG1 = 0b000  // PG1 is event source
}EVTyPGS_e; // PWM Event Source Selection bits


#define REG_PWMEVTy_EVTySEL_HIGH_RED_ERROR 0b0000000011110000 // High-resolution error event signal
#define REG_PWMEVTy_EVTySEL_ADC_TRIGGER_2 0b0000000010010000 // ADC Trigger 2 signal
#define REG_PWMEVTy_EVTySEL_ADC_TRIGGER_1 0b0000000010000000 // ADC Trigger 1 signal
#define REG_PWMEVTy_EVTySEL_STEER 0b0000000001110000 // STEER signal (available in Push-Pull Output modes only)(4)
#define REG_PWMEVTy_EVTySEL_CAHALF 0b0000000001100000 // CAHALF signal (available in Center-Aligned modes only)(4)
#define REG_PWMEVTy_EVTySEL_PCI_FAULT 0b0000000001010000 // PCI Fault active output signal
#define REG_PWMEVTy_EVTySEL_PCI_CL 0b0000000001000000 // PCI current-limit active output signal
#define REG_PWMEVTy_EVTySEL_PCI_FF 0b0000000000110000 // PCI feed-forward active output signal
#define REG_PWMEVTy_EVTySEL_PCI_SYNC 0b0000000000100000 // PCI Sync active output signal
#define REG_PWMEVTy_EVTySEL_PWM_OUT 0b0000000000010000 // PWM Generator output signal(3)
#define REG_PWMEVTy_EVTySEL_PGTRGSEL 0b0000000000000000 // Source is selected by the PGTRGSEL<2:0> bits    

typedef enum {
    PWMEVTy_EVTySEL_HIGH_RED_ERROR = 0b1111, // High-resolution error event signal
    PWMEVTy_EVTySEL_ADC_TRIGGER_2 = 0b1001, // ADC Trigger 2 signal
    PWMEVTy_EVTySEL_ADC_TRIGGER_1 = 0b1000, // ADC Trigger 1 signal
    PWMEVTy_EVTySEL_STEER = 0b0111, // STEER signal (available in Push-Pull Output modes only)(4)
    PWMEVTy_EVTySEL_CAHALF = 0b0110, // CAHALF signal (available in Center-Aligned modes only)(4)
    PWMEVTy_EVTySEL_PCI_FAULT = 0b0101, // PCI Fault active output signal
    PWMEVTy_EVTySEL_PCI_CL = 0b0100, // PCI current-limit active output signal
    PWMEVTy_EVTySEL_PCI_FF = 0b0011, // PCI feed-forward active output signal
    PWMEVTy_EVTySEL_PCI_SYNC = 0b0010, // PCI Sync active output signal
    PWMEVTy_EVTySEL_PWM_OUT = 0b0001, // PWM Generator output signal(3)
    PWMEVTy_EVTySEL_PGTRGSEL = 0b0000 // Source is selected by the PGTRGSEL<2:0> bits    
}EVTySEL_e; // PWM Event Selection bits

#define REG_PWMEVTy_EVTySYNC_SYSCLK_SYNC 0b0001000000000000 // Event output signal is synchronized to the system clock
#define REG_PWMEVTy_EVTySYNC_NO_SYNC 0b0000000000000000  //  Event output is not synchronized to the system clock

typedef enum {
    PWMEVTy_EVTySYNC_SYSCLK_SYNC = 0b1, // Event output signal is synchronized to the system clock
    PWMEVTy_EVTySYNC_NO_SYNC = 0b0  // Event output is not synchronized to the system clock
}EVTySYNC_e; // PWM Event Output Sync bit

#define REG_PWMEVTy_EVTySTRD_NO_STRETCH 0b0010000000000000 // Event output signal pulse width is not stretched
#define REG_PWMEVTy_EVTySTRD_8CLK_STRECH 0b0000000000000000  // Event output signal is stretched to 8 PWM clock cycles minimum(

typedef enum {
    PWMEVTy_EVTySTRD_NO_STRETCH = 0b1, // Event output signal pulse width is not stretched
    PWMEVTy_EVTySTRD_8CLK_STRECH = 0b0  // Event output signal is stretched to 8 PWM clock cycles minimum(
}EVTySTRD_e; // PWM Event Output Stretch Disable bit

#define REG_PWMEVTy_EVTyPOL_ACTIVE_LOW 0b0100000000000000 // Event output signal is active-low
#define REG_PWMEVTy_EVTyPOL_ACTIVE_HIGH 0b0000000000000000  // Event output signal is active-high

typedef enum {
    PWMEVTy_EVTyPOL_ACTIVE_LOW = 0b1, // Event output signal is active-low
    PWMEVTy_EVTyPOL_ACTIVE_HIGH = 0b0  // Event output signal is active-high
}EVTyPOL_e; // PWM Event Output Polarity bit

#define REG_PWMEVTy_EVTyOEN_ENABLE 0b1000000000000000 // // Event output signal is output on PWMEVTy pin
#define REG_PWMEVTy_EVTyOEN_DISABLE 0b0000000000000000 // Event output signal is internal only

typedef enum {
    PWMEVTy_EVTyOEN_ENABLE = 0b1, // Event output signal is output on PWMEVTy pin
    PWMEVTy_EVTyOEN_DISABLE = 0b0 // Event output signal is internal only
}EVTyOEN_e; // PWM Event Output Polarity bit

typedef struct {
    volatile EVTyOEN_e EVTyOEN : 1; // PWM Event Output Enable bit
    volatile EVTyPOL_e EVTyPOL : 1; // PWM Event Output Polarity bit
    volatile EVTySTRD_e EVTySTRD : 1; // PWM Event Output Stretch Disable bit
    volatile EVTySYNC_e EVTySYNC : 1; // PWM Event Output Sync bit
    volatile unsigned : 4; // reserved
    volatile EVTySEL_e EVTySEL : 4; // PWM Event Selection bits
    volatile unsigned : 1; // reserved
    volatile EVTyPGS_e EVTyPGS : 3; // PWM Event Source Selection bits
}PWMEVTy_t;

typedef union {
    volatile uint32_t value; // EVENT OUTPUT CONTROL REGISTER DIRECT READ/WRITE
    volatile PWMEVTy_t PGxEVT; // PWM EVENT OUTPUT CONTROL REGISTER A, B, C, D, E or F
}REGBLK_PWMEVTy_t_CONFIG_t; // PWM EVENT OUTPUT CONTROL REGISTER CONFIGURATION


/* ===========================================================================
 * PGxDTL/H: PWM GENERATOR x DEAD-TIME REGISTER LOW/HIGH
 * ===========================================================================*/
#define REG_PGxDT_VALID_DATA_WRITE_MASK 0x3FFF3FFF
#define REG_PGxDT_VALID_DATA_READ_MASK 0x3FFF3FFF

/* ********************************************************************************
 * COMPILER v1.35 ISSUE:
 * 
 * The reserved two MSBs of the two 16-bit values are causing the compiler to fail
 * and have therefore been taken out for the time being. To prevent writing invalid
 * values to DTL and DTH, it's recommended to use the REG_PGxDT_VALID_DATA_WRITE_MASK
 * above.
 * 
 * Weirdly this doesn't seem to be an issue with all other data structures in this
 * or similar driver header files. Investigation is on-going (09/06/2018 AR, M91406)
 * 
 * typedef struct {
 *     volatile unsigned DT_FALLING : 14; // dead time low-side PWM output
 *     volatile unsigned  : 2; // reserved
 *     volatile unsigned DT_RISING : 14; // dead time high-side PWM output
 *     volatile unsigned  : 2; // reserved
 * }PGxDT_t;
 *
 * ******************************************************************************** */

typedef struct {
    volatile uint32_t DT_FALLING : 16; // dead time low-side PWM output
    volatile uint32_t DT_RISING : 16; // dead time high-side PWM output
} PGxDT_t;

typedef union {
    volatile uint32_t value;
    volatile PGxDT_t PGxDT;
} REGBLK_PGxDEAD_TIME_t;


/* ===========================================================================
 * PGxDC: PWM GENERATOR x DUTY CYCLE REGISTER
 * ===========================================================================*/
#define REG_PGxDC_VALID_DATA_WRITE_MASK 0xFFFF
#define REG_PGxDC_VALID_DATA_READ_MASK 0xFFFF

typedef struct {
    
    volatile unsigned DC : 16; // duty cycle time period common PWM modes

} __attribute__((packed)) PGxDC_t;

typedef union {
    volatile PGxDC_t PGxDC;
    volatile uint16_t value;
} REGBLK_PGxDUTY_CYCLE_t;

/* ===========================================================================
 * PGxDCA: PWM GENERATOR x DUTY CYCLE ADJUSTMENT REGISTER
 * ===========================================================================*/
#define REG_PGxDCA_VALID_DATA_WRITE_MASK 0x00FF
#define REG_PGxDCA_VALID_DATA_READ_MASK 0x00FF

typedef struct {
    
    volatile unsigned DCA : 8; // duty cycle time period common PWM modes
    volatile unsigned : 8; // reserved

} __attribute__((packed)) PGxDCA_t;

typedef union {
    volatile PGxDCA_t PGxDC;
    volatile uint16_t value;
} REGBLK_PGxDUTY_CYCLE_ADJUSTMENT_t;

/*
typedef struct {
    volatile uint16_t PCLKCON_t;
    volatile uint16_t FSCL_t 
    volatile uint16_t FSMINPER_t
    volatile uint16_t MPHASE_t
    volatile uint16_t MDC_t 
    volatile uint16_t MPER_t 
    volatile uint16_t LFSR_t 
    volatile uint16_t CMBTRIGL_t
    volatile uint16_t CMBTRIGH_t
    volatile uint16_t LOGCONA_t
    volatile uint16_t LOGCONB_t
    volatile uint16_t LOGCONC_t
    volatile uint16_t LOGCOND_t
    volatile uint16_t LOGCONE_t
    volatile uint16_t LOGCONF_t
    volatile uint16_t PWMEVTA_t
    volatile uint16_t PWMEVTB_t
    volatile uint16_t PWMEVTC_t
    volatile uint16_t PWMEVTD_t
    volatile uint16_t PWMEVTE_t
    volatile uint16_t PWMEVTF_t
};
*/

typedef struct {
    volatile REGBLK_PWMEVTy_t_CONFIG_t PWMEVTy; 
    volatile REGBLK_PGxCH_CONFIG_t PGxCON; // PWM GENERATOR x CONTROL REGISTER LOW/HIGH
    volatile uint16_t PGxSTAT; // PWM GENERATOR x STATUS REGISTER
    volatile REGBLK_PGxIO_CONFIG_t PGxIOCON; // PWM GENERATOR x I/O CONTROL REGISTER LOW/HIGH
    volatile uint32_t PGxyPCI; // PWM GENERATOR xy PCI REGISTER LOW(HIGH)
    volatile uint32_t PGxEVT; // PWM GENERATOR x EVENT REGISTER LOW/HIGH
    volatile uint32_t PGxLEB; // PWM GENERATOR x LEADING-EDGE BLANKING REGISTER LOW/HIGH
    volatile uint16_t PGxPHASE; // PWM GENERATOR x PHASE REGISTER
    volatile REGBLK_PGxDUTY_CYCLE_t PGxDC; // PWM GENERATOR x DUTY CYCLE REGISTER
    volatile REGBLK_PGxDUTY_CYCLE_ADJUSTMENT_t PGxDCA; // PWM GENERATOR x DUTY CYCLE ADJUSTMENT REGISTER
    volatile uint16_t PGxPER; // PWM GENERATOR x PERIOD REGISTER
    volatile uint16_t PGxTRIGA; // PWM GENERATOR x TRIGGER A REGISTER
    volatile uint16_t PGxTRIGB; // PWM GENERATOR x TRIGGER B REGISTER
    volatile uint16_t PGxTRIGC; // PWM GENERATOR x TRIGGER C REGISTER
    volatile REGBLK_PGxDEAD_TIME_t  PGxDT; // PWM GENERATOR x DEAD-TIME REGISTER LOW/HIGH
    volatile uint16_t PGxCAP; // PWM GENERATOR x CAPTURE REGISTER
}HSPWM_C_TYPE_PWM_CHANNEL_CONFIG_t;





// Prototypes

extern inline uint16_t hspwm_init_independent_pwm
(
    uint16_t channel,
    REGBLK_PCLK_CONFIG_t regPCLK,
    REGBLK_PGxCH_CONFIG_t regPGxCON,
    REGBLK_PGxEVT_CONFIG_t regPGxEVT,
    REGBLK_PGxIO_CONFIG_t regPGxIOCON,
    REGBLK_PGxDEAD_TIME_t regPGxDT
    );

extern inline uint16_t hspwm_init_pwm_timing
(
    uint16_t channel,
    uint16_t regPGxPER,
    uint16_t regPGxDC,
    uint16_t regPGxPHASE
    );

extern inline uint16_t hspwm_enable_pwm(uint16_t channel, bool wait_for_hres);
extern inline uint16_t hspwm_disable_pwm(uint16_t channel);
extern inline uint16_t hspwm_ovr_hold(uint16_t channel);
extern inline uint16_t hspwm_ovr_release(uint16_t channel);


#endif
// End of File _P33SMPS_SMPS_PWM_H_
