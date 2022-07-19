/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_head.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:07:28 by msaouab           #+#    #+#             */
/*   Updated: 2022/07/18 16:46:08 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	head_texture(t_cub *cub)
{
	cub->fd = open(&cub->tmp[3], O_RDONLY);
	if (cub->fd < 0)
		ft_error("files texture not found\n", 0);
	if (cub->tmp[0] == 'N')
		cub->fd_texture[0] = cub->fd;
	if (cub->tmp[0] == 'S')
		cub->fd_texture[1] = cub->fd;
	if (cub->tmp[0] == 'E')
		cub->fd_texture[2] = cub->fd;
	if (cub->tmp[0] == 'W')
		cub->fd_texture[3] = cub->fd;
}

void	head_rgb(t_cub *cub, char *tmp, char c)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (ft_isdigit(tmp[i]) == 0)
			ft_error("RGB Colors Not valid\n", 0);
		if ((tmp[i] == ',' && ft_isdigit(tmp[i + 1]) != 1) || \
			(ft_atoi(&tmp[i + 1]) < 0 || ft_atoi(&tmp[i + 1]) > 255))
			ft_error("RGB Colors Not valid\n", 0);
		i++;
	}
	rgb_to_hex(cub, tmp, c);
}

void	check_head(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->head_map)
	{
		cub->tmp = ft_strtrim(cub->map[i], " ");
		if (cub->tmp[0] == 'C' && cub->tmp[1] == ' ')
			head_rgb(cub, &cub->tmp[2], 'C');
		else if (cub->tmp[0] == 'F' && cub->tmp[1] == ' ')
			head_rgb(cub, &cub->tmp[2], 'F');
		else if (cub->tmp[0] == 'N' && cub->tmp[2] == ' ')
			head_texture(cub);
		else if (cub->tmp[0] == 'S' && cub->tmp[2] == ' ')
			head_texture(cub);
		else if (cub->tmp[0] == 'E' && cub->tmp[2] == ' ')
			head_texture(cub);
		else if (cub->tmp[0] == 'W' && cub->tmp[2] == ' ')
			head_texture(cub);
		free (cub->tmp);
	}
}

void	parsing_head(t_cub *cub)
{
	int	cnt;

	cnt = cub->_c + cub->_f + cub->_n + cub->_s + cub->_e + cub->_w;
	if (cnt != 6)
		ft_error("map not valid\n", 0);
	else
		check_head(cub);
}

void	read_head(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->head_map)
	{
		cub->tmp = ft_strtrim(cub->map[i], " ");
		if (cub->tmp[0] == 'C')
			cub->_c += 1;
		if (cub->tmp[0] == 'F')
			cub->_f += 1;
		if (cub->tmp[0] == 'N' && cub->tmp[1] == 'O')
			cub->_n += 1;
		if (cub->tmp[0] == 'S' && cub->tmp[1] == 'O')
			cub->_s += 1;
		if (cub->tmp[0] == 'E' && cub->tmp[1] == 'A')
			cub->_e += 1;
		if (cub->tmp[0] == 'W' && cub->tmp[1] == 'E')
			cub->_w += 1;
		free (cub->tmp);
	}
	parsing_head(cub);
}
