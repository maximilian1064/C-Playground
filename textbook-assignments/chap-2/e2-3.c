/*====================================*/
/*| HEX STRING TO INTEGER CONVERSION |*/
/*====================================*/

#include <stdio.h>
#include <stdbool.h>

int htoi(char s[])
{
    unsigned int sum=0;


    /*Transform all characters to lower case*/

    /*
     *Don't modify the content of char* string, it is stored in read-only memory WTF, 
     *Anyway, I love C and Memory ;-D
     */

    /*
     *for(int i=0; (s[i]<='9' && s[i]>='0') 
     *             || (s[i]<='f' && s[i]>='a') 
     *             || (s[i]<='F' && s[i]>='A') 
     *             || ( (s[i]=='x' || s[i]=='X') && i==1 );
     *             ++i)
     *{
     *   if( (s[i]<='F' && s[i]>='A') || (i==1 && s[i]=='X') )
     *       s[i] += 32[>'a' - 'A'<];
     *}
     */


    /*Detect possible 0x or 0X prefix*/

    int starting_point;
    if(s[0]=='0' && (s[1]=='x' || s[1]=='X') )
        starting_point = 2;
    else
        starting_point = 0;

    for(int i=starting_point; (s[i]<='9' && s[i]>='0') 
                              || (s[i]<='f' && s[i]>='a')
                              || (s[i]<='F' && s[i]>='A');
                              ++i)
        sum = sum*16 + s[i] - ( (s[i]<='9' && s[i]>='0')? 48: ( (s[i]<='f' && s[i]>='a')?87:55) );

    return (int) sum;

}

int main()
{
    char* test_set[12] = {"0x0000000f","0X000000ff","0x00000fff",
                          "0x0000ffff","0x000fffff","0x00fFFFff",
                          "0X0Fffffff","0xFFffffff","0Fffffff",
                          "kx99999999","999kx99999","0Xffxxxx"};

    int reference[12] = {0x0000000f,0x000000ff,0x00000fff,
                         0x0000ffff,0x000fffff,0x00ffffff,
                         0x0fffffff,0xffffffff,0x0fffffff,
                         0,0x999,255};

    bool test_result = true;
    int test_temp;
    
    for(int i=0; i<12; ++i)
    {
        test_temp = htoi(test_set[i]);
        if( test_temp!=reference[i] )
        {
            test_result = false;
            printf("test %d failed\n", i);
            break;
        }
        printf(" TEST_SET: element %2d: %15d (DEC),\t%10x (HEX)\n",i,test_temp,test_temp);
        printf("REFERENCE: element %2d: %15d (DEC),\t%10x (HEX)\n",i,reference[i],reference[i]);

    }

    if(test_result)
        printf("\nall test passed\n");
    else
        printf("test failed\n");

    return 0;

}
