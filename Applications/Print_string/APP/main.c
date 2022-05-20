/*
 * main.c
 *
 *  Created on: May 17, 2022
 *      Author: Karim
 */

#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"

int main(void)
{
	HLCD_vInit();


	while(1)     //Super loop
	{
		HLCD_vPrintString("Hello guys,^_^");
		HLCD_vSetCursorPosition(ROW_TWO,COLUMN1);
		HLCD_vPrintString("I'm Karim Mohamed");
		HLCD_vClrScreen();
		HLCD_vPrintString("I'm 21 years old");
		HLCD_vSetCursorPosition(ROW_TWO,COLUMN1);
		HLCD_vPrintString("And I'm studying at Al-Azhar University");
		HLCD_vClrScreen();
		HLCD_vPrintString("Have a nice day");
		HLCD_vSetCursorPosition(ROW_TWO,COLUMN5);
		HLCD_vPrintString("(^_^)");
		HLCD_vClrScreen();

	}
}



