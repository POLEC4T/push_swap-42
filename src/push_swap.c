/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:25:57 by mniemaz           #+#    #+#             */
/*   Updated: 2025/01/07 14:50:44 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * initializes a and b stacks
 * fill a with argv
 */
void	setup_stacks(t_stack *a, t_stack *b, char **strtab_numbers, int tablen)
{
	init_stack(a, tablen, STACK_A);
	if (!a->list)
		exit(1);
	init_stack(b, tablen, STACK_B);
	if (!b->list)
	{
		free(a->list);
		exit(1);
	}
	while (((tablen) > 0))
	{
		tablen--;
		push(a, ft_atoi(strtab_numbers[tablen], a, b));
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**strtab_numbers;
	int		tablen;

	strtab_numbers = NULL;
	if (ac == 2)
		strtab_numbers = ft_split(av[1], ' ');
	else if (ac > 2)
		strtab_numbers = av + 1;
	tablen = strtab_len(strtab_numbers);
	if (tablen == 0 || ac < 2)
		exit(0);
	if (!input_only_nb(strtab_numbers))
		write_error_exit();
	setup_stacks(&a, &b, strtab_numbers, tablen);
	if (ac == 2)
		free_tab_str(strtab_numbers);
	if (got_duplicates(&a))
	{
		free_stacks(&a, &b);
		write_error_exit();
	}
	sorter(&a, &b);
	free_stacks(&a, &b);
}
