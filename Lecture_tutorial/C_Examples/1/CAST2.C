#include<stdio.h>
// Examples of explicit casting and promotion

void main()
{
	int c=10;
	float d=10.2,e;

	e=((int)(d)*c);              //  100   integer arithmetic
	printf("\n e is %f",e);

	e=(d*c);                     //  102   float arithmetic
	printf("\n e is %f",e);

	e=c/4;                       //   2.0   integer arithmetic
	printf("\n e is %f",e);

	e=(float)(c/4);              //   2.0  integer arithmetic
	printf("\n e is %f",e);      //   result is promoted to float

	e=(float)c/4;                //   2.5  float arithmetic
	printf("\n e is %f",e);

	e=c/4.0;                     //   2.5   float arithmetic
	printf("\n e is %f",e);

}
