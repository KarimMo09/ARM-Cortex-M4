/*
 * EXTI_prg.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Karim
 */

#include  "../../LIB/STD_TYPES.h"
#include  "../../LIB/Bit_math.h"
#include "../GPIO/GPIO_int.h"
#include "EXTI_prv.h"
#include "EXTI_cfg.h"
#include "EXTI_int.h"

static void (*GS_fpEXTI_SetCallBack[15])(void)={NULL};

void MEXTI_vInit(void)
{
	/*------Clear All Flags--------*/
	EXTI->PR=0xFFFFFFFF;
}
void MEXTI_vEnableInterrupt(u8 A_u8Portid,u8 A_u8Line, u8 A_u8SenseCtrl)
{
	/*--------Input Validation------*/
	if(A_u8Line<16)
	{
		/*---EXTIx Configuration---*/
		switch(A_u8Portid)
		{
		case GPIO_PORTA :
						 SYSCFG->EXTICR[A_u8Line/4] |= (GPIO_PORTA << ((A_u8Line%4)*4) );
						 break;
		case GPIO_PORTB :
						 SYSCFG->EXTICR[A_u8Line/4] |= (GPIO_PORTB << ((A_u8Line%4)*4) );
						 break;
		case GPIO_PORTC :
						 SYSCFG->EXTICR[A_u8Line/4] |= (GPIO_PORTC << ((A_u8Line%4)*4) );
						 break;
		default :
			/*Error*/
			break;
		}

		/*---Set Trigger---*/
		switch(A_u8SenseCtrl)
		{
		case RISING_TRIGGER :
			 SET_BIT(EXTI->RTSR,A_u8Line);
			 CLR_BIT(EXTI->FTSR,A_u8Line);
			 break;
		case FALLING_TRIGGER :
			 CLR_BIT(EXTI->RTSR,A_u8Line);
			 SET_BIT(EXTI->FTSR,A_u8Line);
			 break;
		case ON_CHANGE:
			 SET_BIT(EXTI->RTSR,A_u8Line);
			 SET_BIT(EXTI->FTSR,A_u8Line);
			 break;
		default :
			/*Error*/
			break;
		}

		/*---Enable Line---*/
		SET_BIT(EXTI->IMR,A_u8Line);
	}
	else
	{
		/* Error
		 * Out OF Range
		 */
	}


}
void MEXTI_vDisableInterrupt(u8 A_u8Line)
{
	/*--------Input Validation------*/
	if(A_u8Line<16)
	{
		CLR_BIT(EXTI->IMR,A_u8Line);
	}

	else
	{
		/* Error
		 * Out OF Range
		 */
	}
}

void MEXTI_vGenerateSWInterrupt(u8 A_u8Line)
{
	/*--------Input Validation------*/
	if(A_u8Line<16)
	{
		SET_BIT(EXTI->SWIER,A_u8Line);
	}

	else
	{
		/* Error
		 * Out OF Range
		 */
	}
}
void MEXTI_vChangeSenseCtrl(u8 A_u8SenseCtrl , u8 A_u8Line)
{
	/*--------Input Validation------*/
	if(A_u8Line<16)
	{
		/*---Set Trigger---*/
		switch(A_u8SenseCtrl)
		{
		case RISING_TRIGGER :
			 SET_BIT(EXTI->RTSR,A_u8Line);
			 CLR_BIT(EXTI->FTSR,A_u8Line);
			 break;
		case FALLING_TRIGGER :
			 CLR_BIT(EXTI->RTSR,A_u8Line);
			 SET_BIT(EXTI->FTSR,A_u8Line);
			 break;
		case ON_CHANGE:
			 SET_BIT(EXTI->RTSR,A_u8Line);
			 SET_BIT(EXTI->FTSR,A_u8Line);
			 break;
		default :
			/*Error*/
			break;
		}
	}
	else
	{
		/* Error
		 * Out OF Range
		 */
	}

}


void MEXTI_vSetCallBack(u8 A_u8EXTILine, void(*A_xfptr)(void))
{
	GS_fpEXTI_SetCallBack[A_u8EXTILine]=A_xfptr;
}
/*--------- ISR --------*/
void EXTI0_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE0]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE0]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE0);
}

void EXTI1_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE1]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE1]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE1);
}

void EXTI2_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE2]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE2]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE2);
}

void EXTI3_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE3]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE3]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE3);
}

void EXTI4_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE4]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE4]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE4);
}

void EXTI5_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE5]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE5]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE5);
}

void EXTI6_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE6]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE6]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE6);
}

void EXTI7_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE7]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE7]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE7);
}

void EXTI8_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE8]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE8]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE8);
}

void EXTI9_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE9]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE9]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE9);
}

void EXTI10_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE10]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE10]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE10);
}

void EXTI11_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE11]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE11]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE11);
}

void EXTI12_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE12]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE12]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE12);
}

void EXTI13_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE13]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE13]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE13);
}

void EXTI14_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE14]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE14]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE14);
}

void EXTI15_IRQHandler(void)
{
	if(GS_fpEXTI_SetCallBack[EXTI_LINE15]!=NULL)
	{
		GS_fpEXTI_SetCallBack[EXTI_LINE15]();
	}
	SET_BIT(EXTI->PR,EXTI_LINE15);
}

