#include <stdint.h>
#include"ADC_driver.h"
#include"project_API.h"
#include"/Users/mak/Desktop/co com pro/inc/tm4c123gh6pm.h"

extern uint32_t PORTS_BASE_ADD[];

void ADC_init(uint8_t port_index,uint8_t pin_num,uint8_t module_num,uint8_t chanl_num){
//asume seq 3
Set_bit(SYSCTL_RCGC2_R,port_index);
while(!Get_bit(SYSCTL_PRGPIO_R,port_index));
Set_bit(SYSCTL_RCGCADC_R ,module_num);
while(!Get_bit(SYSCTL_PRADC_R,module_num));

Set_bit(Get_add(PORTS_BASE_ADD[port_index]+GPIOAFSEL),pin_num);
Reset_bit(Get_add(PORTS_BASE_ADD[port_index]+GPIODEN),pin_num);
Set_bit(Get_add(PORTS_BASE_ADD[port_index]+GPIOAMSEL),pin_num);

if(module_num == 0){
Reset_bit(ADC0_ACTSS_R,3);//disable for seq 3 during config
Reset_bits(ADC0_EMUX_R,0xf000);//cpu triger
ADC0_SSMUX3_R=chanl_num;
ADC0_SSCTL3_R |= 6;
}else{
Reset_bit(ADC1_ACTSS_R,3);//disable for seq 3 during config
Reset_bits(ADC1_EMUX_R,0xf000);//cpu triger
ADC1_SSMUX3_R=chanl_num;
ADC1_SSCTL3_R |=6 ;
}
Set_bit(ADC0_ACTSS_R,3);


}

uint32_t ADC_read(uint8_t module_num){

if (module_num == 0)
{
Set_bit(ADC0_PSSI_R,3);
while(Get_bit(ADC0_RIS_R,3) == 0){}
uint32_t x = ADC0_SSFIFO3_R ;
Reset_bit(ADC0_ISC_R ,3);
return x;
}else{
Set_bit(ADC1_PSSI_R,3);
while(Get_bit(ADC1_RIS_R,3) == 0){}
uint32_t x = ADC1_SSFIFO3_R ;
Reset_bit(ADC1_ISC_R ,3);
return x;
}
}

void temp_init(){

	Set_bit(SYSCTL_RCGCADC_R ,0);
	while(!Get_bit(SYSCTL_PRADC_R,0));

	Set_bit(SYSCTL_RCGCWTIMER_R ,0);
	while(!Get_bit(SYSCTL_PRWTIMER_R,0));


	Reset_bit(ADC0_ACTSS_R,3);

    Write_bits(ADC0_EMUX_R,0xf000,0x5000);

	ADC0_SSMUX3_R=0;

	ADC0_SSCTL3_R |=0x0e;   

	Set_bit(ADC0_ACTSS_R,3);


	WTIMER0_CTL_R=0;
	WTIMER0_CFG_R=0x04;
	WTIMER0_TAMR_R =0x02;
	WTIMER0_TAILR_R=16000000;
}

uint32_t temp_read(){
	Set_bits(WTIMER0_CTL_R,0x21);
	while(Get_bit(ADC0_RIS_R,3) == 0){}
	uint32_t x = 147 + 25 - (247 * ADC0_SSFIFO3_R)/4096 ;
	Reset_bit(ADC0_ISC_R ,3);
	return x;
}
