/*
 * KPD_int.h
 *
 *  Created on: May 17, 2022
 *      Author: Karim
 */

#ifndef HAL_KPD_KPD_INT_H_
#define HAL_KPD_KPD_INT_H_

#include "../../MCAL/DIO/DIO_int.h"
#define KPD_PORT     DIO_PORTC
#define KPD_PORT_Dir 0x0f
#define NOT_PRESSED  0xff

void KPD_vInit(void);
u8   KPD_u8GetPressedKey(void);

#endif /* HAL_KPD_KPD_INT_H_ */
