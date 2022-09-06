/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:07:50 by nickras           #+#    #+#             */
/*   Updated: 2022/05/16 21:16:03 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, s + i);
			i++;
		}
	}
}

/* char add(unsigned int i, char s)
{
    s = s + i;
    return (s);
}

int main(void)
{
    char        s[] = "";

    printf("%s\n", ft_striteri(s, add));
    return (0);
}
 */
