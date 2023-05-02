/*
 * ex2.c
 *
 *  Created on: Aug 4, 2018
 *      Author: nobol billy
 */
#include<avr/io.h>
#include<avr/interrupt.h>
void Timer_ovf(void){
	TCCR0=(1<<FOC0)|(1<<CS02)|(1<<CS00);
	TCNT0=0;
	OCR0=250;
	TIMSK=(1<<OCRE0);
	}
ISR(TIMER0_COMP_vect){

}

int main(){
	DDRC|=(1<<0);
	PORTC&=~(1<<0);
Timer_ovf();
while(1){

}
}

