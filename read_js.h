/*
 * js_test.h
 *
 *  Created on: Dec 4, 2019
 *      Author: dafre
 */

#ifndef READ_JS_H_
#define READ_JS_H_

#include "msp.h"
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

extern volatile uint16_t _nadc[32];
void joystick_configure(void);
int8_t joysticklocation(uint8_t channelx, uint8_t channely);

#endif /* READ_JS_H_ */
