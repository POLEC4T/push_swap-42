/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:24:28 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/11 16:21:09 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

/**
 * shift up every element, first one becomes the last one
 */
int	rotate_a(t_stack *a, int is_rr)
{
	int	tmp;
	int	i;

	i = a->top;
	while (i)
	{
		tmp = a->list[i - 1];
		a->list[i - 1] = a->list[i];
		a->list[i] = tmp;
		i--;
	}
	if (!is_rr)
		ft_printf("ra\n");
	return (1);
}

/**
 * shift up every element, first one becomes the last one
 */
int	rotate_b(t_stack *b, int is_rr)
{
	int	tmp;
	int	i;

	i = b->top;
	while (i)
	{
		tmp = b->list[i - 1];
		b->list[i - 1] = b->list[i];
		b->list[i] = tmp;
		i--;
	}
	if (!is_rr)
		ft_printf("rb\n");
	return (1);
}
/**
 * shift up every element, first one becomes the last one
 */
int	rotate_anb(t_stack *a, t_stack *b)
{
	rotate_a(a, 1);
	rotate_b(b, 1);
	ft_printf("rr\n");
	return (1);
}
