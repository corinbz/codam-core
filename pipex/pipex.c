/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:48:19 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/25 13:54:28 by corin            ###   ########.fr       */
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
    // child2 = fork();
    // if (child2 < 0)
    //      return (perror("Fork: "));
    // if (child2 == 0)
    //     child_two(f2, cmd2, cmd2_with_flags, end, envp);
    close(end[0]);
    close(end[1]);
    waitpid(child1, &status, 0);  // supervising the children
    // waitpid(child2, &status, 0);  // while they finish their tasks
	// ft_free_all(cmd1_with_flags,cmd2_with_flags,0);
	// ft_free_all(&cmd1,&cmd2,0);
}

void child_one(t_data *data, int *end, char **envp)
{
	close(end[0]);
	dup2(data->in_fd, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	if (execve(data->cmd_paths[0], data->cmd1_args, envp) == -1)
	{
		display_error(data, "child one execve failed");
	}
}
void child_two(int fd2, char *cmd2, char **cmd2_inc_flags, int *end, char **envp)
{
	close(end[1]);
	dup2(end[0],STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	// if (!cmd_including_flags)
		// perror("alloc fail");
	if (execve(cmd2, cmd2_inc_flags, envp) == -1)
		{
			perror("execve failed");
			exit(2);
		}
}