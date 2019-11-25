/*
 * up_start.c
 *
 *  Created on: Nov 20, 2019
 *      Author: maxpettit
 */


#include "pwm.h"
#include "msp.h"
#include "z_driver.h"
#include "up_start.h"


void startup_config(){
    config_pwm_timer();
    config_pwm_gpio();
    pen_config();
    start_pwm(10,z_pwm,0);
    //config pins
    //config & enable interrupt
}

void startup_go(){
    pen_up();
    start_msg();
}

void start_msg(){

}

