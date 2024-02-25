/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:26:35 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/25 14:01:25 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_2d(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void free_data(t_data *data)
{
	free_2d(data->possible_paths);
	free_2d(data->cmd2_args);
	free_2d(data->cmd1_args);
	free_2d(data->cmd_paths);
	// free(data->out_fd);
	// free(data->invalid_infile);
	// free(data);
}

void ft_free(char *str)
{
	if (str || *str)
	{
		free(str);
		str = NULL;
	}
}
