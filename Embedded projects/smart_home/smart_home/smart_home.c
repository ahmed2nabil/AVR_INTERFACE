/*
 * smart_home.c
 *
 *  Created on: May 2, 2020
 *      Author: 20114
 */
#include"smart1.h"
#include<avr/eeprom.h>
int main(){
LCD_init();
SPI_initMaster();
LCD_clearScreen();
uint8 flag_admin=-1;
uint8 flag_guest=-1;
uint8 flag_set_up;
uint8 Admin_guest_option;
while(1){
	//===================================first set up================================
	flag_set_up=eeprom_read_byte((uint8*)admin_set);
	if (!(flag_set_up==0)){
		first_set_up();
	}
	//==============================login===========================================
	LCD_clearScreen();
	LCD_displayString("0:Admin");
	LCD_goToRowColumn(1,0);
	LCD_displayString("1:guest");
	LCD_goToRowColumn(2,0);
	Admin_guest_option=KeyPad_getPressedKey();
	LCD_displayCharacter("*");
	_delay_ms(600);
if(Admin_guest_option==1){
flag_guest=guest_check_password();
}
else if(Admin_guest_option==0){
flag_admin=admin_check_password();
}
///===========================Admin Mode=============================================
if(flag_admin==1){
	LCD_clearScreen();
	LCD_displayString("Right admin password");
}
else {
	LCD_clearScreen();
	LCD_displayString("Wrong admin password");
}
//==================================guest Mode ====================================
if(flag_admin==1){
	LCD_clearScreen();
	LCD_displayString("Right guest password");
}
else {
	LCD_clearScreen();
	LCD_displayString("Wrong guest password");
}
}
	return 0;
}




uint8 guest_check_password(void){
	uint8 check_guest_password[pass_size];
	eeprom_read_block(check_guest_password,(uint8*)address_guest,pass_size);
	uint8 guest_password[pass_size];
	uint8 flag=-1;
		LCD_clearScreen();
		LCD_displayString("Guest Mode");
		LCD_goToRowColumn(1,0);
		LCD_displayString("Enter password");
		for(int i=0;i<pass_size;i++)
		{
			guest_password[i]=KeyPad_getPressedKey();
			if(guest_password[i]==check_guest_password){
				flag=1;
			}
			LCD_displayCharacter('*');
		_delay_ms(600);

		}
		return flag;
}

uint8 admin_check_password(void){
	uint8 check_admin_password[pass_size];
	eeprom_read_block(check_admin_password,(uint8*)address_admin,pass_size);
	uint8 admin_password[pass_size];
	uint8 flag=-1;
		LCD_clearScreen();
		LCD_displayString("Admin Mode");
		LCD_goToRowColumn(1,0);
		LCD_displayString("Enter password");
		for(int i=0;i<pass_size;i++)
		{
			admin_password[i]=KeyPad_getPressedKey();
			if(admin_password[i]==check_admin_password){
				flag=1;
			}
			LCD_displayCharacter('*');
		_delay_ms(600);

		}
		return flag;
}

void first_set_up(void){
	uint8 option;
	LCD_clearScreen();
LCD_displayString("Set Password for ");
LCD_goToRowColumn(1,0);
LCD_displayString("0:Admin  1:Guest");
option=KeyPad_getPressedKey();
_delay_ms(600);
if(option==0){
set_password_admin();
}
else if (option==1){
	set_password_guest();
}
if(option==0){
LCD_clearScreen();
LCD_displayString("Set Password for guest ");
LCD_goToRowColumn(1,0);
set_password_guest();
}
else if ()
}
void set_password_admin(void){
uint8 admin_password[pass_size];
	LCD_clearScreen();
	LCD_displayString("Admin Mode");
	LCD_goToRowColumn(1,0);
	LCD_displayString("Enter password");
	for(int i=0;i<pass_size;i++)
	{
		admin_password[i]=KeyPad_getPressedKey();
		LCD_displayCharacter('*');
	_delay_ms(600);
	}
	eeprom_write_block(admin_password,(uint8*)address_admin,pass_size);
	eeprom_write_byte((uint8*)admin_set,0);
}

void set_password_guest(void){
uint8 guest_password[pass_size];
	LCD_clearScreen();
	LCD_displayString("Admin Mode");
	LCD_goToRowColumn(1,0);
	LCD_displayString("Enter password");
	for(int i=0;i<pass_size;i++)
	{
		guest_password[i]=KeyPad_getPressedKey();
		LCD_displayCharacter('*');
	_delay_ms(600);
	}
	eeprom_write_block(guest_password,(uint8*)address_guest,pass_size);
	eeprom_write_byte((uint8*)guest_set,0);
}