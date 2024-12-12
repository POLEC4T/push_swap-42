/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:24:28 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/12 10:54:00 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

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
			ft_printf("ra\n");
		else if (s->stack_id == STACK_B)
			ft_printf("rb\n");
	}
	return (1);
}

/**
 * shift up every element, first one becomes the last one
 */
int	rotate_anb(t_stack *a, t_stack *b)
{
	rotate(a, NO_PRINT);
	rotate(b, NO_PRINT);
	ft_printf("rr\n");
	return (1);
}
