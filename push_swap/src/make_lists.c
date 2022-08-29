/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:44:45 by nickras           #+#    #+#             */
/*   Updated: 2022/08/25 14:09:44 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_push	*ft_lstnew_new(char *content, t_push *stack_a, t_count *instr_2)
{
	t_push	*new;

	new = malloc(sizeof(t_push));
	if (!new)
	{
		new = NULL;
		exit_statement_and_free(stack_a, 1, instr_2);
	}
	new->next = NULL;
	new->prev = stack_a;
	new->len = 1;
	new->subs = NULL;
	new->index = -1;
	new->num = ft_atoi_push(content, new, instr_2);
	return (new);
}

t_push	*create_linked_list(int argc, \
char **argv, t_push *stack_a, t_count *instr_2)
{
	int		i;
	t_push	*ptr_first;

	i = 1;
	stack_a = ft_lstnew_new(argv[i], stack_a, instr_2);
	stack_a->prev = NULL;
	i++;
	ptr_first = stack_a;
	while (i < argc)
	{
		stack_a->next = ft_lstnew_new(argv[i], stack_a, instr_2);
		stack_a = stack_a->next;
		i++;
	}
	stack_a->next = NULL;
	return (ptr_first);
}
