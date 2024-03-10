#include<LPC17xx.h>
unsigned int i,j,c=0,f=0,SW2=0;
unsigned long LED = 0x00000000;

int main(void)
{
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;
	LPC_PINCON->PINSEL4 &= (3 << 24);
	LPC_GPIO2->FIODIR |= (1<<12);

	while (1) 
	{// Read the state of SW2
	SW2 = (LPC_GPIO2->FIOPIN >> 12) & 1;
	// If SW2 is pressed (1), increment the counter
	if (SW2 == 1)
	{
		LPC_GPIO0->FIOPIN=LED<<4;
		if(LED==0) f=1;			
		LED--;
		if(f==1)
		{
			LED=255;
			f=0;
		}
	} 
	// If SW2 is not pressed (0), decrement the counter
	else
	{
		LPC_GPIO0->FIOPIN=LED<<4;
		if(LED==255) f=1;
		LED++;
		if(f==1)
		{
			LED=0;
			f=0;
		}
	}
	for(int d=0;d<10000;d++);
	}
}