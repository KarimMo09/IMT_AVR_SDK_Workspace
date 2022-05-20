/*
 * main.c
 *
 *  Created on: May 10, 2022
 *      Author: Karim
 */
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "Bit_math.h"
int main(void) 
{
	SET_BIT(DDRA,0) ;//Set pin A0 o/p
	CLR_BIT(PORTA,1)  ;
	SET_BIT(PORTA,1)  ;
    unsigned char flag=0;
	while(1)     //Super loop
	{

		if(READ_BIT(PINA,1)==0 && flag==0)
		{
				TOG_BIT(PORTA,0);
				flag=1;
		}
		else if(READ_BIT(PINA,1)==1)
		{
			flag=0;
		}
		/*if(READ_BIT(PINB,1)==0)
		{
			SET_BIT(PORTB,0)  ; //Set pin A0 High
		}
		else
		{
			CLR_BIT(PORTB,0)  ;
		}*/

	}
}


