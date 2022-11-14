
/*
 * functions.c
 *
 * Created: 12/6/2021 12:53:18 PM
 *  Author: Abdalrahman_Amin
 */
#include "header.h"
#include "LCD.h"
#include "EEPROM.h"
#include "KEYPAD.h"
#include "PASSWORD.h"


void save_password(uint8_t *correct_pass){
	for(uint8_t i=0;i<4;i++){
		EEPROM_write(100+i,correct_pass[i]);
	}
}

uint8_t compare_password(uint8_t *correct_pass , uint8_t *check){
			for(uint8_t i=0;i<4;i++){
				if(check[i]!=correct_pass[i]){//wrong_password();
					return 0;
					}
			}
			correct_password();
			return 1;
			//break;
}

void read_entered_pass(uint8_t *entered_pa){
	//global_digit=0;//set global to initial value
	//LCD_write_command(0xc0); 
	for (uint8_t i=0;i<4;i++)
	{   while(!KEYPAD_read());
		entered_pa[i]=KEYPAD_read();
		while(KEYPAD_read());	
	}	
}

void correct_password(void){
	SETBIT(PORTD,0); // action open door	
}