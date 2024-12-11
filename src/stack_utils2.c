/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:17:10 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/11 14:54:11 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_both_till_top(t_stack *a, t_stack *b, int *idx,
		int *wanted_idx_b)
{
	if (a->curr_direction == UP && b->curr_direction == UP)
	{
		while ((*idx) != a->top && (*wanted_idx_b) != b->top)
		{
			rotate_anb(a, b);
			(*wanted_idx_b)++;
			(*idx)++;
		}
	}
	else if (a->curr_direction == DOWN && b->curr_direction == DOWN)
	{
		while ((*idx) >= 0 && (*wanted_idx_b) >= 0)
		{
			reverse_rotate_anb(a, b);
			(*wanted_idx_b)--;
			(*idx)--;
		}
	}
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
	int i;
	int idx_min;

	i = s->top;
	idx_min = s->top;
	while (--i >= 0)
		if (s->list[i] < s->list[idx_min])
			idx_min = i;
	return (idx_min);
}