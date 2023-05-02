/*
 * mychallenge.c
 *
 *  Created on: Aug 6, 2018
 *      Author: nobol billy
 */
#include <avr/io.h>
#include <avr/interrupt.h>

#define NUMBER_OF_OVERFLOWS_PER_SECOND 122
unsigned char g_tick = 0;
ISR (TIMER0_OVF_vect) {
g_tick++;
if (g_tick== NUMBER_OF_OVERFLOWS_PER_SECOND){
	g_tick=0;
	if (PORTC==9)
		PORTC=0;
	else
		PORTC++;
}
}
void timer0_init_normal(void){
TCCR0 |= (1<<CS02);
TCNT0= 0;
TIMSK = (1<<FOC0) | (1<<TOIE0);
}
int main (){
	DDRC = 0xFF;
	PORTC = 0x00;
	SREG |= (1<<7);
	timer0_init_normal();
	while(1) {

	}
}
