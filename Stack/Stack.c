#include "Stack.h"

void initStack(Stack *p)
{
    p->data=malloc(sizeof(int)*50);//genero arreglo dinamico
    p->valid=0;
    p->dim=50;
}
void push(Stack*p,int value)
{
    if(p->valid == p->dim)//verifico si el arreglo no tiene mas espacio
    {
        p->dim+=50;//aumenta dimension a gusto
        p->data=realloc(p->data,sizeof(int)*p->dim);
    }
    p->data[p->valid]=value;//agrego el dato
    p->valid++;// aumento validos
}
int pop(Stack*p)
{
    int aux = p->data[p->valid-1];//tomo en aux el ultimo valor
    p->valid--;//resto uno a validos
    return aux;
}
int top(Stack p) //pila como copia
{
    return p.data[p.valid-1];
}
int emptyStack(Stack p)
{
    int flag=1;
    if(p.valid >0)
    {
        flag=0;
    }
    return flag;
}
void showStack(Stack p)
{
    int i;
    for(i=0;i<p.valid;i++)
    {
        printf("-%d-", p.data[i]);
    }
}
