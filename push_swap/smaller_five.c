/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaller_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:52:07 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/04 14:53:07 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_node *stack)
{
	long	min;
	t_node	*min_t_node;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_t_node = stack;
		}
		stack = stack->next;
	}
	return (min_t_node);
}

t_node	*find_max(t_node *stack)
{
	long	max;
	t_node	*max_t_node;

	if (!stack)
		return (NULL);
	max = 0;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_t_node = stack;
		}
		stack = stack->next;
	}
	return (max_t_node);
}

void	sort_five(t_node **a, t_node **b)
{
	t_node	*min_t_node;

	min_t_node = find_min(*a);
	if ((*a)->next == min_t_node)
		swap(a);
	else if ((*a)->next->next == min_t_node)
	{
		rotate(a);
		rotate(a);
	}
	else if ((*a)->next->next->next == min_t_node)
	{
		reverse_rotate(a);
		reverse_rotate(a);
	}
	else if ((*a)->next->next->next->next == min_t_node)
		reverse_rotate(a);
	push(a, b, 'b');
	sort_four(a, b);
	push(b, a, 'a');
}

void	sort_four(t_node **a, t_node **b)
{
	t_node	*min_t_node;

	min_t_node = find_min(*a);
	if ((*a)->next == min_t_node)
		swap(a);
	else if ((*a)->next->next == min_t_node)
	{
		reverse_rotate(a);
		reverse_rotate(a);
	}
	else if ((*a)->next->next->next == min_t_node)
		reverse_rotate(a);
	push(a, b, 'b');
	sort_three(a);
	push(b, a, 'a');
}

void	sort_three(t_node **a)
{
	t_node	*biggest_t_node;

	biggest_t_node = find_max(*a);
	if (biggest_t_node == *a)
		rotate(a);
	else if ((*a)->next == biggest_t_node)
		reverse_rotate(a);
	if ((*a)->index > (*a)->next->index)
		swap(a);
}
