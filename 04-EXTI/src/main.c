#include "LIB/STD_TYPES.h"
#include "LIB/Bit_math.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/EXTI/EXTI_int.h"
#include "MCAL/EXTI/EXTI_prv.h"
#include "MCAL/NVIC/NVIC_int.h"

void EXTI0_ISR(void)
{
	MGPIO_vSetPinVal_fast(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
	ARM_DELAY(1000);
	MGPIO_vSetPinVal_fast(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
}

int main()
{
 	 MGPIO_Config_t Pin0_cfg={
     		.Port= GPIO_PORTB ,
			.Pin=GPIO_PIN0,
     		.Mode = GPIO_MODE_INPUT,
     		.InputPull= GPIO_INPUT_PULL_DOWN,
                };
  	 MGPIO_Config_t Pin1_cfg={
      		.Port= GPIO_PORTA ,
			.Pin=GPIO_PIN1,
      		.Mode = GPIO_MODE_OUTPUT,
      		.OutputType=GPIO_OTYPE_PUSHPULL ,
      		.OutputSpeed=GPIO_SPEED_HIGH,
                 };

	 MRCC_vInit();
	 MRCC_vEnableClock( RCC_AHB1  ,RCC_GPIOA_EN);
	 MRCC_vEnableClock( RCC_AHB1  ,RCC_GPIOB_EN);
	 MRCC_vEnableClock( RCC_APB2  ,RCC_SYSCFG_EN);
	 MEXTI_vSetCallBack(EXTI_LINE0,EXTI0_ISR);

     MGPIO_vInit(&Pin0_cfg);
     MGPIO_vInit(&Pin1_cfg);

  	 MEXTI_vEnableInterrupt(GPIO_PORTB,EXTI_LINE0,FALLING_TRIGGER);
     MNVIC_vEnablePerihral(NVIC_EXTI_LINE0_EN);



      while (1)
     {

     }

}

