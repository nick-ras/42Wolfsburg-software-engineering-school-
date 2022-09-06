/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:20:37 by nrasmuss          #+#    #+#             */
/*   Updated: 2022/05/09 18:17:57 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The  strdup()  function  returns  a pointer to a 
new string which is a duplicate of the string s. 
Memory for the new string is obtained with malloc(3), 
and can be freed with free(3). */

char	*ft_strdup(const char *s1)
{
	int		i;
	int		length;
	char	*target1;

	length = 0;
	while (s1[length])
		length++;
	target1 = malloc(sizeof(char) * length + 1);
	if (!target1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
			target1[i] = s1[i];
		i++;
	}
	target1[i] = '\0';
	return (target1);
}

/* int	main(void)
{
	   char source[] = "3233";
 
	printf("%s\n", strdup(source));
	printf("%s\n", ft_strdup(source));
	return (0);
} */