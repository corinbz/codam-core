/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:46:25 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/21 15:26:20 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char **get_possible_paths(char **env_path, char *cmd)
{
	//returns an array containing all possible locations of the cmd
	char **path;
	int	i;
	int j;
	int k;
	
	i = 0;
	j = 0;
	k = 0;
	
	cmd = ft_strjoin("/",cmd);//mem check
	if(!cmd)
		return (NULL);
	while(env_path[i])
	{
		path = ft_split(env_path[i], '=');//mem check
		if (!path)
			return (NULL);
		if(!ft_strncmp(path[j],"PATH",5))
			{
				path = ft_split(path[1],':');
				if (!path)
					return (NULL);
				while(path[k])
				{
					path[k] = ft_strjoin(path[k],cmd);//mem check
					if (!path[k])
						return (NULL);
					k++;
				}
				return (path);
			}
		j = 0;
		i++;
	}
	return (NULL);
}

int	executable_exists(char *path) 
{
    if (access(path, X_OK) != -1)
        return(1);
	// printf("%s\n", path);
	// perror("Path does not exist or is not executable");
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
		printf("file is readable\n");
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
