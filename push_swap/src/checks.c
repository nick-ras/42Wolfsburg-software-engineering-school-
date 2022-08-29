/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:44:13 by nickras           #+#    #+#             */
/*   Updated: 2022/08/25 13:57:00 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_multiples(t_push *first, t_count *instr_2)
{
	t_push	*outer;
	t_push	*inner_up;

	outer = first;
	while (outer->next)
	{
		inner_up = outer->next;
		while (inner_up)
		{
			if (inner_up->num == outer->num)
			{
				free(instr_2);
				instr_2 = NULL;
				exit_statement_and_free(first, 1, instr_2);
			}
			inner_up = inner_up->next;
		}
		outer = outer->next;
	}
}

void	check_if_small_or_big(int argc, t_count *instr_2)
{
	if (argc > 520 || argc <= 1)
	{
		free(instr_2);
		instr_2 = NULL;
		exit (1);
	}
}

// check if order is correct
int	numbers_in_order(t_push *first)
{
	t_push	*next;

	next = first;
	while (first->next)
	{
		next = first->next;
		if (first->num > next->num)
			return (1);
		first = first->next;
	}
	return (0);
}

void	sort_check_full(t_push *stack_a, t_count *instructions_2, int argc)
{
	t_push	*next_nb;

	stack_a = go_to_first(stack_a);
	while (stack_a->next)
	{
		next_nb = stack_a->next;
		if (stack_a->index + 1 != next_nb->index)
		{
			if (stack_a->index != 2)
				return ;
			if (next_nb->index != 0)
				return ;
		}
		stack_a = next_nb;
	}
	if (argc - 1 == length_list(stack_a))
		sort_low_to_high(stack_a, instructions_2);
}

int	sort_check_partial(t_push *stack_a)
{
	t_push	*next_nb;

	indexing_partial(stack_a, length_list(stack_a));
	stack_a = go_to_first(stack_a);
	while (stack_a->next)
	{
		next_nb = stack_a->next;
		if (stack_a->index_tmp + 1 != next_nb->index_tmp)
		{
			if (stack_a->index_tmp != 2)
				return (0);
			if (next_nb->index_tmp != 0)
				return (0);
		}
		stack_a = next_nb;
	}
	return (1);
}
