/*
 * ex2.c
 *
 *  Created on: Aug 10, 2018
 *      Author: nobol billy
 */
#include<avr/io.h>
#include<util/delay.h>
#define size 8
unsigned char count=0;
unsigned char arr[size]={8,12,4,6,2,3,1,9};
int main (){
	PORTC&=0xF0;
	while(1){
		_delay_ms(500);
		PORTC=(arr[count]&0x0F)|(PORTC&0xF0);
		count++;
		if(count==size)
			count=0;

	}

}

