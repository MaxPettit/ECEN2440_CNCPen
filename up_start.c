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
#include "uart_driver.h"


void startup_config(){
    config_pwm_timer();
    config_pwm_gpio();
    pen_config();
    start_pwm(10,z_pwm,0);
    uart_config();
}

void startup_go(){
    pen_up();
    start_msg();
}

void start_msg(){
    int err, i;
    lcd_clear();
    char *Boot = "**** Booting ***";
    char *Wait = "***Please Wait**";
    err = uart_write(Boot);
    err = uart_write(Wait);
    for(i = 0; i < 1000; i++);
    lcd_clear();
    err = uart_write("my name max me like big peen");
    if(err) return;
}

