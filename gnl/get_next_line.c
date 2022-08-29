/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:55:19 by nickras           #+#    #+#             */
/*   Updated: 2022/06/17 18:55:23 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*put_s_str_leftover_in_buf(char *s_str)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (s_str[i] != '\n' && s_str[i] != '\0')
	{
		buf[i] = s_str[i];
		i++;
	}
	if (s_str[i] == '\n')
		buf[i++] = '\n';
	buf[i] = '\0';
	while (s_str[i] != '\0')
		s_str[j++] = s_str[i++];
	s_str[j] = '\0';
	return (buf);
}

void	edit_buf_and_s_str(char *s_str, char *buf)
{
	int		i;
	int		j;

	i = 0;
	if (!buf)
		return ;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	j = 0;
	if (buf[i] == '\n')
		i++;
	while (buf[i] != '\0')
	{
		s_str[j++] = buf[i];
		buf[i] = '\0';
		i++;
	}
	s_str[j] = '\0';
}

char	*read_lines(int fd, char *s_str, char *buf, char *temp)
{
	int		read_count;
	char	*char_ptr;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!ft_strchr(buf, '\n'))
	{
		read_count = read(fd, temp, BUFFER_SIZE);
		if (read_count <= 0)
		{
			free(temp);
			if (read_count == -1 || buf[0] == '\0')
			{
				free(buf);
				return (NULL);
			}
			return (buf);
		}
		temp[read_count] = '\0';
		char_ptr = buf;
		buf = ft_strjoin(buf, temp);
		free(char_ptr);
	}
	free(temp);
	edit_buf_and_s_str(s_str, buf);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	s_str[BUFFER_SIZE];
	char		*buf;

	if (!s_str[0])
		s_str[0] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= __INT_MAX__)
	{
		return (NULL);
	}
	if (ft_strchr(s_str, '\n'))
		return (put_s_str_leftover_in_buf(s_str));
	else
	{
		buf = put_s_str_leftover_in_buf(s_str);
		buf = read_lines(fd, s_str, buf, NULL);
		return (buf);
	}
}
