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
#include <stdio.h>
#include <stdlib.h>

void pen_config(void){
    P6->DIR &= ~BIT6;
    P6IES = BIT6;
    P6IE = BIT6;
    P6SEL0 = ~BIT6;
    P6SEL1 = ~BIT6;
    __NVIC_EnableIRQ(PORT6_IRQn);
    __NVIC_SetPriority(PORT6_IRQn, 2);
   // P10->DIR |= BIT0;
}

void pen_up(void){
    int up = 8;
    TIMER_A2->CCR[1] = (up*CALC_PERIOD(200))/100;

}

void pen_down(void){
//    stop_pwm(z_pwm);
//    start_pwm(5,z_pwm,0);
    int dwn = 5;
    TIMER_A2->CCR[1] = (dwn*CALC_PERIOD(200))/100;

}

void PORT6_IRQHandler(void){
    uint32_t flag = P6IFG & BIT4;
        if(flag){
            P6IFG &= ~BIT4;
                toggle_z(); //Task
            }
}

void toggle_z(void){
    P10->OUT ^= BIT4;
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
