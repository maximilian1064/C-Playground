/*==================================================================================*/
/*| GET THE POSITION OF THE FIRST CHARACTER IN S1 THAT MATCHES ANY CHARACTER IN S2 |*/
/*==================================================================================*/

#include<stdio.h>
#include<string.h>
enum boolean {false,true};

int any(char s1[], char s2[])
{
    int i;
    for(i=0; s1[i]!='\0'; ++i)
    {
        int k;
        for(k=0; s2[k]!='\0'; ++k)
            if(s1[i] == s2[k])
                return i;
    }
    return -1;
}

int main()
{
    char test_set[][8] = { "hello", "world", "hallo!", "welt",
                            "bonjour", "la", "vie", "latin" };
    char reference[] = "wa";
    int i;
    for(i=0; i<8; ++i)
    {
        printf("%d ", strpbrk(test_set[i],reference) - test_set[i]);
        printf("%d\n",any(test_set[i], reference));
    }


    /*small test to relationship between array and pointer, more to learn*/

    printf("%16lx\t%16lx\t%16lx\n", *test_set, test_set[0], &test_set[0][0]);
    char* test1 = "test";
    char test2[] = "test";
    char test3[5] = "test";
    printf("%16lx\t%16lx\t%16lx\n", test1, test2, test3);

    char* test_set2[2] = { "hello", "world" };
    printf("%16lx\t%16lx\t%16lx\n", test_set2, test_set2[0], &test_set2[0][0]);   
    return 0;
}
