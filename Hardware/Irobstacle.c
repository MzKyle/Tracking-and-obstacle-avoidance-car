#include "stm32f10x.h"                  // Device header

void Irobstacle_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}


uint8_t Left_Irobstacle_Get(void)
{
	return GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11);
}

uint8_t Right_Irobstacle_Get(void)
{
	return GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12);
}
