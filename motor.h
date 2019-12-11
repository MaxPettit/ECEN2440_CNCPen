/*
 * motor.h
 *
 *  Created on: Dec 7, 2019
 *      Author: maxpettit, Nathan
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#define x_pwm 0
#define y_pwm 1

/*
   Starts and stops motor pwm based on joystick position
   Determines direction of motors based on joystick position
*/
void motor_pos(volatile uint8_t pos);

// Toggles direction of motors based on joystick position
void set_dir(char c, int t);

#endif /* MOTOR_H_ */
