/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:46:25 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/24 11:59:55 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"


void get_possible_paths(t_data *data,char **envp, char *cmd)
{
	char	*tmp;
	size_t	i;
	i = 0;
	//returns an array containing all possible locations of the cmd
	while(envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			data->path = ft_split(envp[i], ':');//check memmory
			tmp =ft_substr(data->path[0], 5, ft_strlen(data->path[0]) - 5);
			free(data->path[0]);
			data->path[0] = tmp;
			return ;
		}
		i++;
	}
}

int	executable_exists(char *path) 
{
    if (access(path, X_OK) != -1)
        return(1);
	return (0);
}

char *get_file_path (char *file_name, char **envp)
{
	//returns the absolute file path of the filename
	int i = 0;
	char *result;
	char **temp_envp;
	file_name = ft_strjoin("/", file_name);//mem check
	if (!file_name)
		return (NULL);
	while(envp[i])
	{
		temp_envp = ft_split(envp[i], '=');
		if (!temp_envp)
			return (NULL);
		if (ft_strncmp(temp_envp[0], "PWD", 4) == 0)
		{
			result = ft_strjoin(temp_envp[1],file_name);
			if (!result)
				return (NULL);
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
char *get_cmd_path(char **path_list)
{
	//loop through all possible paths and check if file is executable
	int i = 0;
	while(path_list[i])
	{
		// printf("%s\n",path_list[i]);
		if(executable_exists(path_list[i]))
			return (path_list[i]);
		i++;
	}
	// perror("command not found or not executable: ");
	return (NULL);
}


char **get_cmd_incl_flags(char *raw_cmd)
{
char **cmd_inc_flags;
cmd_inc_flags = ft_split(raw_cmd, ' ');
if (!cmd_inc_flags)
	return (NULL);
return (cmd_inc_flags);
}
