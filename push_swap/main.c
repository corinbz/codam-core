/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:12:33 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/08 22:55:46 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	parse_av(ac, av, &a);
	set_default_index(a);
	assign_index (a, count_elements(a));
	if (!stack_sorted(a))
		apply_algorithm(&a, &b, count_elements(a));
	free_stack(&a);
	return (0);
}
