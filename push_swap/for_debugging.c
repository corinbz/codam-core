/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_debugging.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:00:41 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/05 14:27:47 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display_elements(t_node *head)
{
    while(head!=NULL)
	{
		printf("%li\n",head->data);
		head = head->next;
	}
}

void display_index(t_node *head)
{
    while(head)
	{
		printf("index is %d, data is %li\n",head->index,head->data);
		head = head->next;
	}
}