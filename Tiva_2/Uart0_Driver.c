/*
 * Uart0_Driner.c
 *
 *  Created on: Apr 7, 2019
 *      Author: mak
 */


#include"Uart0_Driver.h"
#include"CPU.h"
#include<stdio.h>

void Uart0_init(){

	SYSCTL_RCGCUART_R |=0x1;
	while(!Get_bit(SYSCTL_PRUART_R,0));
	
	SYSCTL_RCGCGPIO_R |=0x1;
	while(!Get_bit(SYSCTL_PRGPIO_R,0));
	

	Reset_bit(UART0_CTL_R,0);//disable uart0 during congigration
	
	UART0_IBRD_R=520;//bud rate
	UART0_FBRD_R=53;
	

	UART0_CC_R= 0;//use system clock
	
	UART0_LCRH_R=0x60;
	

	if (Interrupt_enable == 1)
	{
	Set_bit(UART0_IM_R,4);
	NVIC_PRI1_R = ((NVIC_PRI1_R & ~0x000000ff) | 3<<13);
	Set_bit(NVIC_EN0_R,5);
	CPUcpsie();
	}

	UART0_CTL_R=0x301;

	GPIO_PORTA_DEN_R=0x03;
	GPIO_PORTA_AFSEL_R=0x03;
	GPIO_PORTA_PCTL_R=0x11;

	__delay_us(1000);
}

void Uart0_tx(uint8_t data){


	while((UART0_FR_R & 0x20) != 0){}
		UART0_DR_R=data;

}
uint8_t Uart0_rx(){
	while((UART0_FR_R & 0x10)!= 0){}
	return (char)UART0_DR_R;
}

void Uart2_init(){

	Set_bit(SYSCTL_RCGCUART_R,2);
	while(!Get_bit(SYSCTL_PRUART_R,2));
	
	Set_bit(SYSCTL_RCGCGPIO_R,3);
	while(!Get_bit(SYSCTL_PRGPIO_R,3));
	

	Reset_bit(UART2_CTL_R,0);//disable uart0 during congigration
	
	UART2_IBRD_R=520;//bud rate
	UART2_FBRD_R=53;
	

	UART2_CC_R= 0;//use system clock
	
	UART2_LCRH_R=0x60;
	

	if (Interrupt_enable == 1)
	{
	Set_bit(UART2_IM_R,4);
	NVIC_PRI15_R =0;
	Set_bit(NVIC_EN1_R,1);
	CPUcpsie();
	}

	UART2_CTL_R=0x301;

	GPIO_PORTD_DEN_R=0xc0;
	GPIO_PORTD_AFSEL_R=0xc0;
	GPIO_PORTD_PCTL_R=0x11000000;

	__delay_us(1000);
}

void Uart2_tx(uint8_t data){


	while((UART2_FR_R & 0x20) != 0){}
		UART2_DR_R=data;

}
uint8_t Uart2_rx(){
	while((UART2_FR_R & 0x10) != 0){}
	return (uint8_t)UART2_DR_R;
}
/*

void Uart5_init(){

	Set_bit(SYSCTL_RCGCUART_R,5);
	while(!Get_bit(SYSCTL_PRUART_R,5));

	Set_bit(SYSCTL_RCGCGPIO_R,4);
	while(!Get_bit(SYSCTL_PRGPIO_R,4));


	//Reset_bit(UART5_CTL_R,0);//disable uart0 during congigration
	UART5_CTL_R =0;

	UART5_IBRD_R=520;//bud rate
	UART5_FBRD_R=53;


	UART5_CC_R= 0;//use system clock

	UART5_LCRH_R=0x70;
	UART5_CTL_R=0x301;
	GPIO_PORTE_DEN_R=0x30;
	GPIO_PORTE_AFSEL_R=0x30;
	GPIO_PORTE_PCTL_R=0x00110000;

	__delay_us(1000);
}
*/

void Uart5_init(){

	Set_bit(SYSCTL_RCGCUART_R,5);
	while(!Get_bit(SYSCTL_PRUART_R,5));
	
	Set_bit(SYSCTL_RCGCGPIO_R,4);
	while(!Get_bit(SYSCTL_PRGPIO_R,4));
	

	//Reset_bit(UART5_CTL_R,0);//disable uart0 during congigration
	UART5_CTL_R =0;

	UART5_IBRD_R=520;//bud rate
	UART5_FBRD_R=53;
	
	if (Interrupt_enable == 1)
		{
		UART5_ICR_R =0x10;
		Set_bit(UART5_IM_R,4);
		NVIC_PRI15_R =0;
		Set_bit(NVIC_EN1_R,29);
		CPUcpsie();

		}
	UART5_CC_R= 0;//use system clock
	
	UART5_LCRH_R=0x70;
	UART5_CTL_R=0x301;
	GPIO_PORTE_DEN_R=0x30;
	GPIO_PORTE_AFSEL_R=0x30;
	GPIO_PORTE_PCTL_R=0x00110000;

	__delay_us(1000);
}

void Uart5_tx(uint8_t data){

	while((UART5_FR_R & 0x20) != 0){}
		UART5_DR_R=data;

}

uint8_t Uart5_rx(){
	while((UART5_FR_R & 0x10) != 0){}
	uint8_t x=UART5_DR_R;
	return x;
}

