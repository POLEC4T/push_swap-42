/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:40:50 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/14 18:11:46 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * ake the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 */
int	push_a(t_stack *a, t_stack *b)
{
	if (b->top == -1)
	{
		write(1, "Warning : push_a was called whereas b is empty", 46);
		return (0);
	}
	push(a, pop(b));
	write(1, "pa\n", 3);
	return (1);
}

/**
 * Takes the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 */
int	push_b(t_stack *a, t_stack *b)
{
	if (a->top == -1)
	{
		write(1, "Warning : push_b was called whereas b is empty", 46);
		return (0);
	}
	push(b, pop(a));
	write(1, "pb\n", 3);
	return (1);
}
