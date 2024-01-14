#include "push_swap.h"
#include <stdlib.h>

node* append_to_empty(node *head, int i)
{
    node *temp = malloc(sizeof(node));
    temp->prev = NULL;
    temp->index = i;
    temp->next = NULL;
    head = temp;
    return head;
}

node* append_to_end(node *head,int i)
{
    if(head == NULL)
    {
        return append_to_empty(head,i);
    }
    node *temp,*tp;
    temp = malloc(sizeof(node));
    temp->prev = NULL;
    temp->index = i;
    temp->next = NULL;
    tp = head;
    while(tp->next != NULL)
    {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
}

// node * append_to_start(node *head, int i);