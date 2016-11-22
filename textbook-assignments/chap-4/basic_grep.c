/*========================================
| BASIC UNIX GREP, SELF IMEPLEMENTED   |
| SEARCH PATTERN IN INPUT, PRINT LINES | 
| CONTAIN THE PATTERN AND THE POSITION |
| OF PATTERNS IN THE INPUT LINES       |
========================================*/

#include<stdio.h> 

// maximum input length
#define MAX_SIZE 1000
#define MAX_PATTERN_SIZE 100

void getInput( char input[], int lim);
int custom_getline( char s[], char input[], int lineEnd);
int stringIndex( char s[], char pattern[]);

int main()
{
    char input[MAX_SIZE];
    char s[MAX_SIZE];
    char pattern[MAX_PATTERN_SIZE];

    /*get pattern*/
    printf("Input your pattern:\n");
    getInput( pattern, MAX_PATTERN_SIZE);

    /*get input*/
    printf("\nInput your lines:\n");
    getInput( input, MAX_SIZE);
    printf("\n");
    
    /*Get lines and print matched lines*/
    int lineEnd = 0;
    int found = 0;
    int rightmost_pos;

    while( lineEnd != -1 )
    {
        lineEnd = custom_getline(s, input, lineEnd);
        rightmost_pos = stringIndex(s, pattern); 

        if(rightmost_pos != -1 )
        {
            printf("%d::%s",rightmost_pos, s);
            found++;
        }
    }

    /*some legacy*/
    return found;

}

void getInput(char input[], int lim)
{
    char c;
    int i=0;
   
    while( --lim>0 && (c=getchar())!=EOF )
        input[i++] = c;
    input[i] = '\0';
}

int custom_getline(char s[], char input[], int lineEnd)
{
    char c;
    int i=0;

    while( (c=input[lineEnd++])!='\0' && c!='\n')
        s[i++] = c;
    s[i++] = '\n';
    s[i] = '\0';
   
    if(c == '\0')
        return -1;
    else 
        // return line End for getting another line in Input
        return lineEnd;
}

int stringIndex( char s[], char pattern[])   
{
    int i=0;

    // the rightmost position of occurence of pattern, to be returned
    // if returns -1, no pattern is found 
    int rightmost_pos = -1;

    // holds the last valid position of occurence of pattern
    // if remains -1, pattern is not yet found
    int old_pos = -1;

    while( s[i++]!='\0')
    {
        int k=1;

        // begin matching if 1st charater matched
        if( s[i-1]==pattern[0])
        {
            rightmost_pos = i-1;
            while( s[i]!='\0' && pattern[k]!='\0' && s[i++]==pattern[k++] )
                ;
            
            // update old position if new occurence found
            // otherwise set the rightmost position value back to the old position 
            if(s[i-1]==pattern[k-1] && pattern[k]=='\0')
            {
                // print newly searched pattern
                printf("%d::",rightmost_pos);
                old_pos = rightmost_pos;
            }
            else
                rightmost_pos = old_pos;
        }
    }
    return rightmost_pos;    
}
