/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:24:28 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/14 18:11:49 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * shift down every element of the stack s, last element becomes the first one
 */
int	reverse_rotate(t_stack *s, enum e_print print_mode)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < s->top)
	{
		tmp = s->list[i + 1];
		s->list[i + 1] = s->list[i];
		s->list[i] = tmp;
		i++;
	}
	if (print_mode == PRINT)
	{
		if (s->stack_id == STACK_A)
			write(1, "rra\n", 4);
		else if (s->stack_id == STACK_B)
			write(1, "rrb\n", 4);
	}
	return (1);
}

/**
 * shift down every element of both stacks a and b,
	last element becomes the first one
 */
int	reverse_rotate_anb(t_stack *a, t_stack *b)
{
	reverse_rotate(a, NO_PRINT);
	reverse_rotate(b, NO_PRINT);
	write(1, "rrr\n", 4);
	return (1);
}
