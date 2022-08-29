/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:57:26 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/18 12:06:16 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
NAME
	memcmp -- compare byte string

LIBRARY
	Standard C Library (libc, -lc)

SYNOPSIS
	#include <string.h>

	int
	memcmp(const void *s1, const void *s2, size_t n);

DESCRIPTION
	The memcmp() function compares byte string s1 against byte string s2.
	Both strings are assumed to be n bytes long.

RETURN VALUES
	The memcmp() function returns zero if the two strings are identical, oth-
	erwise returns the difference between the first two differing bytes
	(treated as unsigned char values, so that `\200' is greater than `\0', for
	example).  Zero-length strings are always identical.  This behavior is not
	required by C and portable code should only depend on the sign of the
	returned value. */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((*(unsigned char *)(s1 + i)) > (*(unsigned char *)(s2 + i)))
			return ((*(unsigned char *)(s1 + i)) - \
			(*(unsigned char *)(s2 + i)));
		if ((*(unsigned char *)(s1 + i)) < (*(unsigned char *)(s2 + i)))
			return ((*(unsigned char *)(s1 + i)) - \
			(*(unsigned char *)(s2 + i)));
		i++;
	}
	return (0);
}

/* int	main()
{
	char	haystack[50] = "the w weather is nce n";
	char	needle[50] = "we";

	printf ("strnstr:    %d: \n", memcmp("", "test", 4));
	printf ("ft_strnstr: %d: \n", ft_memcmp("", "test", 4));
	return (0);
} */
