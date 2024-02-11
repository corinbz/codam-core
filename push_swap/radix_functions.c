/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:49:04 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/10 15:04:31 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max_bits(t_node **head)
{
	t_node	*a;
	int		max_bits;
	size_t	temp_index;

	a = find_max(*head);
	max_bits = 0;
	temp_index = a->index;
	while (temp_index != 0)
	{
		temp_index = temp_index >> 1;
		max_bits++;
	}
	return (max_bits);
}
/* loop through the nodes and sort each number by the bit
 starting from the least significant bit. if the bit is 0, push to b
 else rotate a. then push all the numbers from b to a and repeat the process
 */

void	push_all(t_node **src, t_node **dst)
{
	int	src_len;

	src_len = count_elements(*src);
	while (src_len--)
		push(src, dst, 'a');
}

void	radix_sort(t_node **a, t_node **b)
{
	int	max_bits;
	int	current_bit;
	int	current_element;
	int	a_len;

	current_bit = 0;
	current_element = 0;
	a_len = count_elements(*a);
	max_bits = check_max_bits(a);
	while (current_bit < max_bits)
	{
		while (current_element < a_len)
		{
			if (!(((*a)->index) >> current_bit & 1))
				push(a, b, 'b');
			else
				rotate(a);
			current_element++;
		}
		current_element = 0;
		push_all(b, a);
		current_bit++;
	}
}

void	apply_algorithm(t_node **a, t_node **b, size_t stack_size)
{
	if (stack_size == 2)
		swap(a);
	else if (stack_size == 3)
		sort_three(a);
	else if (stack_size == 4)
		sort_four(a, b);
	else if (stack_size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}
