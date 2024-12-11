/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:22:20 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/18 10:57:23 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putaddr(unsigned long addr)
{
	int	counter;

	if (!addr)
		return (ft_putstr("(nil)"));
	counter = 0;
	counter += ft_putstr("0x");
	counter += ft_put_ul_base(addr, "0123456789abcdef");
	return (counter);
}
