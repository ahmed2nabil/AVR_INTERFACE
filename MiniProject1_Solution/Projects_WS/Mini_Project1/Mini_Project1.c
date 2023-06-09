/*
 * Mini_Project1.c
 *
 *  Created on: Jun 19, 2017
 *  Author: Mohamed Tarek
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define NUMBER_OF_COMPARE_MATCHES_PER_SECOND 4

// variable to count the number of timer ticks (compare match)
unsigned char g_tick = 0;

// flag will be set when the timer count 1 second
unsigned char count_second_flag = 0;

// variables to hold the clock time
unsigned char seconds_count = 0;
unsigned char minutes_count = 0;
unsigned char hours_count = 0;

// Interrupt Service Routine for timer0 compare mode
ISR(TIMER0_COMP_vect)
{
	g_tick++;
	if(g_tick == NUMBER_OF_COMPARE_MATCHES_PER_SECOND)
	{
		count_second_flag = 1;
		g_tick = 0; //clear the tick counter again to count a new second
	}
}

void timer0_init_CTC_mode(unsigned char tick)
{
	TCNT0 = 0; //timer initial value
	OCR0  = tick; //compare value
	TIMSK |= (1<<OCIE0); //enable compare interrupt
	/* Configure timer0 control register
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. No need for OC0 in this example so COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS02) | (1<<CS00);
}

// External INT0 Interrupt Service Routine
ISR(INT0_vect)
{
	seconds_count = 0;
	minutes_count = 0;
	hours_count = 0;
}

// External INT0 enable and configuration function
void INT0_Init(void)
{
	// Enable external interrupt pin INT0
	GICR  |= (1<<INT0);
	// Trigger INT0 with the falling edge
	MCUCR &= ~(1<<ISC00);
	MCUCR |= (1<<ISC01);
}

int main(void)
{
	// configure INT0/PD2 as input pin
	DDRD  &= (~(1<<PD2));
	// enable internal pull up resistor at INT0/PD2 pin
	PORTD |= (1<<PD2);

	// configure first 6 pins in PORTA as output pins
    DDRA |= 0x3F;

    // configure first four pins of PORTC as output pins
	DDRC |= 0x0F;

	// initialize all the 7-segment with zero value
	PORTA |= 0x3F;
	PORTC &= 0xF0;

	// enable global interrupts in MC.
	SREG  |= (1<<7);

	// start timer0 to generate compare interrupt every 250 MiliSeconds
	timer0_init_CTC_mode(250);

	// activate external interrupt INT0
	INT0_Init();

    while(1)
    {
    	if(count_second_flag == 1)
    	{
    		//enter here every one second
    		//increment seconds count
    		seconds_count++;

    		if(seconds_count == 60)
    		{
    			seconds_count = 0;
    			minutes_count++;
    		}
    		if(minutes_count == 60)
    		{
    			minutes_count = 0;
    			hours_count++;
    		}
    		if(hours_count == 24)
    		{
    			hours_count = 0;
    		}
    	    // reset the flag again
    	    count_second_flag = 0;
    	}
    	else
    	{
    		// out the number of seconds
    		PORTA = (PORTA & 0xC0) | 0x01;
    		PORTC = (PORTC & 0xF0) | (seconds_count%10);

    		// make small delay to see the changes in the 7-segment
    		// 2Miliseconds delay will not effect the seconds count
    		_delay_ms(2);

    		PORTA = (PORTA & 0xC0) | 0x02;
    		PORTC = (PORTC & 0xF0) | (seconds_count/10);

    		_delay_ms(2);

    		// out the number of minutes
    		PORTA = (PORTA & 0xC0) | 0x04;
    		PORTC = (PORTC & 0xF0) | (minutes_count%10);

    		_delay_ms(2);

    		PORTA = (PORTA & 0xC0) | 0x08;
    	    PORTC = (PORTC & 0xF0) | (minutes_count/10);

    	    _delay_ms(2);

    	    // out the number of hours
    	    PORTA = (PORTA & 0xC0) | 0x10;
    	    PORTC = (PORTC & 0xF0) | (hours_count%10);

    	    _delay_ms(2);

    	    PORTA = (PORTA & 0xC0) | 0x20;
    	    PORTC = (PORTC & 0xF0) | (hours_count/10);

    	    _delay_ms(2);
    	}
    }
}
