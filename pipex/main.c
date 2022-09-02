// gcc -Wextra -Werror main.c ../libftprintf/libftprintf.a && ./a.out ls

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include "../libftprintf/ft_printf.h"
#include <sys/types.h>
#include <sys/wait.h>
#define READ 0
#define WRITE 1

char **commands(char **argv)
{
	char *arr1;
	char *joined;
	char **split;

	arr1 = malloc(sizeof(argv[2] + 2));
	ft_strlcpy(arr1, argv[2], (int)ft_strlen(argv[2]));
	arr1[ft_strlen(argv[2]) - 1] = ' ';
	arr1[ft_strlen(argv[2])] = '\0';
	joined = ft_strjoin(arr1, argv[3]);
	split = ft_split(joined, ' ');

	free(arr1);
	arr1 = NULL;
	free(joined);
	joined = NULL;
	return (split);
}

char	**set_paths(char **cmds, char *envp_index)
{
	char	*str;
	char	**path_envp;
	char	*path1;
	char **both_paths;
	int found_first;
	int j;
	int	first;

	first = 0;
	j = 0;
	path_envp = ft_split(envp_index, ':');
	while (path_envp[j])
	{
		//|| access(ft_strjoin(path_envp[j], ft_strjoin("/", cmds[2])), \
			R_OK) == 0
		int the_path = access(ft_strjoin(path_envp[j], ft_strjoin("/", cmds[0])), R_OK);
		if (the_path == 0 && first == 0)
		{
			// To do: free path arrays!
			path1 = ft_strjoin(ft_strjoin(path_envp[j], ft_strjoin("/", cmds[0])), " ");
				first = 1;
			}
			else if (the_path == 0 && first == 1)
			{
				return (ft_split(ft_strjoin(path1, ft_strjoin(path_envp[j],	ft_strjoin("/", cmds[2]))), ' '));
			}
		}
		j++;
}

char	**get_path1(char **cmds, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
			return (set_paths(cmds, envp[i]));
		i++;
	}
}

void execute(char *cmd, char *argument, char **envp, char *path)
{
	char *options[3] = {NULL, NULL, NULL};
	char *arr[50];

	if (ft_strncmp(cmd, "ls", ft_strlen("ls")) == 0)
	{
		options[0] = cmd;
		options[1] = argument;
		// printf()
		if (execve(path, options, envp) == -1)
		{
			perror(ft_strjoin(path, ft_strjoin("/", cmd)));
			exit(1);
		}
	}
}


int main(int argc, char **argv, char **envp)
{
	char **paths;
	char **cmds;
	char *buffer[400];
	pid_t pid1;
	int pipefd[2];
	int reader;
	int fd[2];

	cmds = commands(argv);
	if (!envp)
	{
		perror("could not find envp!\n");
		exit(2);
	}


	paths = get_path1(cmds, envp); // gets full path of cmd1 program
	printf("paths: %s   second  %s\n", paths[0], paths[1]);



	fd[READ] = open(argv[1], O_RDONLY); //not the pipe!
	fd[WRITE] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 744);
	if (fd[READ] < 0 || fd[WRITE] < 0)
	{
		perror("open doesnt work");
		return (-1);
	}


	if (pipe(pipefd) == -1) // Create a pipe and error check
		return (1);

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork function error\n"); // will also print errno
		exit(1);
	}
	if (pid1 == 0)//-----------------------------------------------
	{
		//cmd1 will be executed by the child and save in pipfd[0]
		if (dup2(pipefd[1], STDOUT_FILENO) < 0 \
		|| dup2(fd[0], STDIN_FILENO) < 0) //infile becomes stdin
		{
			ft_printf("dup error\n"),
			exit(1);
		}
		close(pipefd[0]);
		close(fd[1]);						// Done writing, close pipe's write end.
		close(pipefd[1]);
		close(fd[0]);
		execute(cmds[0], cmds[1], envp, paths[0]); // child proces is replaced by execve output
		ft_printf("second  didnt exec\n");
		return (0);
	}
	else
	{               //second fork
		int	pid2 = fork(); 
		if (pid2 == - 1)
		{
			ft_printf("fork error\n");
			return (3);
		}
		if (pid2 == 0)		//--------------------------------In the parent process, we want end[0] to be our stdin (end[0] reads from end[1] the output of cmd1), and outfile to be our stdout
		{
			if (dup2(pipefd[READ], STDIN_FILENO) < 0 \
			|| dup2(fd[WRITE], STDOUT_FILENO) < 0) //infile becomes stdin
			{
				ft_printf("dup error\n"),
				exit(1);
			}
			printf("cmds2  %s cmds3  %s  paths1  %s\n", cmds[2], cmds[3], paths[1]);
			close(pipefd[0]);
			close(fd[1]);						// Done writing, close pipe's write end.
			close(pipefd[1]);
			close(fd[0]);
			execute(cmds[2], cmds[3], envp, paths[1]);
			ft_printf("second  didnt exec\n");
			return (0);
		}
		else
		{ //IN PARENT
			waitpid(pid1, NULL, 0); // Wait for child.
			waitpid(pid2, NULL, 0); // Wait for child.

			close(pipefd[0]);			// Read everything, close pipe's readend.
			close(pipefd[1]);			// Nothing to write, close pipe's writeend.
			close(fd[0]);	
			close(fd[1]);
			return (0);
		}
	}
}
