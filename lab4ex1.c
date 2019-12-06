#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100 
#define NUMBER '0'   
#define MAXVAL 100 
#define BUFSIZE 100  

int getop(char []);
void push(double);
double pop(void);


int sp = 0;

int main() {
    int type;
    double op1, op2;
    char s[MAXOP];
    
    while((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
				op2 = pop();
				op1 = pop();
                push(op1 - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero mod\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    printf("error: stack empty\n");
    return 0.0;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetchar(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetchar: too many characters\n");
    else
        buf[bufp++] = c;
}

int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
    if (c == '-')
    {
        s[++i] = c = getch();
        if (!isdigit(c))
        {
            ungetchar(c);
            return '-';
        }
    }
    if (isdigit(c))
        while(isdigit(s[++i] = c = getch()));
    if (c == '.')
        while(isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetchar(c);
    return NUMBER;



