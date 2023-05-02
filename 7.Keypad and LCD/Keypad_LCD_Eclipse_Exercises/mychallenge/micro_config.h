/*
 * micro_config.h
 *
 *  Created on: Sep 15, 2018
 *      Author: nobol billy
 */
/* file contains all MC libraries we need */

#ifndef MICRO_CONFIG
#define MICRO_CONFIG

#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

#endif
