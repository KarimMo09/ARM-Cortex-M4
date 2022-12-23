/*
 * EXTI_int.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Karim
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_
enum
{
	 EXTI_LINE0    ,
	 EXTI_LINE1    ,
	 EXTI_LINE2    ,
	 EXTI_LINE3    ,
	 EXTI_LINE4    ,
	 EXTI_LINE5    ,
	 EXTI_LINE6    ,
	 EXTI_LINE7    ,
	 EXTI_LINE8    ,
	 EXTI_LINE9    ,
	 EXTI_LINE10   ,
	 EXTI_LINE11   ,
	 EXTI_LINE12   ,
	 EXTI_LINE13   ,
	 EXTI_LINE14   ,
     EXTI_LINE15   ,
};



#define RISING_TRIGGER   0
#define FALLING_TRIGGER  1
#define ON_CHANGE        2

void MEXTI_viNIT(void);
void MEXTI_vEnableInterrupt(u8 A_u8Portid,u8 A_u8Line, u8 A_u8SenseCtrl);
void MEXTI_vDisableInterrupt(u8 A_u8Line);
void MEXTI_vGenerateSWInterrupt(u8 A_u8Line);
void MEXTI_vChangeSenseCtrl(u8 A_u8SenseCtrl , u8 A_u8Line);
void MEXTI_vSetCallBack(u8 A_u8EXTILine, void(*A_xfptr)(void));

#endif /* MCAL_EXTI_EXTI_INT_H_ */
