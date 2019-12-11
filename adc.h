/*
 * adc.h
 *
 *  Created on: Dec 4, 2019
 *      Author: Nathan
 */
#include "msp.h"
#include <stdint.h>

#ifndef ADC_H_
#define ADC_H_

/* 
   Checks for ref and enable internal vref
   Sets ADC14 sample-and-hold times
   Stars ADC sample conversions
   Sets ADC14 clock source
   Turns on ADC14
   Sets 14-bit resolution
   Enables ADC conversions and ADC in in NVIC module
*/
void ADC_init();

/* 
   Maps MCTL channel to a pin on the MSP432 and sets vref
   Enables interrupt for channel and enables the ADC conversions
*/
void ADC_addChannel(uint8_t channel, uint8_t map, uint8_t vref);

// Returns ADC value stored in MEM
uint16_t ADC_getN(uint8_t channel);

// Returns ADC value after conversion
double ADC_getMV(uint8_t channel);

// Ends conversion in a sequence of ADC readings
void ADC_EOS(uint8_t channel);

// Starst ADC conversions
void ADC_start();

#endif /* ADC_H_ */
