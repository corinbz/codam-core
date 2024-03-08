/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:28:48 by ccraciun          #+#    #+#             */
/*   Updated: 2024/03/08 20:47:32 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

void	initialiaze_data(t_data *data, char **envp, char **av)
{
	data->cmd_paths = ft_calloc(3, sizeof(char *));
	if (!data->cmd_paths)
		display_error(data, "Failed to allocate cmd_paths");
	data->cmd_args = ft_calloc(5, sizeof(char **));
	if (!data->cmd_args)
		display_error(data, "Failed to allocate cmd_args");
	data->possible_paths = ft_calloc(1, sizeof(char *));
	if (!data->possible_paths)
		display_error(data, "Failed to allocate possible_paths");
	create_and_open_files(data, av);
	if (!both_cmd_abs_pt(av, 2, 3))
		get_possible_paths(data, envp);
	get_cmd_incl_flags(data, av[2], 0);
	get_cmd_incl_flags(data, av[3], 1);
	get_commands_path(data, av, 2, 3);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (!ac_check(ac))
		return (ft_putstr_fd("Invalid number of arguments",
				STDERR_FILENO), EXIT_FAILURE);
	initialiaze_data(&data, envp, av);
	pipex(&data, envp);
	free_data(&data);
	return (0);
}
