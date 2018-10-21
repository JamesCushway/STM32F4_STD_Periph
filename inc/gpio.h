/*
 * gpio.h
 *
 *  Created on: 06 Oct 2018
 *      Author: jamescushway
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdio.h>

#define PERIPH_BASE 			(0x40000000)
#define AHB1_PERIPH_BASE 		(PERIPH_BASE + 0x00020000)
#define RCC_BASE 				(AHB1_PERIPH_BASE + 0x3800)
#define AHB1ENR 				(RCC_BASE + 0x30)

/* AHB1 bus */
#define AHB1_ENR ((uint32_t *)AHB1ENR)

/* Bus offsets for GPIOA - GPIOI */
#define RCC_AHB1Periph_GPIOA 	0x00000001
#define RCC_AHB1Periph_GPIOB 	0x00000002
#define RCC_AHB1Periph_GPIOC 	0x00000004
#define RCC_AHB1Periph_GPIOD 	0x00000008
#define RCC_AHB1Periph_GPIOE 	0x00000010
#define RCC_AHB1Periph_GPIOF 	0x00000020
#define RCC_AHB1Periph_GPIOG 	0x00000040
#define RCC_AHB1Periph_GPIOH 	0x00000080
#define RCC_AHB1Periph_GPIOI 	0x00000100

/* GPIO port base addresses */
#define GPIOA_BASE 				AHB1_PERIPH_BASE
#define GPIOB_BASE 				(AHB1_PERIPH_BASE + 0x0400)
#define GPIOC_BASE 				(AHB1_PERIPH_BASE + 0x0800)
#define GPIOD_BASE 				(AHB1_PERIPH_BASE + 0x0C00)
#define GPIOE_BASE 				(AHB1_PERIPH_BASE + 0x1000)
#define GPIOF_BASE 				(AHB1_PERIPH_BASE + 0x1400)
#define GPIOG_BASE 				(AHB1_PERIPH_BASE + 0x1800)
#define GPIOH_BASE 				(AHB1_PERIPH_BASE + 0x1C00)
#define GPIOI_BASE 				(AHB1_PERIPH_BASE + 0x2000)

/* GPIO typedef struct */
typedef struct {
	  uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
	  uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
	  uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
	  uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	  uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
	  uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
	  uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
	  uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
	  uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

/* GPIO init struct */
typedef struct {
	uint32_t GPIO_Pin;
	uint32_t Mode;
	uint32_t OType;
	uint32_t Speed;
	uint32_t PUPD;
} GPIO_InitTypeDef;

/* GPIO Port Structs */
#define GPIOA ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI ((GPIO_TypeDef *) GPIOI_BASE)

/* GPIO pins */
#define GPIO_PIN_01 (uint32_t)0x01
#define GPIO_PIN_02 (uint32_t)0x02
#define GPIO_PIN_03 (uint32_t)0x03
#define GPIO_PIN_04 (uint32_t)0x04
#define GPIO_PIN_05 (uint32_t)0x05
#define GPIO_PIN_06 (uint32_t)0x06
#define GPIO_PIN_07 (uint32_t)0x07
#define GPIO_PIN_08 (uint32_t)0x08
#define GPIO_PIN_09 (uint32_t)0x09
#define GPIO_PIN_10 (uint32_t)0x0A
#define GPIO_PIN_11 (uint32_t)0x0B
#define GPIO_PIN_12 (uint32_t)0x0C
#define GPIO_PIN_13 (uint32_t)0x0D
#define GPIO_PIN_14 (uint32_t)0x0E
#define GPIO_PIN_15 (uint32_t)0x0F

/* GPIO init declaration */
void GPIO_RCC(uint32_t RCC_AHB1Periph_GPIOx);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_Set_Pin(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
void GPIO_Reset_Pin(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);



#endif /* GPIO_H_ */
