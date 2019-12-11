/*
 * z_driver.c
 *
 *  Created on: Nov 18, 2019
 *      Author: maxpettit
 */
#include "msp.h"
#include "pwm.h"
#include "up_start.h"
#include "z_driver.h"
#include "uart_driver.h"
#include <stdio.h>
#include <stdlib.h>

void pen_config(void){
    P6->DIR &= ~BIT7; // Set P6.7 as input
    P6IES = BIT7;
    P6IE = BIT7; // Enable interrupts on P6.7
    P6SEL0 &= ~BIT7; 
    P6SEL1 &= ~BIT7; // Set P6.7 to trigger interrupt on falling edge
    __NVIC_EnableIRQ(PORT6_IRQn);
    __NVIC_SetPriority(PORT6_IRQn, 2);
    P1->DIR |= BIT0;
}

void pen_up(void){
    int err;
   // TIMER_A2->CCR[1] = cnt_up;
    TIMER_A3->CCR[1] = cnt_up;  // Set CCR1 thereby changing duty cycle
    lcd_clear();                // Clear LCD
    err = uart_write("Pen Up"); // Write Pen up to LCD, err is ignored (error in uart_write does not occur)
}

void pen_down(void){
    int err;
   // TIMER_A2->CCR[1] = cnt_dwn;
    TIMER_A3->CCR[1] = cnt_dwn; // Set CCR1 thereby changing duty cycle
    lcd_clear();                // Clear LCD
    err = uart_write("Pen Down"); // Write Pen Down to LCD, err is ignored
}

void PORT6_IRQHandler(void){
    uint32_t flag = P6IFG & BIT7;
        if(flag){
            P6IFG &= ~BIT7; // Clear flag
                toggle_z(); // Do toggling in separate function
            }
}

void toggle_z(void){
    if(TIMER_A3->CCR[1] == cnt_up){ // If the duty cycle currently corresponds to pen_up do pen_down
        pen_down();
    }
    else{                           // If the duty cycle currently corresponds to pen_down do pen_up
        pen_up();
    }

    P1->OUT ^= BIT0;                // Toggle LED on board
}

void test_z(void){
        config_pwm_timer();
        config_pwm_gpio();
        start_pwm(2);
    int i;
   while(1){                        // Cycle through positions over time
       pen_up();
       for(i = 0; i < 500000; i++);
      pen_down();
      for(i = 0; i < 500000; i++);
   }
}
