/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:07:20 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/10 16:13:05 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @param s the stack
 * @param idx the index of the element to put at the top of s
 * @return the number of every operations that would be
 * needed to put the elem to the top of the stack s
 */
int get_cost_put_to_top(t_stack *s, int idx)
{
    int cost;

    cost = 0;
    while (idx != s->top && idx >= 0)
	{
		if (idx > s->top / 2)
			idx++;
		else
			idx--;
        cost++;
	}
    return (cost);
}