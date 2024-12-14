#ifndef __BSP_ABIT_GPIO_H
#define __BSP_ABIT_GPIO_H

#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_exti.h"

#define LED_GPIO_PIN            GPIO_Pin_13

void bsp_abit_gpio_init();

#endif //__BSP_ABIT_GPIO_H