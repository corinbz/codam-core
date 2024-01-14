#include "push_swap.h"
#include "./libft/libft.h"
#include <stdlib.h>
int main(int ac, char *av[])
{
	int i = 1;
	node *a = NULL;
	if(ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		{
		av = ft_split(av[1], ' ');
		i = 0;
		}
	while (av[i]) 
	{
		// printf("%i\n",ft_atoi(av[i]));
		a = append_to_end(a, ft_atoi(av[i]));
		i++;
	}
	while(a!=NULL)
	{
		// printf("got\n");
		printf("%li\n",a->index);
		a = a->next;
	}
	return (0);
}