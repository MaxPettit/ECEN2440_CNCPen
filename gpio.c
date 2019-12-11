/*
 * gpio.c
 *
 *  Created on: Dec 7, 2019
 *      Author: Efram Aredo
 */

#include "msp.h"
#include "gpio.h"
void config_drv_gpio(void){

//Rising edge moves indexer to next step.

// direction pin */
// Level sets direction of step
// direction pin correspond from msp to drv8834 x
// Output gets set by Joystick
    P5->DIR |= BIT2; // P1.2 output
    P5->SEL1 &= ~BIT2; // P1.2 select primary function
    P5->SEL0 &= ~BIT2; // P1.2 select primary function
    

// Enbale pin 
// Logic low enables all outputs.
// enable pin correspond from msp to drv8834
    P2->DIR |= BIT5;
    P2->OUT &= ~BIT5;
    P2->SEL1 &= ~BIT5;
    P2->SEL0 |= BIT5;

// pins for setting step size
// Controls microstep mode (full, half, up to 1/32-step) along with M1.
// full speed M0 & M1 are low
// #define M0 13
    P3->DIR |= BIT0;
    P3->OUT |= BIT0;
    P3->SEL1 &= ~BIT0;
    P3->SEL0 &= ~BIT0;

  // #define M1 14
    P5->DIR |= BIT0;
    P5->OUT|= BIT0;
    P5->SEL1 &= ~BIT0;
    P5->SEL0 &= ~BIT0;
    
     /* config pin  */
//   Logic high to put the device in indexer mode.
    P1->DIR |= BIT6;
    P1->OUT|=BIT6;
    P1->SEL1 &= ~BIT6;
    P1->SEL0 &= ~BIT6;

     /* sleep pin  */
// Logic high to enable device,
//logic low to enter low-power sleep mode and reset all internal logic.
    P1->DIR |= BIT7;
    P1->OUT|=BIT7;
    P1->SEL1 &= ~BIT7;
    P1->SEL0 &= ~BIT7;



    /*Motor 2*/
    
    /* direction pin */
    //Level sets direction of step.
    // direction pin correspond from msp to drv8834 x
    // Output gets set by Joystick
        P3->DIR |= BIT7; // P1.2 output
        P3->SEL1 &= ~BIT7; // P1.2 select primary function
        P3->SEL0 &= ~BIT7; // P1.2 select primary function

    /* Enbale pin */
    //Logic low enables all outputs.
    //enable pin correspond from msp to drv8834
        P3->DIR |= BIT5;
        P3->OUT &= ~BIT5;
        P3->SEL1 &= ~BIT5;
        P3->SEL0 |= BIT5;

    // pins for setting step size
    // Controls microstep mode (full, half, up to 1/32-step) along with M1.
    // full speed M0 & M1 are low
    
        P5->DIR |= BIT1;
        P5->OUT |= BIT1;
        P5->SEL1 &= ~BIT1;
        P5->SEL0 &= ~BIT1;

      // #define M1 14
        P3->DIR |= BIT6;
        P3->OUT&= ~BIT6;
        P3->SEL1 &= ~BIT6;
        P3->SEL0 &= ~BIT6;
    
      /* config pin  */
    // Logic high to put the device in indexer mode.
        P5->DIR |= BIT4;
        P5->OUT|= BIT4;
        P5->SEL1 &= ~BIT4;
        P5->SEL0 &= ~BIT4;

    /* sleep pin  */
    //Logic high to enable device,
    //logic low to enter low-power sleep mode and reset all internal logic.
        P5->DIR |= BIT5;
        P5->OUT|=BIT5;
        P5->SEL1 &= ~BIT5;
        P5->SEL0 &= ~BIT5;
}




