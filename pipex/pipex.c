/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:48:19 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/25 15:33:24 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    pipex(t_data *data, char **argv, char **envp)
{
    int   end[2];
    int   status;
    __pid_t child1;
    __pid_t child2;
	
	pipe(end);
	//first command
    child1 = fork();
    if (child1 < 0)
         return (perror("Fork: "));
    if (child1 == 0)
        child_one(data, end, envp);
	// second command
    child2 = fork();
    if (child2 < 0)
         return (perror("Fork: "));
    if (child2 == 0)
        child_two(data, end, envp);
    close(end[0]);
    close(end[1]);
    waitpid(child1, &status, 0);  // supervising the children
    waitpid(child2, &status, 0);  // while they finish their tasks
}

void child_one(t_data *data, int *end, char **envp)
{
	close(end[0]);
	// close(end[1]);
	dup2(data->in_fd, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	if (execve(data->cmd_paths[0], data->cmd_args[0], envp) == -1)
	{
		display_error(data, "child one execve failed");
	}
}
void child_two(t_data *data, int *end, char **envp)
{
	close(end[1]);
	dup2(end[0],STDIN_FILENO);
	dup2(data->out_fd, STDOUT_FILENO);
	if (execve(data->cmd_paths[1], data->cmd_args[1], envp) == -1)
	{
		display_error(data, "child two execve failed");
	}
}