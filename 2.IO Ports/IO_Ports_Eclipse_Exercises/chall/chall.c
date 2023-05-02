/*
 * chall.c
 *
 *  Created on: Jan 2, 2020
 *      Author: nobol billy
 */


#include<avr/io.h>
#include<util/delay.h>
int main(){

DDRC=0xFF;
PORTC =0x01;

while(1){
_delay_ms(500);
PORTC = (PORTC<<1);
if(PORTC==0x00)
	PORTC=0x01;
}
}
