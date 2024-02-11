/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:48:19 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/11 16:05:47 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int open_file(char *file_name,char **envp)
// {
	
// }

void process_child(int *p, char **av, char **envp)
{
	// int input;
	// close(p[0]);
	// dup2(p[1],1);
	// close(p[1]);
	char **cmd_inc_flags = get_cmd_incl_flags(av[2]);
	char **cmd_path = get_cmd_path(get_possible_paths(envp, cmd_inc_flags[0]));
	get_file_path(av[1], envp);
	if (cmd_path)
	{
		if (execve(*cmd_path, cmd_inc_flags, envp) == -1) {
			perror("execve failed"); 
		}
	} else {
		perror("File does not exist or is not executable\n");
	}
}