/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:44:20 by nickras           #+#    #+#             */
/*   Updated: 2022/08/22 17:44:21 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//rotates stack a, and gives new last link
t_push	*r(t_push *first)
{
	t_push	*second;
	t_push	*last;

	first = go_to_first(first);
	if (length_list(first) < 2)
		return (first);
	last = ft_lstlast_new(first);
	second = first->next;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	return (second);
}

//reverse rotates, returns new last
t_push	*rr(t_push *first)
{
	t_push	*sec_last;
	t_push	*last;

	first = go_to_first(first);
	if (length_list(first) < 2)
		return (first);
	last = ft_lstlast_new(first);
	sec_last = last->prev;
	sec_last->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	return (last);
}
