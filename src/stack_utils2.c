/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:17:10 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/14 11:17:44 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	process_rotates(t_stack *a, t_stack *b, int i_a, int i_b,
		enum e_operation_mode op_mode)
{
	int	ops_counter;
	int	idx;
	int	wanted_idx_b;

	idx = i_a;
	wanted_idx_b = i_b;
	ops_counter = rotate_both_till_top(a, b, idx, wanted_idx_b, op_mode);
	return (ops_counter);
}

void	update_indices(t_stack *a, t_stack *b, int *idx, int *wanted_idx_b)
{
	if (a->direc == UP && b->direc == UP)
	{
		(*wanted_idx_b)++;
		(*idx)++;
	}
	else if (a->direc == DOWN && b->direc == DOWN)
	{
		(*wanted_idx_b)--;
		(*idx)--;
	}
}

/**
 *
 */
int	rotate_both_till_top(t_stack *a, t_stack *b, int i_a, int i_b,
		enum e_operation_mode mode)
{
	int	ops_counter;

	ops_counter = 0;
	while ((a->direc == UP && i_a != a->top && b->direc == UP
			&& i_b != b->top) || (a->direc == DOWN && i_a >= 0
			&& b->direc == DOWN && i_b >= 0))
	{
		if (mode == MODE_EXECUTE)
		{
			if (a->direc == UP && b->direc == UP)
				rotate_anb(a, b);
			else if (a->direc == DOWN && b->direc == DOWN)
				reverse_rotate_anb(a, b);
		}
		else if (mode == MODE_COUNT)
			ops_counter++;
		update_indices(a, b, &i_a, &i_b);
	}
	ops_counter += rotate_till_top(a, i_a, mode);
	ops_counter += rotate_till_top(b, i_b, mode);
	return (ops_counter);
}

int	is_stack_sorted(t_stack *s)
{
	int	i;
	int	idx_min;

	i = s->top;
	idx_min = s->top;
	while (--i >= 0)
		if (s->list[i] < s->list[idx_min])
			idx_min = i;
	i = idx_min + 1;
	while (--i > 0)
		if (s->list[i] > s->list[i - 1])
			return (0);
	if (idx_min < s->top && s->list[0] > s->list[s->top])
		return (0);
	i = s->top + 1;
	while (--i - 1 > idx_min)
		if (s->list[i] > s->list[i - 1])
			return (0);
	return (1);
}

/**
 * get the index of the minimum value of the stack
 */
int	get_idx_min_val(t_stack *s)
{
	int	i;
	int	idx_min;

	i = s->top;
	idx_min = s->top;
	while (i >= 0)
	{
		if (s->list[i] < s->list[idx_min])
			idx_min = i;
		i--;
	}
	return (idx_min);
}
