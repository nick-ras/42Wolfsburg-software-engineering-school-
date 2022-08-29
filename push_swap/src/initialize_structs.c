/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nickras <nickras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:44:27 by nickras           #+#    #+#             */
/*   Updated: 2022/08/24 10:19:05 by nickras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_instructions_struct(t_count *instructions)
{
	instructions->dif = -2147483648;
	instructions->dif_bg = 2147483647;
	instructions->ra = 1000;
	instructions->ra_tmp = 1000;
	instructions->rr = 1000;
	instructions->rr_tmp = 1000;
	instructions->ra_bg = 1000;
	instructions->ra_bg_tmp = 1000;
	instructions->rr_bg = 1000;
	instructions->rr_bg_tmp = 1000;
	instructions->stack_b_pos = 0;
	instructions->stack_a_pos = 0;
	instructions->lowest = -2147483648;
}

void	reset_count_rotations(t_count *instructions)
{
	instructions->dif = 0;
	instructions->dif_bg = 0;
	instructions->ra = 0;
	instructions->ra_tmp = 0;
	instructions->rr = 0;
	instructions->rr_tmp = 0;
	instructions->ra_bg = 0;
	instructions->ra_bg_tmp = 0;
	instructions->rr_bg = 0;
	instructions->rr_bg_tmp = 0;
	instructions->stack_b_pos = 0;
	instructions->stack_a_pos = 0;
	instructions->lowest = -2147483648;
}

void	final_initialize_instructions_struct(t_count *instructions)
{
	instructions->dif = 2147483647;
	instructions->ra = 0;
	instructions->rr = 0;
	instructions->stack_b_pos = 0;
	instructions->stack_a_pos = 0;
	instructions->lowest = -2147483648;
	instructions->dif_bg = 0;
	instructions->ra_tmp = 0;
	instructions->rr_tmp = 0;
	instructions->ra_bg = 0;
	instructions->ra_bg_tmp = 0;
	instructions->rr_bg = 0;
	instructions->rr_bg_tmp = 0;
}

void	extra_initialization(t_count *instr)
{
	instr->stack_a_pos = 0;
	instr->dif = -2147483648;
	instr->dif_bg = 2147483647;
}
