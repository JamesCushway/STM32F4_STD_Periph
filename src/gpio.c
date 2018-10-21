/*
 * gpio.c
 *
 *  Created on: 19 Oct 2018
 *      Author: jamescushway
 */
#include "../inc/gpio.h"

void GPIO_RCC(uint32_t RCC_AHB1Periph_GPIOx) {
	*AHB1_ENR |= RCC_AHB1Periph_GPIOx;
}

void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct) {

	/* Mode configuration */
	GPIOx->MODER  &= ~(0x03 << (GPIO_InitStruct->GPIO_Pin * 2));
	GPIOx->MODER |= (uint32_t)(GPIO_InitStruct->Mode) << (GPIO_InitStruct->GPIO_Pin * 2);

	if (GPIO_InitStruct->Mode == 0x01 || GPIO_InitStruct->Mode == 0x02) {
		/* Speed configuration */
		GPIOx->OSPEEDR &= ~(0x03 << (GPIO_InitStruct->GPIO_Pin * 2));
		GPIOx->OSPEEDR |= ((uint32_t)(GPIO_InitStruct->Speed) << (GPIO_InitStruct->GPIO_Pin * 2));

		/* Output Type configuration*/
		GPIOx->OTYPER  &= ~((0x01) << (GPIO_InitStruct->GPIO_Pin));
		GPIOx->OTYPER |= (uint32_t)((0x00) << (GPIO_InitStruct->GPIO_Pin));
	}

	/* Pull-up Pull down resistor configuration*/
	GPIOx->PUPDR &= ~(0x03 << (GPIO_InitStruct->GPIO_Pin * 2));
	GPIOx->PUPDR |= (((uint32_t)0x01) << (GPIO_InitStruct->GPIO_Pin * 2));
}

void GPIO_Set_Pin(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin) {
	GPIOx->BSRR = 0x1 << GPIO_Pin;
}

void GPIO_Reset_Pin(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin) {
	GPIOx->BSRR = GPIO_Pin << 0x10;
}
