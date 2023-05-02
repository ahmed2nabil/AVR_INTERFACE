/*
 * Challenge1.c
 *
 *  Created on: Jun 4, 2017
 *  Author: Mohamed Tarek
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC  = 0xFF;	// Configure all PORTC pins as output pins
	PORTC = 0x01;   // First led is on at the beginning (Positive Logic configuration)

	while(1)
	{

		_delay_ms(500);
		PORTC = (PORTC<<1); //every time only one led is ON
		if(PORTC == 0x00)
		{
			/* In case PORTC equals ZERO after 8 shifts
			 * turn on the first led to start rolling again */
			PORTC = 0x01;
		}
	}
}



