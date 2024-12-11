/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:22:13 by mniemaz           #+#    #+#             */
/*   Updated: 2024/12/09 10:01:51 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_arg(char flag, va_list ptr)
{
	int	counter;

	counter = 0;
	if (flag == 's')
		counter += ft_putstr(va_arg(ptr, char *));
	else if (flag == 'd' || flag == 'i')
		counter += ft_putnbr(va_arg(ptr, int));
	else if (flag == 'c')
		counter += ft_putchar(va_arg(ptr, int));
	else if (flag == 'u')
		counter += ft_put_ui_base(va_arg(ptr, unsigned int), "0123456789");
	else if (flag == 'x')
		counter += ft_put_ui_base(va_arg(ptr, unsigned int),
				"0123456789abcdef");
	else if (flag == 'X')
		counter += ft_put_ui_base(va_arg(ptr, unsigned int),
				"0123456789ABCDEF");
	else if (flag == '%')
		counter += ft_putchar('%');
	else if (flag == 'p')
		counter += ft_putaddr(va_arg(ptr, unsigned long));
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		counter;

	if (!str || write(1, 0, 0) == -1)
		return (-1);
	counter = 0;
	va_start(ptr, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			counter += print_arg(str[i + 1], ptr);
			i++;
		}
		else if (str[i] != '%')
			counter += ft_putchar(str[i]);
	}
	va_end(ptr);
	return (counter);
}
