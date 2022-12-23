/*
 * STK_int.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Karim
 */

#ifndef MCAL_STK_STK_INT_H_
#define MCAL_STK_STK_INT_H_

#define STK_EN     0
#define TICKINT    1
#define CLKSOURCE  2
#define COUNTFLAG  16
#define SINGLE_INTERVAL   1
#define PERIODIC_INTERVAL 2

#define MS   (3125)

void MSTK_vInit(void);

void MSTK_vSetBusyWait(u32 A_u32Ticks);

void MSTK_vSetIntervalSingle(u32 A_u32Ticks , void (*fptr)(void));
void MSTK_vSetIntervalPeriodic(u32 A_u32Ticks , void (*fptr)(void));

void MSTK_vStopInterval(void);

u32  MSTK_vGetElapsedTime(void);
u32  MSTK_vGetRemainingTime(void);



#endif /* MCAL_STK_STK_INT_H_ */
