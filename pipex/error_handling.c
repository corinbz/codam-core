/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:08:47 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/27 10:00:40 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	ac_check(int ac, char **av)
{
	if (ac != 5)
		return (perror("you must have exactly 4 arguments"), false);
	return (true);
}

void	display_error(t_data *data, char *error)
{
	free_data(data);
	perror(error);
	exit(EXIT_FAILURE);
}
