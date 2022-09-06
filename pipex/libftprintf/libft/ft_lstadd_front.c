/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:56:28 by nickras           #+#    #+#             */
/*   Updated: 2022/05/20 09:14:19 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Parameters lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.
Return value None
External functs. None
Description Adds the node ’new’ at the beginning of the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{	
	if (new && lst)
	{
		new->next = lst[0];
		lst[0] = new;
	}
}
