#include <stdio.h>

/*for atof*/
#include <stdlib.h>

/*for isdigit*/
#include <ctype.h>

#define MAX_OP_SIZE  100
#define NUMBER       -10 
#define MAX_OP_NUMBER 10
#define MAX_BUF_SIZE  100
#define BUF_EMPTY    -1

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
                    printf("error: division by 0.0");
                break;
            case '*':
                push( pop() * pop());
                break;
            case '\n':
                printf("result:\t%.8g\n", pop());
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
        return c;

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
