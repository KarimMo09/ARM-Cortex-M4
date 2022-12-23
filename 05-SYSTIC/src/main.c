#include "LIB/STD_TYPES.h"
#include "LIB/Bit_math.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/STK/STK_int.h"
#include "HAL/LED_MATRIX/LEDMTX_int.h"

u8 G_u8NUM=0;

void STK_ISR(void)
{
	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN15);
	/*MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN1);
	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN3);
	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN4);
	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN5);
	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN6);
	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN7);
	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN8);
	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN9);
	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN10);
	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN11);
	MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN12);*/

}

int main()
{
	 MRCC_vInit();
	 MRCC_vEnableClock( RCC_AHB1  ,RCC_GPIOA_EN);
	 MGPIO_Config_t Pin_cfg={
	    		.Port= GPIO_PORTA ,
				.Pin= GPIO_PIN15,
	    		.Mode = GPIO_MODE_OUTPUT,
	    		.OutputType=GPIO_OTYPE_PUSHPULL ,
	    		.OutputSpeed=GPIO_SPEED_HIGH,
	    		.InputPull= GPIO_INPUT_NO_PULL,
	               };
	 MGPIO_vInit(&Pin_cfg);
	 MSTK_vInit();
     MSTK_vSetIntervalPeriodic(1000*MS,STK_ISR);
      while (1)
     {

     }

}

