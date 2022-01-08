#ifndef _pwm
#define _pwm
#include<stdint.h>
void pwm_init(uint8_t port_index,uint8_t module_num,uint8_t pin_num,uint8_t chanl_num,uint32_t load ,uint32_t comp);
#endif 
