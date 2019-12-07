/*
 * js_test.c
 *
 *  Created on: Dec 4, 2019
 *      Author: dafre
 */

#include <read_js.h>
#include <stdlib.h>
#include <stdint.h>
#include "msp.h"
#include "adc_test.h"

void joystick_configure(void){
    P4->SEL0 |= BIT4;
    P4->SEL1 |= BIT4;
    P6->SEL0 |= BIT0;
    P6->SEL1 |= BIT0;

    P2->DIR |= 0x07;
    P2->OUT = 0;
}

int8_t jslocation(uint8_t channelx, uint8_t channely){
    int8_t location = 0;
    int16_t xaxis = ADC_getN(channelx);
    int16_t yaxis = ADC_getN(channely);

    if((xaxis >= 14000) && (yaxis >= 14000)){
        location = 4;                               // Joystick Right
        P2->OUT = 0x05;
    }
    else if ((xaxis < 15000) && (yaxis < 1000) && (xaxis> 12000)){
        location = 3;                               // Joystick Left
        P2->OUT = 0x06;
    }
    else if((xaxis > 14000) && (yaxis > 12000) && (yaxis < 14000)){
        location = 2;                               // Joystick Up
        P2->OUT = 0x07;
    }
    else if((yaxis > 12000) && (xaxis < 1000) && (yaxis < 14000)){
        location = 1;                               // Joystick Down
        P2->OUT = 0x04;
    }
    else if((xaxis < 4000) && (yaxis > 12000)){
        location = 6;                               // Joystick Bottom Right
        P2->OUT = 0x03;
    }
    else if((xaxis > 14000) && (yaxis < 6000)){
        location = 5;                               // Joystick Top Left
        P2->OUT = 0x02;
    }
    else if((xaxis < 1000) && (yaxis < 13000) && (yaxis > 3000)){
        location = 7;                               // Joystick Bottom Left
        P2->OUT = 0x01;
    }
/*    else if((xaxis > 15500) && (yaxis < 13000) && (yaxis > 3000)){
        location = 8;
    }
    else if ((xaxis < 11000) && (yaxis < 3000) && (xaxis > 7000)){
        location = 9;
    }*/
    else{
       location = 0;
       P2->OUT = 0;
    }
    return location;
}
