/*
 * gpio.h
 *
 *  Created on: Oct 17, 2019
 *      Author: maxpettit
 */

#ifndef Z_DRIVER_H_
#define Z_DRIVER_H_

#define z_pwm   2
#define dwn  6.6
#define up 7.2
#define cnt_up    (up*CALC_PERIOD(200))/100
#define cnt_dwn    (dwn*CALC_PERIOD(200))/100

void pen_config(void);
void pen_up(void);
void pen_down(void);
void toggle_z(void);
void test_z(void);

#endif /* Z_DRIVER_H_ */
