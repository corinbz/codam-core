/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:28:48 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/24 11:53:58 by ccraciun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

/*
$> ./pipex infile "ls -l" "wc -l" outfile
Should behave like: < infile ls -l | wc -l > outfile

./pipex infile cmd1 cmd2 outfilepipe()
 |
 |-- fork()
      |
      |-- child // cmd1
      :     |--dup2()
      :     |--close end[0]
      :     |--execve(cmd1)
      :
      |-- parent // cmd2
            |--dup2()
            |--close end[1]
            |--execve(cmd2)

fd[0] is set up for reading, fd[1] is set up for writing
pipe is used to communicate between processes (forks). 

    infile                                             outfile
as stdin for cmd1                                 as stdout for cmd2            
       |                        PIPE                        ↑
       |           |---------------------------|            |
       ↓             |                       |              |
      cmd1   -->    end[1]       ↔       end[0]   -->     cmd2           
                     |                       |
            cmd1   |---------------------------|  end[0]
           output                             reads end[1]
         is written                          and sends cmd1
          to end[1]                          output to cmd2
       (end[1] becomes                      (end[0] becomes 
        cmd1 stdout)                           cmd2 stdin)

On linux, you can check your fds currently open with the command ls -la /proc/$$/fd
			
*/


int main(int ac, char **av, char **envp)
{
	int file1;
	int file2;
	t_data data;
	
	if (!ac_check(ac,av))
		return (perror("Invalid number of arguments"), EXIT_FAILURE);
	ft_bzero(&data, sizeof(t_data));
	get_possible_paths(&data, envp, av[2]);
	free_data(&data);
	// printf("%s\n",data->path[0]);
	// file1 = open(av[1], O_RDONLY);
	// file2 = open(av[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	// if (file1 == -1 || file2 == -1)
	// 	return(perror("error opening / creating files"),2);
	// pipex(file1, file2, av[2], av[3], envp);
	// // char *filepath = get_cmd_path(get_possible_paths(envp, av[2]));
	// // printf("path is %s\n", filepath);
	// close(file1);
	// close(file2);
	// return (0);
}
