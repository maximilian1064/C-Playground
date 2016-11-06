#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    /*INTEGER*/
    int length = 0;
    unsigned char c_base = 1;
    unsigned short s_base = 1;
    unsigned int i_base = 1;
    unsigned long l_base = 1;

    while(c_base)
    {
        length++;
        c_base <<= 1;
    }
    printf("range of unsigned char: 0 - %lu\n", (unsigned long)((1<<length)-1) );
    printf("range of signed char: %ld - %ld\n", (long)(-(1<<length-1)), (long)((1<<length-1)-1) );  

    length = 0;
    while(s_base)
    {
        length++;
        s_base <<= 1;
    }
    printf("range of unsigned short: 0 - %lu\n", (unsigned long)((1<<length)-1) );
    printf("range of signed short: %ld - %ld\n", (long)(-(1<<length-1)), (long)((1<<length-1)-1) );  


    length = 0;
    while(i_base)
    {
        length++;
        i_base <<= 1;
    }
    printf("range of unsigned int: 0 - %lu\n", (unsigned long)((1lu<<length)-1) );
    printf("range of signed int: %ld - %ld\n", (long)(-(1<<length-1)), (long)((1<<length-1)-1) );  



    length = 0;
    while(l_base)
    {
        length++;
        l_base <<= 1;
    }
    printf("range of unsigned long: 0 - %lu\n", (1lu<<length-1) + ((1lu<<length-1)-1) );
    printf("range of signed long: %ld - %ld\n", -(1l<<length-2) - (1l<<length-2) , (1l<<length-2) + ((1l<<length-2)-1) );  

    /*FLOAT*/



    return 0;
}

