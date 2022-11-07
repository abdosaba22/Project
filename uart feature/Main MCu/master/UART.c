/*

 * UART.c
 *
 * Created: 12/15/2021 11:37:57 AM
 *  Author: Abd-Alrahman Sabaa
 */ 
//extern unsigned char p[3];
#include "UART.h"

/*****************************************************************************
* Function Name: Uart_init
* Purpose      : initialize UART with one zero bit, no parity, baud rate 9600 and 8 bit data
* Parameters   : void
* Return value : void
*****************************************************************************/

void Uart_init(void){
	UBRRH=0;
	UBRRL=103; //baud rate 9600
	SETBIT(UCSRB,TXEN);
	SETBIT(UCSRB,RXEN);
	SETBIT(UCSRC,URSEL);
	SETBIT(UCSRC,UCSZ0);
	SETBIT(UCSRC,UCSZ1);
	SETBIT(UCSRB,RXCIE);
	//SETBIT(UCSRB,TXCIE);
	//SETBIT(SREG,7);
	sei();
}

/*****************************************************************************
* Function Name: Uart_Transmit
* Purpose      : Send 8-bit data and make sure the data is out
* Parameters   : uint8_t  data to send
* Return value : void
*****************************************************************************/

void Uart_Transmit(uint8_t data){
	while(READBIT(UCSRA, UDRE) == 0);
	UDR = data;
	//goto aa; 
	while(READBIT(UCSRA, TXC) == 0); // stuck , when data transmitted --> out
}
/*****************************************************************************
* Function Name: Uart_Read
* Purpose      : wait until receiving 1 byte (sync function)
* Parameters   : void
* Return value : data received
*****************************************************************************/

uint8_t Uart_Receive(void){
	//while(READBIT(UCSRA,RXC)==0);// stuck , when there is unread data -->out 
	return UDR; // data received 
}

/*****************************************************************************
* Function Name: Uart_Transmit_string
* Purpose      : Send array of char  and make sure the string is out
* Parameters   : uint8_t*  pointer to string which needed to send
* Return value : void
*****************************************************************************/

void Uart_Transmit_string(uint8_t *data){
	while(*data != '\0')
	{
		Uart_Transmit(*data);
		data++;
		_delay_ms(20);
	}
}

/*****************************************************************************
* Function Name: Uart_Transmit_string
* Purpose      : receive array of char and make sure the string is in
* Parameters   : uint8_t*  pointer to string which received
* Return value : void
*****************************************************************************/

void Uart_Receive_string(uint8_t *data){
	uint8_t i = 0;
	data[i] = Uart_Receive();
	while(data[i] != '\0')
	{
		i++;
		data[i] = Uart_Receive();
		
	}
	data[i] = '\0';
}
