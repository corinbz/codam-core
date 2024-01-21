#include "push_swap.h"

// last element becomes first

void reverse_rotate(node **head)
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
    *head = last;
    last->prev->next = NULL;
    last->prev = NULL;
}