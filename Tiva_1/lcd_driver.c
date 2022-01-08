
#include"lcd_driver.h"
#include"/Users/mak/Desktop/co com pro/inc/tm4c123gh6pm.h"



extern int PORTS_BASE_ADD [];
void __delay_us(uint32_t x){
//	SYS_TICK_wait(x*1000);
uint32_t i=0,j=0;
  for(;i<x;i++)
	for(;j<3;j++){}

}

void lcd_initt(){

	Port_Init(port);
	Port_SetPinDirection(port,0xf0,PORT_PIN_OUT);
	Port_SetPinDirection(port,1<<E,PORT_PIN_OUT);
	Port_SetPinDirection(port,1<<RS,PORT_PIN_OUT);
	DIO_WritePort(port,0xff,STD_LOW);
	  lcd_command(0x33);
    lcd_command(0x32);
    lcd_command(0x28);
    lcd_command(0x0e);
    lcd_command(0x01);
    __delay_us(2000);
    lcd_command(0x06);
}


 void lcd_command(uint8_t comm){

  
    	  Write_bits(Get_add(PORTS_BASE_ADD[port]+GPIODATA),0xf0,comm);
    	  Reset_bit(Get_add(PORTS_BASE_ADD[port]+GPIODATA),RS);
        Set_bit(Get_add(PORTS_BASE_ADD[port]+GPIODATA),E);
            __delay_us(2);
        Reset_bit(Get_add(PORTS_BASE_ADD[port]+GPIODATA),E);
           __delay_us(100);
        Write_bits(Get_add(PORTS_BASE_ADD[port]+GPIODATA),0xf0,comm<<4);
		    	
		    Reset_bit(Get_add(PORTS_BASE_ADD[port]+GPIODATA),RS);
        Set_bit(Get_add(PORTS_BASE_ADD[port]+GPIODATA),E);
            __delay_us(2);
        Reset_bit(Get_add(PORTS_BASE_ADD[port]+GPIODATA),E);
           __delay_us(100);

 }

 void lcd_out(uint8_t data){

      Set_bit(Get_add(PORTS_BASE_ADD[port]+GPIODATA),RS);

  	  Write_bits(Get_add(PORTS_BASE_ADD[port]+GPIODATA),0xf0,data);
         Set_bit(Get_add(PORTS_BASE_ADD[port]+GPIODATA),RS);
        Set_bit(Get_add(PORTS_BASE_ADD[port]+GPIODATA),E);
            __delay_us(2);
        Reset_bit(Get_add(PORTS_BASE_ADD[port]+GPIODATA),E);
           __delay_us(100);
      Write_bits(Get_add(PORTS_BASE_ADD[port]+GPIODATA),0xf0,data<<4);
      
      Set_bit(Get_add(PORTS_BASE_ADD[port]+GPIODATA),E);
            __delay_us(2);
      Reset_bit(Get_add(PORTS_BASE_ADD[port]+GPIODATA),E);
           __delay_us(100);

 }

void lcd_print(uint8_t *str){
  uint8_t i=0;
    while(str[i]){
    lcd_out(str[i]);
    i++;
    }
 }

void lcd_print_num(uint16_t num){
  lcd_out(num/100+'0');
        num%=100;
        lcd_out(num/10+'0');
        num%=10;
 lcd_out(num+'0');
 __delay_us(100);
 lcd_command(0x2);
}


