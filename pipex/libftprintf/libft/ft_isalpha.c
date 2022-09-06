/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:56:12 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/16 19:29:31 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

/* int	main(void)
{
	unsigned char c;

	c = 47;
	while (c < 123)
	{
		printf("         --%d--\n", ft_isalpha(c));
		printf("ORIGINAL --%d--\n", isalpha(c));
		c++;
	}
	return (0);
} */
