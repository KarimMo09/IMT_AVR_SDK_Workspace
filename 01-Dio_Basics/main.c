/*
 * main.c
 *
 *  Created on: May 10, 2022
 *      Author: Karim
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//DDRB =0b00000001  ; //Set pin A0 o/p
	DDRB=0b00000001;
	    while(1)
	    {
			PORTB=0b00000001;
			_delay_ms(1000);
			PORTB=0b00000000;
			 _delay_ms(1000);
		}


	/*while(1)     //Super loop
	{
		PORTB=0b00000000  ; //Set pin A0 Low
		_delay_ms(1000) ;
		PORTB=0b00000001  ; //Set pin A0 High
		_delay_ms(1000);
		/*for(int i=0;i<4;i++)
		{
			_delay_ms(250   ) ;
			PORTB<<=1;
		}*/

	}*/
}


