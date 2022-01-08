#include"timer_driver.h"


void Systic_init(){
NVIC_ST_CTRL_R=0x00;
NVIC_ST_RELOAD_R=0x00ffffff;
NVIC_ST_CURRENT_R=0;
NVIC_ST_CTRL_R=0x05;
}
void Systic_wait(uint32_t delay ){
	NVIC_ST_RELOAD_R=delay -1;
	NVIC_ST_CURRENT_R=0;
	while(!(NVIC_ST_CTRL_R & 0x00010000));

}
void Systic_wait_10ms(uint32_t delay ){
	uint32_t i;
	for(i=0;i<delay;i++)
		Systic_wait(800000);




}
