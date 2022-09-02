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
		if (access(ft_strjoin(path_envp[j], ft_strjoin("/", cmds[0])), R_OK) \
			== 0 || access(ft_strjoin(path_envp[j], ft_strjoin("/", cmds[2])), \
			R_OK) == 0)
		{
			// To do: free path arrays!
			if (first == 0)
			{
				path1 = ft_strjoin(ft_strjoin(path_envp[j], ft_strjoin("/", cmds[0])), " ");
				first++;
			}
			else if (first == 1)
			{
				return (ft_split(ft_strjoin(path1, ft_strjoin(path_envp[j],	ft_strjoin("/", cmds[2]))), ' '));
			}
		}
		j++;
	}
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
		if (execve(path, options, envp) == -1)
		{
			perror(ft_strjoin(path, ft_strjoin("/", cmd)));
			exit(1);
		}
		else
			execve(path, options, envp);
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

	cmds = commands(argv);
	if (!envp)
	{
		ft_printf("could not find envp!\n");
		exit(1);
	}



	paths = get_path1(cmds, envp); // gets full path of cmd1 program
	printf("paths: %s     %s\n", paths[0], paths[1]);
	if (pipe(pipefd) == -1) // Create a pipe and error check
		return (1);



	pipefd[0] = open(argv[1], O_RDONLY);
	pipefd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 744);
	if (pipefd[0] < 0 || pipefd[1] < 0)
		return (-1);


	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork function error\n"); // will also print errno
		exit(1);
	}
	else if (pid1 == 0)-----------------------------------------------
	{
		//cmd1 will be executed by the child and save in pipfd[0]
		if (dup2(pipefd[1], STDOUT_FILENO) < 0 \
		|| dup2(pipefd[0], STDIN_FILENO) < 0) //infile becomes stdin
		{
			ft_printf("dup error\n"),
			exit(1);
		}
		close(pipefd[0]);
		close(pipefd[1]);						// Done writing, close pipe's write end.
		execute(cmds[0], cmds[1], envp, paths[0]); // child proces is replaced by execve output
	}

	int pid2 = fork();
	if (pid2 == - 1)
	{
		ft_printf("fork error\n");
		return (3);
	}
	if (pid2 == 0)//----------------------------------------------------In the parent process, we want end[0] to be our stdin (end[0] reads from end[1] the output of cmd1), and outfile to be our stdout
	{
		wait(NULL);
		dup2(STDIN_FILENO, ends[0]), //output of exec becomes ends[0]
		dup2(pipefd[1], STDOUT_FILENO); //outfile is stdout, which after next line will be output of exec
		execute(cmds[2], cmds[3], envp, paths[1]);
		close(pipefd[0]);
		close(pipefd[1]);
	}

	// IN PARENT
	waitpid(pid1, NULL, 0); // Wait for child.
	waitpid(pid2, NULL, 0); // Wait for child.

	reader = read(0, buffer, 5);//read from stdin? which is same as stdout
	if (reader == -1)
	{
		ft_printf("read error\n");
		return (3);
	}
	buffer[reader] = '\0';

	close(pipefd[0]);					// Read everything, close pipe's read end.
	close(pipefd[1]);					// Nothing to write, close pipe's write end.
	printf("%s\"\n", buffer); // prints output
	return (0);
}
