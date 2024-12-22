#include<stdio.h>

main()
{
	char *names[3];
	char *names1;
	int i;
	char str_array[20];
	printf("\n Ptr is %d",sizeof(str_array));
	printf("\n Names is %d",sizeof(names));

	for(i=0;i<3;i++)
       {
		printf("\n Enter Name");
		scanf("%s",str_array);
		names[i]=(char *)malloc(sizeof(str_array));
		strcpy(names[i],str_array);
       }

       printf("\n out of loop");
       for(i=0;i<3;i++)
       printf("\n %s",names[i]);

}