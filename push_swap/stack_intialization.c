/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_intialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:53:27 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/10 15:07:20 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*append_to_empty(t_node *head, long i)
{
	t_node	*temp;

	temp = ft_calloc(4, sizeof(t_node));
	if (temp == NULL)
		return (NULL);
	temp->data = i;
	head = temp;
	return (head);
}

t_node	*append_to_end(t_node *head, long i)
{
	t_node	*temp;
	t_node	*tp;

	if (head == NULL)
		return (append_to_empty(head, i));
	temp = ft_calloc(4, sizeof(t_node));
	if (temp == NULL)
		return (NULL);
	temp->data = i;
	tp = get_last(head);
	tp->next = temp;
	temp->prev = tp;
	return (head);
}

// t_node	*append_to_start(t_node *head, long i)
// {
// 	t_node	*temp;

// 	if (head == NULL)
// 		return (append_to_empty(head, i));
// 	temp = malloc(sizeof(t_node)); // again  :P
// 	temp->data = i;
// 	temp->next = head;
// 	head->prev = temp;
// 	head = temp;
// 	return (head);
// }
