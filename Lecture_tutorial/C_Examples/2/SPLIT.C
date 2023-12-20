#include<stdio.h>

main()
{
    unsigned int i,temp;
    char lo_byte,hi_byte;

    int calc;

    printf("\n enter a nr : ");
    scanf("%d",&i);

//     Splitting the integer
    printf("\n you entered 0x%x",i);

    lo_byte=i;
    hi_byte=i>>8;

    temp=lo_byte;
    printf("\n lo_byte is 0x%x",temp);

    temp=hi_byte;
    printf("\n hi_byte is 0x%x",temp);

//    Splicing it back together again

    calc=(((hi_byte<<8)|0x00ff)&(lo_byte|0xff00));
//    note  the bit operator "&" which is different from the
//    conditional operator "&&"

//    lo_byte | ff00  :: ff(lo_byte)
//    hi_byte | 00ff  :: (hi_byte)ff
//    (hi_byte)ff & ff(lo_byte) :: (hi_byte)(lo_byte)
//    In SPJ newer version we have to declare hi_byte as int , why ??



    printf("\n calc is : 0x%x or %d",calc,calc);

}






