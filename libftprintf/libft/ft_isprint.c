/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrasmuss <nrasmuss@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:56:27 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/02 20:56:30 by nrasmuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/* int main(void)
{
	int i = 0;
	while (i <= 127)
		{
			printf("%d", ft_isprint(i));
			printf("%d\n", isprint(i));
			i++;
		}
	return (0);
} */
