/*	Author: Kevin Nguyen knguy523@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #3  Exercise #2
 *	Exercise Description: A car has a fuel-level sensor that sets PA3..PA0 to a value between 0 (empty) 
 *		and 15 (full). A series of LEDs connected to PC5..PC0 should light to graphically indicate 
 *		the fuel level. If the fuel level is 1 or 2, PC5 lights. If the level is 3 or 4, PC5 
 *		and PC4 light. Level 5-6 lights PC5..PC3. 7-9 lights PC5..PC2. 10-12 lights PC5..PC1. 
 *		13-15 lights PC5..PC0. Also, PC6 connects to a "Low fuel" icon, which should light if 
 *		the level is 4 or less
 *	 
 *	 
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;	// A is input
	DDRC = 0xFF; PORTC = 0x00;	// C is output
    /* Insert your solution below */
	unsigned char tempA, tempC = 0x00;

    while (1) {
	tempA = PINA & 0x0F;
	tempC = 0x00;
	if(tempA > 0)
		tempC |= 0x20;
	if(tempA >= 3)
		tempC |= 0x10;
	if(tempA >= 5)
		tempC |= 0x08;
	if(tempA >= 7)
		tempC  |= 0x04;
	if(tempA >= 10)
		tempC |= 0x02;
	if(tempA >= 13)
		tempC |= 0x01;
	if(tempA <= 4)
		tempC |= 0x40;

	PORTC = tempC;
	}
    return 1;
}
