/* n!  using  for  loop  */
# include <stdio .h>

 int  main ()
 {
  int i, n, f;
  char err_flag;
  printf (" Enter n: ");
  scanf ("%d", &n);
  f = 1;                           					 /* 0! */

	 for (i = 1; i <= n;i++)
	{
		 f *= i;                   					/* Now , f = i!  why is this better than  f=f * i  */
		if(f>1000)
		{
		 err_flag=1;
		 break;           // check what warning and what it means
		}
	}
  printf ("\n %d! = %d\n", n, f);

  if(err_flag=1 && n>7)
  printf("\n Value overflow Error");


 }
