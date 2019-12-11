/*
 * js_test.h
 *
 *  Created on: Dec 4, 2019
 *      Author: Nathan
 */

#ifndef READ_JS_H_
#define READ_JS_H_

#include "msp.h"
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

extern volatile uint16_t _nadc[32];

// Config xout and yout pins on the joystick to MSP pins for ADC reading
void joystick_configure(void);

// Experimentally get ADC values to determine semi-accurate values that correspond to joystick positions
int8_t joysticklocation(uint8_t channelx, uint8_t channely);

#endif /* READ_JS_H_ */
