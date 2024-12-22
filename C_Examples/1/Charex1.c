#include<stdio.h>

//  this example shows that arithmetic operations can be done on any variable that is specified as char

main()
{
	char ch1;
	char ch2;

	ch1='a';
	ch2=ch1+1;                                    				// is this valid ???
	printf("ch1 is %d ch2 is %c",ch1,ch2);

}