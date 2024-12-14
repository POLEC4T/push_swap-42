/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:02:12 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/14 18:11:52 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Swaps the first two elements of the stack s
 */
int	swap(t_stack *s, enum e_print print_mode)
{
	int	val1;
	int	val2;

	val1 = pop(s);
	val2 = pop(s);
	push(s, val1);
	push(s, val2);
	if (print_mode == PRINT)
	{
		if (s->stack_id == STACK_A)
			write(1, "sa\n", 3);
		if (s->stack_id == STACK_B)
			write(1, "sb\n", 3);
	}
	return (1);
}
