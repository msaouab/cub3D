/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_charcters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:24:25 by msaouab           #+#    #+#             */
/*   Updated: 2022/07/18 16:49:32 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rgb_to_hex(t_cub *cub, char *tmp, char c)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == ',')
			i++;
		if (c == 'C')
		{
			cub->rgb_c *= 10;
			cub->rgb_c += tmp[i] - '0';
		}
		if (c == 'F')
		{
			cub->rgb_f *= 10;
			cub->rgb_f += tmp[i] - '0';
		}
		i++;
	}
}

void	check_character(t_cub *cub, int i, int j)
{
	if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' || \
		cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
	{
		cub->type = cub->map[i][j];
		cub->_p++;
	}
}

void	parse_char(t_cub *cub)
{
	int	i;
	int	j;

	i = cub->head_map;
	while (i < cub->count_line)
	{
		j = 0;
		while (cub->map[i][j])
		{
			check_character(cub, i, j);
			j++;
		}
		i++;
	}
	if (cub->_p != 1)
		ft_error("map does not have a player\n", 0);
}
