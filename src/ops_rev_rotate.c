/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:24:28 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/11 16:25:25 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

/**
 * shift down every element, first one becomes the last one
 */
int	reverse_rotate_a(t_stack *a, int is_rrr)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < a->top)
	{
		tmp = a->list[i + 1];
		a->list[i + 1] = a->list[i];
		a->list[i] = tmp;
		i++;
	}
	if (!is_rrr)
		ft_printf("rra\n");
	return (1);
}

/**
 * shift down every element, first one becomes the last one
 */
int	reverse_rotate_b(t_stack *b, int is_rrr)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < b->top)
	{
		tmp = b->list[i + 1];
		b->list[i + 1] = b->list[i];
		b->list[i] = tmp;
		i++;
	}
	if (!is_rrr)
		ft_printf("rrb\n");
	return (1);
}

/**
 * shift down every element, first one becomes the last one
 */
int	reverse_rotate_anb(t_stack *a, t_stack *b)
{
	reverse_rotate_a(a, 1);
	reverse_rotate_b(b, 1);
	ft_printf("rrr\n");
	return (1);
}
