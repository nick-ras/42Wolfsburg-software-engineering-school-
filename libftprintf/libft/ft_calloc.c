/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:23:14 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/24 12:07:57 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	result;

	if (nmemb >= __SIZE_MAX__ || size >= __SIZE_MAX__)
		return (NULL);
	result = nmemb * size;
	ptr = malloc(result);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (result));
	return (ptr);
}

/* int	main(void)
{
	
	
	
	size_t  size = __SIZE_MAX__;
	size_t  count = __SIZE_MAX__;
	printf("MINE%p\n",  ft_calloc(size, count));
	printf("ORIG%p\n",  calloc(size, count));
	return (0);
	
} */
