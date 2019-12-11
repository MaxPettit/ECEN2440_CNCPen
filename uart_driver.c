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


void uart_config(){
    //Set UCA2CTLW0: Uart, No parity, 8 bit data, 1 stop bit, LSB first
    UCA2CTLW0 = UCSWRST;        // Clear register and put into settings mode
    UCA2CTLW0 |= UCSSEL_2;      // Choose src clk, SMCLK
    UCA2CTLW0 |= UCMODE_0;      // UART mode
    UCA2CTLW0 &= ~BITD;         // LSB 1st


    // Set Baud rate based on src clk
    // 3000000 hz smclk
    UCA2MCTLW = BIT0;           // Set UCOS16
    UCA2MCTLW |= 0x8 << 4;      // UCBRF0 = 8;
    UCA2MCTLW |= 0x55 << 8;     // UCBRS0 = 0x55;
    UCA2BRW = 19;               // UCBR = 19


    //enable interrupt
    UCA2IE = UCTXIE;
    __NVIC_EnableIRQ(EUSCIA2_IRQn);

    UCA2CTLW0 &= ~UCSWRST;      // Take out of standby

    // P3.3 = TX, P3.2 = RX
    // Select pin mode
    P3->SEL0 |= BIT3;
    P3->SEL1 &= ~BIT3;
    P3->SEL0 |= BIT2;
    P3->SEL1 &= ~BIT2;

}

int uart_write(const char *str)
{
    if (str != NULL) {                      
        while (*str != '\0') {                      // While input is not null
            while (!(UCA2IFG & EUSCI_A_IFG_TXIFG)); // UCTXIFG = 1 when buffer is ready for more if it's 0, wait
            UCA2TXBUF = *str;                       // Load the string into buffer
            str++;                                  // Increment String
        }
        return 0;
    }
    return 1;
}

void lcd_clear(){
    int err;
    err = uart_write("|");                          // Put LCD into settings mode
    err = uart_write("-");                          // Clear Display
}
