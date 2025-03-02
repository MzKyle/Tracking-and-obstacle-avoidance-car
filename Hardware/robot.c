#include "stm32f10x.h"                  // 设备头文件
#include "PWM.h"
#include "Delay.h"

// 机器人初始化
void robot_Init(void)
{
    PWM_Init();  // 初始化PWM
}

// 设置机器人速度
void robot_speed(uint8_t left1_speed, uint8_t left2_speed, uint8_t right1_speed, uint8_t right2_speed)
{
    TIM_SetCompare1(TIM4, left1_speed);  // 设置左前轮速度
    TIM_SetCompare2(TIM4, left2_speed);  // 设置左后轮速度
    TIM_SetCompare3(TIM4, right1_speed); // 设置右前轮速度
    TIM_SetCompare4(TIM4, right2_speed); // 设置右后轮速度
}

// 机器人前进
void makerobo_run(int8_t speed, uint16_t time)
{
    if (speed > 100)
    {
        speed = 100;
    }
    if (speed < 0)
    {
        speed = 0;
    }
    robot_speed(speed, 0, speed, 0); // 设置前进速度
    Delay_ms(time);                  // 延时
    // robot_speed(0, 0, 0, 0);      // 停止机器人
}

// 机器人刹车
void makerobo_brake(uint16_t time)
{
    robot_speed(0, 0, 0, 0); // 停止机器人
    Delay_ms(time);          // 延时
}

// 机器人左转
void makerobo_Left(int8_t speed, uint16_t time)
{
    if (speed > 100)
    {
        speed = 100;
    }
    if (speed < 0)
    {
        speed = 0;
    }
    robot_speed(0, 0, speed, 0); // 设置左转速度
    Delay_ms(time);              // 延时
    // robot_speed(0, 0, 0, 0);   // 停止机器人
}

// 机器人原地左转
void makerobo_Spin_Left(int8_t speed, uint16_t time)
{
    if (speed > 100)
    {
        speed = 100;
    }
    if (speed < 0)
    {
        speed = 0;
    }
    robot_speed(0, speed, speed, 0); // 设置原地左转速度
    Delay_ms(time);                  // 延时
    // robot_speed(0, 0, 0, 0);      // 停止机器人
}

// 机器人右转
void makerobo_Right(int8_t speed, uint16_t time)
{
    if (speed > 100)
    {
        speed = 100;
    }
    if (speed < 0)
    {
        speed = 0;
    }
    robot_speed(speed, 0, 0, 0); // 设置右转速度
    Delay_ms(time);              // 延时
    // robot_speed(0, 0, 0, 0);   // 停止机器人
}

// 机器人原地右转
void makerobo_Spin_Right(int8_t speed, uint16_t time)
{
    if (speed > 100)
    {
        speed = 100;
    }
    if (speed < 0)
    {
        speed = 0;
    }
    robot_speed(speed, 0, 0, speed); // 设置原地右转速度
    Delay_ms(time);                  // 延时
    // robot_speed(0, 0, 0, 0);      // 停止机器人
}

// 机器人后退
void makerobo_back(int8_t speed, uint16_t time)
{
    if (speed > 100)
    {
        speed = 100;
    }
    if (speed < 0)
    {
        speed = 0;
    }
    robot_speed(0, speed, 0, speed); // 设置后退速度
    Delay_ms(time);                  // 延时
    // robot_speed(0, 0, 0, 0);      // 停止机器人
}
