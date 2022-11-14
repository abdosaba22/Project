
/*
 * KEYPAD.h
 *
 * Created: 12/4/2021 5:58:00 PM
 *  Author: Abdalrahman_Amin
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_
/*
-------------------------
|     |     |     |     | <---------- KP0 - PC0
-------------------------
|     |     |     |     | <---------- KP1 - PC1
-------------------------                       | rows are output
|     |     |     |     | <---------- KP2 - PC2 | from avr
-------------------------
|     |     |     |     | <---------- KP3 - PC3
-------------------------
|     |     |     | PULL UP
|     |     |     |
KP4   KP5   KP6   KP7

KP(0,1,2,3) INPUT  = PC0,1,2,3  OUTPUT
KP(4 TO 7) OUTPUT = PC4,5,6,7  INPUT PULL

*/

#include "header.h"
//                                 i/p | o/p     |  i/p pull up
#define KEYPAD_PORT_INIT() DDRC = 0b00001111;  PORTC = 0b11110000;

#define KP0(x) if(x == 1) SETBIT(PORTC,0); else CLRBIT(PORTC,0);
#define KP1(x) if(x == 1) SETBIT(PORTC,1); else CLRBIT(PORTC,1);
#define KP2(x) if(x == 1) SETBIT(PORTC,2); else CLRBIT(PORTC,2);
#define KP3(x) if(x == 1) SETBIT(PORTC,3); else CLRBIT(PORTC,3);

#define KP4 READBIT(PINC,4)
#define KP5 READBIT(PINC,5)
#define KP6 READBIT(PINC,6)
#define KP7 READBIT(PINC,7)


void KEYPAD_init(void);
uint8_t KEYPAD_read(void);




#endif

