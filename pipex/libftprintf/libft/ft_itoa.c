/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:29:04 by nickras           #+#    #+#             */
/*   Updated: 2022/05/31 11:27:51 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* gcc -Wall -Werror -Wextra ft_itoa.c ft_strlen.c ft_strdup.c && ./a.out */

#include "libft.h"

static int	count_length(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = count_length(n);
	array = malloc(sizeof(char) * (i + 1));
	if (!array)
		return (NULL);
	ft_bzero(array, i + 1);
	if (n < 0)
	{
		array[0] = '-';
		n = n * -1;
	}
	while (n > 9)
	{
		array[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	array[i - 1] = (n % 10) + '0';
	return (array);
}

/* int	main(void)
{
	printf("%s\n", ft_itoa(-9));
	return (0);
} */
