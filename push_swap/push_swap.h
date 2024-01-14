#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

//** INCLUDES **
#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"

//** DOUBLY LINKED LIST **
typedef struct node
{
	long long data;
	size_t index;
	struct node* next;
	struct node* prev;
}node;

// ** FUNCTION PROTOTYPES **
node* append_to_end(node *head,int i);
node* append_to_empty(node *head, int i);
#endif
