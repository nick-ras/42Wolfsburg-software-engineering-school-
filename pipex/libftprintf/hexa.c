/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:40:44 by nickras           #+#    #+#             */
/*   Updated: 2022/05/31 18:41:27 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int n)
{
	unsigned int	temp;
	int				count;

	count = 0;
	if (n > 15)
		count += ft_hexa(n / 16);
	n = n % 16 + 48;
	if (n >= 58 && n % 16 <= 63)
	{
		temp = n + 39;
		count += write(1, &temp, 1);
	}
	else
		count += write(1, &n, 1);
	return (count);
}

int	ft_hexau(unsigned int n)
{
	unsigned int	temp;
	int				count;

	count = 0;
	if (n > 15)
		count += ft_hexau(n / 16);
	n = n % 16 + 48;
	if (n >= 58 && n % 16 <= 63)
	{
		temp = n + 7;
		count += write(1, &temp, 1);
	}
	else
		count += write(1, &n, 1);
	return (count);
}

int	ft_hexaul(unsigned long n)
{
	int	count;

	count = 0;
	if (!n)
		return (write(1, "0x0", 3));
	else
		count += write(1, "0x", 2);
	count += longhexa(n);
	return (count);
}

int	longhexa(unsigned long n)
{
	int	count;

	count = 0;
	if (n > 15)
		count += longhexa(n / 16);
	n = n % 16;
	if (n < 10)
		count += handle_char(n + 48);
	else
		count += handle_char(n + 87);
	return (count);
}
