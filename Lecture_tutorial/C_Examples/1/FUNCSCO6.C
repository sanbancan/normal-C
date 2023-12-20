// concept of global variable ;  scope / visibility  of variable ; static storage class
// auto , static , extern , register

#include<stdio.h>

int glob_i=100;                      // scope as long as program is executing visiblity global
int add(int , int);

int main()
{
   int i,j,k;
   i=10;
   j=20;

   k=add(i,j);
   printf("\n first sum  is %d",k);                       //  30
   printf("\n global is %d",glob_i);

   getch();
   k=add(i,j);													 //  30
   printf("\n second sum  is %d",k);
   printf("\n global is %d",glob_i);

   getch();
   k=add(i,j);
   printf("\n third sum  is %d",k);
   printf("\n global is %d",glob_i);
}


 int add(int i,int j)
 {
	auto int m,cnt=0;			          // scope as long as function is executing visibilty is local
	static int stat=0;                       // scope as long as program is executing visibility is local

	glob_i++;
	printf("\n \n in add");

	m=i+j;

	i++;
	j++;
	stat++;
	cnt++;

	printf("\n stat is %d",stat);               // persists because it is static
	printf("\n cnt is %d" ,cnt);               // evaporates because it is auto
    printf("\n glob is %d" ,glob_i);       //  persists because it is global
	printf("\n i is %d",i);                        // local copy
	printf("\n j is %d",j);                        // local copy
	printf("\n leaving add \n \n");
	return(m);

 }


