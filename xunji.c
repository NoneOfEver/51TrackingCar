#include <STC89C5xRC.H>
#include "car.h"
#include <intrins.h>

sbit D1 = P1^0;//外右侧
sbit D2 = P1^1;//中间右侧
sbit D3 = P1^2;//中间左侧
sbit D4 = P1^3;//外左侧

int flag=0;
unsigned char count = 0;//圈数
int ms =0;

//void Time1_Init()//100ms
//{
//    TMOD|=0X10;//选择为定时器0模式，工作方式1
//	TL1 = 0xA4;//初始值
//	TH1 = 0xFF;
//	TF1 = 0;//清除TF1标志
//	TR1 = 1;//定时器1开始计时
//	ET1 = 1;//定时器1中断允许开关
//	EA = 1;//定时器总开关
//	
//}

//void Time1_Routine() interrupt 3 //定时器1中断函数
//{
//	TL1 = 0xA4;
//	TH1 = 0xFF;
//	ms++;
//	if(ms>=10)//1m
//	{
//		car_stop();
//		flag=1;
//	}
//}
void Delay50ms()
{
	unsigned char data i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}

void xunji()
{	
	if(D1==1 && D2==0 && D3==1 && D4==1)//右转
	{
		car_rightgo();
		
	}
	if(D1==1 && D2==1 && D3==0 && D4==1)//左转
	{
		car_leftgo();
		

	}
	if(D1==0 && D2==1 && D3==1 &&D4==1)//右大转
	{
		car_rightstop();
		

	}
	if(D1==1 && D2==1 && D3==1 && D4==0)//左大转
	{
		car_leftstop();
		
	}
//	if(D1==1&&D2==1&&D3==1&&D4==1)
//	{
//		car_go();
//	}
	if((D1==0 && D2==1 && D3==0 && D4==1)||(D1==0 && D2==1 && D3==1 && D4==0)||(D1==1&&D2==0&&D3==1&&D4==0))
	{
		count++;
//		if(count>=8)
//		{
//			Timer1_Init();
//		}
//		else
//		{
//			car_go();
//		}
	}
	if(D1==0 && D2==1 && D3==1 && D4==0)
	{
		if(count%2==1)
		{
			car_go();
		}
		else
		{
			car_rightback();
		}
	}
	
}
