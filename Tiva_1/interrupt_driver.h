#ifndef interrupt_
#define interrupt_
#include<stdint.h>

void Gpio_interrupt_init(uint8_t port_index,uint8_t en_mask,uint8_t priorty);


#endif
