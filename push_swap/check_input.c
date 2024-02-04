/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:14:25 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/04 16:26:29 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	are_duplicates(char **av)
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
				display_error();
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
	if (ac >= 2 && !av[1][0])
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
			free_stack(a);
			display_error();
		}
		*a = append_to_end(*a, ft_atol(av[i]));
		i++;
	}
	free_argv(av);
}
