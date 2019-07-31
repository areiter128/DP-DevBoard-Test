

#include <xc.h>

#include "p33SMPS_slave_core.h"
#if defined (__P33SMPS_CH_MSTR__) 

//#include <libpic30.h>
//#include "slave.h"
//extern __psv__ char * slave[];

#define SLAVE_IMAGE     slave
#define SLAVE_NUMBER    1


/**
 Section: Driver Interface Function Definitions
*/
void initialize_Slave(void)
{
    //SRSTIE disabled; SLVEN disabled; MSTIRQ disabled; RFITSEL Trigger data valid interrupt when 1st FIFO entry is written by Slave; STMIACK disabled; 
    MSI1CON = 0x00;	
    //WFEN enabled; RFEN enabled; 
    MSI1FIFOCS = 0x8080;	
    
    return;

}

uint16_t start_Slave(void)
{
//    _start_slave();
    
    
	asm volatile
	(	"push w0 \n"
        "mov #0x55, w0 \n"
        "mov w0, MSI1KEY \n"
        "mov #0xAA, w0 \n"
        "mov w0, MSI1KEY \n"
        "bset MSI1CON, #15 \n"
        "pop w0 \n"
	);


    return(MSI1CONbits.SLVEN);
    
}

uint16_t stop_Slave(void)
{
    
	asm volatile
	(	"push w0 \n"
        "mov #0x55, w0 \n"
        "mov w0, MSI1KEY \n"
        "mov #0xAA, w0 \n"
        "mov w0, MSI1KEY \n"
        "bclr MSI1CON, #15 \n"
        "pop w0 \n"
	);

    return(1 - MSI1CONbits.SLVEN);
    
}

int program_Slave(void)               
{
//    return(_program_slave(SLAVE_NUMBER, 0, SLAVE_IMAGE));
    
    asm volatile 
    (   "cp       w0, #1 \n"
        "bra z,   good_slave \n"
#if ESLV_INVALID < 1024
        "retlw    #ESLV_INVALID,w0 \n"
#else
        "mov      #ESLV_INVALID,w0 \n"
        "return \n"
#endif
"good_slave:      \n"
        "push     DSRPAG \n"
        "push     DSWPAG \n"
        "mov.d    w0, w4 ; makes things easier later \n"
        "mov      w3, DSRPAG \n"
"next_record: \n"
        "mov.d    [w2++], w0 ; w0 <- dest address, w1 <- len \n"
        "cp0      w1 \n"
        "bra eq,  done ; all finished, no error \n"
        "mov      [w2++], w6 ; w6 <- page:format \n"
        "lsr      w6,#7,w7 \n"
        "mov      w7, DSWPAG ; write page \n"
        "and      #0x7f,w6 \n"                 
        "cp       w6,#FMT_DUO_COPY3 \n"
        "bra eq,  copy_slave \n"
        "mov      #ESLV_BAD_IMAGE,w0 ; set error code and return \n"
        " \n"
        "done:   "
        "pop      DSWPAG \n"
        "pop      DSRPAG \n"
        "return \n"
        " \n"
        " \n""      // ready to copy len (w1) instructions 
        " \n""      // starting at w2, storing at w0
        " \n"
        "copy_slave: \n"   
        "dec      w1,w1 \n"
        "cp0      w5 \n"
        "bra nz,  verify_slave \n"
        "repeat   w1 \n"
        "ldslv    [w2++],[w0++],#1 \n"
        "bra      next_record ; read the next record \n"
        " \n"
        "verify_slave: \n"
        "repeat   w1 \n"
        "vfslv    [w2++],[w0++],#1 \n"
        "btss.b   MSI1STAT+1, #3 \n"
        "bra      next_record \n"
        "vefify_failed: \n"
        "mov     #ESLV_VERIFY_FAIL,w0 \n"
        "bra     done \n"
    );
    
    return(1);
}

#endif // __P33SMPS_CH_MSTR__







