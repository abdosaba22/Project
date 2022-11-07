
/*
 * LCD.h
 *
 * Created: 12/4/2021 2:48:24 PM
 *  Author: Abd-Alrahman Saba
 */ 
#ifndef LCD_H_
#define LCD_H_

#include "header.h" 
#define LCD_PORT_INIT() DDRC |= 0b11111100;
#define RS(x) if(x == 1) SETBIT(PORTC,2); else CLRBIT(PORTC,2);
#define EN(x) if(x == 1) SETBIT(PORTC,3); else CLRBIT(PORTC,3);
#define D4(x) if(x == 1) SETBIT(PORTC,4); else CLRBIT(PORTC,4);
#define D5(x) if(x == 1) SETBIT(PORTC,5); else CLRBIT(PORTC,5);
#define D6(x) if(x == 1) SETBIT(PORTC,6); else CLRBIT(PORTC,6);
#define D7(x) if(x == 1) SETBIT(PORTC,7); else CLRBIT(PORTC,7);

void LCD_init(void);
void LCD_write_command(uint8_t);
void LCD_write_char(uint8_t);
void LCD_write_num(uint16_t);
void LCD_write_string(uint8_t *);

#endif
