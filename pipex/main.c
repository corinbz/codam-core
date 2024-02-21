/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:28:48 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/21 12:23:20 by ccraciun         ###   ########.fr       */
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
	int end[2];
	int status;
	file1 = open("in.txt", O_RDONLY);
	file2 = open("out.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
	char *cmd[] = {"cat", NULL};
		dup2(file1, STDIN_FILENO);
		dup2(file2, STDOUT_FILENO);
		if (execve("/usr/bin/cat",cmd,envp) == -1)
			perror("execve failed to run:");
		close(file1);
		close(file2);
	return (0);
}
