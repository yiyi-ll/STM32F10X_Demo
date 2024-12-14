#include "main.h"

#define LedTask_Stack           128
#define LedTask_Prio            2
TaskHandle_t LedTask_Handler;

#define DebugTask_Stack         128
#define DebugTask_Prio          4
TaskHandle_t DebugTask_Handler;

void Led_Task(void *param)
{
    while(1)
    {
		GPIO_ResetBits(GPIOC, LED_GPIO_PIN);
		vTaskDelay(500);
		GPIO_SetBits(GPIOC, LED_GPIO_PIN);
		vTaskDelay(500);
    }
}

void Debug_Task(void *param)
{
	while(1)
	{
		printf("hello abit\r\n");
		vTaskDelay(500);
	}
}

int main()
{
    bsp_abit_delay_init(72);
    bsp_abit_gpio_init();
    bsp_abit_usart_init(115200);
	bsp_abit_nvic_init();

	xTaskCreate((TaskFunction_t)Led_Task,
			(const char *)"Led_Task",
			(const configSTACK_DEPTH_TYPE)LedTask_Stack,
			(void *)NULL,
			(UBaseType_t) LedTask_Prio,
			(TaskHandle_t *)&LedTask_Handler);

	// xTaskCreate((TaskFunction_t)Debug_Task,
	// 		(const char *)"Debug_Task",
	// 		(const configSTACK_DEPTH_TYPE)DebugTask_Stack,
	// 		(void *)NULL,
	// 		(UBaseType_t) DebugTask_Prio,
	// 		(TaskHandle_t *)&DebugTask_Handler);
    
    vTaskStartScheduler();

	while(1);

    return 0;
}