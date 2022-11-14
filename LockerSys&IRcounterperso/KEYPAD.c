
/*
 * KEYPAD.c
 *
 * Created: 12/4/2021 5:58:17 PM
 *  Author: Abdalrahman_Amin
 */
 
#include "KEYPAD.h"

const uint8_t keypad_matrix[] = {
	'7','8','9','/',
	'4','5','6','*',
	'1','2','3','-',
	'c','0','=','+'};
void KEYPAD_init(void){
	KEYPAD_PORT_INIT();
}

uint8_t KEYPAD_read(void){
	uint8_t i;
	for(i = 0; i < 4; i++){
		switch(i){
			case 0: KP0(0);KP1(1);KP2(1);KP3(1); break;
			case 1: KP0(1);KP1(0);KP2(1);KP3(1); break;
			case 2: KP0(1);KP1(1);KP2(0);KP3(1); break;
			case 3: KP0(1);KP1(1);KP2(1);KP3(0); break;
		}
		
		if(KP4 == 0) return keypad_matrix[0 + i*4];
		if(KP5 == 0) return keypad_matrix[1 + i*4];
		if(KP6 == 0) return keypad_matrix[2 + i*4];
		if(KP7 == 0) return keypad_matrix[3 + i*4];
		_delay_ms(1);
	}
	return 0;
}