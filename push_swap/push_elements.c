#include "push_swap.h"

void push(node **src, node **dest)
{
    node *temp;
    if (*src == NULL)
        return;
    temp = (*src)->next;
    (*src)->next = *dest;
    *dest = *src;
    *src = temp;
}