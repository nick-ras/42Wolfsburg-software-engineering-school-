/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:15:24 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/18 12:04:15 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name ft_strjoin
Prototype char *ft_strjoin(char const *s1, char const *s2);
Turn in files -
Parameters s1: The prefix string.
s2: The suffix string.
Return value The new string.
NULL if the allocation fails.
External functs. malloc
Description Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’. */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*concat;
	size_t		count;
	size_t		lenconcat;

	lenconcat = 0;
	count = 0;
	if (!s1)
		return (NULL);
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

/* int	main(void)
{
	char s1[] = "1234";
	char s2[] = "22";

	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
} */
