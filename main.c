#include <z_driver.h>
#include "msp.h"
#include "pwm.h"
#include "up_start.h"

/**
 * main.c
 */


void main(void)
{
//    start_pwm(50,0,100);
//    start_pwm(50,1,100);
//    start_pwm(50,3,100);


        startup_config();
        //startup_go();
        //test_z();

    P1->DIR |= BIT0; // LED
       P1->OUT &= BIT0; // LED

       while(1);

}
