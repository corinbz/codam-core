#include "push_swap.h"

node* append_to_empty(node *head, long long i)
{
    node *temp = malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = i;
    temp->next = NULL;
    head = temp;
    return head;
}

node* append_to_end(node *head,long long i)
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

node* append_to_start(node *head, long long i)
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
    while(head!=NULL)
	{
		printf("%lu\n",head->index);
		head = head->next;
	}
}
void	assign_index(node *stack_a, int stack_size)
{
	node	*ptr;
	node	*highest;
	int		value;

	while (--stack_size > 0)
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
	}
}

int is_sorted(node *head)
{
    // node *temp = head;
    if (head == NULL)
        return (1);
    while(head->next)
    {
            printf("comparing %lu with %lu\n",head->index,head->next->index);
            if (head->index < head->next->index)
            {
                head = head->next;
                continue;
            }
            return (1);
        }
    return (0);
}