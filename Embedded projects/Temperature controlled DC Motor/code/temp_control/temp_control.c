/*
 * temp_control.c
 *
 *  Created on: Apr 19, 2020
 *      Author: 20114
 */


#include "adc.h"
#include "lcd.h"


void motor_config(void){
	/* two pins output for motor*/
	SET_BIT(DDRD,PD0);
	SET_BIT(DDRD,PD1);
	CLEAR_BIT(PORTD,PD0);//set 0 to motor
	CLEAR_BIT(PORTD,PD1);
}


int main (void){
LCD_init();
ADC_init();
motor_config();
LCD_displayString("Room Temp :");
LCD_goToRowColumn(0,17);
LCD_displayCharacter('C');
uint16 temp;
	while(1){
		LCD_goToRowColumn(0,13); /* display the number every time at this position */
			temp=ADC_readChannel(0); /* read channel two where the temp sensor is connect */
			temp = (temp*150*5)/(1023*1.5); /* calculate the temp from the ADC value*/
			LCD_intgerToString(temp); /* display the temp on LCD screen */
			if(temp>27){
				SET_BIT(PORTD,PD0);
				CLEAR_BIT(PORTD,PD1);
			}
			else {
				CLEAR_BIT(PORTD,PD0);
				CLEAR_BIT(PORTD,PD1);
			}
	}
return 0;
}
