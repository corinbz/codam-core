#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

//** INCLUDES **
#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"
#include <limits.h>
#include <unistd.h>
#include <stdbool.h> // Include the necessary header file to define the "bool" type

//** DOUBLY LINKED LIST **
typedef struct node
{
	long data;
	size_t index;
	struct node* next;
	struct node* prev;
}node;

//error hadling
void display_error(void);
// push
void push(node **src, node **dest, char a);

// ** FUNCTION PROTOTYPES **

//* initializing stack
node* append_to_end(node *head,long i);
node* append_to_empty(node *head, long i);
node* append_to_start(node *head, long i);

//** stack utils
size_t count_elements(node *head);
void assign_index(node *stack_a, int stack_size);
void display_index(node *head);
void swap(node **head);
void display_elements(node *head);
node *get_last(node *head);

// check valid input

int are_duplicates(char **av);

//algorithm stuff

bool	stack_sorted(node *stack);
void rotate(node **head);
void reverse_rotate(node **head);
node	*find_min(node *stack);
node	*find_max(node *stack);
void sort_three(node **a);
void sort_four(node **a,node **b);
void sort_five(node **a,node **b);

// radix sort

int check_max_bits(node **stack);
void radix_sort(node **a,node **b);
#endif
