#include<stdio.h>

// internally all array identifiers are converted to pointers
// most of the issues are covered in "point3.c"
main()
{
    int arr[5]={1,2,3,4,5};
    int *p;
    int i=0;
    p=arr;

    while(i<5)
    {
	printf("\n p address is %u  arr address is %u",arr,p);
	printf("   value is %d",arr[i]);
	printf("   %d",*p);
	printf("   %d",*(arr+i)); // addition is associative
	printf("   %d",i[arr]);
	// arr++;
	i++;
	p++;
    }

}
// so when to choose array notation or pointer notation ??


