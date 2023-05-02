/*
 * mychallenge2.c
 *
 *  Created on: Aug 10, 2018
 *      Author: nobol billy
 */
#include<avr/io.h>
#include<util/delay.h>

void Timer0_PWM_Init(unsigned char duty_cycle){
	TCNT0 =0 ;
	OCR0 = duty_cycle;
	DDRB |= (1<<PB3);
	TCCR0 = (1<<WGM01) | (1<<WGM00) |  (1<<COM01) |(1<<CS01);

}
int main(){
	 Timer0_PWM_Init(128);
	while(1){
	}
}
