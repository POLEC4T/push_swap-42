/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:45:46 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/11 15:13:24 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

/**
 * @return the pos of the elem in b above which we want to push our elem
 * which means :
 * if a lower number exists
 * - its pos (index)
 * else
 * - the index of biggest number
 */
int	get_nearest_lower_idx(t_stack *b, int val_to_push)
{
	int	i_nearest_lower;
	int	nearest_lower;
	int	i;
	int	idx_biggest;

	i_nearest_lower = -1;
	nearest_lower = INT_MIN;
	idx_biggest = b->top;
	i = b->top;
	while (i >= 0)
	{
		if (b->list[i] < val_to_push && (b->list[i] > nearest_lower))
		{
			i_nearest_lower = i;
			nearest_lower = b->list[i];
		}
		if (b->list[i] > b->list[idx_biggest])
			idx_biggest = i;
		i--;
	}
	if (i_nearest_lower == -1)
		i_nearest_lower = idx_biggest;
	return (i_nearest_lower);
}

/**
 * @return the pos of the elem in a above which we want to push our elem
 * which means :
 * if an higher number exists
 * - its pos (index)
 * else
 * - the index of smallest number
 */
int	get_nearest_higher_idx(t_stack *a, int val_to_push)
{
	int	i_nearest_higher;
	int	nearest_higher;
	int	i;
	int	idx_smallest;

	i_nearest_higher = -1;
	nearest_higher = INT_MAX;
	idx_smallest = a->top;
	i = a->top;
	while (i >= 0)
	{
		if (a->list[i] > val_to_push && (a->list[i] < nearest_higher))
		{
			i_nearest_higher = i;
			nearest_higher = a->list[i];
		}
		if (a->list[i] < a->list[idx_smallest])
			idx_smallest = i;
		i--;
	}
	if (i_nearest_higher == -1)
		i_nearest_higher = idx_smallest;
	return (i_nearest_higher);
}

/**
 * - rotate val to top of a
 * - rotate b to the pos wanted
 * - push to b
 * wanted_idx is the pos of the elem in b above which we want to push our elem
 */
void	push_val(t_stack *a, t_stack *b, int idx)
{
	int	wanted_idx_b;

	wanted_idx_b = get_nearest_lower_idx(b, a->list[idx]);
	if (a->top / 2 < idx + 1)
		a->curr_direction = UP;
	else
		a->curr_direction = DOWN;
	if (b->top / 2 < wanted_idx_b + 1)
		b->curr_direction = UP;
	else
		b->curr_direction = DOWN;
	// ft_printf("dir:%d\n", a->curr_direction);
	rotate_both_till_top(a, b, &idx, &wanted_idx_b);
	rotate_till_top(a, idx);
	rotate_till_top(b, wanted_idx_b);
	push_b(a, b);
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	wanted_idx_a;

	wanted_idx_a = get_nearest_higher_idx(a, b->list[b->top]);
	a->curr_direction = a->top / 2 < wanted_idx_a;
	rotate_till_top(a, wanted_idx_a);
	push_a(a, b);
}

void	sorter(t_stack *a, t_stack *b)
{
	int	idx_min_val;

	push_b(a, b);
	push_b(a, b);
	while (a->top > 2)
	{
		push_val(a, b, a->top - 2);
	}
	if (!is_stack_sorted(a))
		swap_a(a, 0);
	idx_min_val = get_idx_min_val(a);
	if (idx_min_val != a->top)
	{
		if (idx_min_val == 0)
			reverse_rotate_a(a, 0);
		else
			rotate_a(a, 0);
	}
	while (b->top >= 0)
		push_back_to_a(a, b);
	a->curr_direction = a->top / 2 < get_idx_min_val(a);
	rotate_till_top(a, get_idx_min_val(a));
}
