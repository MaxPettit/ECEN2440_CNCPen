/*
 * gpio.h
 *
 *  Created on: Oct 17, 2019
 *      Author: maxpettit
 */

#ifndef Z_DRIVER_H_
#define Z_DRIVER_H_

#define z_pwm   2
#define dwn  6.6                                // Duty cycle for pen down position
#define up 7.2                                  // Duty cycle for pen up position
#define cnt_up    (up*CALC_PERIOD(200))/100     // CCR1 value if pen is up
#define cnt_dwn    (dwn*CALC_PERIOD(200))/100   // CCR1 value if pen is down

/* Configures and enables interrupt */
void pen_config(void);

/* Sets pen to up position */
void pen_up(void);

/* Sets pen to down position */
void pen_down(void);

/* Called from IRQ handler
 * Toggles the pen position and toggles LED
 */
void toggle_z(void);

/* Function used for testing 
 * used to determine optimal values for duty cycles
 */
void test_z(void);

#endif /* Z_DRIVER_H_ */
