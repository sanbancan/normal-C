#include <Philips\8xC668.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <macros31.h>
#include <standard.h>
#include "ProlLcd.c"

// B7FE for a 20 msec timer   / 10 msec timer in 6 clk mode
unsigned char p2data;
unsigned char str1[6];
unsigned char str2[6];
unsigned char logo[17]=" Adroit Devices ";
unsigned char ch;
bit d_set;
bit change=0;
bit add,sub,equal,div;
unsigned char cnt=0;
unsigned int out;

interrupt(2) d_bounce() using 1
{
	TR0=0;
	d_set=1;
}

void func_key_grp1()
{
	d_set=0;

	if(p2data==0xe7)
	ch='0';

	if(p2data==0xeb)
	ch='1';

	if(p2data==0xed)
	ch='2';

	if(p2data==0xee)
	ch='3';

}


void func_key_grp2()
{
	d_set=0;

	if(p2data==0xd7)
	ch='4';

	if(p2data==0xdb)
	ch='5';

	if(p2data==0xdd)
	ch='6';

	if(p2data==0xde)
	ch='7';
}

void func_key_grp3()
{
	d_set=0;

	if(p2data==0xb7)
	ch='8';

	if(p2data==0xbb)
	ch='9';

}


void func_key_grp4()
{
	d_set=0;

	if(p2data==0x77)
	{
	printf("\n+");
	cnt=0;
	add=1;
	change=1;
	equal=0;
	}

	if(p2data==0x7b)
	{
	printf("\n-");
	cnt=0;
	sub=1;
	change=1;
	equal=0;
	//add=0;
	}

	if(p2data==0x7d)
	{
	printf("\n=");
	equal=1;
	sub=1;
	}

}


void main ()
{
	unsigned int inp1,inp2;
	delay_ms(100);
	lcd_init();

	RCAP2H = 0xff ;
	RCAP2L = 0xdc ;
	T2CON = 0x34 ;
	S0CON = 0x50 ;

	P2=0xFF;

	TMOD = 0x01 ; // 16 bit Timer mode
	TH0=0xb7;	  // 20 msec Timer
	TL0=0xfe;

	enable();
	enable_t0();

	str1[cnt]=0;
	str2[cnt]=0;

	display_lcd(logo);
	LcdSet=1;
	printf("\n CALCULATOR READY \n");

	while(1)
	{

		P2=0xef;
		p2data=P2;

		// FIRST row
		if(p2data!=0xef)
		{
			if(!d_set)
			{
			TH0=0xb7;    // start debounce timer
			TL0=0xfe;
			TR0=1;
			}

			if(d_set)
			{
			func_key_grp1();
				if(cnt<6)
				{
				if(!change)
				str1[cnt]=ch;

				if(change)
				str2[cnt]=ch;

				cnt++;

				if(!change)
				str1[cnt]=0;

				if(change)
				str2[cnt]=0;

				printf("\n %s",str1);
				printf("\n %s",str2);
				}
			}
		}


	// SECOND row

	  	P2=0xdf;
	   	p2data=P2;
		if(p2data!=0xdf)
		{
			if(!d_set)
		   {
			TH0=0xb7;    // start debounce timer
			TL0=0xfe;
			TR0=1;
		   }

			if(d_set)
			{
			func_key_grp2();
				if(cnt<6)
				{
				if(!change)
				str1[cnt]=ch;

				if(change)
				str2[cnt]=ch;

				cnt++;
				if(!change)
				str1[cnt]=0;
				if(change)
				str2[cnt]=0;

				printf("\n %s",str1);
				printf("\n %s",str2);
				}
			}
		}


		// THIRD row

	   	P2=0xbf;
	   	p2data=P2;
	   	 if(p2data!=0xbf)
		{
			if(!d_set)
		   {
			TH0=0xb7;    // start debounce timer
			TL0=0xfe;
			TR0=1;
		   }
			 if(d_set)
			{
			func_key_grp3();
				if(cnt<6)
				{
				if(!change)
				str1[cnt]=ch;

				if(change)
				str2[cnt]=ch;

				cnt++;
				if(!change)
				str1[cnt]=0;
				if(change)
				str2[cnt]=0;

				printf("\n %s",str1);
				printf("\n %s",str2);
				}
		    }
		}

	    // FOURTH row

		P2=0x7f;
	   	p2data=P2;
		if(p2data!=0x7f)
		{
			if(!d_set)
		   {
			TH0=0xb7;    // start debounce timer
			TL0=0xfe;
			TR0=1;
		   }
				if(d_set)
				{
				func_key_grp4();
					if(add & equal)
					{
					inp1=atoi(str1);
					inp2=atoi(str2);
					out=inp1+inp2;

					itoa_c31(out,logo,5);
					display_lcd(logo);
					printf("\n sum is %d",out);
					}
				}
		}

			if(cnt==5)
			cnt=5;

	}


}
