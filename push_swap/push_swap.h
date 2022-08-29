/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:16:46 by nickras           #+#    #+#             */
/*   Updated: 2022/08/29 15:22:45 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include "../libftprintf/ft_printf.h"

typedef struct s_push
{
	int				num;
	int				len;
	int				index;
	int				index_tmp;
	struct s_push	*prev;
	struct s_push	*next;
	struct s_push	*subs;
}	t_push;

typedef struct counter_list
{
	int		stack_a_pos;
	int		stack_b_pos;
	int		dif;
	int		dif_bg;
	int		ra;
	int		ra_tmp;
	int		rr;
	int		rr_tmp;
	int		ra_bg;
	int		ra_bg_tmp;
	int		rr_bg;
	int		rr_bg_tmp;
	t_push	*lowest_ptr;
	int		lowest;
}	t_count;

int		main(int argc, char **argv);
t_push	*create_linked_list(int argc, char **argv, t_push *stack_a, \
t_count *instr_2);
void	is_digits(char **argv);
void	is_not_only_minus(char **argv);

//helpers
int		length_list(t_push *lst);
int		abs_val(int value);
void	exit_statement_and_free(t_push *stack_a, int i, t_count *instr_2);
void	indexing(t_push *stack_a, int length);
void	indexing_partial(t_push *stack_a, int length);
void	clear_partial_index(t_push *stack);
int		highest_index(t_push *stack);
t_push	*go_to_first(t_push *stack);

//checks
void	check_multiples(t_push *first, t_count *instr_2);
void	check_if_small_or_big(int argc, t_count *instr_2);
void	sort_check_full(t_push *stack_a, t_count *instructions, int argc);
int		sort_check_partial(t_push *stack_a);
int		numbers_in_order(t_push *first);
//void	print_lists(t_push *stack_a, t_push *stack_b);

//libft
t_push	*ft_lstlast_new(t_push *lst);
int		ft_atoi_push(char *str, t_push *stack_a, t_count *instr_2);
t_push	*ft_lstnew_new(char *content, t_push *stack_a, t_count *instr_2);

//make longest increasing subsequence and sorting pipeline
void	make_lis(t_push *stack_a);
void	clean_lis(t_push *stack_a);
t_push	*find_last_in_sequence(t_push *stack_a);

//sorting and using commands
t_push	*sa_first_and_last(t_push *stack, t_count *instr_2);
t_push	*sort_3_numbers(t_push *stack, t_count *instr_2, int argc);
t_push	*use_sa_5(t_push *stack, t_count *instr_2);
void	sort_five_numbers(t_push *stack_a, t_push *stack_b, t_count *instr_2);
void	push_out_and_in(t_push *stack_a, int argc, t_count *instr_2);
void	sorting_back(t_push *stack_a, t_push *stack_b, t_count *instr_2);
void	sort_low_to_high(t_push *stack, t_count	*instr_2);

//making instructions
int		does_is_use_less_commands(t_push *stack_a, t_count *instructions);
void	make_instructions(t_push *stack_a, t_push *first, t_push \
*stack_b, t_count *instructions);
t_push	*make_instructions_subfunction(t_push *stack_a, t_push *stack_b, \
t_count *instructions);
int		fastest_route(int b_dif, t_push *stack_a);
void	calculate_num_before(t_push *stack_a, \
t_push	*stack_b, t_count *dif, int argc);
void	set_commands(t_push *stack_a, t_push *stack_b, t_count *instructions);
void	set_commands_bg(t_push *stack_a, t_push *stack_b, \
t_count *instructions);

//executes instructions, return stack_b last
t_push	*execute_instructions(t_push *last_main, \
t_push *stack_b, t_count *instructions);
t_push	*execute_stack_a(t_push *stack, t_count *instr_2);
t_push	*execute_ra(t_push *stack_a, t_count *instructions);

//initialize
void	initialize_instructions_struct(t_count *instructions);
void	extra_initialization(t_count *instr);
void	reset_count_rotations(t_count *instructions);
void	final_initialize_instructions_struct(t_count *instructions);

//commands
t_push	*sa(t_push *stack_a);
t_push	*pa(t_push *stack_a, t_push *stack_b);
t_push	*pb(t_push *stack_a, t_push *stack_b);
t_push	*pb_first_push(t_push *stack_a, t_push *stack_b);
t_push	*r(t_push *stack);
t_push	*rr(t_push *stack);
#endif