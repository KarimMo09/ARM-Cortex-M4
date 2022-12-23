/*
 * LEDMTX_cfg.c
 *
 *  Created on: Sep 6, 2022
 *      Author: Karim
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "LEDMTX_cfg.h"

/* 1- Set GPIO Pin Configuration */
MGPIO_Config_t rows[NO_ROWS]={
					{.Port=GPIO_PORTA ,.Pin=GPIO_PIN0,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTA ,.Pin=GPIO_PIN1,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTA ,.Pin=GPIO_PIN2,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTA ,.Pin=GPIO_PIN3,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTA ,.Pin=GPIO_PIN4,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTA ,.Pin=GPIO_PIN5,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTA ,.Pin=GPIO_PIN6,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTA ,.Pin=GPIO_PIN7,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL }
							  };

MGPIO_Config_t cols[NO_COLS]={
					{.Port=GPIO_PORTB ,.Pin=GPIO_PIN0 ,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTB ,.Pin=GPIO_PIN1 ,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTB ,.Pin=GPIO_PIN5 ,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTB ,.Pin=GPIO_PIN6 ,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTB ,.Pin=GPIO_PIN7 ,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTB ,.Pin=GPIO_PIN8 ,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTB ,.Pin=GPIO_PIN9 ,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL },
					{.Port=GPIO_PORTB ,.Pin=GPIO_PIN10,.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,.OutputType=GPIO_OTYPE_PUSHPULL }
							  };
