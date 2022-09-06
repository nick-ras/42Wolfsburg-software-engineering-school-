/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:48:07 by nickras           #+#    #+#             */
/*   Updated: 2022/05/20 11:06:04 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function name ft_lstadd_back
Turn in files -
Parameters lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.
Return value None
External functs. None
Description Adds the node ’new’ at the end of the list.*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (*lst)
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	else if (lst)
	{
		*lst = new;
	}
}
