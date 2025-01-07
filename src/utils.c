/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:51:10 by mniemaz           #+#    #+#             */
/*   Updated: 2025/01/07 14:51:49 by mniemaz          ###   ########.fr       */
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
	while (strtab[i])
		i++;
	return (i);
}

void	write_error_exit(void)
{
	write(1, ERROR, 6);
	exit(1);
}