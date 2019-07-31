
#ifndef SLAVE_TYPEDEF_H
#define SLAVE_TYPEDEF_H


/**
 Section: Data Type Definitions
*/
        
/**
  MSI Slave Status Enumeration

  @Summary
    Defines the status enumeration of Slave core.

  @Description
    This enumeration defines the different operating modes of MSI Slave core.
 */
typedef enum
{  
    SLAVE_SYSTEM_STATUS_NOT_IN_LOW_POWER_MODE,
    SLAVE_SYSTEM_STATUS_DEEP_SLEEP,
    SLAVE_SYSTEM_STATUS_SLEEP,
    SLAVE_SYSTEM_STATUS_IDLE,
    SLAVE_SYSTEM_STATUS_RUNNING,
    SLAVE_SYSTEM_STATUS_IN_RESET
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


#endif //SLAVE_TYPEDEF_H

