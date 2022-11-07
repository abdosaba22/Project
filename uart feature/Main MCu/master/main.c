/*
 * uart_mast.c
 *
 * Created: 10/27/2022 1:17:05 PM
 * Author : DELL
 */ 

#include "header.h"
uint8_t i=0,k=0;
				
uint8_t arr[8]={5,0,0,0,0,0,37};
uint8_t done=0;
	
int main(void)
{
    /* Replace with your application code */
	Uart_init();
	SETBIT(DDRD,7);
	SETBIT(DDRD,6);
	SETBIT(DDRD,5);
	SETBIT(DDRD,4);
	CLRBIT(DDRB,0); // control portb 3
	CLRBIT(DDRB,1); // control portb 4
	CLRBIT(DDRB,2); // control portb 5
	// O/P
	SETBIT(DDRB,3);
	SETBIT(DDRB,4);
	SETBIT(DDRB,5);
	//arr[4]=37;
	uint8_t j=0;
	_delay_ms(2000);	
    Uart_Transmit(6);
    _delay_ms(10);
	Uart_Transmit(arr[6]);
	while (1) 
    {	
		
		//sei();
		/*
		if(READBIT(PINB,0)){ while(READBIT(PINB,0)); TOGBIT(PORTB,3); state=1; TOGBIT(arr[1],0); arr[4]+=1; }
		if(READBIT(PINB,1)){ while(READBIT(PINB,1)); TOGBIT(PORTB,4); state=1; TOGBIT(arr[2],0); }
		if(READBIT(PINB,2)){ while(READBIT(PINB,2)); TOGBIT(PORTB,5); state=1; TOGBIT(arr[3],0); }
		*/
	
		//cli();
		//cli();
		//cli();
		//_delay_ms(10);
		if(READBIT(PINB,0)){j=3; while(READBIT(PINB,0)); TOGBIT(PORTB,j); TOGBIT(arr[j],0); Uart_Transmit(j); _delay_ms(10);TOGBIT(PORTD,7); Uart_Transmit(arr[j]); _delay_ms(10); }
		if(READBIT(PINB,1)){j=4; while(READBIT(PINB,1)); TOGBIT(PORTB,j); TOGBIT(arr[j],0); Uart_Transmit(j); _delay_ms(10);TOGBIT(PORTD,7); Uart_Transmit(arr[j]); _delay_ms(10); }
		if(READBIT(PINB,2)){j=5; while(READBIT(PINB,2)); TOGBIT(PORTB,j); TOGBIT(arr[j],0); Uart_Transmit(j); _delay_ms(10);TOGBIT(PORTD,7); Uart_Transmit(arr[j]); _delay_ms(10); }
		//_delay_ms(10);
		//sei();
		//sei();
		//sei();
		if(done){
			switch(arr[i]){
				case 0: CLRBIT(PORTB,i); break;
				case 1: SETBIT(PORTB,i); break;
				default: break;
			}
			done=0;
		}
/*
		if(done){
			switch(arr[3]){
				case 0: CLRBIT(PORTB,3); break;
				case 1: SETBIT(PORTB,3); break;
				default: break;
			}
			//LCD_write_command(0xc6);
			switch(arr[4]){
				case 0: CLRBIT(PORTB,4); break;
				case 1: SETBIT(PORTB,4); break;
				default: break;
			}
			//LCD_write_command(0xcb);
			switch(arr[5]){
				case 0: CLRBIT(PORTB,5); break;
				case 1: SETBIT(PORTB,5); break;
				default: break;
			}
			done=0;
			//_delay_ms(500);
		}
	*/	
    }
	
}


ISR(USART_RXC_vect){
	uint8_t d=UDR;	
	if(k==0 && d<3 ) {TOGBIT(PORTD,6); return; }
	else if(k==0 && d>=3) {
		TOGBIT(PORTD,5);
		i=d; k=1; return; }
	else if(k==1){
		TOGBIT(PORTD,4);
		arr[i]=d;
		k=0; done=1;
	}
	UDR=0;
}


