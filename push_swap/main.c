#include "push_swap.h"
#include <stdlib.h>
int main(void)
{
	node *head = malloc(sizeof(node));
	node *tail = malloc(sizeof(node));
	head->prev = tail;
	head->next = tail;
	head->data = 1;
	tail->prev = head;
	tail->next = head;
	tail->data = 2;
	
	printf("%d",head->next->data);
	return EXIT_SUCCESS;
}

