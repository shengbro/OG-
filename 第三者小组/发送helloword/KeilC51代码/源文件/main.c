#include <REGX51.H>

unsigned char cntTxd = 0;
unsigned char* p;
unsigned char ch[] = "helloword";

void Delayms(unsigned int x)
{
	while(x)
	{
		unsigned char i,j;
	
		i = 2;
		j = 239;
		do
		{
		while(--j);
		}while(--i);
		x--;
	}
}

void ConfigUART(unsigned int baud)
{
	SCON = 0x50;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TH1 = 256-(11059200/12/32)/baud;
	TL1 = TH1;
	ET1 = 0;
	ES = 1;
	TR1 = 1;
}

void InterruptUART() interrupt 4
{
	if(TI)
	{
		TI = 0;
		p = ch;
		if(cntTxd > 0)
		{
			SBUF = *p;
			cntTxd--;
			p++;
		}
		
	}
}

void main()
{
	EA = 1;
	ConfigUART(9600);

  while(1)
	{
		cntTxd = sizeof(ch)-1;
	  TI = 1;
		Delayms(1000);
	}
}