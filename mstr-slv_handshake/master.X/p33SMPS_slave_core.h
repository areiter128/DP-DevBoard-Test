
#ifndef __P33SMPS_DUAL_CORE_DEVICES_SLAVE_CORE_H__
#define __P33SMPS_DUAL_CORE_DEVICES_SLAVE_CORE_H__

#include "mcal.h"

#if defined (__P33SMPS_CH_MSTR__)
/**
 Section: Included Files
*/

#include <stdint.h>
#include <stdbool.h>

/* ===========================================================================
 * MSI1CON: MSI1 MASTER CONTROL REGISTER
 * ===========================================================================*/
#define REG_MSIxCON_VALID_DATA_WRITE_MASK 0x8F80
#define REG_MSIxCON_VALID_DATA_READ_MASK  0x8F80

#define REG_MSIxCON_SRSTIE_ENABLED  0b0000000010000000 // Master Slave Reset event interrupt occurs when Slave enters Reset state
#define REG_MSIxCON_SRSTIE_DISABLED 0b0000000000000000 // Master Slave Reset event interrupt does not occur when Slave enters Reset state

typedef enum {
    MSIxCON_SRSTIE_ENABLED = 0b1, // Master Slave Reset event interrupt occurs when Slave enters Reset state
    MSIxCON_SRSTIE_DISABLED = 0b0 // Master Slave Reset event interrupt does not occur when Slave enters Reset state
}MSIxCON_SRSTIE_e; // Slave Reset Event Interrupt Enable bit

#define REG_MSIxCON_STMIACK_SET   0b0000000100000000 // If STMIRQ = 1, Master Acknowledges Slave interrupt request, else protocol error
#define REG_MSIxCON_STMIACK_CLEAR 0b0000000000000000 // If STMIRQ = 0, Master has not yet Acknowledged Slave interrupt request, else no Slave to Master interrupt request is pending

typedef enum {
    MSIxCON_STMIACK_SET   = 0b1, // If STMIRQ = 1, Master Acknowledges Slave interrupt request, else protocol error
    MSIxCON_STMIACK_CLEAR = 0b0  // If STMIRQ = 0, Master has not yet Acknowledged Slave interrupt request, else no Slave to Master interrupt request is pending
}MSIxCON_STMIACK_e; // Master to Slave Interrupt Acknowledge bit (to Acknowledge the Slave interrupt)

#define REG_MSIxCON_MSTIRQ_SET   0b0000001000000000 // Master has issued an interrupt request to the Slave
#define REG_MSIxCON_MSTIRQ_CLEAR 0b0000000000000000 // Master has not issued a Slave interrupt request

typedef enum {
    MSIxCON_MSTIRQ_SET = 0b1,  // Master has issued an interrupt request to the Slave
    MSIxCON_MSTIRQ_CLEAR = 0b0 // Master has not issued a Slave interrupt request
}MSIxCON_MSTIRQ_e; // Master to Slave Interrupt Request bit

#define REG_MSIxCON_RFITSEL_FIFO_FULL 0b0000110000000000 // Trigger data valid interrupt when FIFO is full after Slave write
#define REG_MSIxCON_RFITSEL_FIFO_75P  0b0000100000000000 // Trigger data valid interrupt when FIFO is 75% full after Slave write
#define REG_MSIxCON_RFITSEL_FIFO_50P  0b0000010000000000 // Trigger data valid interrupt when FIFO is 50% full after Slave write
#define REG_MSIxCON_RFITSEL_FIFO_1ST  0b0000000000000000 // Trigger data valid interrupt when 1st FIFO entry is written by Slave        

typedef enum {
    MSIxCON_RFITSEL_FIFO_FULL = 0b11, // Trigger data valid interrupt when FIFO is full after Slave write
    MSIxCON_RFITSEL_FIFO_75P = 0b10, // Trigger data valid interrupt when FIFO is 75% full after Slave write
    MSIxCON_RFITSEL_FIFO_50P = 0b01, // Trigger data valid interrupt when FIFO is 50% full after Slave write
    MSIxCON_RFITSEL_FIFO_1ST = 0b00  // Trigger data valid interrupt when 1st FIFO entry is written by Slave        
}MSIxCON_RFITSEL_e;

