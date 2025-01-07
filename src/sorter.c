/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:45:46 by mniemaz           #+#    #+#             */
/*   Updated: 2025/01/07 16:50:04 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief pushes the optimal value from a to b
 * (the one that needs the least amount of operations)
 * @details if op_mode is COUNT_MODE, it only count how many operations
 * would have been made, without doing any operation
 */
static int	push_opti_to_b(t_stack *a, t_stack *b,
		enum e_operation_mode op_mode)
{
	int	ops_counter;

	b->idx_to_top = get_nearest_lower_idx(b, a->list[a->idx_to_top]);
	a->direc = (a->top) / 2 < (a->idx_to_top + 1);
	b->direc = (b->top) / 2 < (b->idx_to_top + 1);
	if (a->direc != b->direc)
		change_direc_if_worth(a, b);
	ops_counter = rotate_both_till_top(a, b, op_mode);
	if (op_mode == MODE_EXECUTE)
		push_b(a, b);
	return (ops_counter);
}

/**
 * @brief rotates the stacks and pushes the top of b to a
 */
static void	push_back_to_a(t_stack *a, t_stack *b)
{
	a->idx_to_top = get_nearest_higher_idx(a, b->list[b->top]);
	a->direc = (a->top / 2) < (a->idx_to_top + 1);
	rotate_till_top(a, a->idx_to_top, MODE_EXECUTE);
	push_a(a, b);
}

/**
 * @returns the index of the value of the stack a for which the number
 *  of operations made is the minimum when pushing it to b
 */
static int	get_cheapest_ops_nb(t_stack *a, t_stack *b)
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
		a->idx_to_top = i;
		nb_ops = push_opti_to_b(a, b, MODE_COUNT);
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
	if (is_stack_sorted(a))
	{
		a->direc = a->top / 2 < get_idx_min_val(a) + 1;
		rotate_till_top(a, get_idx_min_val(a), MODE_EXECUTE);
		return ;
	}
	if (a->top > 2)
		push_b(a, b);
	if (a->top > 2)
		push_b(a, b);
	while (a->top > 2)
	{
		a->idx_to_top = get_cheapest_ops_nb(a, b);
		push_opti_to_b(a, b, MODE_EXECUTE);
	}
	if (!is_stack_sorted(a))
		swap(a, 0);
	while (b->top >= 0)
	{
		push_back_to_a(a, b);
	}
	a->direc = (a->top / 2) < (get_idx_min_val(a) + 1);
	rotate_till_top(a, get_idx_min_val(a), MODE_EXECUTE);
}
