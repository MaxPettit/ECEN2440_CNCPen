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
    WDTCTL = WDTPW | WDTHOLD;                                       // Stop WDT
    SCB->SCR &= ~SCB_SCR_ENABLE_SLEEPONEXIT;

    startup_config();                                               // Config PWM, servo, and LCD
    config_drv_gpio();                                              // Config motor driver board GPIO
    startup_go();                                                   // Starts servo PWM and displays start-up message

#ifdef JOYSTICK
    joystick_configure();                                           // Configure Joystick
#endif

#ifdef ADC
    ADC_init();                                                     // Config ADC
    ADC_addChannel(0,15,0);                                         // Set MEM0 for x-axis
    ADC_addChannel(4,9,0);                                          // Set MEM4 for y-yaxis
    ADC_EOS(15);                                                    // Enable EOS
    ADC_start();                                                    // Enable ADC
#endif
    __enable_irq();                                                 // Enable Interrupts

    while(1){                                                       // While loop to keep program running and get ADC readings
#ifdef JOYSTICK
        value = jslocation(0,4);                                    // Set a value based on joystick position
        motor_pos(value);                                           // Moves motor based on joystick position
        led_color(value);                                           // Changes LED based on joystick position
#endif
    }
}
