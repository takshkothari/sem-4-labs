#include <LPC17xx.h>
#include <stdio.h>

unsigned int seg_select[4] = {0<<23, 1<<23, 2<<23, 3<<23};
unsigned int dig1=0x00, dig2=0x00, dig3=0x00, dig4=0x00;
unsigned int twenty_count=0x00, seg_count=0x00, temp1=0x00;
unsigned char array_dec[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char one_s_f=0x00;
unsigned long int i=0;

void delay(void);
void display(void);
int main(void)
{ 
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= 0xFF0000FF; //P0.4 to P0.11 GPIO data lines
	LPC_PINCON->PINSEL3 &= 0xFFC03FFF; //P1.23 to P1.26 GPIO enable lines
	LPC_GPIO0->FIODIR |= 0x00000FF0; //P0.4 to P0.11 output
	LPC_GPIO1->FIODIR |= 0x07800000; //P1.23 to P1.26 output
	while(1) {
		delay();
		display();
		seg_count +=1; 
		if(seg_count == 0x05) { 
			seg_count = 0x00;
			one_s_f=0xFF;
			dig1 -=1;
			if(dig1 == 0x00) { 
				dig1 = 0x9;
				dig2 -=1;
				if(dig2 == 0x0)
				{
					dig2 = 0x9;
					dig3-=1;
					if(dig3 == 0x0)
					{
						dig3 = 0x9;
						dig4 -= 1;
						if(dig4 == 0x0) {
							dig4 = 0x9;
							dig3 = 0x9;
							dig2 = 0x9;
							dig1 = 0x9;
						}//end of dig4
					} //end of dig3
				} //end of dig2
			} //end of dig1
		} //end of seg_count
		display();
	} //end of while(1)
}//end of main

void display(void) //To Display on 7-segments
{
	LPC_GPIO1->FIOPIN = seg_select[seg_count]; 
	if(seg_count == 0x00) { // For Segment U8
		temp1 = dig1;
		LPC_GPIO1->FIOPIN=0xF87FFFFF;
	}
	else if(seg_count == 0x01) { // For Segment U9
		temp1 = dig2;
		LPC_GPIO1->FIOPIN=0xF8FFFFFF;
	}
	else if(seg_count == 0x02) {// For Segment U10
		temp1 = dig3;
		LPC_GPIO1->FIOPIN=0xF97FFFFF;
	}
	else if(seg_count == 0x03) {// For Segment U11
		temp1 = dig4;
		LPC_GPIO1->FIOPIN=0xF9FFFFFF;
	}
	LPC_GPIO0->FIOPIN = array_dec[temp1]<<4; // Taking Data Lines for 7-Seg
	for(i=0;i<500;i++);
}
void delay(void)
{ 
	unsigned int i;
	for(i=0;i<10000;i++);
	if(twenty_count==1000) {
		one_s_f=0xff;
		twenty_count=0x00;
	} else
		twenty_count += 1;
}