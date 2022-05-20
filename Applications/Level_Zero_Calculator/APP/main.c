/*
 * main.c
 *
 *  Created on: May 17, 2022
 *      Author: Karim
 */
#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KPD/KPD_int.h"

#include "calc.h"

int main(void)
{
	KPD_vInit();
	HLCD_vInit();



	while(1)     //Super loop
	{
		A_vCalc();
	}

}



