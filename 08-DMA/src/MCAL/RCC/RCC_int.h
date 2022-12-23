/*
 * RCC_int.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Karim
 */

#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_

#define RCC_AHB1         1
#define RCC_AHB2         2
#define RCC_APB1         3
#define RCC_APB2         4
/*-------AHB1 connected peripheral--------*/
#define RCC_GPIOA_EN    0
#define RCC_GPIOB_EN    1
#define RCC_GPIOC_EN    2
#define RCC_GPIOD_EN    3
#define RCC_GPIOE_EN    4
#define RCC_GPIOH_EN    7
#define RCC_CRC_EN      12
#define RCC_DMA1_EN     21
#define RCC_DMA2_EN     22
/*----------------------------------------*/
/*-------AHB2 connected peripheral--------*/
#define RCC_OTGFS_EN    7
/*----------------------------------------*/
/*-------APB1 connected peripheral--------*/
#define RCC_TIM2_EN     0
#define RCC_TIM3_EN     1
#define RCC_TIM4_EN     2
#define RCC_TIM5_EN     3
#define RCC_WWDG_EN     11
#define RCC_SPI2_EN     14
#define RCC_SPI3_EN     15
#define RCC_UART2_EN    17
#define RCC_I2C1_EN     21
#define RCC_I2C2_EN     22
#define RCC_I2C3_EN     23
#define RCC_PWR_EN      28
/*----------------------------------------*/

/*-------APB2 connected peripheral--------*/
#define RCC_TIM1_EN     0
#define RCC_UART1_EN    4
#define RCC_UART6_EN    5
#define RCC_ADC1_EN     8
#define RCC_SDIO_EN     11
#define RCC_SPI1_EN     12
#define RCC_SPI4_EN     13
#define RCC_SYSCFG_EN   14
#define RCC_TIM9_EN     16
#define RCC_TIM10_EN    17
#define RCC_TIM11_EN    18
/*----------------------------------------*/
void MRCC_vInit(void);
void MRCC_vEnableClock(u32 A_u32BusId, u32 A_u32PeripheralId);
void MRCC_vDisbleClock(u32 A_u32BusId, u32 A_u32PeripheralId);


#endif /* MCAL_RCC_RCC_INT_H_ */
