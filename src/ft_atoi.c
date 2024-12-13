/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:44:45 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/13 12:49:23 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"
#include "../include/push_swap.h"

int	handle_overflows(int sign, unsigned long res, unsigned long limit,
		int to_add)
{
	if (sign == 1 && (res > limit || (res == limit && to_add > 7)))
		return (0);
	else if (sign == -1 && (res > limit || (res == limit && to_add > 8)))
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr, t_stack *a, t_stack *b)
{
	int				i;
	int				sign;
	unsigned long	res;
	unsigned long	limit;

	i = 0;
	sign = 1;
	res = 0;
	limit = (unsigned long)(__INT_MAX__ / 10);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (!handle_overflows(sign, res, limit, nptr[i] - '0'))
		{
			free_stacks(a, b);
			ft_printf(ERROR);
			exit(1);
		}
		res = res * 10 + nptr[i++] - '0';
	}
	return (res * sign);
}
