#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
    Stack primera;
    initStack(&primera);

    push(&primera,5);
    push(&primera,8);
    push(&primera,3);
    push(&primera,9);
    printf("\nPila: ");
    showStack(primera);

    printf("\n\n Se desapila...\n");
    pop(&primera);

    printf("\n El tope es: %d",top(primera));
    printf("\n\nPila vacia? 1=si / 0=no : %d\n\n",emptyStack(primera));
    return 0;
}
