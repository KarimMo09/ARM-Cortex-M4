/*
 * NVIC_int.h
 *
 *  Created on: Aug 28, 2022
 *      Author: Karim
 */

#ifndef MCAL_NVIC_NVIC_INT_H_
#define MCAL_NVIC_NVIC_INT_H_




/////////////////////////
#define MEMORY_MANAGE      -7
#define BUS_FAULT          -6
#define USAGE_FAULT        -5
/////////////////////////
#define SV_CALL 		   -4
/////////////////////////
#define SYSTICK            -3
#define PEND_SV            -2
////////////////////////////
/*------------Interrupts types----------*/
typedef enum
{
	NVIC_WWDG_EN 	              ,
	NVIC_EXTI_LINE16_EN           ,
	NVIC_EXTI_LINE21_EN           ,
	NVIC_EXTI_LINE22_EN           ,
	NVIC_FLASH_EN                 ,
	NVIC_RCC_EN                   ,
	NVIC_EXTI_LINE0_EN 	          ,
	NVIC_EXTI_LINE1_EN 	          ,
	NVIC_EXTI_LINE2_EN 	          ,
	NVIC_EXTI_LINE3_EN 	          ,
	NVIC_EXTI_LIINE4_EN 	      ,
	NVIC_DMA1_STREAM0_EN          ,
	NVIC_DMA1_STREAM1_EN          ,
	NVIC_DMA1_STREAM2_EN          ,
	NVIC_DMA1_STREAM3_EN          ,
	NVIC_DMA1_STREAM4_EN          ,
	NVIC_DMA1_STREAM5_EN          ,
	NVIC_DMA1_STREAM6_EN          ,
	NVIC_ADC_EN 				  ,
	NVIC_EXTI_LINE9_5_EN = 23 	  ,
	NVIC_TIM1_BRK_TIM9_EN 		  ,
	NVIC_TIM1_UP_TIM10_EN 		  ,
	NVIC_TIM1_TRG_COM_TIM11_EN    ,
	NVIC_TIM1_CC_EN 			  ,
	NVIC_TIM2_EN 				  ,
	NVIC_TIM3_EN 				  ,
	NVIC_TIM4_EN 				  ,
	NVIC_I2C1_EV_EN               ,
	NVIC_I2C1_ER_EN               ,
	NVIC_I2C2_EV_EN               ,
	NVIC_I2C2_ER_EN               ,
	NVIC_SPI1_EN 				  ,
	NVIC_SPI2_EN 				  ,
	NVIC_USART1_EN 				  ,
	NVIC_USART2_EN 				  ,
	NVIC_EXTI_LINE15_10_EN = 40	  ,
	NVIC_EXTI_LINE17_EN			  ,
	NVIC_EXTI_LINE18_EN			  ,
	NVIC_DMA1_STREAM7_EN   = 47	  ,
	NVIC_SDIO_EN 		   = 49	  ,
	NVIC_TIM5_EN 				  ,
	NVIC_SPI3_EN 				  ,
	NVIC_DMA2_STREAM0_EN   = 56   ,
	NVIC_DMA2_STREAM1_EN          ,
	NVIC_DMA2_STREAM2_EN          ,
	NVIC_DMA2_STREAM3_EN          ,
	NVIC_DMA2_STREAM4_EN          ,
	NVIC_OTG_FS_EN		   = 67	  ,
	NVIC_DMA2_STREAM5_EN   	      ,
	NVIC_DMA2_STREAM6_EN          ,
	NVIC_DMA2_STREAM7_EN          ,
	NVIC_USART6_EN       		  ,
	NVIC_I2C3_EV_EN       		  ,
	NVIC_I2C3_ER_EN       		  ,
	NVIC_FPU_EN            = 81   ,
	NVIC_SPI4_EN           = 84

}NVIC_InterruptEnable_t;
typedef enum
{
	NO_GROUP_PRIORITY              ,
	GROUP_PRIORITY_0 = 0           ,
	GROUP_PRIORITY_1               ,
	GROUP_PRIORITY_2               ,
	GROUP_PRIORITY_3               ,
	GROUP_PRIORITY_4               ,
	GROUP_PRIORITY_5               ,
	GROUP_PRIORITY_6               ,
	GROUP_PRIORITY_7               ,
	GROUP_PRIORITY_8               ,
	GROUP_PRIORITY_9               ,
	GROUP_PRIORITY_10              ,
	GROUP_PRIORITY_11              ,
	GROUP_PRIORITY_12              ,
	GROUP_PRIORITY_13              ,
	GROUP_PRIORITY_14              ,
	GROUP_PRIORITY_15

}NVIC_InterrupGroupPriority_t;

typedef enum
{
	NO_SUB_PRIORITY              ,
	SUB_PRIORITY_0 = 0           ,
	SUB_PRIORITY_1               ,
	SUB_PRIORITY_2               ,
	SUB_PRIORITY_3               ,
	SUB_PRIORITY_4               ,
	SUB_PRIORITY_5               ,
	SUB_PRIORITY_6               ,
	SUB_PRIORITY_7               ,
	SUB_PRIORITY_8               ,
	SUB_PRIORITY_9               ,
	SUB_PRIORITY_10              ,
	SUB_PRIORITY_11              ,
	SUB_PRIORITY_12              ,
	SUB_PRIORITY_13              ,
	SUB_PRIORITY_14              ,
	SUB_PRIORITY_15

}NVIC_InterrupSubPriority_t;




void MNVIC_vEnablePerihral(u8 A_INTID);
void MNVIC_vDisablePerihral(u8 A_INTID);
void MNVIC_vSetPending(u8 A_INTID);
void MNVIC_vClearPending(u8 A_INTID);
u8   MNVIC_u8GetActive(u8 A_INTID);
void MNVIC_vSetPriorityConfig(void);
void MNVIC_vSetPriority (s8 A_s8INTID, u8 A_u8GroupPriority, u8 A_u8SubPriority);



#endif /* MCAL_NVIC_NVIC_INT_H_ */
