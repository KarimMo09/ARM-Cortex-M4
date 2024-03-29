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
#define WWDG 	            0
#define EXTI16              1
#define EXTI21              2
#define EXTI22              3
#define FLASH               4
#define RCC                 5
#define ETI0 	            6
#define EXTI1 	            7
#define EXTI2 	            8
#define EXTI3 	            9
#define EXTI4 	            10
#define DMA1_STREAM0        11
#define DMA1_STREAM1        12
#define DMA1_STREAM2        13
#define DMA1_STREAM3        14
#define DMA1_STREAM4        15
#define DMA1_STREAM5        16
#define DMA1_STREAM6        17
#define ADC 				18
#define EXTI9 				23
#define TIM1_BRK_TIM9 		24
#define TIM1_UP_TIM10 		25
#define TIM1_TRG_COM_TIM11  26
#define TIM1_CC 			27
#define TIM2 				28
#define TIM3 				29
#define TIM4 				30
#define I2C1_EV             31
#define I2C1_ER             32
#define I2C2_EV             33
#define I2C2_ER             34
#define SPI1 				35
#define SPI2 				36
#define USART1 				37
#define USART2 				38
#define EXTI15_10 			30
#define EXTI17 				41
#define EXTI18 				42
#define DMA1_STREAM7 		47
#define SDIO 				49
#define TIM5 				50
#define SPI3 				51
#define DMA2_STREAM0        56
#define DMA2_STREAM1        57
#define DMA2_STREAM2        58
#define DMA2_STREAM3        59
#define DMA2_STREAM4        60
#define OTG_FS				67
#define DMA2_STREAM5        68
#define DMA2_STREAM6        69
#define DMA2_STREAM7        70
#define USART6              71
#define I2C3_EV             72
#define I2C3_ER             73
#define FPU                 81
#define SPI4                84

#define NO_GROUP_PRIORITY	0
#define GROUP_PRIORITY_0 	0
#define GROUP_PRIORITY_1 	1
#define GROUP_PRIORITY_2    2
#define GROUP_PRIORITY_3    3
#define GROUP_PRIORITY_4    4
#define GROUP_PRIORITY_5    5
#define GROUP_PRIORITY_6    6
#define GROUP_PRIORITY_7    7
#define GROUP_PRIORITY_8    8
#define GROUP_PRIORITY_9    9
#define GROUP_PRIORITY_10   10
#define GROUP_PRIORITY_11   11
#define GROUP_PRIORITY_12   12
#define GROUP_PRIORITY_13   13
#define GROUP_PRIORITY_14   14
#define GROUP_PRIORITY_15   15

#define NO_SUB_PRIORITY     0
#define SUB_PRIORITY_0      0
#define SUB_PRIORITY_1      1
#define SUB_PRIORITY_2      2
#define SUB_PRIORITY_3      3
#define SUB_PRIORITY_4      4
#define SUB_PRIORITY_5      5
#define SUB_PRIORITY_6      6
#define SUB_PRIORITY_7      7
#define SUB_PRIORITY_8      8
#define SUB_PRIORITY_9      9
#define SUB_PRIORITY_10     10
#define SUB_PRIORITY_11     11
#define SUB_PRIORITY_12     12
#define SUB_PRIORITY_13     13
#define SUB_PRIORITY_14     14
#define SUB_PRIORITY_15     15




void MNVIC_vEnablePerihral(u8 A_INTID);
void MNVIC_vDisablePerhral(u8 A_INTID);
void MNVIC_vSetPending(u8 A_INTID);
void MNVIC_vClearPending(u8 A_INTID);
u8   MNVIC_u8GetActive(u8 A_INTID);
void MNVIC_voidSetPriorityConfig(void);
void MNVIC_vSetPriority (s8 A_s8INTID, u8 A_u8GroupPriority, u8 A_u8SubPriority);



#endif /* MCAL_NVIC_NVIC_INT_H_ */
