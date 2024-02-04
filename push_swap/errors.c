/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:30:34 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/04 14:43:46 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(void)
{
	char	*error_message;

	error_message = "Error\n";
	write (2, error_message, ft_strlen(error_message));
	exit(1);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

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
	if (NULL == argv || NULL == *argv || ft_strnstr(argv[i], "./push_swap", 12))
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
