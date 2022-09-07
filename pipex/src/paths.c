/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:05:22 by nickras           #+#    #+#             */
/*   Updated: 2022/09/07 12:40:59 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*free_stuff_and_return(char **path_envp, char *addon, \
char *cmd, char *path)
{
	free_list(path_envp);
	free(addon);
	if (ft_strnstr(cmd, " ", ft_strlen(cmd)))
	{
		free(cmd);
		cmd = NULL;
	}
	return (path);
}

char	*free_stuff_and_return_cmd(char **path_envp, char *addon, \
char *cmd, char *path)
{
	free_list(path_envp);
	free(addon);
	free(path);
	path = NULL;
	path = ft_strdup(cmd);
	if (ft_strnstr(cmd, " ", ft_strlen(cmd)))
	{
		free(cmd);
		cmd = NULL;
	}
	return (path);
}

char	*make_path_executable(char **path_envp, char *addon, \
char *cmd, char *path)
{
	int	j;

	j = 0;
	while (path_envp[j])
	{
		path = ft_strjoin(path_envp[j], addon);
		if (access(cmd, R_OK) == 0)
			return (free_stuff_and_return_cmd(path_envp, addon, cmd, path));
		else if (access(path, R_OK) == 0)
			return (free_stuff_and_return(path_envp, addon, cmd, path));
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
	{
		cmd = cmd_get_command(cmd);
		addon = ft_strjoin("/", cmd);
	}
	path_envp = ft_split(envp_index, ':');
	path = make_path_executable(path_envp, addon, cmd, path);
	if (!ft_strnstr(cmd, " ", ft_strlen(cmd)))
		free(cmd);
	if (path == NULL)
	{
		free_list(path_envp);
		free(addon);
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
