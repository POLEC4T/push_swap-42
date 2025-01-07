/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:37:49 by mniemaz           #+#    #+#             */
/*   Updated: 2025/01/07 13:50:51 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @returns the value at the top of the stack s and
 * decrease the top index of the stack s
 */
int	pop(t_stack *s)
{
	int	top_value;

	if (s->top == -1)
	{
		write(2, "Error : Stack underflow", 23);
		return (-1);
	}
	top_value = s->list[s->top];
	s->top--;
	return (top_value);
}

/**
 * @brief pushes val to the top of s and increases top index
 */
void	push(t_stack *s, int val)
{
	if (s->top + 1 == s->max_top_idx)
	{
		write(2, "Error : Stack underflow", 23);
		return ;
	}
	s->top++;
	s->list[s->top] = val;
}

/**
 * @returns 1 if the stack is sorted from the minimum value
 * to the maximum value.
 * @details The minimum value does not have to be
 * at the top of the stack for the stack to be sorted.
 */
int	is_stack_sorted(t_stack *s)
{
	int	i;
	int	idx_min;

	idx_min = get_idx_min_val(s);
	i = idx_min;
	while (--i > 0)
		if (s->list[i] > s->list[i - 1])
			return (0);
	if (idx_min < s->top && s->list[0] > s->list[s->top])
		return (0);
	i = s->top + 1;
	while (--i - 1 > idx_min)
		if (s->list[i] > s->list[i - 1])
			return (0);
	return (1);
}
