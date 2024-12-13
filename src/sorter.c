/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:45:46 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/13 15:58:54 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

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
		nb_ops = push_val(a, b, i, MODE_COUNT);
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
	int tmp;
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
		tmp = get_cheapest_ops_nb(a, b);
		if (tmp == -1)
		{
			ft_printf("Warning : no cheapest found");
			tmp = a->top;
		}
		push_val(a, b, tmp, MODE_EXECUTE);
	}
	if (!is_stack_sorted(a))
		swap_a(a, 0);
	while (b->top >= 0)
		push_back_to_a(a, b, b->top, MODE_EXECUTE);
	// ft_printf("a->top %d, (get_idx_min_val(a) + 1) %d\n", a->top, (get_idx_min_val(a) + 1));
	a->direc = (a->top / 2) < (get_idx_min_val(a) + 1);
	rotate_till_top(a, get_idx_min_val(a), MODE_EXECUTE);
}
