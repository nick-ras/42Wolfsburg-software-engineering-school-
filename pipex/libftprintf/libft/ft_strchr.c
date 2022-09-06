/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:57:43 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/16 14:35:25 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* int main(void)
{
	int	c = 0;
	const char s[] = "\0";
	
	printf("correct %p\n", strchr(s, c));
	printf("myown   %p\n", ft_strchr(s, c));
	return (0);
} */
