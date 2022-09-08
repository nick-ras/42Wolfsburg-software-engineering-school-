/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:20:56 by nickras           #+#    #+#             */
/*   Updated: 2022/09/08 15:12:05 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <errno.h>
# include <fcntl.h>
# include "./libftprintf/ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>
# define READ 0
# define WRITE 1

//main.c
void	execute(char *cmd, char **envp, char *path);
void	free_list(char **path_envp);
int		main(int argc, char **argv, char **envp);
int		fd_to_infile(char *argv);
int		fd_to_outfile(char *argv);
void	path__is_null_so_free(char **path_envp, char *addon);

//helpers.c
void	early_errors(int argc, char **envp);
void	close_fds_wait_exit(int *fd, int *pipefd, pid_t pid1, pid_t pid2);
void	open_is_minus_one(void);
void	fork_minus_one(pid_t pid);

//paths.c
char	*make_path_executable(char **path_envp, char *addon, \
char *cmd, char *path);
char	*set_paths(char *cmd, char *envp_index);
char	*cmd_get_command(char *cmd);
char	*get_path(char *cmd, char **envp);

//pids.c
void	pid1_is_0(int *fd, int *pipefd, char *cmd, char **envp);
void	pid2_is_0(int *fd, int *pipefd, char *cmd, char **envp);

#endif