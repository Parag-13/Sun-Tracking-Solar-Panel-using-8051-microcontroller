#include <reg51.h>
#include <stdio.h>

sbit sw1 = P3^0;//sw for direction control
sbit sw2 = P3^1;

sbit dec_speed=P3^2;//Sw for decreasing speed
sbit inc_speed=P3^3; //Sw for increasing speed

unsigned char x=30000;

void msdelay(unsigned int time)

{
unsigned int i,j;

for(i=0;i<time;i++)

for(j=0;j<922;j++);

}
void main()
{

sw1=1;	//making P2.0 as inputs
	
sw2=1;
	

	
inc_speed=1;       //making P3.2 as an input

dec_speed=1;       //making P3.3 as an input

P2=0x00;           //making P2 as an output port

IE =0X85;          //Enable EX INTO and INT1

TCON=0X05; 
	
	
while(1)

{
if(sw1==0)          //Anticlockwise

{
	
	
	P2=0x03;
	msdelay(x);
	
	P2=0x06;
	msdelay(x);
	
	P2=0x0C;
	msdelay(x);
	
	P2=0x09;
	msdelay(x);
		
}

else if(sw2==0)       //Clockwise

{
	
	P2=0x09;
	msdelay(x);
	P2=0x0C;
	msdelay(x);
	P2=0x06;
	msdelay(x);
	P2=0x03;
	msdelay(x);
	
	
}



}
}
void int0() interrupt 0      //Will be called every time INTO SW is pressed

{
if(x<30000)

x=x+60;
}

void int1() interrupt 2     //Will be called every time INT1 SW is pressed

{
if(x>20) 
	x=x-60;

}