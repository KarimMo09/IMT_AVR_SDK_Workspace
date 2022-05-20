/*
 * main.c
 *
 *  Created on: May 17, 2022
 *      Author: Karim
 */
#include "../LIB/Bit_math.h"
#include "../LIB/STD_TYPES.h"
#include "../HAL/KPD/KPD_int.h"
#include "../HAL/SSD/SSD_int.h"


int main(void)
{

	u8 L_u8Key=0;
	SSD_vInit(SSD1);
	SSD_vInit(SSD2);
	KPD_vInit();
	SSD_vDisplayNum(SSD1,L_u8Key%10);
	SSD_vDisplayNum(SSD2,L_u8Key/10);
	while(1)     //Super loop
	{
		L_u8Key=KPD_u8GetPressedKey();
		if(L_u8Key!=NOT_PRESSED)
		{
			/*seven segment display code*/
			SSD_vDisplayNum(SSD1,L_u8Key%10);
			SSD_vDisplayNum(SSD2,L_u8Key/10);

		}

	}
}



