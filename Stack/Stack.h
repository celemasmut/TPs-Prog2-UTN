#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct
{
    int*data;
    int valid;
    int dim;
}Stack;

void initStack(Stack *p);
void push(Stack*p,int value);
int pop(Stack*p);
int top(Stack p);
int emptyStack(Stack p);
void showStack(Stack p);

#endif // STACK_H_INCLUDED
