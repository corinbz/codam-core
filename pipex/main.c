/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:28:48 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/25 16:24:26 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void initialiaze_data(t_data *data, char **envp, char **av)
{
	ft_bzero(data, sizeof(t_data));
	data->cmd_paths = ft_calloc(3, sizeof(char *));
	data->cmd_args = ft_calloc(3, sizeof(char **));
	create_and_open_files(data, av);
	get_possible_paths(data, envp);
	get_cmd_incl_flags(data, av[2], 0);
	get_cmd_incl_flags(data, av[3], 1);
	get_cmd_path(data, 0);
	get_cmd_path(data, 1);
}

int main(int ac, char **av, char **envp)
{
	t_data data;
	
	if (!ac_check(ac,av))
		return (perror("Invalid number of arguments"), EXIT_FAILURE);
	initialiaze_data(&data, envp, av);	
	pipex(&data, av, envp);
	free_data(&data);
	return (0);
}
