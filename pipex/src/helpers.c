/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:04:48 by nickras           #+#    #+#             */
/*   Updated: 2022/09/08 14:46:45 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	early_errors(int argc, char **envp)
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

void	close_fds_wait_exit(int *fd, int *pipefd, pid_t pid1, pid_t pid2)
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

void	fork_minus_one(pid_t pid)
{
	if (pid == -1)
	{
		ft_printf("fork error\n");
		exit (2);
	}
}
