/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:05:56 by nickras           #+#    #+#             */
/*   Updated: 2022/09/06 18:19:11 by nickras          ###   ########.fr       */
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

void	pid2_is_0(int *fd, int *pipefd, char *cmd, char **envp)
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
