/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccraciun <ccraciun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:28:48 by ccraciun          #+#    #+#             */
/*   Updated: 2024/02/11 15:35:05 by ccraciun         ###   ########.fr       */
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
	int end[2];
	pipe(end);
	__pid_t parent = fork();
	if(parent < 0)
		return (EXIT_FAILURE);
	if(parent != 0)
		//we are in the child process
		process_child(end, av, envp);
	else
		return (0);
	return (0);
}
void	pipex(int f1, int f2);