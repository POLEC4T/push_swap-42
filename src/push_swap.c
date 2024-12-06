/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:25:57 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/06 17:48:13 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/push_swap.h"

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
    int *a;
    int *b;
    int i;

    i = 0;
	if (!is_input_valid(av + 1))
    {
		ft_printf(ERROR);
        exit(1);
    }

    a = malloc((ac - 1) * sizeof(int));
    b = malloc((ac - 1) * sizeof(int));
    while((av[i + 1]))
    {
        a[i] = ft_atoi(av[i + 1]);
        i++;
    }
    ft_printf("av[0]:%d\nav[1]:%d\nav[1]:%d",a[0], a[1], a[2]);
}