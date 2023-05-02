/*
 * common macros.h
 *
 *  Created on: Sep 15, 2018
 *      Author: nobol billy
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_
/*PUT THIS BIT IS ZERO */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))
/*PUT THIS BIT IS ONE */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
/*TOGGLE THIS BIT*/
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))
/*ROTATE THE VALUES AT REGISTERS RIGHT*/
#define ROR(REG,NUM) ( REG = ( REG>>NUM ) | ( REG<<(8-NUM) ) )
/*ROTATE THE VALUES AT REGISTERS LEFT*/
#define ROL(REG,NUM) ( REG = ( REG<<NUM ) | ( REG>>(8-NUM) ) )
/*CHECK A BIT IS SET IF YES  RETURN TRUE*/
#define BIT_IS_SET(REG,BIT) (REG&(1<<BIT))
/*CHECK A BIT IS CLEAR IF YES  RETURN TRUE*/
#define BIT_IS_CLEAR(REG,BIT) (REG &~(1<<BIT))
#endif /* COMMON_MACROS_H_ */
