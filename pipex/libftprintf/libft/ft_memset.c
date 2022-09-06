/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:57:40 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/18 10:48:15 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = c;
		i++;
	}
	return (b);
}

/* int main(void)
{
	size_t len = 8;
	int c = 255;
	void *b;
	printf("--%s--\n",  ft_memset(&b, c, len));
	printf("--%s--",  memset(&b, c, len));
	return (0);
} */
