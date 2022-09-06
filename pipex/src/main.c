// gcc -Wextra -Werror main.c ../libftprintf/libftprintf.a && ./a.out ls
//make re && ./pipex infile "cat -e" "grep 3" outfile

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

void	free_list(char **path_envp)
{
	int	i;

	i = 0;
	while (path_envp[i])
	{
		free(path_envp[i]);
		path_envp[i] = NULL;
		i++;
	}
}

char	*cmd_get_command(char *cmd)
{
	int		i;
	int		len;
	char	*new_cmd;

	i = 0;
	while (cmd[i] != ' ')
	{
		i++;
		len = i;
	}
	new_cmd = malloc(sizeof(char) * len + 1);
	ft_strlcpy(new_cmd, cmd, len + 1);
	return (new_cmd);
}

char	*make_path_executable(char **path_envp, char *addon, \
char *cmd, char *path)
{
	int		access_int;
	int		j;

	j = 0;
	while (path_envp[j])
	{
		path = ft_strjoin(path_envp[j], addon);
		access_int = access(path, R_OK);
		if (access_int == 0)
		{
			free_list(path_envp);
			free(addon);
			if (ft_strnstr(cmd, " ", ft_strlen(cmd)))
				free(cmd);
			return (path);
		}
		free(path);
		path = NULL;
		j++;
	}
	return (NULL);
}

char	*set_paths(char *cmd, char *envp_index)
{
	char	**path_envp;
	char	*path;
	char	*addon;

	path = NULL;
	if (ft_strnstr(cmd, " ", ft_strlen(cmd)))
		cmd = cmd_get_command(cmd);
	//ft_printf("cmd %s\n", cmd);
	path_envp = ft_split(envp_index, ':');
	addon = ft_strjoin("/", cmd);
	path = make_path_executable(path_envp, addon, cmd, path);
	if (path == NULL)
	{
		free_list(path_envp);
		free(addon);
		if (ft_strnstr(cmd, " ", ft_strlen(cmd)))
			free(cmd);
		perror("enter valid command");
		exit (2);
	}
	else
		return (path);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
			return (set_paths(cmd, envp[i]));
		i++;
	}
	perror("could not find path in envp");
	exit (2);
}

void	execute(char *cmd, char **envp, char *path)
{
	char	*options[3];
	char	**split_cmd;

	options[0] = NULL;
	options[1] = NULL;
	options[2] = NULL;
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
		exit(2);
	}
	else
		free_list(split_cmd);
}

void	early_errors(int argc,char **envp)
{
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
}

void	pid1_is_0(int *fd, int *pipefd, char * cmd, char **envp)
{
	char	*path;

	path = get_path(cmd, envp);
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
	execute(cmd, envp, path);
	ft_printf("first didnt exec\n");
}

void	pid2_is_0(int *fd, int *pipefd,char * cmd, char **envp)
{
	char	*path;

	path = get_path(cmd, envp);
	close(pipefd[WRITE]);
	close(fd[READ]);
	if (dup2(pipefd[READ], STDIN_FILENO) < 0 \
	|| dup2(fd[WRITE], STDOUT_FILENO) < 0)
	{
		ft_printf("dup error\n"),
		exit(2);
	}
	close(fd[WRITE]);
	close(pipefd[READ]);
	path = NULL;
	path = get_path(cmd, envp);
	execute(cmd, envp, path);
	ft_printf("second  didnt exec\n");
}

void close_fds_wait_exit(int *fd, int *pipefd, pid_t pid1, pid_t pid2)
{
	int		status;

	close(fd[0]);
	close(fd[1]);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	exit (0);
}

void	open_is_minus_one(void)
{
	perror("open doesnt work");
	exit(2);
}

void	pid_minus_one(pid_t pid)
{
	if (pid == -1)
	{
		ft_printf("fork error\n");
		exit (2);
	}
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		pipefd[2];

	early_errors(argc, envp);
	//printf("path: %s  \n", path);
	fd[READ] = open(argv[1], O_RDONLY);
	fd[WRITE] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 744);
	if (fd[READ] < 0 || fd[WRITE] < 0)
		open_is_minus_one();
	if (pipe(pipefd) == -1) //CREATE PIPE
		return (1);
	pid1 = fork();
	pid_minus_one(pid1);
	if (pid1 == 0) //PID 1
		pid1_is_0(fd, pipefd, argv[2], envp);
	else
	{
		//waitpid(pid1, NULL, 0);
		// close(fd[0]);
		// close(pipefd[1]);
		pid2 = fork();
		pid_minus_one(pid2);
		if (pid2 == 0) //PID2
			pid2_is_0(fd, pipefd, argv[3], envp);
		close_fds_wait_exit(fd, pipefd, pid1, pid2);
	}
}

