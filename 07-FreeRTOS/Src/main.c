#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_int.h"


#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"


xSemaphoreHandle rgbSem=0;


BaseType_t rgbSem_Status;

MGPIO_Config_t pin_arr[]={
		{GPIO_PORTA, GPIO_PIN0, GPIO_MODE_OUTPUT, GPIO_SPEED_LOW  , GPIO_OTYPE_PUSHPULL }
		,{GPIO_PORTA, GPIO_PIN1, GPIO_MODE_OUTPUT, GPIO_SPEED_LOW  , GPIO_OTYPE_PUSHPULL }
};

void Task_LEDRED(void * pvParams)
{
	(void)pvParams;
	while(1)
	{
		rgbSem_Status= xSemaphoreTake(rgbSem ,600);
		if (rgbSem_Status== pdPASS)
		{
			MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN0);
			xSemaphoreGive(rgbSem);
			vTaskDelay(500);

		}

	}
}
void Task_LEDBLUE(void * pvParams)
{
	(void)pvParams;
	while(1)
	{

		rgbSem_Status= xSemaphoreTake(rgbSem ,600);
		if (rgbSem_Status == pdPASS)
		{


			xSemaphoreGive(rgbSem);
			vTaskDelay(500);
			MGPIO_vTogPinVal(GPIO_PORTA,GPIO_PIN1);

		}

	}
}

int main(void)
{
 
	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1, RCC_GPIOA_EN);

	for(int i=0; i<	(sizeof(pin_arr)/sizeof(pin_arr[0])); i++)
	{
			MGPIO_vInit(&pin_arr[i]);
	}

	vSemaphoreCreateBinary(rgbSem);

	xTaskCreate(Task_LEDRED , NULL ,50, NULL ,1,NULL);
	xTaskCreate(Task_LEDBLUE, NULL ,50, NULL ,1,NULL);



	vTaskStartScheduler();
	while(1)
	{

	}



}
 
