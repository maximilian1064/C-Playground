#include<stdio.h>
enum boolean {false,true};

void squeeze(char s1[], char s2[])
{
    int i,j;
    for(i=j=0; s1[i]!='\0'; ++i)
    {
        int k;
        int flag = false;
        for(k=0; s2[k]!='\0'; ++k)
            if(s1[i]==s2[k])
            {
                flag = true;
                break;
            }
        if(!flag)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

int main()
{
    char test_set[][8] = { "hello", "world", "hallo!", "welt",
                            "bonjour", "la", "vie", "latin" };
    char reference[] = "lwab";
    int i;
    for(i=0; i<8; ++i)
    {
        printf("%s ",test_set[i]);
        squeeze(test_set[i], reference);
        printf("%s\n",test_set[i]);
    }

    /*
     *char test[] = "hello";
     *test[5] = '!';
     *int a = 7;
     *printf("%8x\n",&a);
     *test[6] = '-';
     *test[a] = '\0';
     *printf("%8x\n", &test);
     *printf("%8x\n", &test[7]);   
     */

    return 0;
}
