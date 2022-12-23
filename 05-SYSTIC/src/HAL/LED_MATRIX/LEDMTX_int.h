/*
 * LEDMTRX_int.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Karim
 */

#ifndef HAL_LED_MATRIX_LEDMATRIX_INT_H_
#define HAL_LED_MATRIX_LEDMATRIX_INT_H_



void HLEDMTX_vInit(void);

void HLEDMTX_vDispalyFrame(u8 A_u8Frame[] , u32 A_u32Frame_delay);
void HLEDMTX_vDisplayMatrix(u8 A_u8Matrix[][8] , u32 A_u32MAtrix_delay );

#endif /* HAL_LED_MATRIX_LEDMATRIX_INT_H_ */
