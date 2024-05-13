#include<stdio.h>
#include<LPC21xx.h>
char arr1[20],arr2[20],arr3[20];
unsigned int i,x,y,z;
void rtc(void)
{
	PREINT= 0x5A;
	PREFRAC=0x46C0;
	CCR=0x00;
	SEC=0;
	MIN=24;
	HOUR=3;
	CCR=0x01;
}
void serial(void)
{
	PINSEL0= 0x05;
	IODIR1=0x00ff0000;
	U0LCR =0x83;
	U0DLM =0x00;
	U0DLL =0x61;
	U0LCR=0x03;
}
void delay(void)
{
	int j;
	for(j=0;j<2000000;j++);
}
int main()
{
	serial();
	rtc();
	while(1)
	{
		i=0;
		x=SEC;
		y=MIN;
		z=HOUR;
		sprintf(arr1,"sec:%d",x);
		while(arr1[i]!='\0')
		{
			while(!(U0LSR & 0x20));
			U0THR =arr1[i];
			i++;
		}
		i=0;
		U0THR='\n';
		sprintf(arr2,"min:%d",y);
		while(arr2[i]!='\0')
		{
			while(!(U0LSR & 0x20));
			U0THR =arr2[i];
			i++;
		}
		i=0;
		U0THR='\n';
		sprintf(arr3,"hour:%d",z);
		while(arr3[i]!='\0')
		{
			while(!(U0LSR & 0x20));
			U0THR =arr3[i];
			i++;
		}
		i=0;
		U0THR='\n';
	}
}
		