#include <STC89C5xRC.H>



sbit IN11 = P0^5;//左前轮
sbit IN12 = P0^6;
	  
sbit IN13 = P0^3;//右前轮
sbit IN14 = P0^4;
	
sbit IN21 = P3^5;//左后轮
sbit IN22 = P3^6;
	
sbit IN23 = P3^3;//右后轮
sbit IN24 = P3^4;

//左前轮
void LF_motor_go() //左前正转
{
	IN13 = 0;
	IN14 = 1;
}
void LF_motor_back() //左前反转
{
	IN13 = 1;
	IN14 = 0;
}
void LF_motor_stop() //左前停止
{
	IN13 = 0;
	IN14 = 0;
}
//右前轮
void RF_motor_go() //右前正转
{
	IN11 = 0;
	IN12 = 1;
}
void RF_motor_back() //右前反转
{
	IN11 = 1;
	IN12 = 0;
}
void RF_motor_stop() //右前停止
{
	IN11 = 0;
	IN12 = 0;
}
//左后轮
void LR_motor_go() //左后正转
{
	IN21 = 1;
	IN22 = 0;
}
void LR_motor_back() //左后反转
{
	IN21 = 0;
	IN22 = 1;
}
void LR_motor_stop() //左后停止
{
	IN21 = 0;
	IN22 = 0;
}
//右后轮
void RR_motor_go() //右后正转
{
	IN23 = 1;
	IN24 = 0;
}
void RR_motor_back() //右后反转
{
	IN23 = 0;
	IN24 = 1;
}
void RR_motor_stop() //右后停止
{
	IN23 = 0;
	IN24 = 0;
}
