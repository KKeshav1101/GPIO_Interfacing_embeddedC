#include<LPC214X.h>
char c;
int main(){
	PINSEL0=0x00000005;
	U0LCR=0x83;
	U0DLL=0X87;
	U0LCR=0X03;
	while(1){
		while(!(U0LSR & 0X01));
		c=U0RBR;
		if(IO0PiN & 0x000004000){
			
				U0THR=c;
				c=c+1;
				while(!(U0LSR & 0X20));
			}
		}
		/*c=c+1;
		while(!(U0LSR & 0X20));
		U0THR=c;*/
	}
	return 0;
}