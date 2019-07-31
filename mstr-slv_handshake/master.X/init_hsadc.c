/*
 * File:   init_hsadc.c
 * Author: M91406
 *
 * Created on October 16, 2018, 11:06 AM
 */


#include <xc.h>
#include "main.h"

void initialize_hsadc(void) {
    
    volatile uint16_t fres = 0;
    volatile REGBLK_ADCON1_t adcon1;
    volatile REGBLK_ADCON2_t adcon2;
    volatile REGBLK_ADCON3_t adcon3;
    volatile REGBLK_ADCON4_t adcon4;
    volatile REGBLK_ADCON5_t adcon5;


    // Run basic initialization of ADC module features
    adcon1.ADCON1.ADSIDL = ADCON1_ADSIDL_RUN; // Run core in doze mode
    adcon1.ADCON1.SHRRES = ADCON1_SHRRES_12BIT; // ADC resolution = 12-bit (0...4095 ticks)
    adcon1.ADCON1.FORM = ADCON1_FORM_INTEGER; // Produce integer (right-aligned) numbers

    adcon2.ADCON2.SHRADCS = ADCON2_SHRADCS_DIV_MIN; // shared core clock divider = 2:1 (minimum)
    adcon2.ADCON2.SHRSAMC = ADCON2_SHRSAMC_0008; // 10x TAD sampling time 
    adcon2.ADCON2.REFCIE = ADCON2_REFCIE_OFF; // no error interrupt is triggered when Vref becomes available
    adcon2.ADCON2.REFERCIE = ADCON2_REFERCIE_OFF; // no error interrupt is triggered when Vref fails
    adcon2.ADCON2.REFERR = 0; // reset error flag
    adcon2.ADCON2.REFRDY = 0; // reset bandgap status bit
    adcon2.ADCON2.EIEN = ADCON2_EIEN_ON; // enable early interrupts
    adcon2.ADCON2.SHREISEL = ADCON2_SHREISEL_8TAD; // ADC interrupts are triggered 8 TAD clocks ahead of completion

    adcon3.ADCON3.CLKSEL = ADCON3_CLKSEL_FOSC; //ADCON3_CLKSEL_AFVCODIV; // set ADC clock to auxiliary clock (common clock with PWM)
    adcon3.ADCON3.CLKDIV = ADCON3_CLKDIV_1; // set ADC input clock divider
    adcon3.ADCON3.SHREN = ADCON3_CxEN_ENABLED; // enable shared ADC core
    adcon3.ADCON3.CNVCHSEL = ADCON3_CNVCHSEL_AN0; // set AN0 to be target for software triggers (not used)
    adcon3.ADCON3.CNVRTCH = ADCON3_CNVRTCH_READY; // reset TRIGGER READY flag bit
    adcon3.ADCON3.REFSEL = ADCON3_REFSEL_AVDD_AVSS; // set ADC reference to AVDD-toAVSS
    adcon3.ADCON3.SHRSAMP = ADCON3_SHRSAMP_HWTRIG; // use hardware trigger
    adcon3.ADCON3.SUSPCIE = ADCON3_SUSPCIE_DISABLED; // disable ISR SUSPEND interrupt 
    adcon3.ADCON3.SUSPEND = ADCON3_SUSPEND_RUN; // disable SUSPEND MODE
    adcon3.ADCON3.SUSPRDY = ADCON3_SUSPRDY_RUNNING; // reset SUSPEND mode status flag bit
    adcon3.ADCON3.SWCTRG = ADCON3_SWCTRG_READY; // set software trigger to READY
    adcon3.ADCON3.SWLCTRG = ADCON3_SWLCTRG_LVLTRG_BY_HW; // set level sensitive triggers for hardware
    adcon3.ADCON3.CNVCHSEL = ADCON3_CNVCHSEL_AN0; // configure the ADC inputs used (not used))
    
    adcon5.ADCON5.SHRCIE = ADCON5L_CxCIE_DISABLED; // disable shared core to generate common interrupts
    adcon5.ADCON5.SHRPWR = ADCON5_CxPWR_OFF; // Power off Shared Core => will be turned on later
    adcon5.ADCON5.WARMTIME = ADCON5H_WARMTIME_CLK_32768;

    // Turn on ADC module power
    fres = hsadc_module_power_up();
    fres &= hsadc_module_disable();

    // Run initialization of ADC module features (no power on yet)
    fres &= hsadc_init_adc_module(adcon1, adcon2, adcon3, adcon4, adcon5);

    // Set ADC Interrupt Trigger for the ADC inputs
    fres &= hsadc_set_adc_input_trigger_source(TP06_ADC_AN_INPUT, REG_ADTRIGxL_TRGSRC_MSTR_PWM1_TRIG1); // set trigger source
    fres &= hsadc_set_adc_input_interrupt(TP06_ADC_AN_INPUT, ADIE_ANx_ON, ADEIE_ANx_ON); // enable VSNS interrupt with early generation enabled
    
    // Set ADC Interrupt Trigger for the ADC inputs
    fres &= hsadc_set_adc_input_trigger_source(TP12_ADC_AN_INPUT, REG_ADTRIGxL_TRGSRC_MSTR_PWM1_TRIG1); // set trigger source
    fres &= hsadc_set_adc_input_interrupt(TP12_ADC_AN_INPUT, ADIE_ANx_ON, ADEIE_ANx_ON); // enable VSNS interrupt with early generation enabled

    // Set ADC interrupt
    TP06_ADC_IP = 5; // interrupt priority needs to be in sync with the config bit setting <#pragma config CTXT1 = IPL5>
    TP06_ADC_IF = 0; // reset VOUT feedback interrupt flag bit
    TP06_ADC_IE = 1; // enable VOUT feedback interrupt

    TP12_ADC_IP = 0; // interrupt priority needs to be in sync with the config bit setting <#pragma config CTXT1 = IPL5>
    TP12_ADC_IF = 0; // reset IOUT feedback interrupt flag bit
    TP12_ADC_IE = 0; // enable IOUT feedback interrupt

    // Enable ADC Module
    fres &= hsadc_module_enable();
   
    // power up ADC core
    fres &= hsadc_power_on_adc_core(TP06_ADCCORE);
    fres &= hsadc_power_on_adc_core(TP12_ADCCORE);
    

    return;
}
