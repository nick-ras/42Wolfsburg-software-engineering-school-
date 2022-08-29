/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:57:37 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/16 20:12:45 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	if (dst1 < src1)
	{
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	if (dst1 > src1)
	{
		while (len > 0)
		{
			dst1[len - 1] = src1[len - 1];
			len--;
		}
	}
	return (dst1);
}

/* int	main(void)
{
	size_t		n = 8;
	char		src[] = "lorem ipsum dolor sit amet";
	char		*dst = src + 5;

	int i = dst - src;
	printf("-%d-\n", i);
	printf("-%p-\n", ft_memmove(dst, src, n));
	printf("-%p-\n", memmove(dst, src, n));
	printf("-%s-\n", ft_memmove(dst, src, n));
	printf("-%s-\n", memmove(dst, src, n));
	write(1, "lorem ipsum dolor sit amet\n", 27);
	write(1, ft_memmove(dst, "con\0sec\0\0te\0tur\n", n), 31);
	printf("\n");
	write(1, memmove(dst, "con\0sec\0\0te\0tur", n), 31);
	return (0);
}
 */
/* 	size_t	i;
	char	*dst1;
	char	*src1;
	char	*original;

	i = 0;
	dst1 = (char *)dst;
	src1 = (char *)src;
	original = (char *)dst;
	if (*((char *)dst + i) == '\0' || *((char *)src + i) == '\0')
		return (dst);
	while (*((char *)src + i) != '\0')
	{
		*(original + i) = *((char *)dst + i);
		i++;
	}
	*(original + i) = '\0';
	i = 0;
	while (i < len)
	{
		if (i >= len)
			break ;
		dst1[i] = src1[i];
		i++;
	}
	return (original); */