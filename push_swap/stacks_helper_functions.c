#include "push_swap.h"

node* append_to_empty(node *head, long i)
{
    node *temp = malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = i;
    temp->next = NULL;
    head = temp;
    return head;
}

node* append_to_end(node *head,long i)
{
    if(head == NULL)
    {
        return append_to_empty(head,i);
    }
    node *temp,*tp;
    temp = malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = i;
    temp->next = NULL;
    tp = head;
    while(tp->next != NULL)
        tp = tp->next;
    tp->next = temp;
    temp->prev = tp;
    return head;
}

node* append_to_start(node *head, long i)
{
    if(head == NULL)
    {
        return append_to_empty(head,i);
    }
    node *temp;
    temp = malloc(sizeof(node));
    // temp->prev = NULL;
    temp->data = i;
    // temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

size_t count_elements(node *head)
{
    size_t result;
    result = 0;
    while(head)
    {
        result++;
        head = head->next;
    }
    return (result);
}

void display_elements(node *head)
{
    while(head!=NULL)
	{
		printf("%lli\n",head->data);
		head = head->next;
	}
}

void display_index(node *head)
{
    while(head)
	{
		printf("index is %lu, data is %lli\n",head->index,head->data);
		head = head->next;
	}
}
void	assign_index(node *stack_a, int stack_size)
{
	node	*ptr;
	node    *highest;
	long    value;

	while (stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->data == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->data > value && ptr->index == 0)
			{
				value = ptr->data;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
            highest->index = stack_size;
        stack_size--;
	}
}

bool	stack_sorted(node *stack) //Define a function that checks if the stack is sorted in ascending order
{
	if (!stack)
		return (1);
	while (stack->next) //Loop until the end of the stack is reached
	{
		if (stack->index > stack->next->index) //Check if the current value is larger than the next node's value, indicating it is out of sort
			return (false);
		stack = stack->next; //If not, move to the next node for processing
	}
	return (true);
}

node *get_last(node *head)
{
    while(head->next)
        head = head->next;
    return (head);
}