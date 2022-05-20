/*
 * SSD_int.h
 *
 *  Created on: May 17, 2022
 *      Author: Karim
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_
#include "../../LIB/STD_TYPES.h"
#define COM_CATHODE   0
#define COM_ANODE     1
#define SSD1          1
#define SSD2          2

#define SSD_TYPE        COM_ANODE
#define SSD1_PORT        DIO_PORTC
#define SSD2_PORT        DIO_PORTB
void SSD_vInit       (u8 A_u8SsdNo);
void SSD_vDisplayNum (u8 A_u8SsdNo,u8 A_u8Num  );
void SSD_vTurnOff    (u8 A_u8SsdNo);




#endif /* HAL_SSD_SSD_INT_H_ */
