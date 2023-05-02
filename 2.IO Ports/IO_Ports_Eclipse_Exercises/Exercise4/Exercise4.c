/*
 * Exercise4.c
 *
 * Created: 11/22/2013 2:34:51 PM
 *  Author: Mohamed Tarek
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char button = 0;
	DDRB = DDRB & (~(1<<PB0)); // configure pin 0 of PORTB to be input pin
	PORTB |= (1<<PB0); //activate the internal pull up resistor of PB0
	
	DDRC = DDRC | (1<<PC0);    // configure pin 0 of PORTC to be output pin
	PORTC = PORTC | (1<<PC0);  // led is off at the beginning
	
    while(1)
    {
		// check if the push button is pressed or not
		if(!(PINB & (1<<PB0)))
		{
			_delay_ms(30);
			//second check due to switch de-bouncing
			if(!(PINB & (1<<PB0)))
			{
				if(button == 0)
				{
					PORTC = PORTC ^ (1<<PC0); // toggle the led
					button = 1;
				}
			}
		}
		else button = 0;
    }
}
