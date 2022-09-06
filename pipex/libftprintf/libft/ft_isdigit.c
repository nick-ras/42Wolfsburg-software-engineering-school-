/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:56:22 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/16 19:37:26 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}

/* int	main(void)
{
	int c;

	c = -5;
	while (c < 123)
	{
		printf("         --%d--\n", ft_isdigit(c));
		printf("ORIGINAL --%d--\n", isdigit(c));
		c++;
	}
	return (0);
} */
