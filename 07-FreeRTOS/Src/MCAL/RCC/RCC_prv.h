/*
 * RCC_prv.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Karim
 */

#ifndef MCAL_RCC_RCC_PRV_H_
#define MCAL_RCC_RCC_PRV_H_


#define RCC_BASE_ADDR	0x40023800

/*-------------RCC Registers------------*/
typedef struct
{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 reserved1;
	u32 reserved2;
	u32 APB1RSTR;
    u32 APB2RSTR;
	u32 reserved3;
	u32 reserved4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 reserved5;
	u32 reserved6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 reserved7;
	u32 reserved8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 reserved9;
	u32 reserved10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 reserved11;
	u32 reserved12;
	u32 BDCR;
	u32 CSR;
	u32 reserved13;
	u32 reserved14;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 reserved15;
	u32 DCFCFGR;

}RCC_MemMap_t;

#define RCC ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))


/*-----------------RCC_CR Bits-----------------*/
#define HSION   		0
#define HSIRDY          1
#define HSITRIM0        3
#define HSITRIM1        4
#define HSITRIM2        5
#define HSITRIM3        6
#define HSITRIM4        7
#define HSICAL0         8
#define HSICAL1         9
#define HSICAL2         10
#define HSICAL3         11
#define HSICAL4         12
#define HSICAL5         13
#define HSICAL6         14
#define HSICAL7         15
#define HSEON 			16
#define HSERDE          17
#define HSEBYP          18
#define CSSON           19
#define PLLON           24
#define PLLRDY          25
#define PLLI2SON        26
#define PLLI2SRDY       27
/*----------------------------------------------*/

/*---------------RCC_PLLCFGR Bits---------------*/
#define PLLM0           0
#define PLLM1           1
#define PLLM2           2
#define PLLM3           3
#define PLLM4           4
#define PLLM5           5
#define PLL0            16
#define PLL1            17
#define PLLSRC          22
/*----------------------------------------------*/

/*---------------RCC_CFGR Bits---------------*/
#define SW0             0
#define SW1             1
#define SWS0            2
#define SWS1            3
#define HPRE0           4
#define HPRE1           5
#define HPRE2           6
#define HPRE3           7
#define PRE10           10
#define PRE11           11
#define PRE12           12
#define PRE20           13
#define PRE21           14
#define PRE22           15
#define RTCPRE0         16
#define RTCPRE1         17
#define RTCPRE2         18
#define RTCPRE3         19
#define RTCPRE4         20
#define MCO10           21
#define MCO11           22
#define I2SSCR          23
#define MCO1PRE0        24
#define MCO1PRE1        25
#define MCO1PRE2        26
#define MCO2PRE0        27
#define MCO2PRE1        28
#define MCO2PRE2        29
#define MCO20           30
#define MCO21           31

/*----------------------------------------------*/


/*Define AHB clock*/
#define RCC_AHB1_SYSTEM_CLK					0
#define RCC_AHB1_SYSTEM_CLK_DIVIDED_BY_2	8
#define RCC_AHB1_SYSTEM_CLK_DIVIDED_BY_4	9
#define RCC_AHB1_SYSTEM_CLK_DIVIDED_BY_8	10
#define RCC_AHB1_SYSTEM_CLK_DIVIDED_BY_16	11
#define RCC_AHB1_SYSTEM_CLK_DIVIDED_BY_64	12
#define RCC_AHB1_SYSTEM_CLK_DIVIDED_BY_128	13
#define RCC_AHB1_SYSTEM_CLK_DIVIDED_BY_256	14
#define RCC_AHB1_SYSTEM_CLK_DIVIDED_BY_512	15
/*Define APB1 clock*/
#define RCC_APB1_AHB_CLK					0
#define RCC_APB1_AHB_CLK_DIVIDED_BY_2		4
#define RCC_APB1_AHB_CLK_DIVIDED_BY_4		5
#define RCC_APB1_AHB_CLK_DIVIDED_BY_8		6
#define RCC_APB1_AHB_CLK_DIVIDED_BY_16	    7

/*Define APB2 clock*/
#define RCC_APB2_AHB_CLK					0
#define RCC_APB2_AHB_CLK_DIVIDED_BY_2		4
#define RCC_APB2_AHB_CLK_DIVIDED_BY_4		5
#define RCC_APB2_AHB_CLK_DIVIDED_BY_8		6
#define RCC_APB2_AHB_CLK_DIVIDED_BY_16	    7

/*----------------------------------------------*/

#define ENABLE          1
#define DISABLE         2
#define NOT_BYPASS      1
#define BYPASS          2
#define RCC_HSI         1
#define RCC_HSE         2
#define RCC_PLL         3





















#endif /* MCAL_RCC_RCC_PRV_H_ */
