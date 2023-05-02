/*
 * Debugging_Example.c
 *
 * Created: 2/22/2014 11:26:15 PM
 * Author: mohamed tarek
 */ 

#include <avr/io.h>

int main(void)
{
	unsigned char counter;
	DDRB = 0xFF; //8 leds at PORTB 
	DDRA = DDRA & (~(1<<PA0)); //switch at PA0
	counter=0;
    while(1)
    {
        counter++;
		PORTB=counter;
		if(PINA & (1<<PA0))
		{
			counter=0;
			PORTB=0;
		}			 
    }
}