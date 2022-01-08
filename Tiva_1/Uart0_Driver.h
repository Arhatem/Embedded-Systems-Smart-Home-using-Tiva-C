/*
 * Uart0_Driver.h
 *
 *  Created on: Apr 7, 2019
 *      Author: mak
 */

#ifndef UART0_DRIVER_H_
#define UART0_DRIVER_H_
#include<stdint.h>
#include"project_API.h"
#include"/Users/mak/Desktop/co com pro/inc/tm4c123gh6pm.h"
#include"lcd_driver.h"
#define Interrupt_enable 1
void Uart0_init();
void Uart0_tx(uint8_t data);
uint8_t Uart0_rx();
void Uart2_init();
void Uart2_tx(uint8_t data);
uint8_t Uart2_rx();
void Uart5_init();
void Uart5_tx(uint8_t data);
uint8_t Uart5_rx();

#endif /* UART0_DRIVER_H_ */
