/*
 * calc.c
 *
 *  Created on: May 20, 2022
 *      Author: Karim
 */

#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KPD/KPD_int.h"
#include "calc.h"
void A_vCalc(void)
{
	u8 L_u8Key=0xff;
	u8 L_u8Eq[OP_LENGTH ];
	u8 L_u8i=IINTIAL  ;
	s8 L_u8Result=IINTIAL  ;
	/* insert the operation */
	while(L_u8i<=3)
		{
			L_u8Key=KPD_u8GetPressedKey();
			if(0xff!=L_u8Key)
			{
				if(L_u8i==IINTIAL )     //clr screen before scan the operation
				{
					HLCD_vClrScreen();
				}
				else
				{

				}
				L_u8Eq[L_u8i]=L_u8Key;
				L_u8i++;
				if(L_u8Key=='/' || L_u8Key=='*' || L_u8Key=='-' || L_u8Key=='+' || L_u8Key=='=' )
				{
					HLCD_vSendChar(L_u8Key);
				}
				else if( L_u8Key=='#')     // this option to clr screen
				{
					HLCD_vClrScreen();
					L_u8i=OP_LENGTH;			  // to break loop
				}
				else
				{
					HLCD_vPrintNumber(L_u8Key);
				}
		     }
		}
		/* check is screen is cleared or not*/
		if(L_u8Key=='#') //screen cleared so do not any thing
		{
		}
		/* insertion completed successfully Print the result */
		else
		{
			switch(L_u8Eq[OPERAND])
			{
				case'+' :L_u8Result=L_u8Eq[NUM1] + L_u8Eq[NUM2];
						 HLCD_vPrintNumber(L_u8Result);
						 break;
				case'-' :L_u8Result=L_u8Eq[NUM1] - L_u8Eq[NUM2];
						 HLCD_vPrintNumber(L_u8Result);
						 break;
				case'*' :L_u8Result=L_u8Eq[NUM1] * L_u8Eq[NUM2];
					     HLCD_vPrintNumber(L_u8Result);
						 break;
				case'/' :if(L_u8Eq[NUM2]==0)
						{
							HLCD_vSetCursorPosition(ROW_TWO,COLUMN5);
							HLCD_vPrintString("Error");
						}
						else
						{
							L_u8Result=L_u8Eq[0]/L_u8Eq[2];
							HLCD_vPrintNumber(L_u8Result);
						}
						 break;
				default :HLCD_vSetCursorPosition(ROW_TWO,COLUMN5);
					     HLCD_vPrintString("Error");

						 break;
			}
		}
		L_u8i=0; //to make new insertion
	}

