/*
 * NVIC_prv.h
 *
 *  Created on: Aug 28, 2022
 *      Author: Karim
 */

#ifndef MCAL_NVIC_NVIC_PRV_H_
#define MCAL_NVIC_NVIC_PRV_H_


#define NVIC_BASE_ADDR    0xE000E100
#define SCB_BASE_ADDR     0xE000ED00
typedef struct
{
	u32 ISER[32];
	u32 ICER[32];
	u32 ISPR[32];
	u32 ICPR[32];
	u32 IABR[32];
	u32 RESERVED[32];
	u8  IPR[240];


}NVIC_MemMap_t;

#define NVIC       ((volatile NVIC_MemMap_t *)(NVIC_BASE_ADDR))
#define NVIC_STIR ((volatile NVIC_MemMap_t *)(NVIC_BASE_ADDR+0xE00))

typedef struct
{

    u32 CPUID;
    u32 ICSR;
    u32 VTOR;
    u32 AIRCR;
    u32 SCR;
    u32 CCR;
    u32 SHPR1;
    u32 SHPR2;
    u32 SHPR3;
    u32 SHCSR;
    u32 CFSR;
    u32 HFSR;
    u32 RESERVED;
    u32 MMFAR;
    u32 BFAR;
    u32 ASFR;

} SCB_MemMap_t;

#define SCB ((volatile SCB_MemMap_t *)(SCB_BASE_ADDR ))


/*--------AIRCR Reg Config-------------*/
#define VECTKEY 0x05FA0000
#define GROUPS_16_SUB_1  0b011
#define GROUPS_8_SUB_2   0b100
#define GROUPS_4_SUB_4   0b101
#define GROUPS_2_SUB_8   0b110
#define GROUPS_1_SUB_16  0b111
#endif /* MCAL_NVIC_NVIC_PRV_H_ */
