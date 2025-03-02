#include "stm32f10x.h"                  // Device header

// 定义LED显示数据
uint8_t LedShowData[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90}; // 0-9的显示数据

// 定义GPIO引脚的枚举类型
typedef enum {
    PIN_0 = GPIO_Pin_0,
    PIN_1 = GPIO_Pin_1,
    PIN_2 = GPIO_Pin_2,
    PIN_3 = GPIO_Pin_3,
    PIN_4 = GPIO_Pin_4,
    PIN_5 = GPIO_Pin_5,
    PIN_6 = GPIO_Pin_6,
    PIN_7 = GPIO_Pin_7
} GPIO_PIN;

// 初始化LED数码管
void LEDSEG_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = PIN_0 | PIN_1 | PIN_2 | PIN_3 | PIN_4 | PIN_5 | PIN_6 | PIN_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_SetBits(GPIOA, PIN_0 | PIN_1 | PIN_2 | PIN_3 | PIN_4 | PIN_5 | PIN_6 | PIN_7);
}

// 数码管显示函数
void Digital_Display(uint8_t val)
{
    uint8_t i;
    uint16_t display_val = LedShowData[val];
    for (i = 0; i < 8; i++)
    {
        GPIO_WriteBit(GPIOA, (GPIO_PIN)(1 << i), (display_val >> i) & 0x01);
    }
}
