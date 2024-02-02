#include "push_swap.h"
#include "./libft/libft.h"

int main(int ac, char **av)
{
	int i = 1;
	node *a = NULL;
	node *b = NULL;
	if(ac == 1 || (ac == 2 && !av[1][0]))
			display_error();
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	while (av[i] && !are_duplicates(av)) 
	{
		a = append_to_end(a, ft_atoi(av[i]));
		i++;
	}
	// display_elements(a);
	assign_index(a,count_elements(a));
	// display_index(a);
	// printf("n: %lu\n",count_elements(a));
	if(count_elements(a) == 5)
		sort_five(&a, &b);
	else if(count_elements(a) == 4)
		sort_four(&a, &b);
	else if(count_elements(a) == 3)
		sort_three(&a);
	else
		radix_sort(&a, &b);
	// display_elements(a);
	return (0);
}