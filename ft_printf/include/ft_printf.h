/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:22:03 by mniemaz           #+#    #+#             */
/*   Updated: 2024/11/18 13:12:22 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_put_ui_base(unsigned int nbr, char *base);
int		ft_put_ul_base(unsigned long nbr, char *base);
int		ft_putaddr(unsigned long addr);
int		ft_putchar(char c);
int		ft_putnbr(int nbr);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);

#endif