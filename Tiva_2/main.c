#include "project_API.h"
#include"lcd_driver.h"
#include"ADC_driver.h"
#include<stdint.h>
#include<stdio.h>
#include"Uart0_Driver.h"
#include"cpu.h"
#include"/Users/mak/Desktop/co com pro/inc/tm4c123gh6pm.h"
#include"interrupt_driver.h"
extern uint32_t PORTS_BASE_ADD[];
void PORTF_Interrupt();
void UART5_Handler();
uint16_t poten_value =0;
uint8_t data ;
uint8_t data1=0;
uint8_t old_data;
void main(){

Uart5_init();
Gpio_interrupt_init(PORTF,0x11,3);
CPUcpsie();
lcd_initt();
lcd_print_num(0);
Get_add(PORTS_BASE_ADD[PORTF]+GPIODEN)=0xff;
Get_add(PORTS_BASE_ADD[PORTF]+GPIODIR) |=0x0e;

Get_add(PORTS_BASE_ADD[5]+GPIODEN)=0xff;
ADC_init(PORTE,3,0,0);
__delay_us(10000);
poten_value = ADC_read(0);
data= ((float)poten_value/4095)*30;
Uart5_tx(data);
__delay_us(10000);
data = old_data;
while(1){
	poten_value = ADC_read(0);
	data= ((float)poten_value/4095)*30;
	Uart5_tx(data);
	__delay_us(10000);
	lcd_print_num(data1);
}


}




void UART5_Handler(){
  data1 =UART5_DR_R;
  Set_bit(UART5_ICR_R,4);
}


void PORTF_Interrupt(){

	if(Get_bit(GPIO_PORTF_MIS_R,0))
	{
		Uart5_tx(0x81);
		 Set_bit(GPIO_PORTF_DATA_R,2);
		    	Reset_bit(GPIO_PORTF_DATA_R,1);

	}
		else if(Get_bit(GPIO_PORTF_MIS_R,4))
	{

		Uart5_tx(0x80);
		 Set_bit(GPIO_PORTF_DATA_R,1);
		    	Reset_bit(GPIO_PORTF_DATA_R,2);

	}

	Set_bits(GPIO_PORTF_ICR_R,0x11);

}


