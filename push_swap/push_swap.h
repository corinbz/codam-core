/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:39:34 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/05 16:32:11 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//** INCLUDES **
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"
# include <limits.h>
# include <unistd.h>
# include <stdbool.h> 

//** DOUBLY LINKED LIST **
typedef struct node
{
	long			data;
	int             index;
	struct node		*next;
	struct node		*prev;
}	t_node;

//error hadling
void	display_error(void);
// push
void	push(t_node **src, t_node **dest, char a);

// ** FUNCTION PROTOTYPES **

//* initializing stack
t_node	*append_to_end(t_node *head, long i);
t_node	*append_to_empty(t_node *head, long i);
t_node	*append_to_start(t_node *head, long i);
void	set_default_index(t_node *stack_a);

//** stack utils
size_t	count_elements(t_node *head);
void	assign_index(t_node *stack_a, int stack_size);
void	display_index(t_node *head);
void	swap(t_node **head);
void	display_elements(t_node *head);
t_node	*get_last(t_node *head);

// check valid input

int		are_duplicates(char **av);
void	parse_av(int ac, char **av, t_node **a);

//algorithm stuff

bool	stack_sorted(t_node *stack);
void	rotate(t_node **head);
void	reverse_rotate(t_node **head);
t_node	*find_min(t_node *stack, long min);
t_node	*find_max(t_node *stack);
void	sort_three(t_node **a);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	apply_algorithm(t_node **a, t_node **b, size_t stack_size);

// radix sort

int		check_max_bits(t_node **stack);
void	radix_sort(t_node **a, t_node **b);

// free stack
void	free_stack(t_node **stack);
void	free_argv(char **argv);
#endif
