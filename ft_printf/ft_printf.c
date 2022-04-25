/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:16:18 by msaouab           #+#    #+#             */
/*   Updated: 2021/11/27 21:07:17 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_check_per(char arg, va_list ap, int *len)
{
	if (arg == 'c')
		ft_putchar(va_arg(ap, int), len);
	else if (arg == '%')
		ft_putchar('%', len);
	else if (arg == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (arg == 'i' || arg == 'd')
		ft_putnbr(va_arg(ap, int), len);
	else if (arg == 'x' || arg == 'X')
		ft_puthex(va_arg(ap, unsigned int), arg, len);
	else if (arg == 'u')
		ft_putnbr_u(va_arg(ap, unsigned int), len);
	else if (arg == 'p')
		ft_pointer(va_arg(ap, void *), len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_check_per(format[i], ap, &len);
		}
		else
			ft_putchar(format[i], &len);
		i++;
	}
	va_end(ap);
	return (len);
}
