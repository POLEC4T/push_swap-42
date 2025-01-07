/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:51:10 by mniemaz           #+#    #+#             */
/*   Updated: 2025/01/07 18:24:15 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @returns the the number of strs in strtab
 * @example ["123", "123", "abc"] => 3
 */
int	strtab_len(char **strtab)
{
	int	i;

	i = 0;
	while (strtab && strtab[i])
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	write_error_exit(void)
{
	write(2, ERROR, 6);
	exit(1);
}

void	write_error_freestacks_exit(t_stack *a, t_stack *b)
{
	free_stacks(a, b);
	write(2, ERROR, 6);
	exit(1);
}

void	write_error_freestrtab_exit(char **tabstr, int ac)
{
	if (ac == 2)
		free_tab_str(tabstr);
	write(2, ERROR, 6);
	exit(1);
}
