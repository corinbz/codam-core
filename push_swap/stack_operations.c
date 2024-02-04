/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:56:27 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/04 15:58:03 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **head)
{
	t_node	*second_node;
	t_node	*first_node;

	if (!*head || !(*head)->next)
		return ;
	second_node = (*head)->next;
	*head = second_node;
	first_node = second_node->prev;
	second_node->prev = first_node->prev;
	first_node->next = second_node->next;
	if (second_node->next)
		second_node->next->prev = first_node;
	second_node->next = first_node;
	first_node->prev = NULL;
	write(1, "sa\n", 3);
}

void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = get_last(*head);
	first = *head;
	last->next = first;
	first->prev = last;
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	reverse_rotate(t_node **head)
{
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = get_last(*head);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *head;
	*head = last;
	last->next->prev = last;
	write(1, "rra\n", 4);
}

void	push(t_node **src, t_node **dest, char a)
{
	t_node	*temp;

	if (*src == NULL)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
	if (a == 'b')
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}
