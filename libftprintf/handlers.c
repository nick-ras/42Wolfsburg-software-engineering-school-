/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:40:30 by nickras           #+#    #+#             */
/*   Updated: 2022/06/03 12:22:40 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(int i)
{
	unsigned char	c;

	c = i;
	return (write(1, &c, 1));
}

int	handle_string(char *str)
{
	if (!str)
		return (write(1, "(null)", 6)); 
	return (write(1, str, ft_strlen(str)));
}

int	handle_decimal(int i)
{
	int		length;
	long	newint;

	newint = (long)i;
	length = 0;
	if (newint < 0)
	{
		length += write(1, "-", 1);
		newint = -newint;
	}
	if (newint / 10)
		length += handle_decimal(newint / 10);
	newint = newint % 10 + '0';
	length += handle_char(newint);
	return (length);
}

int	ft_uitoa(unsigned int n)
{
	int		length;
	long	newint;

	newint = (long)n;
	length = 0;
	if (newint / 10)
		length += handle_decimal(newint / 10);
	newint = newint % 10 + '0';
	length += handle_char(newint);
	return (length);
}

/* int main() {
ft_hexa(1234567);
  return 0;
} */