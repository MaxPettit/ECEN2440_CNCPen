/*
 * up_start.h
 *
 *  Created on: Nov 20, 2019
 *      Author: maxpettit
 */

#ifndef UP_START_H_
#define UP_START_H_

/* Calls functions to configure many components
 *     UART, Timers, Interrupts, etc  */
void startup_config(void);

/* Sets pen to up and displays startup message */
void startup_go(void);

/* Writes startup message to LCD*/
void start_msg(void);

#endif /* UP_START_H_ */
