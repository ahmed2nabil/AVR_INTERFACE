/*
 * my.c
 *
 *  Created on: Jan 17, 2020
 *      Author: nobol billy
 */


#include<avr/io.h>
#include<util/delay.h>

#define FULL_WAVE_STEPS 8

 int main (){
	 unsigned char motor_steps[FULL_WAVE_STEPS] = {12,4,6,2,3,1,9,8};
	 	unsigned char count = 0;
	 DDRC |= 0xFF ;
	 PORTC &= 0xF0;
	 while (1){
		 _delay_ms(500);
		 PORTC = (motor_steps[count] & 0x0F) | (PORTC & 0xF0);
		 				count++;
		 				if(count == FULL_WAVE_STEPS)
		 				{
		 					//start from the beginning after finish the full motor rotation.
		 					count = 0;
		 				}
	 }
 }
