/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:45:46 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/11 18:28:46 by mniemaz          ###   ########.fr       */
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
int	push_val(t_stack *a, t_stack *b, int idx, enum e_mode mode)
{
	int	wanted_idx_b;
	int	ops_counter;

	wanted_idx_b = get_nearest_lower_idx(b, a->list[idx]);
	a->direc = a->top / 2 < idx + 1;
	b->direc = b->top / 2 < wanted_idx_b + 1;
	ops_counter = rotate_both_till_top(a, b, &idx, &wanted_idx_b, mode);
	ops_counter += rotate_till_top(a, idx, mode);
	ops_counter += rotate_till_top(b, wanted_idx_b, mode);
	if (mode == OPS_MODE)
		push_b(a, b);
	return (ops_counter);
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	wanted_idx_a;

	wanted_idx_a = get_nearest_higher_idx(a, b->list[b->top]);
	a->direc = a->top / 2 < wanted_idx_a;
	rotate_till_top(a, wanted_idx_a, OPS_MODE);
	push_a(a, b);
}

int	get_cheapest_ops_nb(t_stack *a, t_stack *b)
{
	int	i;
	int	idx_cheapest;
	int	cheapest_ops;
	int	nb_ops;

	cheapest_ops = INT_MAX;
	idx_cheapest = -1;
	i = a->top;
	while (i >= 0)
	{
		nb_ops = push_val(a, b, i, COUNT_MODE);
		if (cheapest_ops > nb_ops)
		{
			cheapest_ops = nb_ops;
			idx_cheapest = i;
		}
		i--;
	}
	return (idx_cheapest);
}

void	sorter(t_stack *a, t_stack *b)
{
	int	idx_min_val;
	int	idx_cheapest;

	idx_cheapest = -1;
	push_b(a, b);
	push_b(a, b);
	while (a->top > 2)
	{
		idx_cheapest = get_cheapest_ops_nb(a, b);
		if (idx_cheapest == -1)
		{
			ft_printf("Warning : idx_cheapest not found\n");
			idx_cheapest = a->top;
		}
		push_val(a, b, idx_cheapest, OPS_MODE);
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
	{
		push_back_to_a(a, b);
	}
	a->direc = a->top / 2 < get_idx_min_val(a) + 1;
	rotate_till_top(a, get_idx_min_val(a), OPS_MODE);
}
