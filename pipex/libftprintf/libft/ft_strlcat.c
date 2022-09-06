/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:57:46 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/16 21:34:28 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* gcc -Wall -Werror -Wextra ft_strlcat.c ft_strlen.c -lbsd && ./a.out */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	count = 0;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (src[count] && dstsize > dstlen + count + 1)
	{
		dst[dstlen + count] = src[count];
		count++;
	}
	dst[count + dstlen] = '\0';
	return (srclen + dstlen);
}

/* int	main(void)
{
	char	dst[] = "rrrr         j";
	char	src[] = "";
	size_t	dstsize = 15;

	printf("ORIG: %zu\n", strlcat(dst, src, dstsize));
	printf("ORIG %s\n", dst);
	printf("MINE %zu\n", ft_strlcat(dst, src, dstsize));
	printf("MINE %s\n", dst);
	return (0);
} */