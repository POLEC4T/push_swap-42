/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:17:10 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/14 16:50:51 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
 * @brief rotates or reverse rotates stack a and b
 * - first, it tries to rotate both down or both up, stops
 * when one of the two "s"->idx_to_top reached the top
 * - then, calls rotate_till_top to let the stack that did not
 * reach the top reach it
 * @warning a->idx_to_top and b->idx_to_top must be set before
 * calling this function
 */
int	rotate_both_till_top(t_stack *a, t_stack *b, enum e_operation_mode mode)
{
	int	ops_counter;
	int	i_a;
	int	i_b;

	ops_counter = 0;
	i_a = a->idx_to_top;
	i_b = b->idx_to_top;
	while ((a->direc == UP && i_a != a->top && b->direc == UP && i_b != b->top)
		|| (a->direc == DOWN && i_a >= 0 && b->direc == DOWN && i_b >= 0))
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

int	rotate_till_top(t_stack *s, int idx, enum e_operation_mode mode)
{
	int	ops_counter;

	if (idx == s->top)
		return (0);
	ops_counter = 0;
	while ((s->direc == UP && idx != s->top) || (s->direc == DOWN && idx >= 0))
	{
		if (mode == MODE_EXECUTE)
		{
			if (s->direc == UP)
				rotate(s, PRINT);
			else
				reverse_rotate(s, PRINT);
		}
		else if (mode == MODE_COUNT)
			ops_counter++;
		if (s->direc == UP)
			idx++;
		else
			idx--;
	}
	return (ops_counter);
}

/**
 * @brief get the index of the minimum value of the stack
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
