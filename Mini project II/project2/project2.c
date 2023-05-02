/*
 * project2.c
 *
 *  Created on: Sep 26, 2018
 *      Author: nobol billy
 */
#include "adc.h"
#include "lcd.h"
void PWM_Timer0_Init(unsigned char set_duty_cycle){

	TCNT0 = 0; //initial timer value

	OCR0  = set_duty_cycle;

	DDRB  = DDRB | (1<<PB3); //set OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
int main(void)
{
	uint16 res_value;
	LCD_init(); /* initialize LCD driver */
	ADC_init(); /* initialize ADC driver */
	LCD_clearScreen(); /* clear LCD at the beginning */
	/* display this string "ADC Value = " only once at LCD */
	LCD_displayString("ADC Value = ");
	SET_BIT(DDRD,PD0);
	SET_BIT(DDRD,PD1);
    while(1)
    {
		LCD_goToRowColumn(0,12); /* display the number every time at this position */
		res_value = ADC_readChannel(0); /* read channel zero where the potentiometer is connect */
		LCD_intgerToString(res_value); /* display the ADC value on LCD screen */
		SET_BIT(PORTD,PD0);
		PWM_Timer0_Init(res_value/4);
    }
}
