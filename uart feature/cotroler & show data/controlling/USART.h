
/*
 * UART.h
 *
 * Created: 12/15/2021 11:37:47 AM
 *  Author: Abd-Alrahman Sabaa
 */ 

#ifndef UART_H_
#define UART_H_


#include "header.h"


void Uart_init(void);


void Uart_Transmit(uint8_t);


uint8_t Uart_Receive(void);

void Uart_Transmit_string(uint8_t *data);
void Uart_Receive_string(uint8_t *data);


#endif