/*
 * pwm.c
 *
 *  Created on: Sep 23, 2019
 */

#include "msp.h"
#include "pwm.h"

void config_pwm_timer(){
    int a_per = 20;
    int z_per = 200;
    //A0 = x axis
    TIMER_A0->R = 0; //Reset timer
    TIMER_A0->CTL |=  TIMER_A_CTL_TASSEL_2; //Select SMCLK
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7; //Set reset/set output mode 0x00E0
    TIMER_A0->CCR[0] = CALC_PERIOD(a_per);//Set ticks
    TIMER_A0->CCR[1] = (50*CALC_PERIOD(a_per))/100;

    //A1 = y axis
    TIMER_A1->R = 0; //Reset timer
    TIMER_A1->CTL |=  TIMER_A_CTL_TASSEL_1; //Select SMCLK
    TIMER_A1->CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7; //Set reset/set output mode 0x00E0
    TIMER_A1->CCR[0] = CALC_PERIOD(a_per);//Set ticks
    TIMER_A1->CCR[1] |= 50*CALC_PERIOD(a_per)/100;

    //A2 = z axis
    TIMER_A2->R = 0; //Reset timer
    TIMER_A2->CTL |=  TIMER_A_CTL_TASSEL_2; //Select SMCLK
    TIMER_A2->CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7; //Set reset/set output mode 0x00E0
    TIMER_A2->CTL |= BIT7; //Clock divider of 4
    TIMER_A2->CCR[0] = CALC_PERIOD(z_per); //Set ticks
    TIMER_A2->CCR[1] = (50*CALC_PERIOD(z_per))/100;

}

void start_pwm(uint8_t duty_cycle, uint8_t timer_sel){
    if(timer_sel == 0){//A0 = x axis
        TIMER_A0->CTL |= TIMER_A_CTL_MC_1;
    }
    if(timer_sel == 1){//A1 = y axis
        TIMER_A1->CTL |= TIMER_A_CTL_MC_1;
    }
    if(timer_sel == 2){//A2 = z axis
        TIMER_A2->CTL |= TIMER_A_CTL_MC_1;
    }
}

void stop_pwm(uint8_t timer_sel){
    if(timer_sel == 0)
        TIMER_A0->CTL &= ~0x010;
    if(timer_sel == 1)
            TIMER_A1->CTL &= ~0x010;
    if(timer_sel == 2)
            TIMER_A2->CTL &= ~0x010;
}

void config_pwm_gpio(void){
    //TimerA0 P2.4 2.4 of course
    P2->DIR |= BIT4;
    P2->SEL1 &= ~BIT4;
    P2->SEL0 |= BIT4;

    //TimerA1 P7.7 or P8.0 8.0 works 7.7 also good use 7.7
    P7->DIR |= BIT7;  //7.7 also works
    P7->SEL1 &= ~BIT7;
    P7->SEL0 |= BIT7;

    //TimerA2 P8.1 or P5.6 5.6 is good
    P5->DIR |= BIT6;
    P5->SEL1 &= ~BIT6;
    P5->SEL0 |= BIT6;





