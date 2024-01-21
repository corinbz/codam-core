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
    // Check if the list is empty or has only one element
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    // Traverse the list to find the last element
    node *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Rotate the list to the right
    last->next = *head;
    (*head)->prev = last;
    *head = last;
    last->prev->next = NULL;
    last->prev = NULL;
}