/*
 * gpio.h
 *
 *  Created on: Oct 17, 2019
 *      Author: maxpettit
 */

#ifndef Z_DRIVER_H_
#define Z_DRIVER_H_

#define z_pwm   2
#define up_freq   300000 //place holder numbers
#define down_freq 100000 //place holder numbers

void pen_config(void);
void pen_up(void);
void pen_down(void);
//void IRQ_handler(); //to be renamed appropriately
void toggle_z(void);
void test_z(void);

#endif /* Z_DRIVER_H_ */
