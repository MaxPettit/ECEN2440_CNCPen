#define ADC
#define JOYSTICK
#define TIMER

#include "z_driver.h"
#include <stdint.h>
#include <stdio.h>
#include "msp.h"
#include "pwm.h"
#include "up_start.h"
#include "uart_driver.h"
#include <adc.h>
#include <read_js.h>
#include "motor.h"
#include "gpio.h"

#define SCB_SCR_ENABLE_SLEEPONEXIT (0x00000002)
volatile uint8_t value;


void main(void) {
    WDTCTL = WDTPW | WDTHOLD;                 // Stop WDT
    SCB->SCR &= ~SCB_SCR_ENABLE_SLEEPONEXIT;

    startup_config();
    config_drv_gpio();
    startup_go();

#ifdef JOYSTICK
    joystick_configure(); // Configure Joystick P1 stuff
#endif
/*#ifdef LED
    config_LED();
#endif*/
#ifdef ADC
    ADC_init(); // Analog to digital configuration
    ADC_addChannel(0,15,0); // MEM0 x dir
    ADC_addChannel(4,9,0); // MEM4 y dir
    ADC_EOS(15); // Enable EOS
    ADC_start(); // Enable ADC
#endif
    __enable_irq(); // Enable Interrupts

   // start_pwm(x_pwm);
  //      P2->OUT |= BIT6;

    while(1){
#ifdef JOYSTICK
//        for(int i=0; i<1000; i++);
        value = jslocation(0,4);
        motor_pos(value);
        led_color(value);


#endif
    }

//    int i;
//    for(i=0; i<1000000; i++);
//    config_drv_gpio();
//    for(i=0; i<10000; i++);
//    start_pwm(0);
//    start_pwm(1);
//
//    while(1);

}
