/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:44:37 by nickras           #+#    #+#             */
/*   Updated: 2022/08/23 09:26:03 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	make_lis(t_push *stack_a)
{
	t_push	*outer;
	t_push	*first;

	first = stack_a;
	outer = stack_a;
	while (outer)
	{
		stack_a = first;
		while (stack_a->next && stack_a != outer)
		{
			if (stack_a->num < outer->num)
			{
				if (stack_a->len + 1 >= outer->len)
				{
					outer->len = stack_a->len + 1;
					outer->subs = stack_a;
					if (!stack_a->subs)
						stack_a->subs = stack_a;
				}
			}
			stack_a = stack_a->next;
		}
		outer = outer->next;
	}
	clean_lis(first);
}

void	clean_lis(t_push *stack_a)
{
	t_push	*tmp;
	int		count;

	count = 0;
	while (stack_a)
	{
		if (stack_a->len >= count)
		{
			count = stack_a->len;
			tmp = stack_a;
		}
		stack_a = stack_a->next;
	}
	stack_a = ft_lstlast_new(tmp);
	while (stack_a)
	{
		if (stack_a == tmp && stack_a != stack_a->subs)
			tmp = tmp->subs;
		else
			stack_a->subs = NULL;
		stack_a = stack_a->prev;
	}
}
