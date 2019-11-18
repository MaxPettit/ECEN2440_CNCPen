/*
 * startup.c
 *
 *  Created on: Nov 18, 2019
 *      Author: maxpettit
 */

#include "pwm.h"
#include "msp.h"

void startup_config{
    config_pwm_timer();
    config_pwm_gpio();
    //config pins
    //config/enable interrupts
}

void startup_go{
    pen_up();
    start_msg();
}

void start_msg{

}

