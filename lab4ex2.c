#include <stdio.h>
#define MAXVAL 100   

int val[MAXVAL];
int sp = 0;

int getop()
{
    if (sp > 0)
        return val[sp - 1];
    printf("error: stack empty\n");
    return -1;
}

int pop()
{
    if (sp > 0)
        return val[--sp];
    printf("error: stack empty\n");
    return -1;
}

void push(int value)
{
    if (sp < MAXVAL)
        val[sp++] = value;
    else
        printf("error: stack full, can't push %d\n", value);
}

void copy_top()
{
    if (sp > 0 && sp < MAXVAL)
    {
        val[sp] = val[sp - 1];
        sp += 1;
    }
    else if (sp == 0)
        printf("error: stack is empty\n");
    else
        printf("error: stack full, can't copy\n");
}

void exchange_top2()
{
    int temp;
    if (sp >= 2) {
        temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    }
    else
        printf("error: stack doesn't have two elements\n");
}

void clear_stack()
{
    sp = 0;
}

void print_stack()
{
    printf("stack content is:");
    for (int i = 0; i < sp; i++)
    {
        printf("%d ", val[i]);
    }
    printf("\n");
}

int main() {
    for (int i = 0; i < 10; i++)
    {
        push(i);
    }

    print_stack();
    printf("stack top is %d \n", getop());
    printf("print stack top and delete it from stack: %d\n", pop());
    printf("exchange stack top two elements\n");
    exchange_top2();
    print_stack();
    printf("print stack top and delete it from stack: %d\n", pop());
    printf("print stack top and delete it from stack: %d\n", pop());
    printf("copy stack top element\n");
    copy_top();
    printf("stack top is %d\n", getop());
    print_stack();
    printf("clear stack\n");
    clear_stack();
    printf("try to get stack top\n");
    getop();
    return 0;
}
