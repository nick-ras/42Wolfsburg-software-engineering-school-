/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:44:22 by nickras           #+#    #+#             */
/*   Updated: 2022/08/24 09:49:38 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	length_list(t_push *lst)
{
	int		i;

	if (!lst)
		return (0);
	lst = ft_lstlast_new(lst);
	i = 1;
	while (lst->prev)
	{
		i++;
		lst = lst->prev;
	}
	return (i);
}

// void	print_lists(t_push *stack_a, t_push *stack_b)
// {
// 	ft_printf("list\n");
// 	stack_a = go_to_first(stack_a);
// 	if (stack_b)
// 		stack_b = go_to_first(stack_b);
// 	while (stack_a)
// 	{
// 		stack_a = stack_a->next;
// 		if (stack_b)
// 		{
// 			ft_printf("  b = %d", stack_b->num);
// 			stack_b = stack_b->next;
// 		}
// 		ft_printf("\n");
// 	}
// 	if (stack_b)
// 	{
// 		while (stack_b)
// 		{
// 			ft_printf("            b = %d\n", stack_b->num);
// 			stack_b = stack_b->next;
// 		}
// 	}
// }

int	abs_val(int value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}

void	exit_statement_and_free(t_push *stack_a, int i, t_count *instr_2)
{
	t_push	*del;

	free(instr_2);
	instr_2 = NULL;
	stack_a = ft_lstlast_new(stack_a);
	while (stack_a)
	{
		del = stack_a;
		stack_a = stack_a->prev;
		free(del);
		del = NULL;
	}
	if (i == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	else
		exit (0);
}

void	indexing(t_push *stack_a, int length)
{
	int		tmp;
	t_push	*first;
	t_push	*tmp_ptr;

	first = stack_a;
	while (length--)
	{
		stack_a = first;
		tmp = -2147483648;
		while (stack_a)
		{
			if (stack_a->num > tmp && stack_a->index == -1)
			{
				tmp = stack_a->num;
				tmp_ptr = stack_a;
			}
			if (stack_a->next == NULL)
				break ;
			stack_a = stack_a->next;
		}
		tmp_ptr->index = length;
		tmp_ptr->index_tmp = -1;
		tmp_ptr->subs = NULL;
		tmp_ptr->len = 1;
	}
}
