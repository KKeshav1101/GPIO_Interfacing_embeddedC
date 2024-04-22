#include<lpc214x.h>
void delay(void);
void ext();
__irq void Ext();
int main(){
	IODIR0=0x00000000;
	IODIR1=0x00ff0000;
	ext();
	while(1){
		IOSET1=0x00ff0000;
		delay();
		IOCLR1=0x00ff0000;
		delay();
	}
	return 0;
}
void ext(){
	EXTMODE=0X02;
	EXTPOLAR &= ~(0X02);
	PINSEL0 = 0X20000000;
	VICIntSelect &= ~(1<<15);
	VICVectAddr5 = (unsigned int)Ext;
	VICVectCntl5 = (1<<5) | 15;
	VICIntEnable = (1<<15);
}
__irq void Ext(){
	IOSET1=0X00550000;
	delay();
	IOCLR1=0x00550000;
	EXTINT |= 0x02;
	VICVectAddr=0;
}
void delay(){
	int i,j;
	for(i=0;i<100;i++)
		for(j=0;j<1000;j++);
}
