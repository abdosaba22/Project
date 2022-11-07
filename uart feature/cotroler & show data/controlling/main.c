/*
 * uart_mast.c
 *
 * Created: 10/27/2022 1:17:05 PM
 * Author : DELL
 */ 
#include "header.h"
//     index     0	 1 	 2	 3	 4	 5	 6
uint8_t arr[8]={ 5 , 0 , 0 , 0 , 0 , 0 ,20 };
uint8_t i=0,k=0;
uint8_t done=0;
uint8_t state = 0;
//uint8_t temp=20;
//#define aa
//extern uint8_t * globalptr;

int main(void)
{
	SETBIT(DDRD,7);
	SETBIT(DDRD,6);
	SETBIT(DDRD,5);
	SETBIT(DDRD,4);
	CLRBIT(DDRB,0); // control portb 3
	CLRBIT(DDRB,1); // control portb 4
	CLRBIT(DDRB,2); // control portb 5
	
	/* Replace with your application code */
	Uart_init();
	//UART_initTx();
	//UART_initRx();
	
	LCD_init();
	
	LCD_write_command(0x01);
	LCD_write_command(0x80);
	LCD_write_string("Led1:Led2:Led3");
	LCD_write_command(0xc1);
	LCD_write_char('F');
	LCD_write_command(0xc6);
	LCD_write_char('F');
	LCD_write_command(0xcb);
	LCD_write_char('F');
	uint8_t j=0;
	
	
	LCD_write_command(0xcc);
	LCD_write_num(arr[6]);
	
	while (1)
	{
	
		
		//cli();
		//cli();
		//cli();
		//_delay_ms(10);
		if(READBIT(PINB,0)){j=3; while(READBIT(PINB,0)); state=1; TOGBIT(arr[j],0); Uart_Transmit(j); _delay_ms(10);TOGBIT(PORTD,7); Uart_Transmit(arr[j]); _delay_ms(10); }
		if(READBIT(PINB,1)){j=4; while(READBIT(PINB,1)); state=1; TOGBIT(arr[j],0); Uart_Transmit(j); _delay_ms(10);TOGBIT(PORTD,7); Uart_Transmit(arr[j]); _delay_ms(10); }
		if(READBIT(PINB,2)){j=5; while(READBIT(PINB,2)); state=1; TOGBIT(arr[j],0); Uart_Transmit(j); _delay_ms(10);TOGBIT(PORTD,7); Uart_Transmit(arr[j]); _delay_ms(10); }
		//_delay_ms(10);
		//sei();
		//sei();
		//sei();
		
		
		if (done || state )
		{
			LCD_write_command(0xc1);
			switch(arr[3]){
				case 0: LCD_write_char('F'); break;
				case 1: LCD_write_char('O'); break;
				default: break;
			}
			LCD_write_command(0xc6);
			switch(arr[4]){
				case 0: LCD_write_char('F'); break;
				case 1: LCD_write_char('O'); break;
				default: break;
			}
			LCD_write_command(0xcb);
			switch(arr[5]){
				case 0: LCD_write_char('F'); break;
				case 1: LCD_write_char('O'); break;
				default: break;
			}
			//temp=arr[4];
			LCD_write_command(0xcc);
			LCD_write_num(arr[6]);
			//_delay_ms(50);
			
			done=0; state=0;
			//LCD_write_num(i);
		}
		
	}
	
}

ISR(USART_RXC_vect){
	//TOGBIT(PORTD,6);
	//TOGBIT(PORTD,7);
	uint8_t d=UDR;
	
	if(k==0 && d<3 ) {TOGBIT(PORTD,6); return; }
	else if(k==0 && d>=0) {TOGBIT(PORTD,5); i=d; k=1; return; }
	else{
		TOGBIT(PORTD,4);
		arr[i]=d;
		k=0; done=1;
	}
UDR=0;
}
