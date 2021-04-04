/*	Author: Kevin Nguyen knguy523@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description: Read an 8-bit value on PA7..PA0 and write that value on PB3..PB0PC7..PC4	 
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
	DDRB = 0x0F; PORTB = 0x00;	// B lower nibble is output
	DDRC = 0xF0; PORTC = 0x00;	// C upper nibble is output
    /* Insert your solution below */
	unsigned char tempB, tempC = 0x00;

    while (1) {
	tempB = (PINA & 0xF0) >> 4;
	tempC = (PINA & 0x0F) << 4;
	PORTB = tempB;  
	PORTC = tempC;
	}
    return 1;
}
