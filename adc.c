/*
 * adc.c
 *
 *  Created on: Dec 1, 2019
 *      Author: Nathan
 */
#include <adc.h>
#include "msp.h"

volatile uint16_t _nadc[32];
volatile uint8_t _eos;                                                      // channel to end the sequence on

void ADC_init(){
    while(REF_A->CTL0 & REF_A_CTL0_GENBUSY);                                //If ref generator busy, wait
    REF_A->CTL0 = REF_A_CTL0_VSEL_0 | REF_A_CTL0_ON;                        // Set/enable internal 1.2V ref
    ADC14->CTL0 |= ADC14_CTL0_SHT0_5                                        // ADC14 sample-and-hold time: 96 cycle sample time on SHT0
                | ADC14_CTL0_SHT1_5                                         // ADC14 sample-and-hold time: 96 cycle sample time on SHT1
                | ADC14_CTL0_SHP                                            // SAMPCON signal is sourced from the sampling timer
                | ADC14_CTL0_MSC                                            // Starts automatic sample conversion
                | ADC14_CTL0_CONSEQ_3                                       // Conversion sequence: repeat-sequence-of-channels
                | ADC14_CTL0_SSEL__HSMCLK                                   // Set ADC14 clock source: HSMCLK
                | ADC14_CTL0_ON;                                            // Turn on ADC14

    ADC14->CTL1 |= ADC14_CTL1_RES__14BIT;                                   // 14-bit resolution
    while(!(REF_A->CTL0 & REF_A_CTL0_GENRDY));                              // Wait for ref generator to settle
    ADC14->CTL0 |= ADC14_CTL0_ENC;                                          // Enable Conversions
    NVIC_EnableIRQ(ADC14_IRQn);                                             // Enable ADC int in NVIC module
}

// ADC 14 interrupt handler
void ADC14_IRQHandler(){
    int i;
    for(i=0;i<=_eos;i++) {
        if(ADC14->IFGR0 & (1<<i)) {
            _nadc[i] = ADC14->MEM[i];
        }
    }
}

// End of conversion in sequence
void ADC_EOS(uint8_t channel){
    ADC14->MCTL[channel]|=ADC14_MCTLN_EOS;
    _eos=channel;
}

// Start ADC14 conversions
void ADC_start(){
    ADC14->CTL0 |= ADC14_CTL0_SC;
}

void ADC_addChannel(uint8_t channel, uint8_t map, uint8_t vref){
    if(channel>31) return;
    if(vref!=0 && vref!=1) return;
    ADC14->CTL0 &= ~ADC14_CTL0_ENC;                                         // Disable ADC14 conversions
    ADC14->MCTL[channel] |= map | (vref<<8);                                // Map MCTL[channel] to a specific pin and set vref
    ADC14->IER0 |= (1<<channel);                                            // Enable interrupt for that channel
    ADC14->CTL0 |= ADC14_CTL0_ENC;                                          // Enable ADC14 Conversions
}

uint16_t ADC_getN(uint8_t channel){
    if(channel>31){
        return 0;
    }
    return _nadc[channel];                                                  // Return the stored MEM[channel] value
}

double ADC_getMV(uint8_t channel){
    if(channel>31){
        return 0;
    }
    int vref = 1200*((ADC14->MCTL[channel]&ADC14_MCTLN_VRSEL_1)>0)+3300*((ADC14->MCTL[channel]&ADC14_MCTLN_VRSEL_1)==0);
    return ((double)ADC_getN(channel))*(((double)vref)/(1<<14));
}
