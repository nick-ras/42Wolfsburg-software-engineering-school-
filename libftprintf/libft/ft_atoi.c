/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:43:09 by nickras           #+#    #+#             */
/*   Updated: 2022/05/27 13:24:45 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			sign;
	int			count;
	long int	number;

	count = 0;
	sign = 1;
	while (str[count] == 32 || (str[count] <= 13 && str[count] >= 9))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
				sign = -1;
		count++;
	}
	number = 0;
	while (str[count] != '\0' && str[count] <= '9' && str[count] >= '0')
	{
		if (number > 2147483648 && sign == -1)
			return (0);
		if (number > 2147483647 && sign == 1)
			return (-1);
		number = number * 10 + (str[count] - '0');
		count++;
	}
	return (sign * number);
}

/* int	main(void)
{


	
	printf("%d", ft_atoi("-5467777777"));
	return (0);
} */
