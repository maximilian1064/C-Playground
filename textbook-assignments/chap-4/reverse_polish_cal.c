#include <stdio.h>

/*for atof*/
#include <stdlib.h>

/*for isdigit*/
#include <ctype.h>

#define MAX_OP_SIZE   100
#define MAX_OP_NUMBER 10
#define BUF_EMPTY     -1

#define NUMBER              -10 

/*commands*/
#define DUPLICATE_STACK_TOP -20
#define SWAP_STACK_TOP      -30
#define PRINT_STACK_CONTENT -40
#define CLEAR_STACK         -50

/*command*/
char dup[] = "dup";
char swap[] = "swap";
char prStack[] = "print";
char clStack[] = "clear";
// function for retrieving command from input
int strMatching( char s1[], char s2[]);

/*get command, operands, operations from input, return command type*/

int getop( char s[]);
int getch();
void ungetch(int c);
int buf = BUF_EMPTY;  


/*stack for the reverse polish semantic*/

float operand_stack[MAX_OP_NUMBER];
// the stack pointer/index, point to next free location
int sp = 0; 
void push(float op);
float pop();


int main()
{
    char s[MAX_OP_SIZE];
    int type;
    float op2;
    
    while( (type = getop(s)) != EOF )
    {
        switch (type) 
        {
            case NUMBER:
                push( atof(s));
                break;
            case DUPLICATE_STACK_TOP:
                if(sp)
                    push( operand_stack[sp-1]);
                else
                    printf("error: stack empty\n");
                break;
            case SWAP_STACK_TOP:
                if(sp>1)
                {
                    float t1=pop();
                    float t2=pop();
                    push(t1);
                    push(t2);
                }
                else
                    printf("error: insufficient items for swap\n");
                break;
            case CLEAR_STACK:
                sp = 0;
                break;
            case PRINT_STACK_CONTENT:
                for(int i=sp-1; i>=0; --i)
                    printf("Top-%d:\t%.8g\n",sp-i-1, operand_stack[i]);
                break;
            case '+':
                push( pop() + pop());
                break;
            case '-':
                op2 = pop();
                push( pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push( pop()/op2);
                else
                    printf("error: division by 0.0\n");
                break;
            case '*':
                push( pop() * pop());
                break;
            case '\n':
                /*print stack top without popping*/
                if(sp)
                    printf("result:\t%.8g\n", operand_stack[sp-1]);
                else
                    printf("error: stack empty\n");
                break;
            default:
                printf("error: unknown command%s\n", s);
                break;
        }
    }
    return 0;
}

int getop( char s[])
{
    int c,i=0;
    while( (s[0]=c=getch()) == ' ' || c == '\t' )
        ;
    s[1] = '\0';

    if( !isdigit(c) && c!='.' )
    {
        /*searching for command*/
        if( c<='z' && c>='a')
        {
            while( (s[++i]=c=getch()) <= 'z' && c>= 'a')
                ;
            s[i] = '\0';
            if(c!=EOF)
                ungetch(c);
            
            if( strMatching(s, dup))
                return DUPLICATE_STACK_TOP;
            else if( strMatching(s, swap))
                return SWAP_STACK_TOP;
            else if( strMatching(s, clStack))
                return CLEAR_STACK;
            else if( strMatching(s, prStack))
                return PRINT_STACK_CONTENT;
            else 
                return s[0];
        }
        else
            // return possible operators
            return c;
    }

    /*searching for number*/
    i = 0;
    if( isdigit(c) ) 
        while( isdigit(s[++i]=c=getch()) )
            ;

    if( c=='.' )
        while( isdigit(s[++i]=c=getch()) )
            ;

    s[i] = '\0';

    if(c!=EOF)
        ungetch(c);

    return NUMBER;
}

int strMatching(char s1[], char s2[])
{
    int i=-1;
    while( s1[++i]!='\0' && s2[i]!='\0' && s1[i]==s2[i] )
        ;
    return ( s1[i]=='\0' && s2[i]=='\0')? 1 : 0; 
}

int getch()
{
    if( buf != BUF_EMPTY)
    {
        int temp = buf;
        buf = BUF_EMPTY;
        return temp;
    }
    else
    {
        return getchar();
    }
}

void ungetch(int c)
{
    buf = c;
}


void push(float op)
{
    if(sp < MAX_OP_NUMBER)
        operand_stack[sp++] = op;
    else
        printf("error: operand stack full, can't push\n");
}

float pop()
{
    if(sp > 0)
        return operand_stack[--sp];
    else
    {
        printf("error: operand stack empty\n");
        return 0.0;
    }
}
