/*
 * motor.c
 *
 *  Created on: Dec 7, 2019
 *      Author: maxpettit, Nathan
 */

#include "msp.h"
#include "pwm.h"
#include "motor.h"

/*
   Starts and stops motor pwm based on joystick position
   Determines direction of motors based on joystick position
*/
void motor_pos(volatile uint8_t pos){

    if(pos == 4){
        set_dir('x', 1);
        stop_pwm(y_pwm);
        start_pwm(x_pwm);
    }
    if(pos == 3){
        set_dir('x', 0);
        stop_pwm(y_pwm);
        start_pwm(x_pwm);
    }
    if(pos == 2){
        set_dir('y', 1);
        stop_pwm(x_pwm);
        start_pwm(y_pwm);
    }
    if(pos == 1){
        set_dir('y', 0);
        stop_pwm(x_pwm);
        start_pwm(y_pwm);
    }
    if(pos == 6){
        set_dir('y', 0);
        start_pwm(y_pwm);
        set_dir('x', 1);
        start_pwm(x_pwm);
    }
    if(pos == 5){
        set_dir('y', 1);
        start_pwm(y_pwm);
        set_dir('x', 0);
        start_pwm(x_pwm);
    }
    if(pos == 7){
        set_dir('y', 0);
        start_pwm(y_pwm);
        set_dir('x', 0);
        start_pwm(x_pwm);
    }
    if(pos == 0){
        stop_pwm(x_pwm);
        stop_pwm(y_pwm);
    }
}

void set_dir(char c, int t){
    // Toggles direction of x-axis motor based on joystick position
    if(c == 'x'){
        if(t == 1)
            P5->OUT &= ~BIT2;
        else if(t == 0)
            P5->OUT |= BIT2;
    }
    // Toggles direction of y-axis motor based on joystick position
    if(c == 'y'){
        if(t == 0)
            P2->OUT &= ~BIT7;
        else if(t == 1)
            P2->OUT |= BIT7;
    }
}
