#include "push_swap.h"

//first element becomes last
void rotate(node **head)
{
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    node *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = *head;
    (*head)->prev = last;
    *head = (*head)->next;
    (*head)->prev = NULL;
    last->next->next = NULL;
}