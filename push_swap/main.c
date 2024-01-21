#include "push_swap.h"
#include "./libft/libft.h"

int main(int ac, char **av)
{
	int i = 1;
	node *a = NULL;
	// node *b = NULL;
	if(ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		{
		av = ft_split(av[1], ' ');
		i = 0;
		}
	while (av[i] && !are_duplicates(av)) 
	{
		// printf("%i\n",ft_atoi(av[i]));
		a = append_to_end(a, ft_atoi(av[i]));
		i++;
	}
	// printf("stack a has %lu elements",count_elements(a));
	assign_index(a,count_elements(a));
	display_elements(a);
	reverse_rotate(&a);
	display_elements(a);
	return (0);
}