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
	DDRB=0x01;
	PORTB=0x01;
	unsigned char seg[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
	unsigned char i;

	while(1)
	{
		for(i=0;i<9;i++)
		{
			PORTA=seg[i];
			_delay_ms(500);
		}

		for(i=9;i>0;i--)
		{
			PORTA=seg[i];
			_delay_ms(500);
		}

	}

}


