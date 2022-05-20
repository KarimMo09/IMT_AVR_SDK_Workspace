/*
 * main.c
 *
 *  Created on: May 11, 2022
 *      Author: Karim
 */
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA=0xFF;
	DDRB=0xFF;
	unsigned char seg[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

	while(1)
	{
			PORTA=~seg[0];
			PORTB=seg[9];
			_delay_ms(1000);
			PORTA=~seg[1];
			PORTB=seg[1];
			_delay_ms(1000);


	}

}


