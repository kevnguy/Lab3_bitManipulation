/*	Author: Kevin Nguyen knguy523@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #3  Exercise #5
 *	Exercise Description:A car's passenger seat weight sensor outputs a 9-bit value (ranging from 0 to 511) 
 *		and connects to input PD7...PD0PB0 on the microcontroller. If the weight is equal to or 
 *		above 70 pounds, the airbag should be enabled by setting PB1 to 1. If the weight is above 5 
 *		but below 70, the airbag should be disabled and an "Airbag disabled" icon should light by 
 *		setting PB2 to 1. (Neither B1 nor B2 should be set if the weight is 5 or less,
 *		as there is no passenger)	 
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
	DDRB = 0x06; PORTB = 0x01;	// lsb B is input B1,B2 is output
	DDRD = 0x00; PORTD = 0xFF;	// D is input
    /* Insert your solution below */
	unsigned char tempB = 0x00;
	unsigned short weight = 0x0000;

    while (1) {
	tempB = 0x00;
	weight = 0x0000;
	weight = (PIND << 1) | (PINB & 0x01);
	if(weight >=  0x0046)	// 70
		tempB = 0x02;
	else if(weight > 0x0005)
		tempB = 0x04;
	
	PORTB = tempB;  
	}
    return 1;
}
