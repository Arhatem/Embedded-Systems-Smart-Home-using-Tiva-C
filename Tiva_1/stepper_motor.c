#include"stepper_motor.h"
#include"Project_API.h"
#include<stdint.h>
const uint8_t arr[4]={0x9,0x3,0x6,0xc};
extern int PORTS_BASE_ADD [];
uint8_t i=0;
uint8_t j;
void motor_run(uint8_t port_index){
Port_Init(port_index);
Get_add(PORTS_BASE_ADD[port_index]+GPIODIR)|= 0x0f;
while(1){

Write_bits(Get_add(PORTS_BASE_ADD[port_index]+GPIODATA),0x0f,arr[i++]);
if (i >= 4)
{
	i=0;
}
delay_ms(5);

}

}
void motor_30_left(uint8_t port_index){

	uint8_t i=3;
	Port_Init(port_index);
	Get_add(PORTS_BASE_ADD[port_index]+GPIODIR)|= 0x0f;
	uint8_t j;
	for(j=0;j<190;j++){

	Write_bits(Get_add(PORTS_BASE_ADD[port_index]+GPIODATA),0x0f,arr[i++]);
	if (i >= 4)
	{
		i=0;
	}
	delay_ms(5);


}}
void motor_30_right(uint8_t port_index){
Port_Init(port_index);
Get_add(PORTS_BASE_ADD[port_index]+GPIODIR)|= 0x0f;
 i=3;

for(j=0;j<190;j++){

Write_bits(Get_add(PORTS_BASE_ADD[port_index]+GPIODATA),0x0f,arr[i--]);
if (i <= 0)
{
	i=3;
}
delay_ms(5);


}
}


