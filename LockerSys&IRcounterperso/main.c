/*
 * LCDapp.c
 *
 * Created: 12/4/2021 2:43:05 PM
 * Author : Abdalrahman_Amin
 */ 

#include "header.h"
#include "LCD.h"
#include "EEPROM.h"
#include "KEYPAD.h"
#include "PASSWORD.h"

uint8_t Number_of_person_in_room=0;
uint8_t Number_trying_pass=0;
void interr_init();
uint8_t flag=0;

int main(void)
{
    /* Replace with your application code */
	SETBIT(DDRD,0); // action out put open door  
	SETBIT(DDRD,5); // alarm 
	KEYPAD_init();
	LCD_init();
	interr_init();
	
	
	uint8_t password_saved[4],Entered_pass[4];
	for(uint8_t i=0;i<4;i++)
	{
		password_saved[i]=EEPROM_read(100+i); //2000
		//if (password_saved[i]==255){password_saved[i]='0';}
	}
	Number_of_person_in_room=0;
	while (1)
    {	
		
		LCD_write_command(0x01);
		LCD_write_command(0x80);
		LCD_write_string("N_of-person=");
		LCD_write_num(Number_of_person_in_room);
		_delay_ms(500);
			if(Number_trying_pass > 0)
			{	
				while(Number_trying_pass<4){
					while(! KEYPAD_read());
					read_entered_pass(&Entered_pass[0]);
					if(compare_password(&password_saved[0],&Entered_pass[0])==1)
					{
						flag=1;
						Number_trying_pass=0;
						while(READBIT(PINB,1));
						break;
					}
					else Number_trying_pass++;
					_delay_ms(100);
				}
				// turn alarm 
				if(Number_trying_pass==4){
					Number_trying_pass=0;
					SETBIT(PORTD,5); // turn on alarm for  500ms
					_delay_ms(500);
					CLRBIT(PORTD,5); 				
				}	
			}
	
	}
}

void interr_init(){
	CLRBIT(PORTD,2); // sensor y indoor  -- int0
	CLRBIT(PORTD,3); // sensor x Outdoor -- int1
	// make interrupt mode rising mode  1 1
	SETBIT(MCUCR,0);
	SETBIT(MCUCR,1);
	SETBIT(GICR,6); // enable INT0
	SETBIT(GICR,7);	// enable INT1
	sei();	
}
ISR(INT0_vect){
	if(flag){
		CLRBIT(PORTD,0);
		Number_of_person_in_room ++;
		// transmit new change to esp
		flag=0;
	}
	else flag=1;
}

ISR(INT1_vect){
	if(flag){
		Number_of_person_in_room--;
		//transmit new change to esp
		flag=0;
	}
	else{
		Number_trying_pass=1;
	}
}

