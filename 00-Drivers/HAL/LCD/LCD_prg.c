/*
 * LCD_prg.h
 *
 *  Created on: May 19, 2022
 *      Author: Karim
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>
#include "LCD_int.h"

void HLCD_vInit(void)
{
	/*Set you pin direction */
	DIO_vSetPortDir(LCD_DATA_PORT,PORT_OUTPUT);
	DIO_vSetPinDir(LCD_CTRL_PORT,LCD_RS_PIN,DIO_OUTPUT);
	DIO_vSetPinDir(LCD_CTRL_PORT,LCD_RW_PIN,DIO_OUTPUT);
	DIO_vSetPinDir(LCD_CTRL_PORT,LCD_EN_PIN,DIO_OUTPUT);

	/*Start init sequence */
	_delay_ms(50);
	HLCD_vSendCommand(0x38);   //function set 2 lines used &5*7 dot
	_delay_ms(1);
	HLCD_vSendCommand(0x0E);   //Display on cursor off blinkink off
	_delay_ms(1);
	HLCD_vSendCommand(CLR_SCREEN);   //clear display
	_delay_ms(3);
	HLCD_vSendCommand(0x06);   //entry mode
	_delay_ms(1);
	/* end initialization */
}

void HLCD_vClrScreen(void)
{
	HLCD_vSendCommand(CLR_SCREEN);
}
void HLCD_vSendCommand(u8 A_u8Cmd)
{
	/*Control RS and RW Pins*/
	
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	
	/* Write Command on the data Pins */
	DIO_vSetPortVal(LCD_DATA_PORT,A_u8Cmd);
	
	/* Pulse on the enable pin */
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);
	_delay_ms(1);
}

void HLCD_vSendChar(u8 A_u8Char)
{
	/*Control RS and RW Pins*/

	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_RS_PIN,DIO_HIGH);
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	
	/* Write Data on the data Pins */
	DIO_vSetPortVal(LCD_DATA_PORT,A_u8Char);
	
	/* Pulse on the enable pin */
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);
	_delay_ms(1);
}

void HLCD_vPrintString(char A_s8String[] )
{
	static u8 L_su8Row=ROW_ONE;
	u8 flag=0;
	for(u8 L_u8Char=0;A_s8String[L_u8Char] !='\0';L_u8Char++)
	{
		HLCD_vSendChar(A_s8String[L_u8Char]);
		_delay_ms(200);
		if(L_u8Char==COLUMN16 && L_su8Row==ROW_ONE)
		{
			HLCD_vSetCursorPosition(ROW_ONE ,COLUMN17);
			HLCD_vSendCommand(SHIFT_SCREEN_LEFT);
			L_su8Row=ROW_TWO;
			flag=1;
		}
		/*else if(A_s8String[L_u8Char] =='\0' && L_su8Row==ROW_ONE)
			L_su8Row=ROW_TWO;
*/
		else if(L_u8Char==COLUMN16 && L_su8Row==ROW_TWO)
		{
			HLCD_vSetCursorPosition(ROW_TWO ,COLUMN17);
			HLCD_vSendCommand(SHIFT_SCREEN_LEFT);
			L_su8Row=ROW_ONE;
			flag=1;
		}
		/*else if(A_s8String[L_u8Char] =='\0' && L_su8Row==ROW_TWO)
			L_su8Row=ROW_ONE;*/
	}
	if(L_su8Row==ROW_ONE && flag==0)
		L_su8Row=ROW_TWO;
	else if (L_su8Row==ROW_TWO && flag==0)
		L_su8Row=ROW_ONE;
	_delay_ms(1000);
	HLCD_vSendCommand(RETURN_HOME);
	HLCD_vSendCommand(ENTRY_MODE);




}
void HLCD_vPrintNumber(s32 A_s32Number )
{
	u8 L_u8DigitNum[25];
	s8 L_s8Digit=0;
	if(A_s32Number<0)
	{
		A_s32Number*=-1;
		HLCD_vSendChar('-');
	}
	else if(A_s32Number==0)
	{
		HLCD_vSendChar(0+48);
	}
	while(A_s32Number)
		{
			L_u8DigitNum[L_s8Digit]=A_s32Number%10;
			A_s32Number/=10;
			L_s8Digit++;
		}
	for(L_s8Digit-=1 ; L_s8Digit>=0 ; L_s8Digit--)
	{
		HLCD_vSendChar(L_u8DigitNum[L_s8Digit]+48);
	}

}
void HLCD_vSetCursorPosition(u8 A_u8LinePos ,u8 A_u8LineNo)
{
	if(A_u8LinePos==ROW_TWO)
	{
		HLCD_vSendCommand(INIT_CURSOR_POS+ROW_TWO+A_u8LineNo);
	}
	else
	{
		HLCD_vSendCommand(INIT_CURSOR_POS+ROW_ONE+A_u8LineNo);
	}

}
void HLCD_vSaveCustomChar(/*TODO:inputs arguments to be provided */)
{

}
void HLCD_vDisplayCustomChar(/*TODO:to be done */)
{

}
