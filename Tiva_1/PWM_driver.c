#include "pwm_driver.h"
#include"project_API.h"
#include<stdint.h>
#include"/Users/mak/Desktop/co com pro/inc/tm4c123gh6pm.h"
extern int PORTS_BASE_ADD [];
void pwm_init(uint8_t port_index,uint8_t module_num,uint8_t pin_num,uint8_t chanl_num,uint32_t load ,uint32_t comp){

Set_bit(SYSCTL_RCGCPWM_R,module_num);//clock for module
while(!Get_bit(SYSCTL_PRPWM_R,module_num));

Set_bit(SYSCTL_RCGC2_R,port_index);//clock for port
while(!Get_bit(SYSCTL_PRGPIO_R,port_index));

Reset_bit(SYSCTL_RCC_R,20);

Set_bit(Get_add(PORTS_BASE_ADD[port_index]+GPIOAFSEL),pin_num);
//Write_bits(Get_add(PORTS_BASE_ADD[port_index]+GPIOPCTL) ,0xf<<(4*pin_num),0x5<<(4*pin_num));
Write_bits( Get_add(PORTS_BASE_ADD[port_index]+GPIOPCTL) , 0xf000, 0x5000);
//Set_bit(Get_add(PORTS_BASE_ADD[port_index]+GPIODIR),pin_num);
Set_bit(Get_add(PORTS_BASE_ADD[port_index]+GPIODEN),pin_num);
PWM1_3_CTL_R =0;
PWM1_3_GENB_R=0x8c;
PWM1_3_LOAD_R =load;
PWM1_3_CMPA_R =comp;
PWM1_3_CTL_R =1;
PWM1_ENABLE_R=0x80;
}
