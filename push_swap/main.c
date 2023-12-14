#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void appendToStackA(node **a, int value) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        // Handle memory allocation error
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*a == NULL) {
        *a = newNode;
    } else {
        node *temp = *a;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main(int ac, char** av) {
    // Declare pointers to two data structures/linked lists, one for stack `a` and another for `b`
    // Set both pointers to NULL to avoid undefined behaviour and indicate we're starting with empty stacks
    node *a = NULL;
    node *b = NULL;

    // Handle input count errors. Argument count must be 2 or more, and the second input must not be empty
    // If input errors, return error
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    else if (ac == 2)
        av = ft_split(av[1], ' ');

    // Append each input number to stack `a`
    for (int i = 0; av[i] != NULL; i++) {
        int value = atoi(av[i]);
        appendToStackA(&a, value);
    }

    // Check if stack `a` is sorted
    // If not sorted, implement our sorting algorithm
    // ...

    // Clean up the stack
    // ...

    return (0);
}