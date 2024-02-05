/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:59:09 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/05 16:33:29 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_elements(t_node *head)
{
	size_t	result;

	result = 0;
	while (head)
	{
		result++;
		head = head->next;
	}
	return (result);
}

void	set_default_index(t_node *stack_a)
{
	t_node	*ptr;

	ptr = stack_a;
	while (ptr)
	{
		ptr->index = 0;
		ptr = ptr->next;
	}
}

void	assign_index(t_node *stack_a, int stack_size)
{
	t_node	*ptr;
	t_node	*highest;
	long	value;

	while (stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->data == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->data > value && ptr->index == 0)
			{
				value = ptr->data;
				highest = ptr;
			}
			ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
		stack_size--;
	}
}

t_node	*get_last(t_node *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

bool	stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (false);
		stack = stack->next;
	}
	return (true);
}
