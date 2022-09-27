/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:04:56 by nickras           #+#    #+#             */
/*   Updated: 2022/09/09 13:21:32 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -Wextra -Werror main.c ../libftprintf/libftprintf.a && ./a.out ls
//make re && ./pipex infile "cat -e" "grep 3" outfile
//bla

#include "../pipex.h"

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
		options[0] = ft_strdup(cmd);
	if (execve(path, options, envp) == -1)
	{
		free_list(split_cmd);
		perror("exec didnt work\n");
		exit(2);
	}
	else
		free_list(split_cmd);
}

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
	free(path_envp);
}

int	fd_to_infile(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		open_is_minus_one();
	return (fd);
}

int	fd_to_outfile(char *argv)
{
	int	fd;

	fd = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0744);
	if (fd < 0)
		open_is_minus_one();
	return (fd);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		pipefd[2];

	early_errors(argc, envp);
	fd[READ] = fd_to_infile(argv[1]);
	fd[WRITE] = fd_to_outfile(argv[4]);
	if (pipe(pipefd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		fork_minus_one(pid1);
	if (pid1 == 0)
		pid1_is_0(fd, pipefd, argv[2], envp);
	else
	{
		pid2 = fork();
		fork_minus_one(pid2);
		if (pid2 == 0)
			pid2_is_0(fd, pipefd, argv[3], envp);
		close_fds_wait_exit(fd, pipefd, pid1, pid2);
	}
}
