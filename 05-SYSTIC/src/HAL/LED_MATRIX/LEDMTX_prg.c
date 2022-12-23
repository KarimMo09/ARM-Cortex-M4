/*
 * LEDMATRIX_prg.c
 *
 *  Created on: Sep 6, 2022
 *      Author: Karim
 */
#include "../../LIB/Bit_math.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/STK/STK_int.h"

#include "LEDMTX_prv.h"
#include "LEDMTX_cfg.h"
#include "LEDMTX_int.h"

void HLEDMATRIX_vInit(void)
{

	for(u8 i=0; i<NO_ROWS ; i++)
	{
		MGPIO_vInit(&rows[i]);
	}
	for(u8 i=0; i<NO_COLS ; i++)
	{
		MGPIO_vInit(&cols[i]);
	}
	MSTK_vInit();
}

static void HLEDMTX_vDisableAllColumns()
{
	for(u8 i=0 ;i<NO_COLS ;i++)
	{
	   MGPIO_vSetPinVal_fast(cols[i].Port ,cols[i].Pin ,GPIO_HIGH);
	}
}

static void HLEDMTX_vSetRowValues(u8 A_u8Row_values)
{
	for(u8 i=0 ;i<NO_ROWS ;i++)
	{
	   MGPIO_vSetPinVal_fast(cols[i].Port ,cols[i].Pin ,GET_BIT(A_u8Row_values,i));
	}

}
static void HLEDMTX_vSetCurrentColumn(u8 A_u8Col_no)
{
	MGPIO_vSetPinVal_fast(cols[A_u8Col_no].Port ,cols[A_u8Col_no].Pin ,GPIO_LOW);
}

void HLEDMTX_vDispalyFrame(u8 A_u8Frame[] , u32 A_u32Frame_delay)
{
	u32 L_u32Count=50*A_u32Frame_delay;
	for(u32 j=0 ;j<L_u32Count ;j++)
	{
		for(u8 i=0; i<NO_COLS; i++)
			{
				/* 1- Disable All Columns */
				HLEDMTX_vDisableAllColumns();
				/* 2- Set Row Values       */
				HLEDMTX_vSetRowValues(A_u8Frame[i]);
				/* 3- Set Current Column */
				HLEDMTX_vSetCurrentColumn(i);
				/* 4- Delay For Suitable FPS */
				MSTK_vSetBusyWait(H_SCAN_TIME);
			}
	}


}

void HLEDMTX_vDisplayMatrix(u8 A_u8Matrix[][NO_COLS] , u32 A_u32MAtrix_delay )
{

}
