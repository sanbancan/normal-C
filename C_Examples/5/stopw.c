#include <Philips\8xC668.h>
#include<stdio.h>
#include<macros31.h>
#include<standard.h>
#include<string.h>
#include<stdlib.h>

unsigned char str[5];
unsigned char temp[5];
unsigned char cntr=1;
unsigned char cntr2=0;
unsigned int clock=0;

unsigned char LkUp[10]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,
						0xBE,0xE0,0xFF,0xE6};

BIT seg1 P2.4
BIT seg2 P2.5
BIT seg3 P2.6
BIT seg4 P2.7

interrupt(4) stop_watch() using 3
{
	//	printf("\nint");
		cntr2++;

		if(cntr2==40)           // 190 6 clock mode ??
		{
			cntr2=0;
			clock++;
		}

			TH1=0xEE;			// 5 msec timer
			TL1=0x00;
			TR1=1;
}


interrupt(2) my_time() using 2
{

			if(cntr==1)
			{
			seg4=1;
			seg1=0;
			P0=str[3];
			}
			if(cntr==2)
			{
			seg1=1;
			seg2=0;
			P0=str[2];
			}
			if(cntr==3)
			{
			seg2=1;
			seg3=0;
			P0=str[1];
			}
			if(cntr==4)
			{
			seg3=1;
			seg4=0;
			P0=str[0];
			cntr=0;
			}

			cntr++;
			TH0=0xD4;
			TL0=0x19;


		/*	TH0=0xee;
	        TL0=0x00; */
	        TR0=1;
}


void display(char temp,char i)
{
	char conv;
	conv=temp-48;

	str[i]=LkUp[conv];
}

void main ()
{

	unsigned int inp;
	unsigned char i;

	inp=9999;

	RCAP2H = 0xff ;
	RCAP2L = 0xdc ;
	T2CON = 0x34 ;
	S0CON = 0x50 ;


	TMOD = 0x11 ;					// both timers in  16 bit  mode
	TCON = 0x00 ;					// Do not switch on timers now


	TH0=0xD4;
	TL0=0x19;

	TH1=0xEE;			// 5 msec timer
	
	TL1=0x00;
	printf("\n stopwatch");

/*
	TH1=0xFC;			// 1 msec timer
	TL1=0x66;
*/
	enable();     	      //  Global enable
	enable_t0();	     //    set IE.1
	enable_t1();		//     set IE.3
	set_lo_t0();        //      rst IP.1
	set_hi_t1();		  //      set IP.3
	TR1=1;
	TR0=1;

	while(1)
	{

//	 scanf("%d",&inp);
	 itoa_c31(clock,temp,4);

	 for(i=0;i<4;i++)
	 display(temp[i],i);

	 }


}