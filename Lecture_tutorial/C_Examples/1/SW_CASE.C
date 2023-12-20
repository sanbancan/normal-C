    #include<stdio.h>

    #define ESC 27

    main()
    {
	int i;
	char ch;

	do
	{
	printf("\n Enter a number ( 1 ~ 3):");
	scanf("%d",&i);

		switch(i)
		{
		case 1:
		printf("\n You entered 1");
		break;
		case 2:
		printf("\n You entered 2");
		break;
		case 3:
		printf("\n You entered 3");
		break;
		}
	 fflush(stdin);
	 printf("\n Press 'Q' to quit");
	 scanf("%c",&ch);

	} while(ch!='Q');

 }