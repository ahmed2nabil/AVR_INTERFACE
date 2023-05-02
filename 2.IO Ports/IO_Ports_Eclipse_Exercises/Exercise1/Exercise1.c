/*
 * Exercise1.c
 *
 *  Created on: Jun 4, 2017
 *  Author: Mohamed Tarek
 */

#include <avr/io.h>

int main()
{
	/********** Initialization Code **********/
	DDRA &= ~(1<<3); // configure pin 3 in PORTA as input pin

	DDRC |= (1<<5); // configure pin 5 in PORTC as output pin
	PORTC &= ~(1<<5); // LED OFF

	while(1)
	{
		/********** Application Code **********/
		if(PINA & (1<<3)) // Check the button status pressed or not
		{
			PORTC |= (1<<5); // LED ON
		}
		else
		{
			PORTC &= (~(1<<5)); // LED OFF
		}
	}
}

