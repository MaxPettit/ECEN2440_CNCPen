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
    P6->DIR &= ~BIT7;
    P6IES = BIT7;
    P6IE = BIT7;
    P6SEL0 &= ~BIT7;
    P6SEL1 &= ~BIT7;
    __NVIC_EnableIRQ(PORT6_IRQn);
    __NVIC_SetPriority(PORT6_IRQn, 2);
    P1->DIR = BIT0;
}

void pen_up(void){
    int err;
    TIMER_A2->CCR[1] = cnt_up;
    lcd_clear();
    err = uart_write("Pen Up");
}

void pen_down(void){
    int err;
    TIMER_A2->CCR[1] = cnt_dwn;
    lcd_clear();
    err = uart_write("Pen Down");
}

void PORT6_IRQHandler(void){
    uint32_t flag = P6IFG & BIT7;
        if(flag){
            P6IFG &= ~BIT7;
                toggle_z(); //Task
            }
}

void toggle_z(void){
    if(TIMER_A2->CCR[1] == cnt_up){
        pen_down();
    }
    else{
        pen_up();
    }

    P1->OUT ^= BIT0;
}

void test_z(void){
        config_pwm_timer();
        config_pwm_gpio();
        start_pwm(10,z_pwm,0);
    int i;
   while(1){
       pen_up();
       for(i = 0; i < 500000; i++);
      pen_down();
      for(i = 0; i < 500000; i++);
   }
}
