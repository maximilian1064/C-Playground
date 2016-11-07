/* 
 * THE C PROGRAMMING LANGUAGE
 *
 * Exercise 2-1. Write a program to determine the ranges of char , short , int , and long
 * variables, both signed and unsigned , by printing appropriate values from standard headers
 * and by direct computation. Harder if you compute them: determine the ranges of the various
 * floating-point types.
 *
 *
 * Format of signed integer here, based on two's complement
 * 0x00000000 --- 0x7FFFFFFF ---> 0 --- 2^31-1
 * 0x80000000 --- 0xFFFFFFFF ---> -2^31 --- -1
 * Get the length, then the range can be calculated
 *
 *
 */

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

    /* In current environment(hardware, OS, compiler), constant will be assigned automatically TYPE int, 
     * Thus expression with constant operand and with result exceeds the range of TYPE int will get a overflow,
     * Remember to mark the constant as TYPE long first with l/lu suffix
     * Especially important when deal with TYPE long variables
     */

    /*
     *long value = 0x7FFFFFFF * 0x0000FFFF;
     *printf("expression value: %ld\n", value);
     */


    /*FLOAT*/



    return 0;
}

