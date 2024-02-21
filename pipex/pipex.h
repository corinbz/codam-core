/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:56:48 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/21 15:35:15 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
# include <stddef.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "./libft/libft.h"

char **get_possible_paths(char **env_path, char *cmd);
int executable_exists(char *path);
char *get_cmd_path(char **path_list);
char **get_cmd_incl_flags(char *raw_cmd);
void process_child(int *p, char **av, char **envp);
char *get_file_path (char *file_name, char **envp);
int executable_exists(char *path);
int in_file_access(char *file_path, char **envp);
void child_one(int fd1, char *cmd1, char **cmd1_inc_flags, int *end, char **envp);
void child_two(int fd2, char *cmd2, char **cmd2_inc_flags, int *end, char **envp);
void    pipex(int f1, int f2, char *cmd1, char *cmd2, char **envp);