/*
 * adc_test.h
 *
 *  Created on: Dec 4, 2019
 *      Author: dafre
 */
#include "msp.h"
#include <stdint.h>

#ifndef ADC_TEST_H_
#define ADC_TEST_H_

void ADC_init();
void ADC_addChannel(uint8_t channel, uint8_t map, uint8_t vref);
uint16_t ADC_getN(uint8_t channel);
double ADC_getMV(uint8_t channel);
void ADC_EOS(uint8_t channel);
void ADC_start();

#endif /* ADC_TEST_H_ */
