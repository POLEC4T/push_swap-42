/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:44:45 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/06 15:49:47 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr(int nbr)
{
	unsigned int	u_nbr;
	int				counter;

	counter = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		counter++;
		u_nbr = -nbr;
	}
	else
		u_nbr = nbr;
	if (u_nbr < 10)
	{
		return (counter + ft_putchar(u_nbr + '0'));
	}
	else
	{
		counter += ft_putnbr(u_nbr / 10);
		return (counter + ft_putnbr(u_nbr % 10));
	}
}

int	ft_put_ui_base(unsigned int nbr, char *base)
{
	unsigned int	u_nbr;
	int				counter;

	counter = 0;
	u_nbr = nbr;
	if (u_nbr < ft_strlen(base))
		return (counter + ft_putchar(base[u_nbr]));
	else
	{
		counter += ft_put_ui_base(u_nbr / ft_strlen(base), base);
		return (counter + ft_put_ui_base(u_nbr % ft_strlen(base),
				base));
	}
}

int	ft_put_ul_base(unsigned long nbr, char *base)
{
	int	counter;

	counter = 0;
	if (nbr < ft_strlen(base))
		return (counter + ft_putchar(base[nbr]));
	else
	{
		counter += ft_put_ul_base(nbr / ft_strlen(base), base);
		return (counter + ft_put_ul_base(nbr % ft_strlen(base), base));
	}
}

int	ft_putstr(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
