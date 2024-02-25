/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:26:35 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/25 20:19:24 by corin            ###   ########.fr       */
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

void	free_3d(char ***arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free_2d(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	free_data(t_data *data)
{
	free_2d(data->cmd_paths);
	free_2d(data->possible_paths);
	free_3d(data->cmd_args);
}

void	ft_free(char *str)
{
	if (str || *str)
	{
		free(str);
		str = NULL;
	}
}
