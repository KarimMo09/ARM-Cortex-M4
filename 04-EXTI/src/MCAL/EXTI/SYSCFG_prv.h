/*
 * SYSCFG_prv.h
 *
 *  Created on: Sep 1, 2022
 *      Author: Karim
 */

#ifndef MCAL_EXTI_SYSCFG_PRV_H_
#define MCAL_EXTI_SYSCFG_PRV_H_



#define SYSCFG_BASE_ADDR	0x40013800

/*-------------SYSCFG Registers------------*/
typedef struct
{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 CMPCR;


}SYSCFG_MemMap_t;

#define SYSCFG ((volatile SYSCFG_MemMap_t*)(SYSCFG_BASE_ADDR))

#endif /* MCAL_EXTI_SYSCFG_PRV_H_ */
