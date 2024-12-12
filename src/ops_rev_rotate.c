/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:24:28 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/12 11:00:00 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

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
			ft_printf("rra\n");
		else if (s->stack_id == STACK_B)
			ft_printf("rrb\n");
	}
	return (1);
}

/**
 * shift down every element, last one becomes the first one
 */
int	reverse_rotate_anb(t_stack *a, t_stack *b)
{
	reverse_rotate(a, NO_PRINT);
	reverse_rotate(b, NO_PRINT);
	ft_printf("rrr\n");
	return (1);
}
