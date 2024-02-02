#include "push_swap.h"

//first element becomes last
void rotate(node **head)
{
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    node *last = get_last(*head);
    last->next = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    last->next->prev = last;
    last->next->next = NULL;
    write(1, "ra\n", 3);
}