#define REG_MSIxCON_SLVEN_ENABLED  0b1000000000000000 // Slave processor is enabled, Slave Reset is released and execution is permitted
#define REG_MSIxCON_SLVEN_DISABLED 0b0000000000000000 // Slave processor is disabled and held in Reset

typedef enum {
    MSIxCON_SLVEN_ENABLED = 0b1,  // Slave processor is enabled, Slave Reset is released and execution is permitted
    MSIxCON_SLVEN_DISABLED = 0b0 // Slave processor is disabled and held in Reset
}MSIxCON_SLVEN_e; // Slave Enable bit

typedef struct {

    volatile unsigned :7; // reserved
    volatile MSIxCON_SRSTIE_e SRSTIE:1;
    volatile MSIxCON_STMIACK_e STMIACK:1;
    volatile MSIxCON_MSTIRQ_e MSTIRQ:1;
    volatile MSIxCON_RFITSEL_e RFITSEL:2;
    volatile unsigned :3; // reserved
    volatile MSIxCON_SLVEN_e SLVEN:1;

} __attribute__((packed)) MSIxCON_t;

typedef union {
    volatile uint16_t value;
    volatile MSIxCON_t MSIxCON;
}REGBLK_MSIxCON_CONFIG_t;


/* ===========================================================================
 * MSI1CON: MSI1 MASTER CONTROL REGISTER
 * ===========================================================================*/
#define REG_MSIxSTAT_VALID_DATA_WRITE_MASK 0x4800
#define REG_MSIxSTAT_VALID_DATA_READ_MASK  0xFF80


typedef struct {
    volatile unsigned :8; // reserved
    volatile uint16_t MTSIACK:1;
    volatile uint16_t STMIRQ:1;
    volatile uint16_t SLVP2ACT:1;
    volatile uint16_t VERFERR:1;
    volatile uint16_t SLVPWR:2;
    volatile uint16_t SLVWDRST:1;
    volatile uint16_t SLVRST:1;
} __attribute__((packed)) MSIxSTAT_t;

typedef union {
    volatile uint16_t value;
    volatile MSIxSTAT_t MSIxSTAT;
}REGBLK_MSIxSTAT_CONFIG_t;

/**
  MSI Slave Status Enumeration

  @Summary
    Defines the status enumeration of Slave core.

  @Description
    This enumeration defines the different operating modes of MSI Slave core.
 */

typedef enum
{  
    SLAVE_SYSTEM_STATUS_NOT_IN_LOW_POWER_MODE = 0,
    SLAVE_SYSTEM_STATUS_DEEP_SLEEP = 1,
    SLAVE_SYSTEM_STATUS_SLEEP = 2,
    SLAVE_SYSTEM_STATUS_IDLE = 3,
    SLAVE_SYSTEM_STATUS_RUNNING = 4,
    SLAVE_SYSTEM_STATUS_IN_RESET = 5
} SLAVE_SYSTEM_STATUS;

/**
  MSI Slave Reset Cause Enumeration

  @Summary
    Defines the slave reset cause enumeration.

  @Description
    This enumeration defines the causes resulting in the reset of the Slave
    core.
 */

typedef enum
{
    SLAVE_RESET_CAUSE_WATCHDOG,
    SLAVE_RESET_CAUSE_UNSPECIFIED
} SLAVE_RESET_CAUSE;

/**
 Section: Interface Routines
*/

extern void inline initialize_Slave(void);
extern int inline program_Slave(void);
extern uint16_t inline start_Slave(void);
extern uint16_t inline stop_Slave(void);

#endif // __P33SMPS_CH_MSTR__
#endif //__P33SMPS_DUAL_CORE_DEVICES_SLAVE_CORE_H__

