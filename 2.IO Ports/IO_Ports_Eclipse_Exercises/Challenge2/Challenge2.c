/*
 * Challenge1.c
 *
 * Created: 11/22/2013 2:43:10 PM
 *  Author: Mohamed Tarek
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char num = 0;
	DDRA  = DDRA & (~(1<<PA0)); // configure pin 0 of PORTA to be input pin
	DDRA  = DDRA & (~(1<<PA1)); // configure pin 1 of PORTA to be input pin
	DDRD |= 0x0F; // configure all pins of PORTD as output pins
	
	// initialize the 7-segment
	PORTD &= ~((1<<PD0) | (1<<PD1) | (1<<PD2) | (1<<PD3));
	
    while(1)
    {
		if(PINA & (1<<PA0)) // check if the first push button is pressed or not
		{
			_delay_ms(30);
			//second check due to switch bouncing
			if(PINA & (1<<PA0))
			{
					if((PORTD & 0x0F) != 9)
					{
						num++;
						PORTD = (PORTD & 0xF0) | (num & 0x0F);
					}
			}
			while(PINA & (1<<PA0)){}
		}
		
		else if(PINA & (1<<PA1))// check if the second push button is pressed or not
		{
			_delay_ms(30);
			//second check due to switch bouncing
			if(PINA & (1<<PA1))
			{
					if((PORTD & 0x0F) != 0)
					{
						num--;
						PORTD = (PORTD & 0xF0) | (num & 0x0F);
					}
			}
			while(PINA & (1<<PA1)){}
		}				       
    }
}
