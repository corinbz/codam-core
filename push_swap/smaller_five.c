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
void sort_3(node *a,node *b)
{
    size_t min;
    size_t middle;
    min = get_min(&a, -1);
    middle = get_min(&a, min);
    while(!&is_sorted)
    {
        if(a->index == min)
        {
            push(&a,&b);
            rotate(&a);
        }
        else if(a->index == middle)
        {
            push(&a,&b);
            reverse_rotate(&a);
        }
        else
        {
            rotate(&a);
        }
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
