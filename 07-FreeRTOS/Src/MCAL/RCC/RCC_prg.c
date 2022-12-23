/*
 * RCC_prg.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Karim
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_math.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"
#include "RCC_int.h"




void MRCC_vInit(void)
{
	/*1- CSS (ON/OFF) */
#if RCC_CSS_ENABLE==ENABLE
	SET_BIT(RCC->CR,CSSON);
#else
	CLR_BIT(RCC->CR,CSSON);
#endif
	/*2- HSE_BYP */
#if RCC_HSE_BYPASS==BYPASS
	SET_BIT(RCC->CR,HSEBYP);
#elif RCC_HSE_BYPASS==NOT_BYPASS
	CLR_BIT(RCC->CR,HSEBYP);
#else
	CLR_BITT(RCC->CR,HSEBYP);
#endif

	/*3- Buses Prescalers */
	RCC->CFGR|= (RCC_AHB1_CLK << 4) | (RCC_APB1_CLK << 10) | (RCC_APB2_CLK<< 13 );
	/*4- Select clk switch (HSI/HSE/PLL) && Enable the selected clock */
#if   RCC_SYSTEM_CLK==RCC_HSI
	  CLR_BIT(RCC->CFGR,SW0);
	  CLR_BIT(RCC->CFGR,SW1);
	  SET_BIT(RCC->CR,HSION);
#elif RCC_SYSTEM_CLK==RCC_HSE
	  SET_BIT(RCC->CFGR,SW0);
	  CLR_BIT(RCC->CFGR,SW1);
	  SET_BIT(RCC->CR,HSEON);
#elif RCC_SYSTEM_CLK==RCC_PLL
   	  CLR_BIT(RCC->CFGR,SW0);
	  SET_BIT(RCC->CFGR,SW1);
	  SET_BIT(RCC->CR,PLLON);
#else
#warning "System clk config is invalid"
#endif


}

void MRCC_vEnableClock(u32 A_u32BusId, u32 A_u32PeripheralId)
{
 switch(A_u32BusId)
 {
 case RCC_AHB1 : SET_BIT(RCC->AHB1ENR,A_u32PeripheralId); break;
 case RCC_AHB2 : SET_BIT(RCC->AHB2ENR,A_u32PeripheralId); break;
 case RCC_APB1 : SET_BIT(RCC->APB1ENR,A_u32PeripheralId); break;
 case RCC_APB2 : SET_BIT(RCC->APB2ENR,A_u32PeripheralId); break;
 default :break;

 }

}
void MRCC_vDisbleClock(u32 A_u32BusId, u32 A_u32PeripheralId)
{
	 switch(A_u32BusId)
	 {
	 case RCC_AHB1 : CLR_BIT(RCC->AHB1ENR,A_u32PeripheralId); break;
	 case RCC_AHB2 : CLR_BIT(RCC->AHB2ENR,A_u32PeripheralId); break;
	 case RCC_APB1 : CLR_BIT(RCC->APB1ENR,A_u32PeripheralId); break;
	 case RCC_APB2 : CLR_BIT(RCC->APB2ENR,A_u32PeripheralId); break;
	 default :break;
	 }
}

