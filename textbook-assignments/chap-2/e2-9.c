/*===============================*/
/*| COUNT THE 1-BITS OF INTEGER |*/
/*===============================*/

/*
 *x&(x-1) deletes the rightmost 1-bit of x
 *
 *REASON: 
 *x: [left bits][rightmost 1-bit][0-bits]
 *x-1: x+0xFFFFFFFF
 *   [left bits][   0-bit       ][1-bits]
 *x&(x-1):
 *   [left bits][   0-bit       ][0-bits]
 */

#include<stdio.h>

int bitcount (int x)
{
    int b;
    for(b=0; x||0; ++b) { x &= x-1; }
    return b;
}

int main()
{
    int test_set[5] = { 0xF5F4F59F,
                        0xFFFFFFFF,
                        0xBBFBFFFF,
                        0x00000000,
                        0xDEADBEEF };

    for(int i=0; i<5; i++)
        printf("%8x, %2d\n", test_set[i], bitcount(test_set[i]) );


    return 0;
}
