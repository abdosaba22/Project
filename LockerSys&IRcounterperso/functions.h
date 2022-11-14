
/*
 * functions.h
 *
 * Created: 3/13/2022 12:54:25 PM
 *  Author: Abd-Alrahman Saba
 */ 
#ifndef FUNCIONS_H_
#define FUNCIONS_H_

#include "header.h"
#include "LCD.h"
#include "PWM.h"
#include "ADC.h"
#include "seven_seg.h"

void save_password(uint8_t *correct_pass);
void reset_password(uint8_t *correct_pass);
uint8_t compare_password(uint8_t *correct_pass , uint8_t *check);
void change_password(uint8_t *coreect_pass,uint8_t *check);
void read_entered_pass(uint8_t *entered_pa);

#endif 