/*
 * uart_driver.h
 *
 *  Created on: Nov 29, 2019
 *      Author: maxpettit
 */

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

void uart_config();
int uart_write(const char *str);
void uart_char(const int *c);
void lcd_config();

#endif /* UART_DRIVER_H_ */
