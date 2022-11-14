
/*
 * EEPROM.c
 *
 * Created: 12/4/2021 5:00:02 PM
 *  Author: Abdalrahman_Amin
 */ 
#include "EEPROM.h"

/***********************************************************
* Function Name: EEPROM_write
* Purpose      : write (data) on location (address)
* Parameters   : address: address of EEPROM location (0 - 1023)
*                data:to be written
* Return value : void
*************************************************************/
void EEPROM_write(uint16_t address , uint8_t data){
	while(READBIT(EECR,EEWE)); // when bit EEWE=1 don't do anything "stuck" 
	EEAR = address; // put our address in address reg
	EEDR = data; //put our our in data reg
	SETBIT(EECR, EEMWE); //enable master bit
	SETBIT(EECR, EEWE);// start writing
}
/***************************************************
* Function Name: EEPROM_read
* Purpose      : read from (address) and return data in it
* Parameters   : uint16_t address: address of EEPROM location range
* Return value : uint8_t: return value in our(address) in EEPROM
****************************************************/

uint8_t EEPROM_read(uint16_t address){
	while(READBIT(EECR,EEWE));
	EEAR = address;
	SETBIT(EECR, EERE);
	return EEDR;

}
