/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:57:48 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/16 21:54:14 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (!dstsize)
		return (srclen);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = *((char *)src + i);
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (srclen);
}

/* int	main(void)
{
	size_t dstsize = 0;
	char src[] = "lorem ipsum dolor sit amet";
	char dest[25] = "12345";

	printf("%zu\n", ft_strlcpy(dest, src, dstsize));
	write(1, dest, 20);
	printf("\n%zu\n", strlcpy(dest, src, dstsize));
	write(1, dest, 20);
	return (0); 
} */
