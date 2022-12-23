/*
 * SSD_prg.c
 *
 *  Created on: May 17, 2022
 *      Author: Karim
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include  "SSD_int.h"

u8 G_u8SSD_Nums[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};


void HSSD_vInit()
{

	MGPIO_Config_t Pin_cfg={
    		.Port= SSD_PORT ,
    		.Mode = GPIO_MODE_OUTPUT,
    		.OutputType=GPIO_OTYPE_PUSHPULL ,
    		.OutputSpeed=GPIO_SPEED_HIGH,
    		.InputPull= GPIO_INPUT_NO_PULL,
               };
	for(u8 PinNo=0;PinNo<=7;PinNo++)
	{
		Pin_cfg.Pin = PinNo;
	    MGPIO_vInit(&Pin_cfg);
	}


}
void HSSD_vDisplayNum (u8 A_u8Num )
{
		#if SSD_TYPE==COM_ANODE
       	  for(u8 PinNo=0;PinNo<7;PinNo++)
			{
				MGPIO_vSetPinVal_fast(SSD_PORT,PinNo,(G_u8SSD_Nums[A_u8Num]>>PinNo)&1);
			}
			MGPIO_vSetLowNibbleVal(SSD_PORT,G_u8SSD_Nums[A_u8Num]);
		#elif SSD_TYPE==COM_CATHODE
		  for(u8 PinNo=0;PinNo<7;PinNo++)
			{
				MGPIO_vSetPinVal_fast(SSD_PORT,PinNo,(~G_u8SSD_Nums[A_u8Num]>>PinNo)&1);
			}
			//MGPIO_vSetLowNibbleVal(SSD_PORT,~G_u8SSD_Nums[A_u8Num ]);
		#endif
}
