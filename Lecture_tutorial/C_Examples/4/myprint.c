
#include <Philips\8xC668.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<standard.h>
#include<macros31.h>

void uart1()
{
RCAP2H = 0xff ;
RCAP2L = 0xdc ;
T2CON = 0x34 ;
S0CON = 0x50 ;
}



void main ()
{

char my_name[20];
uart1();

printf("\n what is your name ?\n");
scanf("%s",my_name);
printf("\n name: %s",my_name);
while(1)
{
asm nop
}

}

