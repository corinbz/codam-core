#include "push_swap.h"

// last element becomes first

/**
 * Reverses the order of a linked list by rotating it to the right.
 * The last element becomes the new head of the list.
 *
 * @param head A pointer to the head of the linked list.
 */
void reverse_rotate(node **head)
{
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    node *last = get_last(*head);
    last->prev->next = NULL;
    last->prev = NULL;
    last->next = *head;
    *head = last;
    last->next->prev = last;
    write(1, "rra\n", 4);
}