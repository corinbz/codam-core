/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:48:19 by ccraciun          #+#    #+#             */
/*   Updated: 2024/03/08 20:49:50 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_data *data, char **envp)
{
	int			end[2];
	int			status;
	__pid_t		child1;
	__pid_t		child2;

	if (pipe(end) == -1)
		display_error(data, "Pipe failed: ");
	child1 = fork();
	if (child1 < 0)
		display_error (data, "Fork child1: ");
	if (child1 == 0)
		child_one(data, end, envp);
	child2 = fork();
	if (child2 < 0)
		display_error (data, "Fork child2: ");
	if (child2 == 0)
		child_two(data, end, envp);
	close(end[0]);
	close(end[1]);
	close(data->in_fd);
	close(data->out_fd);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

void	child_one(t_data *data, int *end, char **envp)
{
	close(end[0]);
	dup2(data->in_fd, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(data->in_fd);
	close(end[1]);
	close(data->out_fd);
	if (execve(data->cmd_paths[0], data->cmd_args[0], envp) == -1)
	{
		dup2(STDERR_FILENO, STDOUT_FILENO);
		ft_putstr_fd("child one execve failed\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	child_two(t_data *data, int *end, char **envp)
{
	close(end[1]);
	dup2(end[0], STDIN_FILENO);
	dup2(data->out_fd, STDOUT_FILENO);
	close(data->in_fd);
	close(data->out_fd);
	close(end[0]);
	if (execve(data->cmd_paths[1], data->cmd_args[1], envp) == -1)
	{
		display_error(data, "child two execve failed\n");
	}
}
