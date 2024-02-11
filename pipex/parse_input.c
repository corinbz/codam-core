/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:46:25 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/11 16:17:01 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char **get_possible_paths(char **env_path, char *cmd)
{
	char **path;
	int	i;
	int j;
	int k;
	
	i = 0;
	j = 0;
	k = 0;
	
	cmd = ft_strjoin("/",cmd);//mem check
	while(env_path[i])
	{
		path = ft_split(env_path[i], '=');//mem check
		if(!ft_strncmp(path[j],"PATH",5))
			{
				path = ft_split(path[1],':');
				while(path[k])
				{
					path[k] = ft_strjoin(path[k],cmd);//mem check
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
    if (access(path, X_OK) != 0)
        return(0);
	return (1);
}

char *get_file_path (char *file_name, char **envp)
{
	int i = 0;
	char *result;
	char **temp_envp;
	file_name = ft_strjoin("/", file_name);//mem check
	while(envp[i])
	{
		temp_envp = ft_split(envp[i], '=');
		// printf("%i\n",ft_strncmp(temp_envp[0], "PWD", 4));
		if (ft_strncmp(temp_envp[0], "PWD", 4) == 0)
		{
			printf("succes");
			result = ft_strjoin(envp[1],file_name);
			return (result);
		}
		i++;
	}
	return (NULL);
}

int in_file_access(char *file_path, char **envp)
{
	printf("%s\n",file_path);
	return (0);
}
char **get_cmd_path(char **path_list)
{
	int i = 0;
	while(path_list[i])
	{
		if(executable_exists(path_list[i]))
			return (&path_list[i]);
		i++;
	}
	return (NULL);
}


char **get_cmd_incl_flags(char *raw_cmd)
{
char **cmd_inc_flags;
cmd_inc_flags = ft_split(raw_cmd, ' ');
if (!cmd_inc_flags)
	exit(2);
return (cmd_inc_flags);
}
