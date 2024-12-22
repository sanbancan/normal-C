#include<stdio.h>

main()
{
      int stud[4][3]={
			{11,12,13},
			{21,22,23},
			{31,32,33},
			{41,42,43},
		       };

      printf("\n %u",stud);
      // base address of array
      printf("\n %u",*stud);
      // address zeroth row , zeroth column :: base address
      printf("\n %d",**stud);
      // value of element at zeroth row,column
      printf("\n %u",*(stud+1));
      printf("\n %u",*(*(stud+1)));
      // value of first element second column

     //  stud++;
     //  how to print the element at zeroth row , first column ?
     //  how to print the element at first row , first column ?



     printf("\n %d",*(*stud+1));
     printf("\n %d",*(*(stud+1)+1));

}