/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:14:25 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/10 15:04:06 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	are_duplicates(t_node **a, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ft_atol(av[i]) == __INT64_MAX__)
		i++;
	j = i + 1;
	while (av[i])
	{
		while (av[j])
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
			{
				free_argv(av);
				free_stack(a);
				display_error();
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

void	parse_av(int ac, char **av, t_node **a)
{
	int	i;

	i = 1;
	if (ac == 2 && av[i][0])
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			display_error();
		i = 0;
	}
	while (av[i])
	{
		if (!av[i][0] || ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
		{
			free_argv(av);
			free_stack(a);
			display_error();
		}
		*a = append_to_end(*a, ft_atol(av[i]));
		i++;
	}
	are_duplicates (a, av);
	free_argv(av);
}
