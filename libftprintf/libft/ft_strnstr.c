/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:57:57 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/23 17:58:56 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + count] == needle[count] \
		&& needle[count] && (i + count) < len)
		{
			if (needle[count + 1] == '\0')
				return ((char *)haystack + i);
			count++;
		}
		i++;
		count = 0;
	}
	return (0);
}

/* int main()
{
	char haystack[4] = "AAAA";
	char needle[5] = "24444";


	//printf ("strnstr:    %s: \n", strnstr(haystack, needle, 5));
	printf ("ft_strnstr: %s: \n", ft_strnstr(haystack, needle, 5));;
	//printf("%p\n", strnstr(s1, "AA", 2));
	return (0);
} */
