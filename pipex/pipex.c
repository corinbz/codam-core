/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:48:19 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/11 18:19:44 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    pipex(int f1, int f2, char *cmd1, char *cmd2)
{
    int   end[2];
    int   status;
    __pid_t child1;
    __pid_t child2;
	pipe(end);
    child1 = fork();
    if (child1 < 0)
         return (perror("Fork: "));
    if (child1 == 0)
        child_one(f1, cmd1);
    child2 = fork();
    if (child2 < 0)
         return (perror("Fork: "));
    if (child2 == 0)
        child_two(f2, cmd2);
    close(end[0]);         // this is the parent
    close(end[1]);         // doing nothing
    waitpid(child1, &status, 0);  // supervising the children
    waitpid(child2, &status, 0);  // while they finish their tasks
}
void process_child(int *p, char **av, char **envp)
{
	int input;
	close(p[0]);
	dup2(p[1],1);
	close(p[1]);
	// input = open(get_file_path(av[1],envp),)
	if(in_file_access(, envp));
	char **cmd_inc_flags = get_cmd_incl_flags(av[2]);
	char **cmd_path = get_cmd_path(get_possible_paths(envp, cmd_inc_flags[0]));
	if (cmd_path)
	{
		if (execve(*cmd_path, cmd_inc_flags, envp) == -1) {
			perror("execve failed"); 
		}
	} else {
		perror("File does not exist or is not executable\n");
	}
}