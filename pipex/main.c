/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:28:48 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/10 19:46:47 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

/*
$> ./pipex infile "ls -l" "wc -l" outfile
Should behave like: < infile ls -l | wc -l > outfile
*/


int main(int ac, char **av, char **env_path)
{
	
	char **cmd_inc_flags;
	if(ac != 5)
	{
		perror("Invalid number of arguments(4):");
		return (1);
	}
	cmd_inc_flags = ft_split(av[2], ' ');
	char **parsed_env_path = parse_env_path(env_path, cmd_inc_flags[0]);
	char **cmd_path = get_cmd_path(parsed_env_path);
	if (cmd_path != NULL) {
		char *envp[] = { NULL };

		if (execve(*cmd_path, cmd_inc_flags, envp) == -1) {
			perror("execve failed");
		}
	} else {
		printf("File does not exist or is not executable\n");
	}
	return (0);
}