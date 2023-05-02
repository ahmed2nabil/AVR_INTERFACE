/*
 * mychallege.c
 *
 *  Created on: Aug 5, 2018
 *      Author: nobol billy
 */
#include<avr/io.h>
#include<avr/interrupt.h>
unsigned char g_counter=0 ;
ISR(INT2_vect){

if(g_counter== 9){
	g_counter=0;
	PORTC = (PORTC & 0xF0) | (g_counter & 0x0F);
PORTB = (PORTB & 0b11111100) | (PORTC & 0b00000011);
PORTB = (PORTB & 0b00111111) | (PORTC << 4 | (PORTC & 0b11000000) );
}
else
{
	g_counter++;
PORTC = (PORTC & 0xF0) | (g_counter & 0x0F);
PORTB = (PORTB & 0b11111100) | (PORTC & 0b00000011);
PORTB = (PORTB & 0b00111111) | (PORTC << 4 | (PORTC & 0b11000000) );
}
}
void INT2_Init(void){
	SREG &= ~(1<<7);
DDRD &= (~(1<<PD2));
	GICR |= (1<<INT2);
	MCUCSR |=(1<<ISC2);
	SREG |=(1<<7);
}
int main (){
	DDRC |= 0x0F;
	PORTC &= 0xF0;
	DDRB |= (1<<PB0) |(1<<PB1)|(1<<PB6)|(1<<PB7);
	PORTB &= ~(1<<PB0) | ~(1<<PB1)| ~(1<<PB6)| ~(1<<PB7);


INT2_Init();
	while(1){
}
}
