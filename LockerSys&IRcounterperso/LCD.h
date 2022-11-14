
/*
 * LCD.h
 *
 * Created: 12/4/2021 2:48:24 PM
 *  Author: Abd-Alrahman Sabaa
 */ 
#ifndef LCD_H_
#define LCD_H_

#include "header.h" 
#define LCD_PORT_INIT() DDRA |= 0b11111100;
#define RS(x) if(x == 1) SETBIT(PORTA,2); else CLRBIT(PORTA,2);
#define EN(x) if(x == 1) SETBIT(PORTA,3); else CLRBIT(PORTA,3);
#define D4(x) if(x == 1) SETBIT(PORTA,4); else CLRBIT(PORTA,4);
#define D5(x) if(x == 1) SETBIT(PORTA,5); else CLRBIT(PORTA,5);
#define D6(x) if(x == 1) SETBIT(PORTA,6); else CLRBIT(PORTA,6);
#define D7(x) if(x == 1) SETBIT(PORTA,7); else CLRBIT(PORTA,7);

void LCD_init(void);
void LCD_write_command(uint8_t);
void LCD_write_char(uint8_t);
void LCD_write_num(uint16_t);
void LCD_write_string(uint8_t *);

#endif
