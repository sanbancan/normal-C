#include<stdio.h>

void swap(int , int);
void swap1(int *,int *);

main()
{
	int i=10,j=20;
	int *p,*k;

	p=&i;
	k=&j;

	printf("\n passed by value");
	swap(i,j);       // pass by value
	printf("\n i is %d, j is %d",i,j);

	printf("\n passed by reference");
	swap1(p,k);
	// pass by reference, passing addresses of i , j
	/* Whenever you need to change a value in a called function
	   pass its reference pointer */
	printf("\n i is %d, j is %d",i,j);

}

void swap(int i,int j)
{
  int temp;
  temp=i;
  i=j;
  j=temp;
}

void swap1(int *p1,int *k1)
{
   int temp;
   temp=*p1;
   *p1=*k1;		 // writing to address location of i and j
   *k1=temp;
}
