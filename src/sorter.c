/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:45:46 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/14 10:59:50 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

int	push_val(t_stack *a, t_stack *b, enum e_operation_mode op_mode)
{
	int	ops_counter;

	b->idx_to_top = get_nearest_lower_idx(b, a->list[a->idx_to_top]);
	a->direc = a->top / 2 < (a->idx_to_top + 1);
	b->direc = b->top / 2 < b->idx_to_top + 1;
	if (a->direc != b->direc)
		change_direc_if_worth(a, b);
	ops_counter = process_rotates(a, b, a->idx_to_top, b->idx_to_top, op_mode);
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
	ops_counter = process_rotates(a, b, wanted_idx_a, idx, op_mode);
	if (op_mode == MODE_EXECUTE)
		push_a(a, b);
	return (ops_counter);
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
		a->idx_to_top = i;
		nb_ops = push_val(a, b, MODE_COUNT);
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
		if (a->idx_to_top == -1)
		{
			ft_printf("Warning : no cheapest found");
			a->idx_to_top = a->top;
		}
		push_val(a, b, MODE_EXECUTE);
	}
	if (!is_stack_sorted(a))
		swap_a(a, 0);
	while (b->top >= 0)
	{
		b->idx_to_top = b->top;
		push_back_to_a(a, b, b->idx_to_top, MODE_EXECUTE);
	}
	// ft_printf("a->top %d, idx_min_val + 1 %d\n", a->top, idx_min_val + 1);
	a->direc = (a->top / 2) < (get_idx_min_val(a) + 1);
	rotate_till_top(a, get_idx_min_val(a), MODE_EXECUTE);
}
