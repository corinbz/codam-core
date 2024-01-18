#include "push_swap.h"

void ft_swap(node *head)
{
    if(head == NULL || 
    (head->next == NULL && head->prev == NULL))
    {
        printf("head is empty or has 1 value");
        exit(1);
    }
    long long temp1;
    while(head->prev !=NULL)
        head = head->prev;
    temp1 = head->data;
    head->data = head->next->data;
    head->next->data = temp1;
}