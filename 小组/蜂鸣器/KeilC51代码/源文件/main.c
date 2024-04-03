#include <REGX52.H>
sbit beep = P3^0;
void Delay(unsigned int x)
{
	while(x--)
	{
		unsigned char i,j;
	
		i = 2;
		j = 239;
		do
		{
			while(--j);
		}while(--i);
	}
}



void main()
{
	while(1)
	{
		beep = 1;
		//Delay(500);
		//P3_0 = 1;
		//Delay(500);
	}
}