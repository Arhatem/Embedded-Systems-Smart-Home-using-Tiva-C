#include"project_API.h"
#include"/Users/mak/Desktop/co com pro/inc/tm4c123gh6pm.h"

uint32_t PORTS_BASE_ADD []={0x40004000,0x40005000,0x40006000,0x40007000, 0x40024000,0x40025000};

void Port_Init( uint8_t port_index){
Set_bit(SYSCTL_RCGC2_R,port_index);
while(!Get_bit(SYSCTL_PRGPIO_R,port_index));
 Get_add(PORTS_BASE_ADD[port_index]+GPIOLOCK)=0x4C4F434B;
Get_add(PORTS_BASE_ADD[port_index]+GPIOCR)=0xff;
Get_add(PORTS_BASE_ADD[port_index]+GPIOAMSEL)=0;
Get_add(PORTS_BASE_ADD[port_index]+GPIOPCTL)=0; 
Get_add(PORTS_BASE_ADD[port_index]+GPIOAFSEL)=0;
Get_add(PORTS_BASE_ADD[port_index]+GPIODEN)=0xff;

}

void Port_SetPinDirection(uint8_t port_index,uint8_t pins_mask ,enum Port_PinDirectionType pins_direction){
(pins_direction)? (Get_add(PORTS_BASE_ADD[port_index]+GPIODIR)|=pins_mask):(Get_add(PORTS_BASE_ADD[port_index]+GPIODIR)&=(~pins_mask));
}

void Port_SetPinPullUp(uint8_t port_index,uint8_t pins_mask,uint8_t enable){
(enable)? (Get_add(PORTS_BASE_ADD[port_index]+GPIOPUR)|=pins_mask): (Get_add(PORTS_BASE_ADD[port_index]+GPIOPUR)&=(~pins_mask));
}

void Port_SetPinPullDown(uint8_t port_index,uint8_t pins_mask,uint8_t enable){
(enable)? (Get_add(PORTS_BASE_ADD[port_index]+GPIOPDR)|=pins_mask): (Get_add(PORTS_BASE_ADD[port_index]+GPIOPDR)&=(~pins_mask));
}
 uint8_t DIO_ReadPort(uint8_t port_index,uint8_t pins_mask){
	return((uint8_t)Get_add(PORTS_BASE_ADD[port_index]+GPIODATA)&pins_mask);
}

void DIO_WritePort(uint8_t port_index,uint8_t pins_mask,enum Dio_LevelType pins_level){
(pins_level) ? (Get_add(PORTS_BASE_ADD[port_index]+GPIODATA)|=pins_mask) : (Get_add(PORTS_BASE_ADD[port_index]+GPIODATA)&=(~pins_mask));
}
void DIO_FlipPort(uint8_t port_index,uint8_t pins_mask){
Get_add(PORTS_BASE_ADD[port_index]+GPIODATA)^=pins_mask;
}
