/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:25:57 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/14 10:10:31 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

int	*init_stack(t_stack *s, int stack_size, enum e_stack_id stack_id)
{
	s->top = -1;
	s->direc = UP;
	s->max_stack_size = stack_size;
	s->stack_id = stack_id;
	s->list = malloc((stack_size) * sizeof(int));
	s->idx_to_top = -1;
	return (s->list);
}

void	initialize_stacks(t_stack *a, t_stack *b, char **av, int ac)
{
	init_stack(a, ac - 1, STACK_A);
	if (!a->list)
		exit(1);
	init_stack(b, ac - 1, STACK_B);
	if (!b->list)
	{
		free(a->list);
		exit(1);
	}
	while (((ac - 1) > 0))
	{
		push(a, ft_atoi(av[ac - 1], a, b));
		ac--;
	}
}

// int	main(int ac, char **av)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	t_stack	*save_a;
// 	t_stack	*save_b;
// 	a = malloc(sizeof(t_stack));
// 	b = malloc(sizeof(t_stack));
// 	save_a = a;
// 	save_b = b;
// 	if (!input_only_nb(av + 1) || ac < 2)
// 	{
// 		ft_printf(ERROR);
// 		exit(1);
// 	}
// 	initialize_stacks(a, b, av, ac);
// 	if (got_duplicates(a))
// 	{
// 		ft_printf(ERROR);
// 		free_stacks(a, b);
// 		exit(1);
// 	}
// 	sorter(a, b);
// 	free_stacks(save_a, save_b);
// }

#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	// t_stack	*save_a;
	// t_stack	*save_b;
	// a = malloc(sizeof(t_stack));
	// b = malloc(sizeof(t_stack));
	// save_a = a;
	// save_b = b;
	if (!input_only_nb(av + 1) || ac < 2)
	{
		ft_printf(ERROR);
		exit(1);
	}
	initialize_stacks(&a, &b, av, ac);
	if (got_duplicates(&a))
	{
		ft_printf(ERROR);
		free_stacks(&a, &b);
		exit(1);
	}
	sorter(&a, &b);
	free_stacks(&a, &b);
}
