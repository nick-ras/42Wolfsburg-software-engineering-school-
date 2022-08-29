/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:44:16 by nickras           #+#    #+#             */
/*   Updated: 2022/08/23 10:18:12 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//swap first two of a
t_push	*sa(t_push *stack_a)
{
	t_push	*next_1;
	t_push	*next_2;

	stack_a = go_to_first(stack_a);
	next_1 = stack_a->next;
	if (next_1->next)
	{
		next_2 = next_1->next;
		stack_a->next = next_2;
		next_2->prev = stack_a;
	}
	else
		stack_a->next = NULL;
	next_1->prev = NULL;
	next_1->next = stack_a;
	stack_a->prev = next_1;
	write(1, "sa\n", 3);
	return (next_1);
}

///pushes last b to a, returns stack_b_next
t_push	*pa(t_push *stack_a, t_push *stack_b)
{
	t_push	*second_b;

	stack_a = go_to_first(stack_a);
	write(1, "pa\n", 3);
	if (stack_b->next)
	{
		second_b = stack_b->next;
		second_b->prev = NULL;
	}
	else
		second_b = NULL;
	stack_b->next = stack_a;
	stack_a->prev = stack_b;
	return (second_b);
}

//pushes last a to b (when stack b is NULL), and return stack b
t_push	*pb_first_push(t_push *stack_a, t_push *stack_b)
{
	t_push	*second;

	write(1, "pb\n", 3);
	if (!stack_a->next)
		return (stack_a);
	second = stack_a->next;
	second->prev = NULL;
	stack_b = stack_a;
	stack_b->next = NULL;
	return (stack_b);
}

////pushes last a to b, and returns new last stack a
t_push	*pb(t_push *stack_a, t_push *stack_b)
{
	t_push	*second;

	if (!stack_a->next)
		return (stack_a);
	write(1, "pb\n", 3);
	second = stack_a->next;
	second->prev = NULL;
	stack_a->next = stack_b;
	stack_b->prev = stack_a;
	return (stack_a);
}
