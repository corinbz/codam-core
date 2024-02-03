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
        write(1,"pb\n",3);
    else
        write(1,"pa\n",3);
}