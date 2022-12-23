/*
 * LEDMATRIX_cfg.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Karim
 */

#ifndef HAL_LED_MATRIX_LEDMTX_CFG_H_
#define HAL_LED_MATRIX_LEDMTX_CFG_H_


#define NO_COLS              8
#define NO_ROWS              8

extern MGPIO_Config_t cols[NO_COLS];
extern MGPIO_Config_t rows[NO_ROWS];

#define H_SCAN_TIME 		 2.5*MS

#endif /* HAL_LED_MATRIX_LEDMTX_CFG_H_ */
