/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:40:50 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/11 16:20:27 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

/**
 * ake the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 */
int	push_a(t_stack *a, t_stack *b)
{
	if (b->top == -1)
	{
		ft_printf("Warning : push_a was called whereas b is empty");
		return (0);
	}
	push(a, pop(b));
	ft_printf("pa\n");
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
		ft_printf("Warning : push_b was called whereas a is empty");
		return (0);
	}
	push(b, pop(a));
	ft_printf("pb\n");
	return (1);
}