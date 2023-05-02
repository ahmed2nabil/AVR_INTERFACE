/*
 * Exercise5.c
 *
 * Created: 11/22/2013 2:43:10 PM
 * Author: Mohamed Tarek
 */

/* Clock is 1Mhz by Default */
 
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char num = 0;
	DDRD  = DDRD & (~(1<<PD4)); // configure pin 4 in PORTD as input pin
	DDRC |= 0x0F; // configure first four pins of PORTC as output pins
	
	// initialize the 7-segment
	PORTC &= ~((1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3));
	
    while(1)
    {
		// check if the push button is pressed or not
		if( PIND & (1<<PD4) )
		{
			_delay_ms(30);
			//second check due to switch bouncing
			if( PIND & (1<<PD4) )
			{
				if((PORTC & 0x0F) == 9)
				{
					// if overflow occurs
					num = 0;
					PORTC = (PORTC & 0xF0) | (num & 0x0F);
				}
				else
				{
					// increment 7-segment every press
					num++;
					PORTC = (PORTC & 0xF0) | (num & 0x0F);
				}
			}
			while( PIND & (1<<PD4) ){} // wait until switch is released
		}									   
    }
}
