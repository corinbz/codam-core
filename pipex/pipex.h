/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:56:48 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/21 18:30:56 by ccraciun         ###   ########.fr       */
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
	bool invalid_infile;
	char **cmd_paths;//executable paths
	char ***cmd_args;//store the flags
	char **path;
} t_data;

//data parsing
void	get_possible_paths(t_data *data, char **envp, char *cmd);
char	*get_cmd_path(char **path_list);
char	**get_cmd_incl_flags(char *raw_cmd);

//file handeling
int		executable_exists(char *path);
char	*get_file_path (char *file_name, char **envp);
int		executable_exists(char *path);
int		in_file_access(char *file_path, char **envp);

//fork stuff
void	child_one(int fd1, char *cmd1, char **cmd1_inc_flags, int *end, char **envp);
void	child_two(int fd2, char *cmd2, char **cmd2_inc_flags, int *end, char **envp);
void    pipex(int f1, int f2, char *cmd1, char *cmd2, char **envp);

//error handeling
bool	ac_check(int ac, char **av);
void	ft_free_all(char **str1, char **str2, char **str3);