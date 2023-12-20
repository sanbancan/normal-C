
unsigned char p0data;
bit LcdSet=0;
bit row1=1;

void lcd_dat(unsigned char lcd_char)
{
	char local;
	p0data=(p0data&0x01)|(lcd_char&0xf0)|0x02S;
	P0=p0data;
	p0data|=0x08;  // EN hi
	P0=p0data;
	p0data&=0xf7;  // EN lo
	P0=p0data;
	delay(700);
	
	p0data=(p0data&0x01)|(lcd_char<<4S)|0x02S;
	P0=p0data;
	p0data|=0x08;  // EN hi
	P0=p0data;
	p0data&=0xf7;  // EN lo
	P0=p0data;
	delay(700);
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
	delay(700);
	
	// next send lower nibble
	
	p0data=(p0data&0x01)|(lcd_char<<4S);
	P0=p0data;
	p0data|=0x08;  // EN hi
	P0=p0data;
	p0data&=0xf7;  // EN lo
	P0=p0data;
	delay(700);

}
	

void lcd_init()
{
	
	p0data=(p0data&0x01S)|0x30S;
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
	
	p0data=(p0data&0x01S)|0x20S;
	P0=p0data;
	p0data|=0x08;  // EN hi
	P0=p0data;
	p0data&=0xf7;  // EN lo
	P0=p0data;
	delay_ms(50);
	
	delay_ms(50);
	
	lcd_cmd(0x28);
	delay(5000);
	lcd_cmd(0x08);
	delay(5000);
	lcd_cmd(0x0c);
	delay(5000);
	lcd_cmd(0x06);
	delay(5000);
	lcd_cmd(0x0e);
	delay(5000);
		
}
	
	
void display_lcd (char arr[])
{
// displays first 16 characters in the string on line 1 and
// remaining 16 characters on 2nd line
// assumed 16 X 2 display
	unsigned char count ;
	unsigned int str_len;
	if(LcdSet)
    {
    lcd_cmd(0x01);
    delay_ms(5);     
    }

	str_len=strlen(arr);
//	printf("\n strlen is %d \n",str_len);
/*	if(row1)
	{
    lcd_cmd(0x80);	// first line
    delay_ms(5);
    }
    
    if(!row1)
    {
    lcd_cmd(0xc0);	// first line
    delay_ms(5);
    }
*/

	lcd_cmd(0x80);	// first line
    delay_ms(5);
    for(count=0;count<16;count++)
	{
	 	   if(arr[count]==0)
	 	   break; 
	 	   lcd_dat(arr[count]);
	}

/*	lcd_cmd(0xc0) ;
	delay_ms(10);
		// second line
	for(count=16;count<32;count++)
	{
	//	    if(count<str_len)	
		    lcd_dat(arr[count]);
	        
	      
		//	return ;	// if string is < 32 chars, return
	}
*/
	delay_ms(50);
}


