#include "push_swap.h"

node	*find_min(node *stack) //Define a function that searches a stack and returns the node with the smallest number
{
	long			min; //To store the smallest value so far
	node	*min_node; //To store a pointer that points to the smallest number

	if (!stack)
		return (NULL);
	min = INT_MAX; //Assign to the smallest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->data < min) //Check if the current node value is smaller than the smallest so far
		{
			min = stack->data; //If so, update the smallest number so far
			min_node = stack; //Set the pointer to point to the node with the smallest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (min_node);
}

node	*find_max(node *stack) //Define a function that searches a stack and returns the node with the biggest number
{
	long			max; //To store the biggest value so far
	node	*max_node; //To store a pointer that points to the biggest number

	if (!stack)
		return (NULL);
	max = 0; //Assign to the biggest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->data > max) //Check if the current node value is smaller than the biggest so far
		{
			max = stack->data; //If so, update the biggest number so far
			max_node = stack; //Set the pointer to point to the node with the biggest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (max_node);
}

void sort_five(node **a,node **b)
{
	node *min_node = find_min(*a);
	if (min_node == *a)
	{
		push(a,b,'b');
		sort_four(a,b);
		push(b,a,'a');
	}
	else if ((*a)->next == min_node)
	{
		swap(a);
		push(a,b,'b');
		sort_four(a,b);
		push(b,a,'a');
	}
	else if ((*a)->next->next == min_node)
	{
		rotate(a);
		rotate(a);
		push(a,b,'b');
		sort_four(a,b);
		push(b,a,'a');
	}
	else if ((*a)->next->next->next == min_node)
	{
		reverse_rotate(a);
		reverse_rotate(a);
		push(a,b,'b');
		sort_four(a,b);
		push(b,a,'a');
	}
	else if ((*a)->next->next->next->next == min_node)
	{
		reverse_rotate(a);
		push(a,b,'b');
		sort_four(a,b);
		push(b,a,'a');
	}
}
void sort_four(node **a,node **b)
{
	node *min_node = find_min(*a);
	if (min_node == *a)
	{
		push(a,b,'b');
		sort_three(a);
		push(b,a,'a');
	}
	else if ((*a)->next == min_node)
	{
		swap(a);
		push(a,b,'b');
		sort_three(a);
		push(b,a,'a');
	}
	else if ((*a)->next->next == min_node)
	{
		reverse_rotate(a);
		reverse_rotate(a);
		push(a,b,'b');
		sort_three(a);
		push(b,a,'a');
	}
	else if ((*a)->next->next->next == min_node)
	{
		reverse_rotate(a);
		push(a,b,'b');
		sort_three(a);
		push(b,a,'a');
	}

}
void sort_three(node **a)
{
	node	*biggest_node; //To store a pointer to the biggest node in stack `a`
	biggest_node = find_max(*a);
	// printf("found biggest node %lu\n",biggest_node->index);
	if (biggest_node == *a) //Check if the current node is the biggest
		rotate(a); //If so, rotate the top node to the bottom of the stack
	else if ((*a)->next == biggest_node) //Check if the second node is the biggest
		reverse_rotate(a); //If so, reverse rotate the bottom node, to the top of the stack
	if ((*a)->index > (*a)->next->index) //Check if the bottom node is the biggest, but the top node is higher than the second node
		swap(a); //If so, simply swap the top and second nodes
}