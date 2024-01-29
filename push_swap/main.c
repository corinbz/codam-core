#include "push_swap.h"
#include "./libft/libft.h"

int main(int ac, char **av)
{
	int i = 0;
	node *a = NULL;
	node *b = NULL;
	// printf("%c",av[1][0]);
	if(ac == 1 || (ac == 2 && !av[1][0]))
			display_error();
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	while (av[i] && !are_duplicates(av)) 
	{
		a = append_to_end(a, ft_atoi(av[i]));
		i++;
	}
	assign_index(a,count_elements(a));
	printf("%lu\n",count_elements(a));
	if(count_elements(a) == 4)
		sort_three(&a);
	else
		radix_sort(&a, &b);
	return (0);
}