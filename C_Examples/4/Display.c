/*   *******************************************************************
Firmware for LCD code prolific systems
Pinouts :
P00    -------------->    NC
P01    -------------->    RS  0 command  1 data
P02    -------------->    R hi  /  W lo always lo in our example
P03    -------------->    E
P04    -------------->    D4
P05    -------------->    D5
P06    -------------->    D6
P07    -------------->    D7
************************************************************************  */

#include <Philips\8xC668.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<standard.h>
#include<macros31.h>

unsigned char p0data;
unsigned char str[33]="Prolific Systems    THANE       ";

void lcd_dat(unsigned char lcd_char)
{
	char local;

	p0data=(p0data&0x01)|(lcd_char&0xf0)|0x02S;
	P0=p0data;
	p0data|=0x08;  // EN hi
	P0=p0data;
	p0data&=0xf7;  // EN lo
	P0=p0data;
	delay_ms(50);

	p0data=(p0data&0x01)|(lcd_char<<4S)|0x02S;
	P0=p0data;
	p0data|=0x08;  // EN hi
	P0=p0data;
	p0data&=0xf7;  // EN lo
	P0=p0data;
	delay_ms(50);
}

void lcd_cmd(unsigned char lcd_char)
{
	// first send higher nibble
	p0data=(p0data&0x01)|(lcd_char&0xf0);
	P0=p0data;
	p0data|=0x08;  // EN hi
	P0=p0data;
	p0data&=0xf7;  // EN lo
	P0=p0data;
	delay_ms(50);

	// next send lower nibble

	p0data=(p0data&0x01)|(lcd_char<<4S);
	P0=p0data;
	p0data|=0x08;  // EN hi
	P0=p0data;
	p0data&=0xf7;  // EN lo
	P0=p0data;
	delay_ms(50);

}


void lcd_init()
{

	p0data=(p0data&0x01S)|0x30S;   // write 3 to the LCD thrice
	P0=p0data;
	delay_ms(50);

    p0data|=0x08;  // EN hi
	P0=p0data;
	p0data&=0xf7;  // EN lo
	P0=p0data;
	delay_ms(50);

	p0data|=0x08;  // EN hi
	P0=p0data;
	p0data&=0xf7;  // EN lo
	P0=p0data;
	delay_ms(50);

	p0data|=0x08;   // EN hi
	P0=p0data;
	p0data&=0xf7;   // EN lo
	P0=p0data;
	delay_ms(25);

	p0data=(p0data&0x01S)|0x20S; // write 2 to the LCD once
	P0=p0data;
	p0data|=0x08;  // EN hi
	P0=p0data;
	p0data&=0xf7;  // EN lo
	P0=p0data;
	delay_ms(50);

	delay_ms(50);

	lcd_cmd(0x28);  // Lcd type init
	delay(5000);
	lcd_cmd(0x08);	// Display off cursor off
	delay(5000);
	lcd_cmd(0x0c);	// Display on Cursor off
	delay(5000);
	lcd_cmd(0x06);  // Shift cursor right
	delay(5000);
	lcd_cmd(0x0e);	// Display cursor blinking
	delay(5000);

}


void display_lcd (char arr[])
{
// displays first 16 characters in the string on line 1 and
// remaining 16 characters on 2nd line
// assumed 16 X 2 display
	unsigned char count ;
	unsigned int str_len;

	str_len=strlen(str);

    lcd_cmd(0x80);	// first line
    delay_ms(10);

    for(count=0;count<16;count++)
	 lcd_dat(arr[count]);

	lcd_cmd(0xc0) ; // second line
	delay_ms(10);

	// second line
	for(count=16;count<32;count++)
	lcd_dat(arr[count]);

}

void main ()
{

	RCAP2H = 0xff ;
	RCAP2L = 0xdc ;   // Setting baud 11.0592MHz at 6 clk mode.
	T2CON = 0x34 ;
	S0CON = 0x40 ;

	printf("\n YES PROLIFIC");

	p0data=0x01;    // make unused pin high !!
	P0=p0data;

	delay_ms(200);

	lcd_init();
	display_lcd(str);

	while(1)
	{
		asm nop
	}

}
