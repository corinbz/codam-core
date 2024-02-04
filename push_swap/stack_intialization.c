/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_intialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:53:27 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/04 14:56:10 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*append_to_empty(t_node *head, long i)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	temp->prev = NULL;
	temp->data = i;
	temp->next = NULL;
	head = temp;
	return (head);
}

t_node	*append_to_end(t_node *head, long i)
{
	t_node	*temp;
	t_node	*tp;

	if (head == NULL)
		return (append_to_empty(head, i));
	temp = malloc(sizeof(t_node));
	tp = head;
	temp->prev = NULL;
	temp->data = i;
	temp->next = NULL;
	while (tp->next != NULL)
		tp = tp->next;
	tp->next = temp;
	temp->prev = tp;
	return (head);
}

t_node	*append_to_start(t_node *head, long i)
{
	t_node	*temp;

	if (head == NULL)
		return (append_to_empty(head, i));
	temp = malloc(sizeof(t_node));
	temp->data = i;
	temp->next = head;
	head->prev = temp;
	head = temp;
	return (head);
}
