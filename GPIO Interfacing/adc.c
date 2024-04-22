#include<LPC214X.h>
unsigned int val;
int main(){
	PINSEL0=0X01000000;
	SCS=0X03;
	FIO1MASK=0xff00ffff;
	FIO1DIR=0X00FF00000;
	FIO1PIN=0X00000000;
	AD0CR=0X00200E02;
	while(1){
		AD0CR |= 0X01000000;
		do{
			val=AD0DR1;
		}
		while(!(val & 0x80000000));
		FIO1PIN=(val<<8);
	}
	return 0;
}