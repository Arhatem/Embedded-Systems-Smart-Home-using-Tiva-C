#ifndef project_API
#define project_API
#include<stdint.h>
#include<math.h>

///////////////////////// bit manipulation/////////////////// 
#define Get_add(add) (*((volatile uint32_t *)(add)))
#define Set_bit(add,bit_num) (add|=(1<<bit_num))
#define Reset_bit(add,bit_num) (add&=(~(1<<bit_num)))
#define toggle_bit(add,bit_num) (add^=(1<<bit_num))
#define Get_bit(add,bit_num) ((add&(1<<bit_num))>>bit_num)
//#define Write_add(add,st,en,data) add=(add&(~(((uint8_t)pow(2,en-st+1)-1)<<st)))^(data<<st);
#define Write_bits(add,mask,data) add = ((add & ~mask) | data);
#define Set_bits(add,mask) (add|=(mask))
#define Reset_bits(add,mask) (add&=(~mask))


//////////////////Regesters base addres///////////////////////
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

/////////////////////Registers offset/////////////////////
#define GPIODATA 0x3FC
#define GPIODIR  0x400
#define GPIOAFSEL 0x420
#define GPIODEN 0x51C
#define GPIOLOCK 0x520
#define GPIOCR 0x524
#define GPIOAMSEL 0x528
#define GPIOPCTL 0x52C
#define GPIOPUR 0x510
#define GPIOPDR 0x514
#define GPIOIBE 0x408
#define GPIOIS 0x404
#define GPIOIEV 0x40C
#define GPIOIM 0x410
#define GPIORIS 0x414
#define GPIOMIS 0x418
#define GPIOICR 0x41C

///////////////////////////new data type//////////////////

enum Port_PinDirectionType{PORT_PIN_IN=0 , PORT_PIN_OUT};
enum Dio_LevelType{STD_LOW=0 , STD_HIGH };



//////////////////////GPIO functions/////////////////

void Port_Init(uint8_t port_index);
void Port_SetPinDirection(uint8_t port_index,uint8_t pins_mask ,enum Port_PinDirectionType pins_direction);
void Port_SetPinPullUp(uint8_t port_index,uint8_t pins_mask,uint8_t enable);
void Port_SetPinPullDown(uint8_t port_index,uint8_t pins_mask,uint8_t enable);
uint8_t DIO_ReadPort(uint8_t port_index,uint8_t pins_mask);
void DIO_WritePort(uint8_t port_index,uint8_t pins_mask,enum Dio_LevelType pins_level);
void DIO_FlipPort(uint8_t port_index,uint8_t pins_mask);


#endif
