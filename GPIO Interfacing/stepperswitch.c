#include<lpc214x.h>
unsigned long i;
void delay(unsigned int);
int main(){
	int a=1;
	IO1DIR=0X00FF0000;
	IO0DIR=0X00000000;
	i=0X00080000;
	while(a){
		if(IO0PIN & 0X00004000){
			i=i<<1;
		}
		else{
			i=i>>1;
		}
		IO1SET=i;
		delay(1000);
		IO1CLR=i;
	}
}
void delay(unsigned int count){
	int i,j;
	for(i=0;i<count;i++){
		for(j=0;j<60;j++);
	}
}