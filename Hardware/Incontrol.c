#include "stm32f10x.h"                  // 设备头文件
#include "misc.h"                       // 包含 NVIC 配置相关定义
#include "Delay.h"

// 定义红外接收引脚和端口
#define IRED_PORT           GPIOA
#define IRED_PIN            GPIO_Pin_8
#define IRED_PORT_RCC       RCC_APB2Periph_GPIOA

uint32_t IR_Receivecode;    // 用于存储接收到的32位红外数据
uint8_t  IR_Receiveflag;    // 用于指示是否接收到完整的红外数据

/*******************************************************************************
* 函数名称         : IRremote_Init
* 函数描述         : 初始化红外接收引脚，配置外部中断
* 输入参数         : 无
* 输出参数         : 无
*******************************************************************************/
void IRremote_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    EXTI_InitTypeDef EXTI_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    // 启用GPIO时钟和复用功能时钟
    RCC_APB2PeriphClockCmd(IRED_PORT_RCC | RCC_APB2Periph_AFIO, ENABLE);

    // 配置红外接收引脚为上拉输入模式
    GPIO_InitStructure.GPIO_Pin = IRED_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(IRED_PORT, &GPIO_InitStructure);

    // 配置GPIO引脚与外部中断线的连接
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);
    EXTI_ClearITPendingBit(EXTI_Line8);

    // 配置外部中断线为下降沿触发
    EXTI_InitStructure.EXTI_Line = EXTI_Line8;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    // 配置NVIC中断优先级和使能
    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;   // 外部中断通道
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; // 抢占优先级为0
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;   // 响应优先级为1
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;      // 使能中断
    NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
* 函数名称         : IRremote_Counttime
* 函数描述         : 计算高电平持续时间，单位为20us
* 输入参数         : 无
* 输出参数         : 高电平持续时间
*******************************************************************************/
uint8_t IRremote_Counttime()
{
    uint8_t t = 0;
    while (GPIO_ReadInputDataBit(IRED_PORT, IRED_PIN) == 1) // 高电平
    {
        t++;
        Delay_us(20);
        if (t >= 250) return t; // 超时退出
    }
    return t;
}

void EXTI9_5_IRQHandler(void) // 红外接收外部中断处理函数
{
    // 中断处理代码（已注释）
    // EXTI_ClearITPendingBit(EXTI_Line8); // 清除中断标志
}
