#include <STC89C5xRC.H>
#include "motor.h"

sbit EN1A = P0^7;//左前
sbit EN1B = P0^2;//右前
sbit EN2A = P3^7;//左后
sbit EN2B = P3^2;//右后

unsigned char counter,compare;


//定时器 中断

void Timer0_Init()//100ms 11.0592MHz
{
	TMOD &= 0xF0;//定时器模式
	TMOD |= 0x01;
	TL0 = 0xA4;//初始值
	TH0 = 0xFF;
	TF0 = 0;//清除TF0标志
	TR0 = 1;//定时器0开始计时
	ET0 = 1;//定时器0中断允许开关
	EA = 1;//定时器总开关
	PT0 = 0;//定时器0中断优先级	
}
void Timer0_Routine() interrupt 1
{
	TL0 = 0xA4;
	TH0 = 0xFF;
	counter++;
	if(counter>=100)
	{
		counter = 0;
	}
	if(counter < compare)
	{
		EN1A = 1;
		EN1B = 1;
		EN2A = 1;
		EN2B = 1;
	}
	else
	{
		EN1A = 0;
		EN1B = 0;
		EN2A = 0;
		EN2B = 0;
	}
	
}

void car_go()//向前直行
{	
	compare = 55;
	LF_motor_go();
	RF_motor_go();
	LR_motor_go();
	RR_motor_go();
}


void car_back()//向后直行
{
	compare=40;
	LF_motor_back();
	RF_motor_back();
	LR_motor_back();
	RR_motor_back();
}

void car_stop()//停
{
	compare = 0;
	LF_motor_stop();
	RF_motor_stop();
	LR_motor_stop();
	RR_motor_stop();
}

void car_leftgo()//向左拐
{
	compare=40;
	LF_motor_stop();
	RF_motor_go();
	LR_motor_stop();
	RR_motor_go();
}

void car_rightgo()//向右拐
{
	compare=40;
	LF_motor_go();
	RF_motor_stop();
	LR_motor_go();
	RR_motor_stop();
}

void car_leftback()//向左后拐
{
	compare=35;
	LF_motor_stop();
	RF_motor_back();
	LR_motor_stop();
	RR_motor_back();
}

void car_rightback()//向右后拐
{
	compare=20;
	LF_motor_back();
	RF_motor_stop();
	LR_motor_back();
	RR_motor_stop();
}

void car_leftstop()//原地左转
{
	compare=60;
	LF_motor_back();
	RF_motor_go();
	LR_motor_back();
	RR_motor_go();
}

void car_rightstop()//原地右转
{
	compare=60;
	LF_motor_go();
	RF_motor_back();
	LR_motor_go();
	RR_motor_back();
}


