/*
 * NVIC_prg.c
 *
 *  Created on: Aug 28, 2022
 *      Author: Karim
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_math.h"
#include "NVIC_prv.h"
#include "NVIC_cfg.h"
#include "NVIC_int.h"

void MNVIC_vEnablePerihral(u8 A_INTID)
{
	SET_BIT(NVIC->ISER[A_INTID/32],( A_INTID%32) );
}
void MNVIC_vDisablePerhral(u8 A_INTID)
{
	SET_BIT(NVIC->ICER[A_INTID/32] , (A_INTID%32) );
}
void MNVIC_vSetPending(u8 A_INTID)
{

	SET_BIT(NVIC->ISPR[A_INTID/32], (A_INTID%32) );
}
void MNVIC_vClearPending(u8 A_INTID)
{
	SET_BIT(NVIC->ICPR[A_INTID/32], (A_INTID%32) );
}
u8   MNVIC_u8GetActive(u8 A_INTID)
{
	return GET_BIT(NVIC->IABR[A_INTID/32],A_INTID%32);
}

void MNVIC_voidSetPriorityConfig(void)
{
	SCB->AIRCR=VECTKEY|(PRIORITY_CONFIG<<8);
}
void MNVIC_vSetPriority (s8 A_s8INTID, u8 A_u8GroupPriority, u8 A_u8SubPriority)
{
	u8 L_u8Priority=A_u8SubPriority|A_u8GroupPriority<<((PRIORITY_CONFIG-3));
	/*if(A_s8INTID<0)
	{
		if(A_s8INTID==MEMORY_MANAGE || A_s8INTID==BUS_FAULT || A_s8INTID==USAGE_FAULT)
		{
			A_s8INTID+=3;
			SCB->SHPR1=(L_u8Priority)<<((8*A_s8INTID)+4);
		}
		else if ( A_s8INTID==SV_CALL )
		{
			A_s8INTID+=7;
			SCB->SHPR2=(L_u8Priority)<<((8*A_s8INTID)+4);
		}
		else if ( A_s8INTID==PEND_SV || A_s8INTID==SYSTICK)
		{
			A_s8INTID+=8;
			SCB->SHPR3=(L_u8Priority)<<((8*A_s8INTID)+4);
		}
	}
	else if(A_s8INTID>=0)
	{
		NVIC->IPR[A_s8INTID]=L_u8Priority<<4;
	}*/
	if(A_s8INTID<0)
	{
		switch(A_s8INTID)
		{
			case  MEMORY_MANAGE...USAGE_FAULT :
					      A_s8INTID+=7;
					      SCB->SHPR1=(L_u8Priority)<<((8*A_s8INTID)+4);
					      break;
			case SV_CALL :
					      A_s8INTID+=7;
					      SCB->SHPR2=(L_u8Priority)<<((8*A_s8INTID)+4);
					      break;
			case PEND_SV :
			case SYSTICK :
						  A_s8INTID+=8;
						  SCB->SHPR3=(L_u8Priority)<<((8*A_s8INTID)+4);
						  break;
			default :
				/*Erorr*/
				          break;
		}
	}
		else if(A_s8INTID>=0)
		{
			NVIC->IPR[A_s8INTID]=L_u8Priority<<4;
		}

}

