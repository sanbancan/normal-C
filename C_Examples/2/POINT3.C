// illustrate use of pointers in arrays.
// illustrate the concept of pointer to pointer

#include<stdio.h>

main()
{
	int a[5]={1,2,3,4,5};
	int i=0;
	int *ptr;
	ptr=a;      // note the absence of ampersand

	while(i<5)
	printf("\n a[%d]=%d",i++,i[a]);
	// WILL THIS GIVE AN ERROR ?? IF NOT WHY ??
	// a[i]=a+i;
	//associativity of pointer addition

	printf("\n");
	i=0;
	while(i<5)
	{
	  printf("\n a[%d]=%d",i++,*(ptr++));
	// note the precedence/parentheses of ptr
	}

	for(i=0;i<5;i++)
	display(&a[i]);

}

display(int *a)
{
	show(&a);
}
// write the function show to display the values passed.
// what will be type of receiving parameter ??

show(int **k)
{
	printf("\n value is %d",**k);
}

