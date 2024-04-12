#include <REGX51.H>

void main()
{
	unsigned int i = 0;
	TMOD = 0x01;  
	TH0  = 0x4C;  
	TL0  = 0x00;
	TR0  = 1;
		while(1)
		{
			if(TF0 == 1)
			{
				TF0 = 0;
				TH0  = 0x4C;  
				TL0  = 0x00;
				P2 = 0x01 + i;
				i++;
			}
			if(i>=8)
			{
				i = 0;
			}
		}
}