/*
 * js_test.c
 *
 *  Created on: Dec 4, 2019
 *      Author: Nathan
 */

#include <stdlib.h>
#include <stdint.h>
#include "msp.h"
#include "adc.h"
#include "read_js.h"

// Config joystick xout and yout to MSP pins for ADC reading
void joystick_configure(void){
    P4->SEL0 |= BIT4;                                                       // Config P4.4 for ADC
    P4->SEL1 |= BIT4;
    P6->SEL0 |= BIT0;                                                       // Config P6.0 for ADC
    P6->SEL1 |= BIT0;
}

int8_t jslocation(uint8_t channelx, uint8_t channely){
    int8_t location = 0;                                                    // Sets joystick to neutral initially
    int16_t xaxis = ADC_getN(channelx);                                     // Get ADC reading on x-axis
    int16_t yaxis = ADC_getN(channely);                                     // Get ADC reading on y-axis

    if((xaxis < 14500) && (xaxis > 12000) && (yaxis >= 16000)){
        location = 4;                                                       // Joystick Right
    }
    else if ((xaxis < 15000) && (yaxis < 1000) && (xaxis> 12000)){
        location = 3;                                                       // Joystick Left
    }
    else if((xaxis > 16000) && (yaxis > 12000) && (yaxis < 14500)){
        location = 2;                                                       // Joystick Up
    }
    else if((yaxis > 12000) && (xaxis < 1000) && (yaxis < 14000)){
        location = 1;                                                       // Joystick Down
    }
    else if((xaxis < 4000) && (yaxis > 12000)){
        location = 6;                                                       // Joystick Bottom Right
    }
    else if((xaxis > 14000) && (yaxis < 6000)){
        location = 5;                                                       // Joystick Top Left
    }
    else if((xaxis < 1000) && (yaxis < 13000) && (yaxis > 3000)){
        location = 7;                                                       // Joystick Bottom Left
    }
    else{
       location = 0;                                                        // Joystick in neutral position
    }
    return location;
}
