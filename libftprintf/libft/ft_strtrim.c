/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:14:35 by nickras           #+#    #+#             */
/*   Updated: 2022/05/18 12:08:31 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;
	unsigned int	s1len;

	i = 0;
	start = 0;
	end = 0;
	if (!s1)
		return (NULL);
	s1len = (unsigned) ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && s1[i])
	{
		start++;
		i++;
	}
	if (s1[start] == '\0')
		return (ft_strdup(""));
	i = 0;
	while (ft_strchr(set, s1[s1len - i - 1]))
	{
		end++;
		i++;
	}
	return (ft_substr(s1, start, ((size_t)s1len - start - end)));
}

/* int	main(void)
{
 	char s1[] = "       ";
	char set[] = " ";

 	printf("%s\n", ft_strtrim(s1, set));
 	return (0);
} */
