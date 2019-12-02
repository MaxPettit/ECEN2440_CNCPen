/*
 * uart_driver.c
 *
 *  Created on: Nov 27, 2019
 *      Author: maxpettit
 */

#include "msp.h"
#include "uart_driver.h"
#include <stdio.h>
#include <stdlib.h>

/*
Need to figure out correct baud rate settings
 */

void uart_config(){
    UCA2CTLW0 = UCSWRST;
    UCA2CTLW0 |= UCSSEL_2; // choose src clk
    UCA2CTLW0 |= UCMODE_0;
    UCA2CTLW0 |= BITD; //MSB 1st
    //UCA2CTLW0 &= ~BITD; //LSB 1st
    UCA2MCTLW = BIT0; //UCOS16

    /*
    UCA2MCTLW |= 0x2 << 4;// UCBRF0 = 2;
    UCA2MCTLW |= 0x00 << 8; //UCBRS0 = 0x00;
    UCA2BRW = 78; //UCBR
    */


       UCA2MCTLW |= 0x8 << 4;// UCBRF0 = 8;
       UCA2MCTLW |= 0x20 << 8; //UCBRS0 = 0x20;
       UCA2BRW = 6; //UCBR


    //enable interrupt
    UCA2IE = UCTXIE;
    __NVIC_EnableIRQ(EUSCIA2_IRQn);

    UCA2CTLW0 &= ~UCSWRST; //take out of standby

    //P3.3 = TX, P3.2 = RX
    P3->SEL0 |= BIT3;
    P3->SEL1 &= ~BIT3;
    P3->SEL0 |= BIT2;
    P3->SEL1 &= ~BIT2;

}

int uart_write(const char *str)
{
    if (str != NULL) {
        while (*str != '\0') {
            while (!(UCA2IFG & EUSCI_A_IFG_TXIFG));
            UCA2TXBUF = *str;
            str++;
        }
        return 0;
    }
    return 1;
}

void uart_char(const int *c)
{
            UCA2TXBUF = *c;
}

void lcd_config(){
}
