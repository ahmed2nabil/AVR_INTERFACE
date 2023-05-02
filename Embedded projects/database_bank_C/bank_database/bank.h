/*
 * bank.h
 *
 *  Created on: Apr 29, 2020
 *      Author: 20114
 */

#ifndef BANK_H_
#define BANK_H_

typedef struct customer {
	char name[30];
	char type ;
	int id ;
	double cash;
} customer_t;


void create__new_customer(void);
#endif /* BANK_H_ */
