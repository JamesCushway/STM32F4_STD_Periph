/*
 * main.c
 *
 *  Created on: 06 Oct 2018
 *      Author: jamescushway
 */
#include "../inc/gpio.h"

int main() {

	GPIO_RCC((uint32_t)RCC_AHB1Periph_GPIOD);	// Clock port D

	GPIO_InitTypeDef GPIO_Init_Struct;

	GPIO_Init_Struct.GPIO_Pin 	= 0x0C;			// Pin 12
	GPIO_Init_Struct.Mode 		= 0x01;			// Output mode
	GPIO_Init_Struct.Speed 		= 0x00;			// 2MHz
	GPIO_Init_Struct.OType 		= 0x00;			// PUPD
	GPIO_Init_Struct.PUPD 		= 0x01;			// Pull up

	GPIO_Init(GPIOD, &GPIO_Init_Struct);

	GPIO_Set_Pin(GPIOD, GPIO_PIN_12);

	while(1) {

	}
}
