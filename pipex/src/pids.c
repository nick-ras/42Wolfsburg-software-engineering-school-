/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:05:56 by nickras           #+#    #+#             */
/*   Updated: 2022/09/08 15:11:16 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pid1_is_0(int *fd, int *pipefd, char *cmd, char **envp)
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

void	pid2_is_0(int *fd, int *pipefd, char *argv, char **envp)
{
	char	*path;

	path = get_path(argv, envp);
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
	path = get_path(argv, envp);
	execute(argv, envp, path);
	ft_printf("second  didnt exec\n");
}

char	*get_path(char *arg_idx, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
			return (set_paths(arg_idx, envp[i]));
		i++;
	}
	perror("could not find path in envp");
	exit (2);
}

char	*cmd_get_command(char *arg_idx)
{
	int		i;
	int		len;
	char	*new_cmd;

	i = 0;
	while (arg_idx[i] != ' ')
	{
		i++;
		len = i;
	}
	new_cmd = malloc(sizeof(char) * len + 1);
	ft_strlcpy(new_cmd, arg_idx, len + 1);
	return (new_cmd);
}
