/*	Author: Kevin Nguyen knguy523@ucr.edu
 *	 *  Partner(s) Name: 
 *	  *	Lab Section: 22
 *	   *	Assignment: Lab #3  Exercise #3
 *	    *	Exercise Description: In addition to the above, PA4 is 1 if a key is in the ignition, PA5 is one 
 *	     *		if a driver is seated, and PA6 is 1 if the driver's seatbelt is fastened. PC7 should light 
 *	      *		a "Fasten seatbelt" icon if a key is in the ignition, the driver is seated, but the belt 
 *	       *		is not fastened. 
 *	        *
 *	         *	I acknowledge all content contained herein, excluding template or example
 *	          *	code, is my own original work.
 *	           */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;	// A is input
	DDRC = 0xFF; PORTC = 0x00;	// C is output
    /* Insert your solution below */
	unsigned char tempA, tempA2, tempC = 0x00;

    while (1) {
	tempA = PINA & 0x0F;
	tempA2 = PINA & 0x70;
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
	if(tempA2 == 0x30)
		tempC |= 0x80; 
	PORTC = tempC;
	}
    return 1;
}
