#include<stdio.h>

main()
{
	int *p;
	int d=10;

	printf("\n value of d id %d",d);

	p=&d;
	printf("\n value of p is 0x%x",p);
	printf("\n input a value : ");
	scanf("%d",p);               // note the absence of &
	printf("\n %d",*p);
	printf("\n %d",d);

	*p++;   	// We have changed the position of the pointer
	printf("\n changed value of p is 0x%x",p);
	printf("\n value stored in p (JUNK) : %d ",*p);  // garbage value
	printf("\n value of d is  %d",d);                 // ok value

	*p--;            		     // bring it back
	printf("\n value of p is back to 0x%x",p);
	printf("\n value stored in p %d",++(*p)); // increment by1

	printf("\n value of d is %d",d);
}

