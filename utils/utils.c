/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:14:25 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/25 16:14:42 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_error(char *str, int exit_status)
{
	write(2, str, ft_strlen(str));
	exit(exit_status);
	return (exit_status);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

float	f_abs(float n)
{
	if (n >= 0)
		return (n);
	return (-n);
}
