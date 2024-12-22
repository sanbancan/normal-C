#include<stdio.h>
// why use two Dim arrays ??
// when you want to group the elements of an array into convenient sub sets
// PID values : Kp,Ki,Kd for example

void main()
{
	int two_dim[4][3]={
			{11,12,13},
			{21,22,23},
			{31,32,33},
			{41,42,43},
		       };
	int i,j;

	for(i=0;i<4;i++)
	{
	  printf("\n");
	  for(j=0;j<3;j++)         // NESTED for loop
	  printf(" %d",two_dim[i][j]);
	}

}




