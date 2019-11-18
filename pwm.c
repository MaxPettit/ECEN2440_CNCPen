/*
 * pwm.c
 *
 *  Created on: Sep 23, 2019
 */
#include "msp.h"
#include "pwm.h"

void config_pwm_timer(void){
 TIMER_A0->R = 0; //Reset timer
 TIMER_A0->CTL |=  TIMER_A_CTL_TASSEL_2; //Select SMCLK
 TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7; //Set reset/set output mode 0x00E0
}

void start_pwm(uint8_t duty_cycle){
 TIMER_A0->CTL |= TIMER_A_CTL_MC_1; //Set UP mode
 TIMER_A0->CCR[0] = CALC_PERIOD(PWM_FREQUENCY); //Set 30 dec

 TIMER_A0->CCR[1] |= (duty_cycle*CALC_PERIOD(PWM_FREQUENCY))/100;
}

void stop_pwm(void){
    TIMER_A0->CTL &= ~0x010;
}

void config_pwm_gpio(void){

    P2->DIR |= 0x10;
    P2->SEL1 &= ~BIT4;
    P2->SEL0 |= 0x10;


}


