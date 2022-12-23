/*
 * DMA_prg.c
 *
 *  Created on: 17 Dec 2022
 *      Author: karim
 */




#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DMA_int.h"
#include "DMA_prv.h"
#include "DMA_cfg.h"

void (*fpCallBack[8])(void)={NULL};

void MDMA_vInit(void)
{
	CLR_BIT(DMA2->S[0].CR , 0); // make sure that the enable bit is disabled before configuration
	DMA2->S[0].CR |= (1<<14)|(1<<12)|(1<<10)|(1<<9)|(1<<8)|(1<<7)|(1<<4) ;
	DMA2->S[0].FCR |= (1<<0)|(1<<1)|(1<<2) ;
}

void MDMA_vSetStream(u8  A_u8StreamId ,
					 u32* A_pu32SrcAddress,
		             u32* A_pu32DestAddress,
					 u32 A_u32DataSize     ,
					 u32 A_u32BlockSize    )
{
	DMA2->S[A_u8StreamId].PAR = A_pu32SrcAddress ;
	DMA2->S[A_u8StreamId].M0AR = A_pu32DestAddress;
	DMA2->S[A_u8StreamId].NDTR = A_u32BlockSize ;
	// A_u32DataSize: (0b00 , 0b01 , 0b10) -> PSIZE and MSIZE

}

void MDMA_vEnableStream(u8  A_u8StreamId)
{
	DMA2->LIFCR |= ((1<<0)|(1<<2) |(1<<3)|(1<<4)|(1<<5));
	SET_BIT(DMA2->S[0].CR , 0); // set enable bit to start transfer
}

void MDMA_vSetStreamCallback(u8  A_u8StreamId ,
		                     void (*fptr)(void))
{
	fpCallBack[A_u8StreamId]=fptr;

}

void DMA2_Stream0_IRQHandler(void)
{
	if(fpCallBack[0]!=NULL)
	{
		fpCallBack[0]();
	}

}





