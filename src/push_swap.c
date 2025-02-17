/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:25:57 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/14 14:07:58 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**strtab_numbers;

	strtab_numbers = NULL;
	if (ac == 2 && ft_strlen(av[1]) != 0)
		strtab_numbers = ft_split(av[1], ' ');
	else if (ac > 2)
		strtab_numbers = av + 1;
	if (strtab_len(strtab_numbers) == 0 || ac < 2)
		exit(EXIT_SUCCESS);
	if (!input_only_nb(strtab_numbers))
		write_error_freestrtab_exit(strtab_numbers, ac);
	setup_stacks(&a, &b, strtab_numbers, ac);
	if (ac == 2)
		free_tab_str(strtab_numbers);
	if (got_duplicates(&a))
		write_error_freestacks_exit(&a, &b);
	sorter(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
