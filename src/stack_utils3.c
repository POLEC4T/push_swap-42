/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:07:50 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/14 14:05:28 by mniemaz          ###   ########.fr       */
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
		if (b->list[i] < val_to_push && (b->list[i] >= nearest_lower))
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
		if (a->list[i] > val_to_push && (a->list[i] <= nearest_higher))
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

static int	*init_stack(t_stack *s, int stack_size, enum e_stack_id stack_id)
{
	s->top = -1;
	s->direc = UP;
	s->max_top_idx = stack_size;
	s->stack_id = stack_id;
	s->list = malloc((stack_size) * sizeof(int));
	s->idx_to_top = -1;
	return (s->list);
}

static void	exit_error_atoi(int ac, char **strtab_numbers, t_stack *a,
		t_stack *b)
{
	if (ac == 2)
		free_tab_str(strtab_numbers);
	free_stacks(a, b);
	write(2, ERROR, 6);
	exit(EXIT_FAILURE);
}

/**
 * initializes a and b stacks
 * fill a with argv
 */
void	setup_stacks(t_stack *a, t_stack *b, char **strtab_numbers, int ac)
{
	int	tablen;
	int	atoi_overflowed;
	int	atoi_value;

	atoi_overflowed = 0;
	tablen = strtab_len(strtab_numbers);
	init_stack(a, tablen, STACK_A);
	if (!a->list)
		write_error_freestrtab_exit(strtab_numbers, ac);
	init_stack(b, tablen, STACK_B);
	if (!b->list)
	{
		free(a->list);
		write_error_freestrtab_exit(strtab_numbers, ac);
	}
	while (((tablen) > 0))
	{
		tablen--;
		atoi_value = ft_atoi_improved(strtab_numbers[tablen], &atoi_overflowed);
		if (atoi_overflowed)
			exit_error_atoi(ac, strtab_numbers, a, b);
		push(a, atoi_value);
	}
}
