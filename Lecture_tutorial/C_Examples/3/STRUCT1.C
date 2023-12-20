#include<stdio.h>

// Why are structures required ??

main()
{
	struct account
	{
	  int acct_nr;
	  char acct_name[15];
	  float balance;
	};

	typedef struct account accnt;

	accnt a1,a2,a3;

	/*  Only now is the memory allocated for the objects !! This is a important feature of an array
	Hence the variables declared inside an array are not really variables , as memory is not assigned to them till the array is instantiated */

	printf("\n Enter acct nr, name , balance \n");
	scanf("%d %s %f",&a1.acct_nr,a1.acct_name,&a1.balance);
	printf("\n Next Record");
	scanf("%d %s %f",&a2.acct_nr,a2.acct_name,&a2.balance);
	printf("\n Next Record");
	scanf("%d %s %f",&a3.acct_nr,a3.acct_name,&a3.balance);
	printf("\n");

	printf("\n %d\t%s\t%f",a1.acct_nr,a1.acct_name,a1.balance);
	printf("\n %d\t%s\t%f",a2.acct_nr,a2.acct_name,a2.balance);
	printf("\n %d\t%s\t%f",a3.acct_nr,a3.acct_name,a3.balance);


}
