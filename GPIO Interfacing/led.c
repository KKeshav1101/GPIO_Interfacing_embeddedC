#include<LPC214X.h>
unsigned int c;
void delay(){
	int i,j;
	for(i=0;i<1000;i++)
		for(j=0;j<1000;j++);
}
int main(){
	c=0x00010000;
	PINSEL0=0X00000000;
	IODIR1=0X000000000;
	
	while(1){
		if(IO0PIN & 0x00004000){
			if(c>0x00800000)
				c=0x00010000;
			IO1SET=c;
			delay();
			IO1CLR=c;
			delay();
			c=c<<1;
			
		}
		else{
			if(c<0x00010000)
				c=0x00800000;
			IO1SET=c;
			delay();
			IO1CLR=c;
			delay();
			c=c>>1;
			
		}
	}
	return 0;
}