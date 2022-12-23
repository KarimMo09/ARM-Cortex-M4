/*
 * STK_prg.c
 *
 *  Created on: Aug 31, 2022
 *      Author: Karim
 */
#include "../../LIB/Bit_math.h"
#include "../../LIB/STD_TYPES.h"
#include "STK_prv.h"
#include "STK_cfg.h"
#include "STK_int.h"

static void (*GS_SYSTICK_CallBack)(void)=NULL;
u8 G_u8IntervalType;
void MSTK_vInit(void)
{

	/*---Select Clock Source---*/
#if   CLKSOURCE_SEL==AHB
	  SET_BIT(STK->CTRL,CLKSOURCE);
#elif CLKSOURCE_SEL==AHB_DIVIDED_BY_8
      CLR_BIT(STK->CTRL,CLKSOURCE);
#endif
      /*---Disable STK-----*/
      CLR_BIT(STK->CTRL,STK_EN);
      /*---Enable STK Interrupt----*/
      SET_BIT(STK->CTRL,TICKINT);

}
void MSTK_vSetBusyWait(u32 A_u32Ticks)
{

    /*----Clear VAL Reg-------*/
    STK->VAL=0;
    /*---Load Desert Value-----*/
    STK->LOAD=A_u32Ticks;

    /*---Enable STK-----*/
    SET_BIT(STK->CTRL,STK_EN);

    /*----- Wait till VAL reg reaches to 0 ----*/
    while(STK->VAL!=0);
   // while(GET_BIT(STK->CTRL,COUNTFLAG)==0);
    /*---Disable STK-----*/
    CLR_BIT(STK->CTRL,STK_EN);

}
void MSTK_vSetIntervalSingle(u32 A_u32Ticks , void (*A_xfptr)(void))
{
	G_u8IntervalType=SINGLE_INTERVAL;
	GS_SYSTICK_CallBack=A_xfptr;
	/*----Clear VAL Reg-------*/
	STK->VAL=0;
    /*---Load Desert Value-----*/
    STK->LOAD=A_u32Ticks;
	/*---Enable STK-----*/
	SET_BIT(STK->CTRL,STK_EN);
}
void MSTK_vSetIntervalPeriodic(u32 A_u32Ticks , void (*A_xfptr)(void))
{
	G_u8IntervalType=PERIODIC_INTERVAL;
	GS_SYSTICK_CallBack=A_xfptr;
	/*----Clear VAL Reg-------*/
	STK->VAL=0;
    /*---Load Desert Value-----*/
    STK->LOAD=A_u32Ticks;
	/*---Enable STK-----*/
	SET_BIT(STK->CTRL,STK_EN);

}
void MSTK_vStopInterval(void)
{
    STK->LOAD=0;
}
u32 MSTK_vGetElapsedTime(void)
{
	return (STK->LOAD - STK->VAL);
}
u32 MSTK_vGetRemainingTime(void)
{
	return (STK->VAL);
}

void SysTick_Handler(void)
{
	if(GS_SYSTICK_CallBack!=NULL)
	{
		if(G_u8IntervalType == SINGLE_INTERVAL)
		{
		    /*---Disable STK-----*/
		    CLR_BIT(STK->CTRL,STK_EN);
		}
		GS_SYSTICK_CallBack();
		CLR_BIT(STK->CTRL,COUNTFLAG);
	}

}



