/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:25:57 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/06 17:14:29 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

int	is_input_valid(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
        j = 0;
		while (input[i][j])
		{
			if (!((input[i][j] >= '0' && input[i][j] <= '9')))
				return (0);
            j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	(void)ac;

	if (!is_input_valid(av + 1))
    {
		ft_printf(ERROR);
        exit(1);
    }
}