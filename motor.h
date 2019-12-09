/*
 * motor.h
 *
 *  Created on: Dec 7, 2019
 *      Author: maxpettit
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#define x_pwm 0
#define y_pwm 1

void motor_pos(volatile uint8_t pos);
void set_dir(char c, int t);

#endif /* MOTOR_H_ */
