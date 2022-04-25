/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:45:52 by msaouab           #+#    #+#             */
/*   Updated: 2021/11/27 21:07:52 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, char arg, int *len)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', len);
		nb *= -1;
	}
	if (nb < 16)
	{
		if (nb <= 9)
			ft_putchar(nb + 48, len);
		else if (nb >= 10 && arg == 'X')
			ft_putchar((nb % 10) + 'A', len);
		else if (nb >= 10 && arg == 'x')
			ft_putchar((nb % 10) + 'a', len);
	}
	else
	{
		ft_puthex(nb / 16, arg, len);
		ft_puthex(nb % 16, arg, len);
	}
}

void	ft_putp(unsigned long nb, int *len)
{
	if (nb < 16)
	{
		if (nb <= 9)
			ft_putchar(nb + 48, len);
		else if (nb >= 10)
			ft_putchar((nb % 10) + 'a', len);
	}
	else
	{
		ft_putp(nb / 16, len);
		ft_putp(nb % 16, len);
	}
}

void	ft_pointer(void *ptr, int *len)
{
	unsigned long	a;

	a = (unsigned long)ptr;
	ft_putstr("0x", len);
	ft_putp(a, len);
}
