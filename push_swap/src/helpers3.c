/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:28:01 by nickras           #+#    #+#             */
/*   Updated: 2022/08/24 09:10:07 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_low_to_high(t_push *stack, t_count	*instr_2)
{
	t_push	*first;

	stack = go_to_first(stack);
	first = stack;
	instr_2->ra = 0;
	while (stack)
	{
		if (stack->index == 0)
			break ;
		stack = stack->next;
		instr_2->ra++;
	}
	instr_2->ra = fastest_route(instr_2->ra, stack);
	first = execute_instructions(first, NULL, instr_2);
	exit_statement_and_free(first, 0, instr_2);
}
