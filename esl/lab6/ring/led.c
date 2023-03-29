#include<LPC17xx.h>

unsigned int i,j,c=1;
unsigned long LED = 0x00000010;

int main(void)
{
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;
	
	while(1)
	{
		LPC_GPIO0->FIOPIN=c<<4;
		for(i=0;i<100;i++);
		
		if(c == 0x80)
			c=1;
		else
			c<<=1;
	}
}