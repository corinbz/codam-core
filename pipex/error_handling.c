/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:08:47 by ccraciun          #+#    #+#             */
/*   Updated: 2024/03/03 16:26:09 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	ac_check(int ac)
{
	if (ac != 5)
		return (false);
	return (true);
}

void	display_error(t_data *data, char *error)
{
	free_data(data);
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}
