/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:51:35 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/17 13:42:34 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @returns 0 if input contains anything else than numbers
 * @example ["123", "123", "abc"] => 0
 * @example ["123", "123", "-123"] => 1
 */
int	input_only_nb(char **input)
{
	int	i;
	int	j;
	int	old_j;

	i = -1;
	while (input[++i])
	{
		j = 0;
		if (input[i][j] == '-')
			j++;
		old_j = j;
		while (input[i][j])
		{
			if (!((input[i][j] >= '0' && input[i][j] <= '9')))
				return (0);
			j++;
		}
		if (j == old_j)
			return (0);
	}
	return (1);
}

/**
 * @returns 1 if the stack s contains the same value mutiple times
 */
int	got_duplicates(t_stack *s)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	while (i <= s->top)
	{
		counter = 0;
		j = 0;
		while (j <= s->top)
		{
			if (s->list[j] == s->list[i])
				counter++;
			if (counter > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
