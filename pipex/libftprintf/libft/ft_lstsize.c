/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:30:38 by nickras           #+#    #+#             */
/*   Updated: 2022/05/20 09:15:48 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function name ft_lstsize
Prototype int ft_lstsize(t_list *lst);
Turn in files -
Parameters lst: The beginning of the list.
Return value The length of the list
External functs. None
Description Counts the number of nodes in a list. */

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	if (!lst)
		return (0);
	temp = lst;
	i = 1;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
