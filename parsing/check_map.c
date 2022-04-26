/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:51:14 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/26 00:52:19 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_map_horizontal(char **map, int width, int height)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (map[i][++j])
		{
			while (map[i][j] == ' ')
				j++;
			if (!map[i][j])
				break ;
			if (map[i][j] != '1')
				return (-1);
			else
			{
				while (map[i][j] != '\0' && map[i][j] != ' ')
					j++;
				if (!map[i][j])
					return(0);
				if (map[i][j] != '\0' && map[i][j - 1] != '1')
					return (-1);
			}
		}
	}
	return (0);
}

int	ft_check_map_vertical(char **map, int width, int height)
{
	int	i;
	int	j;

	j = 0;
	while (j < width)
	{
		i = 0;
		while (i < height)
		{
			while (i < height && map[i][j] == ' ')
				i++;
			if (i == height)
				break ;
			if (map[i][j] != '1')
				return (printf("hello\n"), -1);
			while (i < height && map[i][j] != ' ')
				i++;
			if (map[i - 1][j] != '1')
				return (-1);
			while (i < height && map[i][j] == ' ')
				i++;
		}
		j++;
	}
	return (0);
}

void	ft_remplir_map(char **map, int width, int height)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	buffer = malloc(sizeof(char) * (width + 1));
	if (!buffer)
		return ;
	while (i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (j < ft_strlen(map[i]))
				buffer[j] = map[i][j];
			else
				buffer[j] = ' ';
		}
		buffer[j] = '\0';
		free(map[i]);
		map[i] = ft_strdup(buffer);
		i++;
	}
	free(buffer);
}

void	ft_check(char **s)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (s[1][j])
	{
		if (s[1][j] == ',')
			i++;
		j++;
	}
	if (i > 2)
		exit(printf("rgb error"));
}
