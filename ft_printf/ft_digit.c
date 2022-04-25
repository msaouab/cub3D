/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:41:12 by msaouab           #+#    #+#             */
/*   Updated: 2021/11/27 21:07:35 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int *len)
{
	unsigned long	nb;

	nb = n;
	if (nb <= 9)
		ft_putchar(nb + '0', len);
	else
	{
		ft_putnbr_u(nb / 10, len);
		ft_putnbr_u(nb % 10, len);
	}
}

void	ft_putnbr(int n, int *len)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', len);
		nb *= -1;
	}
	if (nb <= 9)
		ft_putchar(nb + '0', len);
	else
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
}
