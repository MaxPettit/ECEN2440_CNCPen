
#define ADC
#define JOYSTICK
#define TIMER

#include <z_driver>
#include <stdint.h>
#include <stdio.h>
#include "msp.h"
#include "pwm.h"
#include "up_start.h"
#include "uart_driver.h"
#include <adc.h>
#include <read_js.h>

#define SCB_SCR_ENABLE_SLEEPONEXIT (0x00000002)
volatile uint8_t value;


void main(void) {
    WDTCTL = WDTPW | WDTHOLD;                 // Stop WDT
    SCB->SCR &= ~SCB_SCR_ENABLE_SLEEPONEXIT;
    
    startup_config();
    startup_go();
    start_pwm(0,1);
    start_pwm(0,0);

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
    while(1){
#ifdef JOYSTICK
        value = jslocation(0,4);
        led_color(value);

#endif
    }

/*    configure_ADC();
    P2->DIR |= 0x07;
    P2->OUT = 0x05;
    if(value == 4)
        P2->OUT = 0x07;
    if(value == 3)
        P2->OUT = 0x05;
    if(value == 2)
        P2->OUT = 0x03;
    if(value == 1)
        P2->OUT = 0x01;
    else
        P2->OUT = 0;*/
}
