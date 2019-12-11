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
    config_pwm_timer();  // Configure timer settings
    config_pwm_gpio();   // Configure timer pin outputs
    pen_config();        // Enable/Configure interrupt for pen
    start_pwm(z_pwm);    // Start the pen PWM
    uart_config();       // Configure UART settings
}

void startup_go(){
    pen_up();            // Set the pen up to start
    start_msg();         // Print startup message
}

void start_msg(){        // Prints startup message
    int err, i;
    lcd_clear();
    char *Boot = "**** Booting ***";
    char *Wait = "***Please Wait**";  // Motor driver needs small amount of time after power up before use
    err = uart_write(Boot);
    err = uart_write(Wait);
    for(i = 0; i < 10000; i++);
    lcd_clear();
    err = uart_write("Go");
    if(err) return;
}

