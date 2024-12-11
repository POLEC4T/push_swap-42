/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:40:50 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/10 10:26:51 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

/**
 * ake the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 */
void	push_a(t_stack *a, t_stack *b)
{
    if (b->top == -1)
    {
        ft_printf("Warning : push_a was called whereas b is empty");
        return ;
    }
	push(a, pop(b));
	ft_printf("pa\n");
}

/**
 * Takes the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 */
void	push_b(t_stack *a, t_stack *b)
{
    if (a->top == -1)
    {
        ft_printf("Warning : push_b was called whereas a is empty");
        return ;
    }
	push(b, pop(a));
	ft_printf("pb\n");
}