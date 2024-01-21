#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

//** INCLUDES **
#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"
#include <limits.h>

//** DOUBLY LINKED LIST **
typedef struct node
{
	long long data;
	size_t index;
	struct node* next;
	struct node* prev;
}node;

// push
void push(node **src, node **dest);

// ** FUNCTION PROTOTYPES **

//* initializing stack
node* append_to_end(node *head,long long i);
node* append_to_empty(node *head, long long i);
node* append_to_start(node *head, long long i);

//** stack utils
size_t count_elements(node *head);
void assign_index(node *stack_a, int stack_size);
void display_index(node *head);
void ft_swap(node *head);
void display_elements(node *head);

// check valid input

int are_duplicates(char **av);

//algorithm stuff

int is_sorted(node *head);
void rotate(node **head);
void reverse_rotate(node **head);


#endif
