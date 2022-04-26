/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:10:03 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/19 22:59:20 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*t;
	char	*src;

	src = (char *) s;
	i = ft_strlen(src);
	t = malloc((i + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		t[i] = src[i];
		i++;
	}
	t[i] = 0;
	return (t);
}

int	ft_atoi(char *nptr)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			b = -b;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		a = a * 10 + *nptr - 48;
		nptr++;
	}
	a *= b;
	if (a < 0 || a > 255)
		exit(printf("rgb error"));
	return (a * b);
}

int	check_file(char *t)
{
	int	i;

	i = 0;
	while (t[i])
		i++;
	i--;
	if (!(t[i] == 'b' && t[i - 1] == 'u' && t[i - 2] == 'c' && t[i - 3] == '.'))
		return (printf("file map must be .cub extension."), 0);
	return (1);
}

int	ft_strcmp(char *s1, char c)
{
	while (*s1 && *s1 == c)
		s1++;
	if (*s1)
		return (1);
	return (0);
}

char	*read_map(int fd)
{
	int		r;
	char	c;
	char	t[800000];
	int		i;

	r = 1;
	i = 0;
	while (read(fd, &c, 1))
	{
		t[i++] = c;
		if (c == '\n')
			break ;
	}
	t[i] = 0;
	return (ft_strdup(t));
}
