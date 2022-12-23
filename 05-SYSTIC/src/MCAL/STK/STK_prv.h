/*
 * STK_prv.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Karim
 */

#ifndef MCAL_STK_STK_PRV_H_
#define MCAL_STK_STK_PRV_H_

#define MSTK_BASE_ADDR   0xE000E010

typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}MSTK_MemMap_t;

#define STK 	((volatile MSTK_MemMap_t *)(MSTK_BASE_ADDR))
#define AHB_DIVIDED_BY_8    0
#define AHB					1


#endif /* MCAL_STK_STK_PRV_H_ */
