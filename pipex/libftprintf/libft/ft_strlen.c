/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:17:24 by nickras           #+#    #+#             */
/*   Updated: 2022/05/09 18:17:25 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

/* int	main()
{
	char str[7] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
	printf("%zu", ft_strlen(str));
	return (0);
} */
