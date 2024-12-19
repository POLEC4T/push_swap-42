/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:07:20 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/15 10:34:16 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief This funcion check if using rr or rrr is better than ra and rb
 * @details the direction is the way the stack are going to rotate
 * in order to put s->idx_to_top to the top of the stack
 * @details let's take this example of stacks a and b where the o needs to
 * go at the top of the stack :
 *
 *  a:  b:
 *   x   x
 *   x   x
 *   x   x
 *   x   o
 *   x   x
 *   o   x
 *   x   x
 *   x   x
 *
 * The initial way to set the optimal direction in order to put o at the
 * top would be to check where it is compared to the middle of the stack.
 * In this case, a->direc would be DOWN and b->direc would be UP. Which would
 * result in the following operations :
 * rra rra rra
 * rb rb rb rb
 * -> 7 operations
 *
 * However it would be better if we used rr to rotate both a and b up in one
 * operation. Like this :
 * rr rr rr (till the o in b is at the top)
 * ra ra
 * -> 5 operations
 *
 * 5 operations < 7 operations
 * -> in this case it's worth it to set the directions of a and b to UP
 */
void	change_direc_if_worth(t_stack *a, t_stack *b)
{
	int	ops_counter;
	int	cheap_ops_counter;
	int	cheap_direc_b;
	int	cheap_direc_a;
	int	i;

	ops_counter = rotate_both_till_top(a, b, MODE_COUNT);
	cheap_ops_counter = ops_counter;
	cheap_direc_a = a->direc;
	cheap_direc_b = b->direc;
	i = -1;
	while (++i <= 1)
	{
		a->direc = i;
		b->direc = i;
		ops_counter = rotate_both_till_top(a, b, MODE_COUNT);
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
