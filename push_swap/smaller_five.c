#include "push_swap.h"

int	get_min(node **stack, int val)
{
	node	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
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
		if (stack->index > max) //Check if the current node value is smaller than the biggest so far
		{
			max = stack->index; //If so, update the biggest number so far
			max_node = stack; //Set the pointer to point to the node with the biggest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (max_node);
}
void sort_3(node **a)
{
	node	*biggest_node; //To store a pointer to the biggest node in stack `a`

    while(!stack_sorted(*a))
    {
        biggest_node = find_max(*a);
        if (biggest_node == *a) //Check if the current node is the biggest
            rotate(a); //If so, rotate the top node to the bottom of the stack
        else if ((*a)->next == biggest_node) //Check if the second node is the biggest
            reverse_rotate(a); //If so, reverse rotate the bottom node, to the top of the stack
        if ((*a)->index > (*a)->next->index) //Check if the bottom node is the biggest, but the top node is higher than the second node
            swap(a); //If so, simply swap the top and second nodes
    }
}
// void sort_5(node *a,node *b)
// {
//     while(count_elements(a) > 3)
//     {
//         push(a, b);
//     }
//     sort_3(a,b);
//     while(count_elements(b) > 0)
//     {
//         push(b, a);
//     }
// }
