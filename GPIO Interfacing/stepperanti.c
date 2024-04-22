#include <LPC214X.H> /* For 360 degree, a=200*/

void delay(unsigned int count)
{
  unsigned int i ,j= 0;
  for(i = 0; i <= count; i ++)
  for(j = 0; j <= 80; j ++);
}

unsigned long i;

int main()
{
	int a=200;
  IODIR1 = 0x00FF0000;
  i = 0x00010000;
	while(a)
{

	IO1SET=i;
	delay(10000);
	IO1CLR=0x000F0000;
		i=i<<1;
	//delay(10000);
	if(i==0x00100000)
		{
		i=0x00010000;
		}
	a=a-1;
	}
}
