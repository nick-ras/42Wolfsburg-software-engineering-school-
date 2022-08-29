/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:58:07 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/17 22:36:23 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

/* int	main(void)
{
	int	i;
	i = -500;
	while (i < -100)
	{
		printf("MINE %d\n", ft_toupper(i));
		printf("ORIG %d\n", toupper(i));
		i++;
	}
} */