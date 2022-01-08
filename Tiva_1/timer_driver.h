/*
 * timer_driver.h
 */

#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_
#include"/Users/mak/Desktop/co com pro/inc/tm4c123gh6pm.h"
#include<stdint.h>
#include<stdio.h>
void Systic_init();
void Systic_wait(uint32_t delay );
void Systic_wait_10ms(uint32_t delay );


#endif /* TIMER_DRIVER_H_ */
