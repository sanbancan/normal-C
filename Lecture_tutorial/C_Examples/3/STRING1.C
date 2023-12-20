#include<stdio.h>

main()
{
	char str[]="hello thomas how are you";
	char ch,*ptr;
	int i;
	ptr=str;

	printf("\n %s\n",ptr);

	scanf("%s",ptr);
	// will work and output properly , but not reliable and gauranteed
	printf("\n %s",str);

	for(i=0;i<5;i++)
	{
	 str[i]='D';
	}

   //	str[i]='\0';
	printf("\n %s",str);

}
