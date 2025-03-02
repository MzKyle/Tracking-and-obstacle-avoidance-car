#ifndef __ROBOT_H
#define __ROBOT_H

// 机器人初始化函数
void robot_Init(void);

// 设置机器人速度函数
void robot_speed(uint8_t left1_speed, uint8_t left2_speed, uint8_t right1_speed, uint8_t right2_speed);

// 机器人运动函数
void makerobo_run(uint8_t speed, uint16_t time); // 机器人前进
void makerobo_brake(uint16_t time);              // 机器人刹车
void makerobo_Left(int8_t speed, uint16_t time); // 机器人左转
void makerobo_Spin_Left(int8_t speed, uint16_t time);  // 机器人原地左转
void makerobo_Right(int8_t speed, uint16_t time);      // 机器人右转
void makerobo_Spin_Right(int8_t speed, uint16_t time); // 机器人原地右转
void makerobo_back(int8_t speed, uint16_t time);       // 机器人后退

#endif
