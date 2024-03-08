/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:06:08 by ccraciun          #+#    #+#             */
/*   Updated: 2024/03/08 20:49:41 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	both_cmd_abs_pt(char **av, size_t av_pos1, size_t av_pos2)
{
	if (ft_strchr(av[av_pos1], '/') && ft_strchr(av[av_pos2], '/'))
	{
		return (true);
	}
	return (false);
}

static char	*get_after_last_slash(char *str)
{
	char	*last_slash;

	last_slash = ft_strrchr(str, '/');
	if (last_slash)
		return (last_slash + 1);
	return (str);
}

void	handle_first_char(t_data *data, char *cmd, size_t av_pos)
{
	char	**temp;

	temp = ft_split(cmd, ' ');
	if (!temp)
		display_error(data, "Malloc failed in is_cmd_absolute_path");
	if (cmd[0] != '.' && cmd[0] != '/')
	{
		data->cmd_paths[av_pos - 2] = ft_strjoin("/", temp[0]);
		if (!data->cmd_paths[av_pos - 2])
		{
			free_2d(temp);
			display_error(data, "Malloc failed in is_cmd_absolute_path");
		}
	}
	else
	{
		data->cmd_paths[av_pos - 2] = ft_strdup(temp[0]);
		if (!data->cmd_paths[av_pos - 2])
		{
			free_2d(temp);
			display_error(data, "Malloc failed in is_cmd_absolute_path");
		}
	}
	free_2d(temp);
}

bool	is_cmd_absolute_path(t_data *data, char *cmd, size_t av_pos)
{
	char	*temp;

	if (ft_strchr(cmd, '/'))
	{
		if (data->cmd_args[av_pos - 2])
			free_2d(data->cmd_args[av_pos - 2]);
		handle_first_char(data, cmd, av_pos);
		data->cmd_args[av_pos - 2] = ft_split(cmd, ' ');
		if (!data->cmd_args[av_pos - 2])
			display_error(data, "Malloc failed in is_cmd_absolute_path");
		temp = ft_strdup(get_after_last_slash(data->cmd_args[av_pos - 2][0]));
		if (!temp)
			display_error(data, "Malloc failed in is_cmd_absolute_path");
		free(data->cmd_args[av_pos - 2][0]);
		data->cmd_args[av_pos - 2][0] = temp;
		return (true);
	}
	return (false);
}

void	get_commands_path(t_data *data, char **av, size_t av_pos1,
					size_t av_pos2)
{
	if (!is_cmd_absolute_path(data, av[av_pos1], av_pos1))
	{
		get_cmd_path(data, av_pos1 - 2);
	}
	if (!is_cmd_absolute_path(data, av[av_pos2], av_pos2))
	{
		get_cmd_path(data, av_pos2 - 2);
	}
}
