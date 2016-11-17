/*===============================================================*/
/*| INTEGER TO STRING, MACHINE INDEPENDENT, CORRECT FOR INT_MIN |*/
/*===============================================================*/

#include<stdio.h>

void reverse(char s[])
{
    int i;
    for(i=0; s[i]!='\0'; ++i)
        ;
    for(int j=0; j<=(i-1-j); ++j)
    {
        char temp = s[j];
        s[j] = s[i-1-j];
        s[i-1-j] = temp;
    }
}


/*
 *assume on every machine the expression x and (unsigned int)x has the same binary content
 *
 *use all these fucking unsigned constants to ensure machine independent behavior 
 *actually no need for my environment!!!!!!!!!!!!!
 */
void itoa(int n, char s[])
{
    int sign;
    unsigned int m;

    /*
     *get the two's complement of n manually, 
     *store it as an unsigned integer,
     *to ensure correct behavior even when 
     *n = INT_MIN
     */
    if( (sign=n)<0 )
        m = ~((unsigned int)n) + 1u; 
    else 
        m = n;


    int i=0;
    do{
        s[i++] = m%10u + 48u;
        m /= 10u;
    }while(m!=0u);
    
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}


int main()
{
    int test_integer[5] = { 0x80000000,
                            128,
                            0x7FFFFFFF,
                            -77900909,
                            0 };
    for(int i=0; i<5; ++i)
    {
        char s[20];
        itoa(test_integer[i], s);
        printf("%d,  %s\n", test_integer[i], s);
    }


    return 0;
}
