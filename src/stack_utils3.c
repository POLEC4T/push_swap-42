/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:07:50 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/13 14:15:59 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @return the pos of the elem in b above which we want to push our elem
 * which means :
 * if a lower number exists
 * - its pos (index)
 * else
 * - the index of biggest number
 */
int	get_nearest_lower_idx(t_stack *b, int val_to_push)
{
	int	i_nearest_lower;
	int	nearest_lower;
	int	i;
	int	idx_biggest;

	i_nearest_lower = -1;
	nearest_lower = INT_MIN;
	idx_biggest = b->top;
	i = b->top;
	while (i >= 0)
	{
		if (b->list[i] < val_to_push && (b->list[i] > nearest_lower))
		{
			i_nearest_lower = i;
			nearest_lower = b->list[i];
		}
		if (b->list[i] > b->list[idx_biggest])
			idx_biggest = i;
		i--;
	}
	if (i_nearest_lower == -1)
		i_nearest_lower = idx_biggest;
	return (i_nearest_lower);
}

/**
 * @return the pos of the elem in a above which we want to push our elem
 * which means :
 * if an higher number exists
 * - its pos (index)
 * else
 * - the index of smallest number
 */
int	get_nearest_higher_idx(t_stack *a, int val_to_push)
{
	int	i_nearest_higher;
	int	nearest_higher;
	int	i;
	int	idx_smallest;

	i_nearest_higher = -1;
	nearest_higher = INT_MAX;
	idx_smallest = a->top;
	i = a->top;
	while (i >= 0)
	{
		if (a->list[i] > val_to_push && (a->list[i] < nearest_higher))
		{
			i_nearest_higher = i;
			nearest_higher = a->list[i];
		}
		if (a->list[i] < a->list[idx_smallest])
			idx_smallest = i;
		i--;
	}
	if (i_nearest_higher == -1)
		i_nearest_higher = idx_smallest;
	return (i_nearest_higher);
}
