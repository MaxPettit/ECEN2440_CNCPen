/*
 * uart_driver.h
 *
 *  Created on: Nov 29, 2019
 *      Author: maxpettit
 */

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

/* Configure eUSCI_A2 */
void uart_config();

/* Write to LCD, returns 1 if error, 0 otherwise
 *    Error will only occur if trying to print empty string
 *    For most uses, output is ignored
 */
int uart_write(const char *str);

/* Send characters that cause LCD to clear display */
void lcd_clear();

#endif /* UART_DRIVER_H_ */
