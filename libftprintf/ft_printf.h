/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:20:56 by nickras           #+#    #+#             */
/*   Updated: 2022/05/31 18:36:43 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int	handler(const char *s, int i, va_list args);
int	ft_printf(const char *s, ...);
int	handle_char(int c);
int	handle_string(char *str);
int	handle_decimal(int i);
int	ft_uitoa(unsigned int n);
int	ft_hexa(unsigned int n);
int	longhexa(unsigned long n);
int	ft_hexaul(unsigned long n);
int	ft_hexau(unsigned int n);

#endif