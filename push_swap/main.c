#include "push_swap.h"
#include "./libft/libft.h"

int main(int ac, char **av)
{
	int i = 1;
	node *a = NULL;
	node *b = NULL;
	if (ac == 1)
		return (0);
	else if(ac == 2 && !av[1][0])
			display_error();
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = 0;
	}
	while (av[i] && !are_duplicates(av)) 
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
		{
			free_stack(&a);
			display_error();
		}
		a = append_to_end(a, ft_atol(av[i]));
		i++;
	}
	free_argv(av);
	assign_index(a,count_elements(a));
	if(!stack_sorted(a))
	{
	if(count_elements(a) == 2)
		swap(&a);
	else if(count_elements(a) == 5)
		sort_five(&a, &b);
	else if(count_elements(a) == 4)
		sort_four(&a, &b);
	else if(count_elements(a) == 3)
		sort_three(&a);
	else
		radix_sort(&a, &b);
	}
	// printf("rra\nrra\npb\nra\npa\n");
	// display_elements(a);
	// display_index(a);
	free_stack(&a);
	return (0);
}