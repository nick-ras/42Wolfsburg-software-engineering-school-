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

// char **commands(char **argv)
// {
// 	char *arr1;
// 	char *joined;
// 	char **split;
// 	arr1 = malloc(sizeof(argv[2] + 2));
// 	ft_strlcpy(arr1, argv[2], (int)ft_strlen(argv[2]));
// 	arr1[ft_strlen(argv[2]) - 1] = ' ';
// 	arr1[ft_strlen(argv[2])] = '\0';
// 	joined = ft_strjoin(arr1, argv[3]);
// 	split = ft_split(joined, ' ');

// 	free(arr1);
// 	arr1 = NULL;
// 	free(joined);
// 	joined = NULL;
// 	return (split);
// }

void	free_list(char **path_envp)
{
	int i;

	i = 0;
	while (path_envp[i])
	{
		free(path_envp[i]);
		path_envp[i] == NULL;
		i++;
	}
}

char	*set_paths(char *cmd, char *argument, char *envp_index)
{
	char	**path_envp;
	char *working_path;
	int j;
	int the_path = -1;
	char	*addon;

	j = 0;
	path_envp = ft_split(envp_index, ':');
	addon = ft_strjoin("/", cmd);
	while (path_envp[j])
	{
		the_path = access(ft_strjoin(path_envp[j], addon), R_OK);
		if (the_path == 0)
		{
			working_path = ft_strjoin(path_envp[j], addon);
			free_list(path_envp);
			free(addon);
			if (argument)
				free (argument);
			free(cmd);
			return (working_path);
		}
		j++;
	}
	perror("enter valid command");
	exit (2);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char **split_cmd;

	if (ft_strnstr(cmd, " ", ft_strlen(cmd)))
		split_cmd = ft_split(cmd, ' ');
	//ft_printf("cmd: %s\n ", cmd);
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
		{
			// ft_printf("print whole envp-> %s\n", envp[i]);
			if (ft_strnstr(cmd, " ", ft_strlen(cmd)))
				return (set_paths(split_cmd[0], split_cmd[1], envp[i]));
			else
				return (set_paths(cmd, NULL, envp[i]));
		}
		i++;
	}
}

void	execute(char *cmd, char **envp, char *path)
{
	char	*options[3] = {NULL, NULL, NULL};
	char	*arr[50];
	char	**split_cmd;

	if (ft_strnstr(cmd, " ", ft_strlen(cmd)))
	{
		split_cmd = ft_split(cmd, ' ');
		options[0] = split_cmd[0];
		options[1] = split_cmd[1];
	}
	else
		options[0] = cmd;
	if (execve(path, options, envp) == -1)
	{
		free_list(split_cmd);
		perror("exec didnt work\n");
		exit(1);
	}
	else
		free_list(split_cmd);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char *path2;
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		pipefd[2];
	int		status;

	if (!envp)
	{
		perror("could not find envp!\n");
		exit(2);
	}

	if (argc != 5)
	{
		ft_printf("argc is not 5\n");
		exit (2);
	}

 //TO DO FEED IT COMMAND
	path = get_path(argv[2], envp);
	path2 = get_path(argv[3], envp);
	//printf("path: %s  \n", path);

	fd[READ] = open(argv[1], O_RDONLY);
	fd[WRITE] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 744);
	if (fd[READ] < 0 || fd[WRITE] < 0)
	{
		perror("open doesnt work");
		return (-1);
	}
	if (pipe(pipefd) == -1) //CREATE PIPE
		return (1);
	pid1 = fork();
	if (pid1 == -1)
	{
		//what to free?
		perror("fork function error\n");
		exit(1);
	}
	if (pid1 == 0) //PID 1
	{
		close(pipefd[0]);
		close(fd[1]);
		if (dup2(fd[READ], STDIN_FILENO) < 0 || \
		dup2(pipefd[WRITE], STDOUT_FILENO) < 0)
		{
			ft_printf("dup error\n"),
			exit(1);
		}
		close(pipefd[1]);
		close(fd[0]);
		execute(argv[2], envp, path);
		ft_printf("first didnt exec\n");
		return (0);
	}
	else
	{
		//waitpid(pid1, NULL, 0);
		// close(fd[0]);
		// close(pipefd[1]);
		pid2 = fork();
		if (pid2 == -1)
		{
			ft_printf("fork error\n");
			return (3);
		}
		if (pid2 == 0) //PID2
		{
			close(pipefd[WRITE]);
			close(fd[READ]);
			if (dup2(pipefd[READ], STDIN_FILENO) < 0 \
			|| dup2(fd[WRITE], STDOUT_FILENO) < 0)
			{
				ft_printf("dup error\n"),
				exit(1);
			}
			close(fd[WRITE]);
			close(pipefd[READ]);
			execute(argv[3], envp, path2);
			ft_printf("second  didnt exec\n");
		}
		close(fd[0]);
		close(fd[1]);
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(pid1, &status, 0);
		waitpid(pid2, &status, 0);
		free(path);
		free(path2);
		exit (0);
	}
}



		// char *buf[20];
		// int test_fd = read(STDIN_FILENO, buf, 19);
		// buf[19] = '\0';
		// ft_printf("test of fd[READ]%s", buf);