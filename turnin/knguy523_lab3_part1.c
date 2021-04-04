/*	Author: Kevin Nguyen knguy523@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: Count the number of 1s on ports A and B and output that number on port C
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
	DDRA = 0x00; PORTA = 0xFF;	// A and B are inputs
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;	// C is output
    /* Insert your solution below */
    	unsigned char count = 0x00;
	unsigned char i = 0x00;
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
    while (1) {
	tempA = PINA;
	tempB = PINB;
	count = 0x00;
	for(i = 0; i < 8; i++){
		if((tempA & (0x01 << i)) != 0)
			count++;
		if((tempB & (0x01 << i)) != 0)
			count++;
	}
	PORTC = count;
    }
    return 1;
}
