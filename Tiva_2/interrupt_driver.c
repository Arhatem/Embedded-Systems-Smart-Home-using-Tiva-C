#include"interrupt_driver.h"
#include"/Users/mak/Desktop/co com pro/inc/tm4c123gh6pm.h"
#include"project_API.h"
extern uint32_t PORTS_BASE_ADD [];

void Gpio_interrupt_init(uint8_t port_index,uint8_t en_mask,uint8_t priorty){

	Port_Init(port_index);
	Reset_bits(Get_add(PORTS_BASE_ADD[port_index]+GPIODIR),en_mask);
	Port_SetPinPullUp(5,en_mask,1);

	Reset_bits(Get_add(PORTS_BASE_ADD[port_index]+ GPIOIS) ,en_mask);
	Reset_bits(Get_add(PORTS_BASE_ADD[port_index]+ GPIOIBE) ,en_mask);
	Reset_bits(Get_add(PORTS_BASE_ADD[port_index]+ GPIOIEV) ,en_mask);

	//Set_bits(Get_add(PORTS_BASE_ADD[port_index]+ GPIOICR),en_mask);
	GPIO_PORTF_ICR_R =0x11;
	Set_bits(Get_add(PORTS_BASE_ADD[port_index]+ GPIOIM),en_mask);

    if(port_index == 0)
	NVIC_PRI0_R = ((NVIC_PRI0_R & ~0x000000ff) | priorty<<5);
   	else if(port_index == 1)
   	NVIC_PRI0_R = ((NVIC_PRI0_R & ~0x0000ff00) | priorty<<13);
   else if(port_index == 2)
   	NVIC_PRI0_R = ((NVIC_PRI0_R & ~0x00ff0000) | priorty<<21);
   else if(port_index == 3)
   	NVIC_PRI0_R = ((NVIC_PRI0_R & ~0xff000000) | priorty<<29);
   else if(port_index == 4)
   	NVIC_PRI1_R = ((NVIC_PRI1_R & ~0x000000ff) | priorty<<5);
   else if(port_index == 5)
   {
	   NVIC_PRI7_R = ((NVIC_PRI7_R & ~0x00ff0000) | priorty<<21);
	   Set_bit(NVIC_EN0_R,30);
   }
   	if (port_index != 5)
   	{
   		Set_bit(NVIC_EN0_R,port_index);	
   	}

}
