#include<stdio.h>
#include<stdlib.h>

unsigned int setbits(unsigned int x, unsigned int p, 
                     unsigned int n, unsigned int y)
{
    /*
     *Don't ever try shifting of type length, undefined behavior in C/C++
     */
    return ( x & ~((~0ul<<(p+1))^(~0ul<<(p+1-n))) ) ^ ( (y<<(p+1-n)) & ~(~0ul<<(p+1)));
}

unsigned int invert(unsigned int x, unsigned int p,
                    unsigned int n)
{
    return x ^ ((~0ul<<(p+1))^(~0ul<<(p+1-n)));
}

unsigned int rightrot(unsigned int x, unsigned int n)
{
    return (x >> n) ^ (x << ((unsigned int)(sizeof(int))*8-n) );
}

int main()
{
    /******************* 2-6 *****************/
    struct test_a {unsigned int x; unsigned int p; 
                   unsigned int n; unsigned int y;};

    struct test_a test_set_a[5] = { 0xF5F4F59F, 7, 8, 0xFFFFFFB4,
                                    0xFFF4F7F5, 0, 0, 0xDEADBEE3,
                                    0xBBFBFFFF, 30,0, 0xDEADBEE2, 
                                    0xDEADBEEF, 31,8, 0xDEADBEEF,
                                    0xDEADBEEF, 29,7, 0xDEADBEEF};

    for(int i=0; i<5; ++i)
        printf("%x\n", setbits(test_set_a[i].x, test_set_a[i].p,
                               test_set_a[i].n, test_set_a[i].y) );

    /*printf("%d\n", 0xFFFFFFFF3FFFFFFF);*/

    /******************* 2-7 *****************/

    for(int i=0; i<5; ++i)
       printf("%x\n", invert(test_set_a[i].x, test_set_a[i].p,
                             test_set_a[i].n) );
   

    /******************* 2-8 *****************/
    for(int i=0; i<5; ++i)
       printf("%x\n", rightrot(test_set_a[i].x, test_set_a[i].n));

 
    return 0;
}
