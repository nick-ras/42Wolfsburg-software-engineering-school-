/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:02:47 by nickras           #+#    #+#             */
/*   Updated: 2022/06/14 18:05:08 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	length;

	length = 0;
	while (s[length])
	{
		if (s[length] == (char)c)
			return ((char *)s + length);
		length++;
	}
	if (s[length] == (char)c)
		return ((char *)s + length);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dstr;
	unsigned char	*srcr;

	dstr = (unsigned char *)dst;
	srcr = (unsigned char *)src;
	if (!n || (!dst && !src && n > 0))
		return (dstr);
	i = 0;
	while (i < n)
	{
		dstr[i] = srcr[i];
		i++;
	}
	return (dstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*concat;
	size_t		count;
	size_t		lenconcat;

	lenconcat = 0;
	count = 0;
	while (s1[count++] != '\0')
		lenconcat++;
	count = 0;
	while (s2[count++] != '\0')
		lenconcat++;
	concat = malloc(sizeof(char) * (lenconcat + 1));
	if (!concat)
		return (NULL);
	ft_memcpy(concat, s1, ft_strlen(s1));
	ft_memcpy(concat + ft_strlen(s1), s2, ft_strlen(s2));
	concat[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (concat);
}
