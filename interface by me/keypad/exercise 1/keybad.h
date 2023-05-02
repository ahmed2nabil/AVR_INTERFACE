/*
 * keybad.h
 *
 *  Created on: Sep 16, 2018
 *      Author: nobol billy
 */

#ifndef KEYBAD_H_
#define KEYBAD_H_
#include"common macros.h"
#include"micro_config.h"
#include"std_types.h"
 /************************** STATIC CONFIGRATION************************ */
#define N_col 4  /*Number of columns of keypad */
#define N_row 4  /*Number of rows of kaeypad  */
/***************************************************************************
 *                         PREPOCESSOR MACROS                             *
 ***************************************************************************/
/*keybad port configration */
#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_IN  PINA
#define KEYPAD_PORT_DIR DDRA
/**********************************************************************
 *                        FUNCTION POROTYPES                          *
 ************************************************************************/
uint8 Keypad_GetPressedKey(void);
#endif /* KEYBAD_H_ */

