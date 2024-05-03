#include<LPC21xx.h>
void display(unsigned int i)
{
	unsigned int a[20]={0x003f0000,0x00060000,0x005b0000,0x004f0000,0x00660000,0x006d0000,0x007d0000,0x00070000,0x007f0000,0x006f0000,0x00770000,0x007c0000,0x00390000,0x005e0000,0x00790000,0x00710000};
	int x;
	PINSEL1=0X00000000;
	IODIR0= 0X00FF0000;
	IOSET0= 0X80000000;
	IOSET0= a[i];
	for(x=0;x<=100000;x++);
	IOCLR0= a[i];
	for(x=0;x<=100000;x++);
}

int main()
{
	unsigned int r0[5]={0x00ee0000,0x00de0000,0x00be0000,0x007e0000};
	unsigned int r1[5]={0x00ed0000,0x00dd0000,0x00bd0000,0x007d0000};
	unsigned int r2[5]={0x00eb0000,0x00db0000,0x00bb0000,0x007b0000};
	unsigned int r3[5]={0x00e70000,0x00d70000,0x00b70000,0x00770000};
	unsigned int value;
	unsigned int i;
	PINSEL2=0X00000000;
	IODIR1 =0XFFF0FFFF;
	PINSEL1=0X00000000;
	IODIR0= 0X00FF0000;
	IOSET0= 0X80000000;
	IOPIN1 =0X00FF0000;
	while(1)
	{
		IOCLR1= 0X00100000;
		value=IOPIN1 & 0x00ff0000;
		for(i=0;i<4;i++)
		{
			if(value==r0[i])
			{
				display(i);
			}
		}
		IOCLR1= 0X00200000;
		value=IOPIN1 & 0x00ff0000;
		for(i=0;i<4;i++)
		{
			if(value==r1[i])
			{
				display(i+4);
			}
		}
		IOCLR1= 0X00400000;
		value=IOPIN1 & 0x00ff0000;
		for(i=0;i<4;i++)
		{
			if(value==r2[i])
			{
				display(i+8);
			}
		}
		IOCLR1= 0X00800000;
		value=IOPIN1 & 0x00ff0000;
		for(i=0;i<4;i++)
		{
			if(value==r3[i])
			{
				display(i+12);
			}
		}
	}
}
		