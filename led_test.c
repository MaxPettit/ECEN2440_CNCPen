/*
 * led_test.c
 *
 *  Created on: Dec 6, 2019
 *      Author: Nathan
 */
#include "msp.h"

void led_color(volatile uint8_t color){
    P2->DIR |= 0x07;                            // Enable LED
    P2->OUT = 0;                                // Set LED off

    if(color == 4)                              // Joystick Right
        P2->OUT = 0x05;                         // LED Color: Pink
    if(color == 3)                              // Joystick Left
        P2->OUT = 0x06;                         // LED Color: Aqua
    if(color == 2)                              // Joystick Up
        P2->OUT = 0x07;                         // LED Color: White
    if(color == 1)                              // Joystick Down
        P2->OUT = 0x04;                         // LED Color: Blue
    if(color == 6)                              // Joystick Bottom Right
        P2->OUT = 0x03;                         // LED Color: Yellow
    if(color == 5)                              // Joystick Top Left
        P2->OUT = 0x02;                         // LED Color: Green
    if(color == 7)                              // Joystick Bottom Left
        P2->OUT = 0x01;                         // LED Color: Red
    if(color == 0)                              // Joystick in Nuetral Position
        P2->OUT = 0;                            // Set LED off
}
