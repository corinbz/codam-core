/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:26:35 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/24 16:07:54 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_2d(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr && arr[i])
		{
			if (arr[i] != NULL)
				free(arr[i]);
			arr[i++] = NULL;
		}
		free(arr);
		arr = NULL;
	}
}

void free_data(t_data *data)
{
	free_2d(data->possible_paths);
	free_2d(data->cmd1_args);
	free_2d(data->cmd2_args);
	// free(data->out_fd);
	// free(data->invalid_infile);
	// free(data);
}
void display_error(t_data *data, char *error)
{
	free_data(data);
	perror(error);
	exit(EXIT_FAILURE);
}
void ft_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}
