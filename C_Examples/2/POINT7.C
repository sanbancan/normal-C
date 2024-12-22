/* This will call a function, here display the current value
   change the current value
   All using pointers */

#include<stdio.h>

main()
{
	int stud[4][3]={
			{11,12,13},
			{21,22,23},
			{31,32,33},
			{41,42,43},
		       };
	int i,j;
	int *ptr;
	ptr = stud;

	changer(&ptr);

	for(i=0;i<=3;i++)
	{
	  printf("\n");
	  for(j=0;j<=2;j++)
	  printf(" %d",stud[i][j]);
	}
}

changer(int **ptr)
	{
		int row,col;
		int value;

		printf("\n enter row  0~2:");
		scanf("%d",&row);
		printf("\n enter col  1~3:");
		scanf("%d",&col);
		value=*(*ptr+(((row*3)+col)-1));
		printf("\n current value is %d",value);
		printf("\n enter new value");
		scanf("%d",&value);
		*(*ptr+(((row*3)+col)-1))=value;

	}

