// illustrate using the while loop and the nested loop

# include <stdio .h>

 int main ()
 {
  float grade , sum ;
  int gradeCount ;
  int another ;

  do {
      sum = gradeCount = 0;

      printf("\n Negative value will quit\n");
      printf("Enter grade : ");
      scanf("%f", &grade);

	while ( grade >= 0.0)          // nesting of loop
	{
	  sum += grade ;
	  ++ gradeCount ;
	  printf ("Enter grade : ");
	  scanf ("%f", &grade );
	}

	printf ("Average : %f\n\n", sum / gradeCount );
	printf("\n 0 will quit");
	  printf (" Another class : ");
	  scanf ("%d", &another );
      } while ( another != 0);

  //   return 0;
}
