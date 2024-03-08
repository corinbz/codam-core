/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:53:38 by corin             #+#    #+#             */
/*   Updated: 2024/03/07 20:20:56 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_and_open_files(t_data *data, char **av)
{
	data->in_fd = open(av[1], O_RDONLY, 0666);
	if (data->in_fd == -1)
		display_error(data, "Error opening input file\n");
	data->out_fd = open(av[4], O_CREAT | O_TRUNC | O_RDWR, 0666);
	if (data->out_fd == -1)
		display_error(data, "Error creating output file\n");
}

// void	get_file_path(t_data *data, char *file_name,
// 	char **envp, char *in_or_out)
// {
// 	int		i;
// 	char	**temp_envp;
// 	char	*result;

// 	i = 0;
// 	file_name = ft_strjoin("/", file_name);
// 	if (!file_name)
// 		display_error(data, "Malloc failed in get_file_path");
// 	while (envp[i])
// 	{
// 		temp_envp = ft_split(envp[i], '=');
// 		if (!temp_envp)
// 			free(file_name);
// 		if (ft_strncmp(temp_envp[0], "PWD", 4) == 0)
// 		{
// 			result = ft_strjoin(temp_envp[1], file_name);
// 			if (!result)
// 				return (free(temp_envp), free(file_name),
// 					display_error(data, "malloc failed"));
// 			if (ft_strncmp(in_or_out, "in", 2) == 0)
// 				data->infile_path = result;
// 			data->outfile_path = result;
// 		}
// 		i++;
// 	}
// }

bool	in_file_access(char *file_path)
{
	if (access(file_path, R_OK) == 0)
	{
		return (true);
	}
	return (false);
}
