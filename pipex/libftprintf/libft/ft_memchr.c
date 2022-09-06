/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:57:18 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/16 19:45:45 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The  memchr()  function scans the initial n 
bytes of the memory area
 pointed to by s for the first instance ofc.  Both c and the bytes of 
 the memory area pointed to by s are interpreted as unsigned char.
The  memchr()  and memrchr() functions return a pointer to the
 matching byte or NULL if the character does not
occur in the given memory area.
 */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	//int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("%p DONE\n", memchr(s, 2 + 256, 3));
	printf("%p\n",   ft_memchr(s, 2 + 256, 3));
	return (0);
}  */
