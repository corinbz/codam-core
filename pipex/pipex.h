/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corin <corin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:56:48 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/25 13:49:33 by corin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
# include <stddef.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "./libft/libft.h"
#include <stdbool.h>

typedef struct s_data
{
	int in_fd;
	int out_fd;
	char *infile_path;
	bool invalid_infile;
	char *cmd_paths[2];
	// char *cmd2_path;
	char **cmd1_args;
	char **cmd2_args;
	char **possible_paths;
} t_data;

//data parsing
void	get_possible_paths(t_data *data, char **envp);
void	get_cmd_path(t_data *data, char *cmd, size_t cmd_nr);
void	get_cmd_incl_flags(t_data *data, char *raw_cmd, size_t cmd_nr);

//file handeling
int		executable_exists(char *path);
char	*get_file_path (char *file_name, char **envp);
int		executable_exists(char *path);
int		in_file_access(char *file_path, char **envp);

//fork stuff
void	child_one(t_data *data, int *end, char **envp);
void    pipex(t_data *data, char **argv, char **envp);

//error handeling
bool	ac_check(int ac, char **av);
void	display_error(t_data *data, char *error);

//mem management
void	free_2d(char **arr);
void	ft_free(char *str);
void	free_data(t_data *data);
