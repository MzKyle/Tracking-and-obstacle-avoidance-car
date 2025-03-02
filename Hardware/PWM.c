#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
      TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
      TIM_OCInitTypeDef TIM_OCInitStructure;

      //使能定时器TIM4时钟（注意TIM4时钟为APB1）
      RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
      // 使能PWM输出GPIO时钟
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);

      //配置GPIO引脚：PB6 - TIM4_CH1
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;// 复用推挽输出
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      GPIO_Init(GPIOB, &GPIO_InitStructure);

      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      GPIO_Init(GPIOB, &GPIO_InitStructure);

      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      GPIO_Init(GPIOB, &GPIO_InitStructure);

      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      GPIO_Init(GPIOB, &GPIO_InitStructure);

      TIM_TimeBaseStructure.TIM_Period = 100 - 1;
      TIM_TimeBaseStructure.TIM_Prescaler =36 - 1;
      TIM_TimeBaseStructure.TIM_ClockDivision = 0;
      TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
      TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

      TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
      TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
      TIM_OCInitStructure.TIM_Pulse = 0;
      TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
      TIM_OC1Init(TIM4, &TIM_OCInitStructure);


      TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
      TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
      TIM_OCInitStructure.TIM_Pulse = 0;
      TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

      TIM_OC2Init(TIM4, &TIM_OCInitStructure);


      TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
      TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
      TIM_OCInitStructure.TIM_Pulse = 0;
      TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
      TIM_OC3Init(TIM4, &TIM_OCInitStructure);


      TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
      TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
      TIM_OCInitStructure.TIM_Pulse = 0;
      TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
      TIM_OC4Init(TIM4, &TIM_OCInitStructure);


      TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
      TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
      TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
      TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
      TIM_ARRPreloadConfig(TIM4, ENABLE);

      TIM_Cmd(TIM4, ENABLE);
}

