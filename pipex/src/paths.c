/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:05:22 by nickras           #+#    #+#             */
/*   Updated: 2022/09/08 15:12:36 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*free_stuff_and_return(char **path_envp, char *addon, \
char *arg_idx, char *path)
{
	free_list(path_envp);
	free(addon);
	if (ft_strnstr(arg_idx, " ", ft_strlen(arg_idx)))
	{
		free(arg_idx);
		arg_idx = NULL;
	}
	return (path);
}

char	*free_stuff_and_return_cmd(char **path_envp, char *addon, \
char *arg_idx, char *path)
{
	free_list(path_envp);
	free(addon);
	free(path);
	path = NULL;
	path = ft_strdup(arg_idx);
	if (ft_strnstr(arg_idx, " ", ft_strlen(arg_idx)))
	{
		free(arg_idx);
		arg_idx = NULL;
	}
	return (path);
}

char	*make_path_executable(char **path_envp, char *addon, \
char *arg_idx, char *path)
{
	int	j;

	j = 0;
	while (path_envp[j])
	{
		path = ft_strjoin(path_envp[j], addon);
		if (access(arg_idx, R_OK) == 0)
			return (free_stuff_and_return_cmd(path_envp, addon, arg_idx, path));
		else if (access(path, R_OK) == 0)
		{
			return (free_stuff_and_return(path_envp, addon, arg_idx, path));
		}
		free(path);
		path = NULL;
		j++;
	}
	return (NULL);
}

// write(2, path, ft_strlen(path));
// 	perror("hi\n");
// 	exit(2);

void	path__is_null_so_free(char **path_envp, char *addon)
{
	free_list(path_envp);
	free(addon);
	perror("enter valid command");
	exit (2);
}

char	*set_paths(char *arg_idx, char *envp_index)
{
	char	**path_envp;
	char	*path;
	char	*addon;

	path = NULL;
	if (ft_strnstr(arg_idx, " ", ft_strlen(arg_idx)))
	{
		arg_idx = cmd_get_command(arg_idx);
		addon = ft_strjoin("/", arg_idx);
	}
	else
	{
		arg_idx = ft_strdup(arg_idx);
		addon = ft_strjoin("/", arg_idx);
	}
	path_envp = ft_split(envp_index, ':');
	path = make_path_executable(path_envp, addon, arg_idx, path);
	if (!ft_strnstr(arg_idx, " ", ft_strlen(arg_idx)))
		free(arg_idx);
	if (path == NULL)
		path__is_null_so_free(path_envp, addon);
	return (path);
}
