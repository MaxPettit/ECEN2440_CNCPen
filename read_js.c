#include "msp.h"
#include "read_js.h"
#include "stdint.h"

/*
 * read_js.c
 *
 *  Created on: Nov 26, 2019
 *      Author: Nathan
 */

void config_js(){
    P4->DIR &= ~BIT5;                                   // P4.5 input
    P4->SEL1 |= BIT5;                                   // Config P4.5 for ADC
    P4->SEL0 |= BIT5;

    P4->DIR &= ~BIT6;                                   // P4.6 input
    P4->SEL1 |= BIT6;                                   // Config P4.6 for ADC
    P4->SEL0 |= BIT6;

    P2->DIR |= 0x07;                                    // Sets led for testing
    P2->OUT = 0;                                        // Sets led off initially

    __enable_interrupt();
    NVIC->ISER[0] = 1 << ((24) & 31);                   // Enable ADC interrupt ***come back***

    ADC14->CTL0 = ADC14_CTL0_SHT0_2 | ADC14_CTL0_SHP | ADC14_CTL0_ON;     // Config ADC14, ADC14 on
    ADC14->CTL1 = ADC14_CTL1_RES_2;                     // Sampling timer

    ADC14->MCTL[0] |= 8;                                // A8 ADC input
    ADC14->IER0 |= ADC14_IER0_IE0;                      // Enable ADC conversion interrupt

    ADC14->MCTL[1] |= 7;                                // A7 ADC input
    ADC14->IER0 |= ADC14_IER0_IE0;                      // Enable ADC conversion interrupt

    //SCB_SCR &= ~SCB_SCR_SLEEPONEXIT;
}

void js_position(){
    if(ADC14->MEM[0] >= 0x7FF)
        P2->OUT = 0x07;
    if(ADC14->MEM[0] <= 0x0000)
        P2->OUT = 0x01;
    if(ADC14->MEM[1] >= 0x7FF)
        P2->OUT = 0x05;
    if(ADC14->MEM[1] <= 0x0000)
        P2->OUT = 0x03;
    else
        P2->OUT = 0;
}

