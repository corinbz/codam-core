/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:46:25 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/10 19:43:16 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char **parse_env_path(char **env_path, char *cmd)
{
	char **path;
	int	i;
	int j;
	int k;
	
	i = 0;
	j = 0;
	k = 0;
	
	cmd = ft_strjoin("/",cmd);
	while(env_path[i])
	{
		path = ft_split(env_path[i], '=');
		if(!ft_strncmp(path[j],"PATH",5))
			{
				path = ft_split(path[1],':');
				while(path[k])
				{
					path[k] = ft_strjoin(path[k],cmd);
					k++;
				}
				return (path);
			}
		j = 0;
		i++;
	}
	return (NULL);
}

int file_exists(char *path) 
{
    if (access(path, X_OK) == 0) {
        return 1;
    } else {
        return 0;  
    }
}
char **get_cmd_path(char **path_list)
{
	int i = 0;
	while(path_list[i])
	{
		if(file_exists(path_list[i]))
			return (&path_list[i]);
		i++;
	}
	return (NULL);
}