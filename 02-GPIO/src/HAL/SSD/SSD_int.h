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
#define SSD          1


#define SSD_TYPE        COM_ANODE
#define SSD_PORT        GPIO_PORTA
void SSD_vInit       ();
void SSD_vDisplayNum (u8 A_u8Num);




#endif /* HAL_SSD_SSD_INT_H_ */
