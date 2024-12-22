#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

main()
{
	unsigned int inp,out;
	char str1[6];
	char str2[19]="The number is ";
	char str3[6]="Thomas";
	char str4[6]="Thomas";
	char *ptr;

	if(str3==str4)
	printf("\n EQUAL");
	else
	printf("\n NOT EQUAL");

	 //	str2=str1;      // Is this valid ??   Why or Why not ??

	printf("\n input a number");
	scanf("%d",&inp);

	itoa(inp,str1,10);
	printf("\n string is %s",str1);

	out=atoi(str1);
	printf("\n number is %d",out);

	if(strlen(str1)>4)
	printf("\n ERROR !!number too long");

	else
	{
	  strcat(str2,str1);
	  printf("\n %s",str2);
	}


}