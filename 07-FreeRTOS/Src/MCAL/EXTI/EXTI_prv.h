/*
 * EXTI_prv.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Karim
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

#define EXTI_BASE_ADDR    (0x40013C00)

typedef struct
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;

}EXTI_MemMap_t;

#define EXTI ((volatile EXTI_MemMap_t *)(EXTI_BASE_ADDR))

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



#endif /* MCAL_EXTI_EXTI_PRV_H_ */
