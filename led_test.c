/*
 * led_test.c
 *
 *  Created on: Dec 6, 2019
 *      Author: dafre
 */
#include "msp.h"

void led_color(volatile uint8_t color){
    P2->DIR |= 0x07;
    P2->OUT = 0;

    if(color == 4)
        P2->OUT = 0x05;
    if(color == 3)
        P2->OUT = 0x06;
    if(color == 2)
        P2->OUT = 0x07;
    if(color == 1)
        P2->OUT = 0x04;
    if(color == 6)
        P2->OUT = 0x03;
    if(color == 5)
        P2->OUT = 0x02;
    if(color == 7)
        P2->OUT = 0x01;
    if(color == 0)
        P2->OUT = 0;
}

