/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:56:48 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/27 10:05:41 by corin            ###   ########.fr       */
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
	char	*infile_path;
	bool	invalid_infile;
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

//file handeling
bool	executable_exists(char *path);
char	*get_file_path(t_data *data, char *file_name, char **envp);
bool	in_file_access(char *file_path, char **envp);
void	create_and_open_files(t_data *data, char **av);

//fork stuff
void	child_one(t_data *data, int *end, char **envp);
void	child_two(t_data *data, int *end, char **envp);
void	pipex(t_data *data, char **argv, char **envp);

//error handeling
bool	ac_check(int ac, char **av);
void	display_error(t_data *data, char *error);

//mem management
void	free_2d(char **arr);
void	free_3d(char ***arr);
void	free_data(t_data *data);
void	ft_free(char *str);
