#include "push_swap.h"

void push(node **src, node **dest, char a)
{
    node *temp;
    if (*src == NULL)
        return;
    temp = (*src)->next;
    (*src)->next = *dest;
    *dest = *src;
    *src = temp;
    if(a == 'b')
        printf("pb\n");
    else
        printf("pa\n");
}