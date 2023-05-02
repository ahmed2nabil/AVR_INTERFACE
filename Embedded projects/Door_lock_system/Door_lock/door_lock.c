/*
 * door_lock.c
 *
 *  Created on: Apr 12, 2020
 *      Author: 20114
 */
#include "keypad.h"
#include "lcd.h"

#define pass_size 4
uint8 fix_pass[pass_size]={0};
void reenter_password(uint8 new_pass[]){
for (int i=0;i<pass_size;i++){
	fix_pass[i]=new_pass[i];
}
}
uint8 check_password(uint8 PassWord[]){
	uint8 flag=0;
	for (int i=0;i<pass_size;i++){
		if(fix_pass[i]==PassWord[i]){
			flag=1;
		}
		else{
			flag=0;
			break;
		}
		}
	return flag;
}

void open_door(void){
	LCD_clearScreen();
	LCD_displayString("The door is opening");
	SET_BIT(PORTD,PD0);
	CLEAR_BIT(PORTD,PD1);
	_delay_ms(5000);
	CLEAR_BIT(PORTD,PD0);
	CLEAR_BIT(PORTD,PD1);
}

void wrong_pass(void){
	LCD_clearScreen();
	LCD_displayString("Wrong,Try again");
	LCD_goToRowColumn(1,1);
}
void display_right_pass_option(void){
	LCD_clearScreen();
		LCD_displayString("1-open door");
		LCD_goToRowColumn(1,0);
		LCD_displayString("2-change password");
}
void motor_config(void){
	/* two pins output for motor*/
	SET_BIT(DDRD,PD0);
	SET_BIT(DDRD,PD1);
	SET_BIT(DDRD,PD2);//control pin
	CLEAR_BIT(PORTD,PD0);//set 0 to motor
	CLEAR_BIT(PORTD,PD1);
	SET_BIT(PORTD,PD2);	//set control
}
void change_password(void){
	LCD_clearScreen();
	LCD_displayString("Enter new password");
	LCD_goToRowColumn(1,1);
uint8 new_p[pass_size];
	for(int i=0; i<pass_size;i++){
	new_p[i]= KeyPad_getPressedKey();
	 LCD_displayCharacter('*');
	 _delay_ms(500);
						}
reenter_password(new_p);
LCD_clearScreen();
	LCD_displayString("Done");
	 _delay_ms(2000);
	 LCD_clearScreen();
	 LCD_displayString("Enter your password");
	 LCD_goToRowColumn(1,1);
}

int main(void){
LCD_init();
LCD_displayString("Enter your password");
LCD_goToRowColumn(1,1);
motor_config();
uint8 password[pass_size];
uint8 option_pick;
while(1){

	for(int i=0; i<pass_size;i++){
	 password[i]= KeyPad_getPressedKey();
	 LCD_displayCharacter('*');
	 _delay_ms(500);
						}

	if (check_password(password)){
display_right_pass_option();
while(!KeyPad_getPressedKey()){}
option_pick=KeyPad_getPressedKey();

if(option_pick==1){
open_door();
}
else {
change_password();
}
	}
else {
wrong_pass();
}
}

return 0;
}
