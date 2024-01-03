#include "car.h"
#include "xunji.h"

extern int flag;

int main()
{
	
	Timer0_Init();
	while(1)
	{	
		xunji();
		if(flag==1)
		{
			return 0;
		}
	}
	
	
	
}
