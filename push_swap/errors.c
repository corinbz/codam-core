#include "push_swap.h"

void display_error(void)
{
   char *error_message = "Error\n";
    write(2, error_message, ft_strlen(error_message));
    exit(1);
}

void	free_stack(node **stack)
{
	node	*tmp;
	node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
    // printf("argv[i] is %s res of strnstr is %s\n",argv[i], ft_strnstr(argv[i], "./push_swap", 12));
	if (NULL == argv || NULL == *argv || ft_strnstr(argv[i], "./push_swap", 12))
		return ;
	while (argv[i])
    {
		free(argv[i]);
        i++;
    }
	free(argv);
}