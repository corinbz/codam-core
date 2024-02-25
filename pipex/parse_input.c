/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:46:25 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/25 13:54:10 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"


void get_possible_paths(t_data *data,char **envp)
{
	char	*tmp;
	size_t	i;
	i = 0;
	while(envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			data->possible_paths = ft_split(envp[i], ':');
			if (!data->possible_paths)
				return ;
			tmp =ft_substr(data->possible_paths[0], 5, ft_strlen(data->possible_paths[0]) - 5);
			if(!tmp)
				return(free_2d(data->possible_paths));
			free(data->possible_paths[0]);
			data->possible_paths[0] = tmp;
			return ;
		}
		i++;
	}
}

int	executable_exists(char *path) 
{
    if (access(path, X_OK) != -1)
        return(1);
	// free(path);
	return (0);
}

char *get_file_path (char *file_name, char **envp)
{
	//returns the absolute file path of the filename
	int i;
	i = 0;
	char *result;
	char **temp_envp;
	file_name = ft_strjoin("/", file_name);//mem check
	if (!file_name)
		return (NULL);
	while(envp[i])
	{
		temp_envp = ft_split(envp[i], '=');
		if (!temp_envp)
			return (free(file_name),NULL);
		if (ft_strncmp(temp_envp[0], "PWD", 4) == 0)
		{
			result = ft_strjoin(temp_envp[1],file_name);
			if (!result)
				return (free(temp_envp),free(file_name),NULL);
			return (result);
		}
		i++;
	}
	return (NULL);
}

int in_file_access(char *file_path, char **envp)
{
	if(access(file_path,R_OK) == 0)
	{
		return (1);
	}
	printf("file does not exist or is not readable.\n");
	return (0);
}
void get_cmd_path(t_data *data, char *cmd, size_t cmd_nr)
{
    size_t i;
	char *new_cmd;

    i = 0;
	new_cmd = ft_strjoin("/", cmd); 
    while (data->possible_paths[i++]) {
        data->cmd_paths[cmd_nr] = ft_strjoin(data->possible_paths[i -1], new_cmd);
        if (!data->cmd_paths[cmd_nr]) {
            ft_free(new_cmd);
			display_error(data, "Malloc failed in get_cmd_path");
            return; 
        }
        if (executable_exists(data->cmd_paths[cmd_nr])) {
			free(new_cmd);
            return; 
        }
		free(data->cmd_paths[cmd_nr]);
    }
	free(new_cmd);
	return(display_error(data, "Command not found"));
}






void	get_cmd_incl_flags(t_data *data, char *raw_cmd, size_t cmd_nr)
{
	if (cmd_nr == 1)
	{
		data->cmd1_args = ft_split(raw_cmd, ' ');
		if (!data->cmd1_args)
			display_error(data, "Malloc failed in get_cmd_incl_flags");
	}
	else
	{
		data->cmd2_args = ft_split(raw_cmd, ' ');
		if (!data->cmd2_args)
			display_error(data, "Malloc failed in get_cmd_incl_flags");
	}
}
