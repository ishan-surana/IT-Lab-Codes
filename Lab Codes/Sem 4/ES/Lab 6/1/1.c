#include <LPC17xx.h>
unsigned int i,j,c=0,f=0;;
unsigned long LED = 0x00000000;

int main(void)
{
LPC_PINCON->PINSEL0 &= 0xFF0000FF; //Configure Port0 PINS P0.4-P0.11 as GPIO function
LPC_GPIO0->FIODIR |= 0x00000FF0; //Configure P0.4-P0.11 as output port
	while(1)
	{
		c++;
		LPC_GPIO0->FIOPIN=LED<<4;
		if(LED==255)
			f=1;
		else if(LED==0)
			f=0;
		if(f==0)
		{
				LED++;
		}
		/*
		else
		{
			if(LED==0)
				f=0;
			else
				LED--;
		}
		*/
		for(i=0;i<50000;i++);
	}
}
