#ifndef adc_
#define adc_
void ADC_init(uint8_t port_index,uint8_t pin_num,uint8_t module_num,uint8_t chanl_num);
uint32_t ADC_read(uint8_t module_num);
void temp_init();
uint32_t temp_read();
#endif
