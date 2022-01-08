#include "project_API.h"
#include"lcd_driver.h"
#include"ADC_driver.h"
#include<stdint.h>
#include<stdio.h>
#include"Uart0_Driver.h"
#include"PWM_driver.h"
#include"stepper_motor.h"
#include"/Users/mak/Desktop/co com pro/inc/tm4c123gh6pm.h"
extern uint32_t PORTS_BASE_ADD[];
void UART5_Handler();
void UART0_Handler();
uint8_t flag_left=1;
uint8_t flag_right=1;
uint8_t volatile data = 0;
uint8_t data2=0;
uint8_t count =0;
uint8_t count2 = 0;
void main(){

	const uint8_t arr[4]={0x9,0x3,0x6,0xc};
pwm_init(PORTF,1,3,3,80000,1);
Get_add(PORTS_BASE_ADD[5]+GPIODEN)=0xff;
Set_bit(GPIO_PORTF_DIR_R,1);
Set_bit(GPIO_PORTF_DIR_R,2);
Uart5_init();
    uint16_t temp =0;
   // uint8_t old_temp =0;
    temp_init();
    Port_Init(PORTD);
    Get_add(PORTS_BASE_ADD[PORTD]+GPIODIR)|= 0x0f;

    while(1){


    	if(flag_right == 0 && count2 > 0){
        		       count2 --;
        		    		Write_bits(Get_add(PORTS_BASE_ADD[PORTD]+GPIODATA),0x0f,arr[count++ & 3]);
        		    		if (count >= 4)
        		    		{
        		    			count=0;
        		    		}

        	}
    	if(flag_left == 0 && count2 > 0){
    		count2 --;
    		Write_bits(Get_add(PORTS_BASE_ADD[PORTD]+GPIODATA),0x0f,arr[count-- & 3]);
    		if (count <= 0)
    		{
    			count=3;
    		}
    	}

    	temp = temp_read();
    data2=temp-60;
    Uart5_tx(data2);
    __delay_us(1000);
    }

}


void UART5_Handler(){
    data=UART5_DR_R;
    		if(data <= 30){

    		PWM1_3_CMPA_R= ((float)(data+97)/127)*79999;

    			}
    	   else if(data == 0x81){
        //stepper turn 30 degree left
    			flag_right =0;
    			flag_left =1;
    			 count2=160;
    			 count=0;
    //Set_bit(GPIO_PORTF_DATA_R,1);
    	//Reset_bit(GPIO_PORTF_DATA_R,2);
    	//PWM1_3_CMPA_R=79999;
    }else if(data == 0x80){
    	//stepper turn 30 degree right
    	 flag_left =0;
    	 count=0;
    	 flag_right =1;
    	 count2=160;
   // 	Set_bit(GPIO_PORTF_DATA_R,2);
    //	Reset_bit(GPIO_PORTF_DATA_R,1);
   // 	PWM1_3_CMPA_R=79999;
    }

    	Set_bit(UART5_ICR_R,4);
}


void UART0_Handler(){

lcd_print_num(0);

}
