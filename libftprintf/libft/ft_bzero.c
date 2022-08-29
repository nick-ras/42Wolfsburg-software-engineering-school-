/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:56:00 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/16 19:28:01 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}

/* int	main(void)
{
	size_t	n = 3;
	char	s[] = "lkjasdflkj";

	ft_bzero(s, n);
	printf("%s", s+3);
	return (0);
} */
