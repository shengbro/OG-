#include <REGX52.H>

unsigned char NixieTable[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void Delay(unsigned int x);

void Nixie(unsigned char Location,Number)
{
	switch(Location)
	{
		case 1 : P2 = 0x01;break;
		case 2 : P2 = 0x02;break;
		case 3 : P2 = 0x04;break;
		case 4 : P2 = 0x08;break;
	
	}
  P0 = NixieTable[Number];
	Delay(1);
	P2 = 0x00;
}

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
		Nixie(1,2);
		//Delay(500);
		Nixie(2,5);
		//Delay(500);
		Nixie(3,1);
		//Delay(500);
		Nixie(4,7);
		//Delay(500);
	}
}