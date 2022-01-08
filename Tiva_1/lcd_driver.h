#ifndef lcd_driver
#define lcd_driver
#include"project_API.h"

//user layer
//#define DATA PORTB
//#define command PORTA
#define port PORTB
#define E 0
#define RS 1
///////////////////////////
void __delay_us(uint32_t x);
void lcd_initt();
void lcd_command(uint8_t comm);
void lcd_out(uint8_t data);
void lcd_print(uint8_t *str);
void lcd_print_num(uint16_t num);
#endif
