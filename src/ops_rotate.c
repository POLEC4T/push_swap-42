/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:24:28 by mniemaz           #+#    #+#             */
/*   Updated: 2025/01/07 14:33:26 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * shift up every element of the stack s,
	first element becomes the last one
 */
int	rotate(t_stack *s, enum e_print print_mode)
{
	int	tmp;
	int	i;

	i = s->top;
	while (i)
	{
		tmp = s->list[i - 1];
		s->list[i - 1] = s->list[i];
		s->list[i] = tmp;
		i--;
	}
	if (print_mode == PRINT)
	{
		if (s->stack_id == STACK_A)
			write(1, "ra\n", 3);
		else if (s->stack_id == STACK_B)
			write(1, "rb\n", 3);
	}
	return (1);
}

/**
 * shift up every element of both stacks a and b,
	first element becomes the last one
 */
int	rotate_anb(t_stack *a, t_stack *b)
{
	rotate(a, NO_PRINT);
	rotate(b, NO_PRINT);
	write(1, "rr\n", 3);
	return (1);
}
