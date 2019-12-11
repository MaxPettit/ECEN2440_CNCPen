/*
 * pwm.h
 *
 *  Created on: Sep 23, 2019
 *      Author: maxpettit
 */

#include <stdint.h>

#ifndef PWM_H_
#define PWM_H_

/*   DEFINES  */
#define SYSTEM_CLOCK        3000000  // [Hz] system_msp432p401r.c
#define PWM_FREQUENCY       10   // [Hz] PWM frequency desired
#define CALC_PERIOD(X)      (SYSTEM_CLOCK / X) //calc # of ticks in period


/* Configure TIMER_A0-A3 to produce PWM waveform
 * - Resets R (timer counter) register
 * - Selects SMCLK (3MHz) in the CTL register
 * - Selects reset/set output mode using CCTL[1]
 */
void config_pwm_timer(void);


/*  Starts PWM signal on Pin XX
 *  - TODO: enable/start timer (UP mode)
 */
void start_pwm(uint8_t timer_sel);


/* Stop Mode */
void stop_pwm(uint8_t timer_sel);


/* Config P2.4 to output TA0.1 waveform 
* - P7.7 for TA1
* - P5.6 for TA2
* - P10.5 for TA3
*/
void config_pwm_gpio(void);


#endif /* PWM_H_ */
