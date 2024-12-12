/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:45:46 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/12 17:07:24 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

/**
 * - rotate val to top of a
 * - rotate b to the pos wanted
 * - push to b
 * wanted_idx is the pos of the elem in b above which we want to push our elem
 */
int	push_val(t_stack *a, t_stack *b, int idx, enum e_operation_mode op_mode)
{
	int					wanted_idx_b;
	int					ops_counter;
	enum e_direction	save_a;
	enum e_direction	save_b;

	wanted_idx_b = get_nearest_lower_idx(b, a->list[idx]);
	a->direc = a->top / 2 < idx + 1;
	b->direc = b->top / 2 < wanted_idx_b + 1;
	save_a = a->direc;
	save_b = b->direc;
	if (a->direc != b->direc)
		change_direc_if_worth(a, b, idx, wanted_idx_b);
	ops_counter = process_rotates(a, b, idx, wanted_idx_b, op_mode);
	if (op_mode == MODE_EXECUTE)
		push_b(a, b);
	return (ops_counter);
}

int	push_back_to_a(t_stack *a, t_stack *b, int idx,
		enum e_operation_mode op_mode)
{
	int	wanted_idx_a;
	int	ops_counter;

	wanted_idx_a = get_nearest_higher_idx(a, b->list[idx]);
	a->direc = a->top / 2 < wanted_idx_a + 1;
	b->direc = b->top / 2 < idx + 1;
	ops_counter = rotate_both_till_top(a, b, &wanted_idx_a, &idx, op_mode);
	ops_counter += rotate_till_top(a, wanted_idx_a, op_mode);
	ops_counter += rotate_till_top(b, idx, op_mode);
	if (op_mode == MODE_EXECUTE)
		push_a(a, b);
	return (ops_counter);
}

int	get_cheapest_ops_nb(t_stack *a, t_stack *b, int (*push_func)(t_stack *a,
			t_stack *b, int idx, enum e_operation_mode op_mode))
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
		nb_ops = push_func(a, b, i, MODE_COUNT);
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
	int	idx_cheapest;

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
		idx_cheapest = get_cheapest_ops_nb(a, b, &push_val);
		if (idx_cheapest == -1)
			idx_cheapest = a->top;
		push_val(a, b, idx_cheapest, MODE_EXECUTE);
	}
	if (!is_stack_sorted(a))
		swap_a(a, 0);
	while (b->top >= 0)
		push_back_to_a(a, b, b->top, MODE_EXECUTE);
	a->direc = a->top / 2 < get_idx_min_val(a) + 1;
	rotate_till_top(a, get_idx_min_val(a), MODE_EXECUTE);
}
