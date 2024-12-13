/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:07:20 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/13 12:51:13 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	change_direc_if_worth(t_stack *a, t_stack *b, int i_a, int i_b)
{
	int	ops_counter;
	int	cheap_ops_counter;
	int	cheap_direc_b;
	int	cheap_direc_a;
	int	i;

	ops_counter = process_rotates(a, b, i_a, i_b, MODE_COUNT);
	cheap_ops_counter = ops_counter;
	cheap_direc_a = a->direc;
	cheap_direc_b = b->direc;
	i = -1;
	while (++i <= 1)
	{
		a->direc = i;
		b->direc = i;
		ops_counter = process_rotates(a, b, i_a, i_b, MODE_COUNT);
		if (ops_counter < cheap_ops_counter)
		{
			cheap_ops_counter = ops_counter;
			cheap_direc_a = a->direc;
			cheap_direc_b = b->direc;
		}
	}
	a->direc = cheap_direc_a;
	b->direc = cheap_direc_b;
}
