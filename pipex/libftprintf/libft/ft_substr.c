/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:43:53 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/17 22:11:25 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name ft_substr
Prototype char *ft_substr(char const *s, unsigned int start,
size_t len);
Turn in files -
Parameters s: The string from which to create the substring.
start: The start index of the substring in the
string ’s’.
len: The maximum length of the substring.
Return value The substring.
NULL if the allocation fails.
External functs. malloc
Description Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’. 
gcc -Wall -Werror -Wextra ft_substr.c ft_strlen.c 
ft_memcpy.c ft_strdup.c && ./a.out
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*target;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if ((size_t)start > ft_strlen(s))
		len = 0;
	else if (len + (size_t)start > ft_strlen(s))
		len = ft_strlen(s) - (size_t)start;
	target = malloc(sizeof(*s) * (len + 1));
	if (!target)
		return (NULL);
	while (i < len)
	{
		target[i] = s[start + i];
		i++;
	}
	target[i] = '\0';
	return (target);
}

/* int	main(void)
{
	char s[] = "tripouille";
	unsigned int start;
	size_t len;
	
	start = 0;
	len = 42000;
	printf("%s\n", ft_substr(s, start, len));
	return (0);
}*/
