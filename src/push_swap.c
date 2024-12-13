/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:25:57 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/13 16:20:10 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

void	initialize_stacks(t_stack *a, t_stack *b, char **av, int ac)
{
	int	i;

	i = 0;
	a->list = malloc((ac - 1) * sizeof(int));
	if (!a->list)
		exit(1);
	b->list = malloc((ac - 1) * sizeof(int));
	a->max_stack_size = ac - 1;
	b->max_stack_size = ac - 1;
	a->stack_id = STACK_A;
	b->stack_id = STACK_B;
	if (!b->list)
	{
		free(a->list);
		exit(1);
	}
	while (((ac - 1) > 0))
	{
		a->list[i] = ft_atoi(av[ac - 1], a, b);
		ac--;
		i++;
	}
	a->top = i - 1;
	b->top = -1;
}

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
