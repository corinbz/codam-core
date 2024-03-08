/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:56:48 by ccraciun          #+#    #+#             */
/*   Updated: 2024/03/06 22:59:28 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "./libft/libft.h"
#include <stdbool.h>

typedef struct s_data
{
	//files
	int		in_fd;
	int		out_fd;
	//comaands and paths
	char	**cmd_paths;
	char	***cmd_args;
	char	**possible_paths;
}	t_data;

//data parsing
void	get_possible_paths(t_data *data, char **envp);
void	get_cmd_path(t_data *data, size_t cmd_nr);
void	get_cmd_incl_flags(t_data *data, char *raw_cmd, size_t cmd_nr);
size_t	ft_2dstrlen(char **arr);
bool	is_cmd_absolute_path(t_data *data, char *cmd, size_t av_pos);
void	get_commands_path(t_data *data, char **av,
			size_t av_pos1, size_t av_pos2);
bool	both_cmd_abs_pt(char **av, size_t av_pos1, size_t av_pos2);
void	handle_first_char(t_data *data, char *cmd, size_t av_pos);

//file handeling
bool	executable_exists(char *path);
void	get_file_path(t_data *data, char *file_name,
			char **envp, char *in_or_out);
bool	in_file_access(char *file_path);
void	create_and_open_files(t_data *data, char **av);

//fork stuff
void	child_one(t_data *data, int *end, char **envp);
void	child_two(t_data *data, int *end, char **envp);
void	pipex(t_data *data, char **envp);

//error handeling
bool	ac_check(int ac);
void	display_error(t_data *data, char *error);

//mem management
void	free_2d(char **arr);
void	free_3d(char ***arr);
void	free_data(t_data *data);
void	ft_free(char *str);
