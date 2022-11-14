
/*
 * PASSWORD.h
 *
 * Created: 2/27/2022 12:18:24 PM
 *  Author: Abdalrahman_Amin
 */ 

#ifndef PASSWORD_H_
#define PASSWORD_H_


void save_password(uint8_t *correct_pass);
void reset_password(uint8_t *correct_pass);
uint8_t compare_password(uint8_t *correct_pass , uint8_t *check);
void change_password(uint8_t *coreect_pass,uint8_t *check);
void read_entered_pass(uint8_t *entered_pa);
void wrong_password(void);
void correct_password(void);

#endif