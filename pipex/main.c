/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:28:48 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/24 12:31:17 by ccraciun         ###   ########.fr       */
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

void initialiaze_data(t_data *data, char **envp, char **av)
{
	ft_bzero(data, sizeof(t_data));
	data->in_fd = open(av[1], O_RDONLY);
	data->out_fd = open(av[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (data->in_fd == -1 || data->out_fd == -1)
	{
		perror("Error opening file");
		free_data(data);
		exit(EXIT_FAILURE);
	}
	get_possible_paths(data, envp);
	get_cmd_path(data, av[2]);
	printf("cmd1 path is %s\n", data->cmd1_path);
}

int main(int ac, char **av, char **envp)
{
	t_data data;
	
	if (!ac_check(ac,av))
		return (perror("Invalid number of arguments"), EXIT_FAILURE);
	initialiaze_data(&data, envp, av);	
	// pipex(data.in_fd, data.out_fd, av[2], av[3], envp);
	// // char *filepath = get_cmd_path(get_possible_paths(envp, av[2]));
	// // printf("path is %s\n", filepath);
	// close(file1);
	// close(file2);
	free_data(&data);
	return (0);
}
