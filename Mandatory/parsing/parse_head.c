/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:24:57 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/17 21:01:34 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
			cub->celling *= 10;
			cub->celling += tmp[i] - '0';
		}
		if (c == 'F')
		{
			cub->floor *= 10;
			cub->floor += tmp[i] - '0';
		}
		i++;
	}
	if (c == 'C')
		cub->rgb_c += 1;
	if (c == 'F')
		cub->rgb_f += 1;
	cub->celling *= 25.69919741;
	cub->floor *= 25.69919741;
}

void	head_texture(t_cub *cub, char c)
{
	char	*s;
	int		fd;

	fd = open(ft_strtrim(&cub->tmp[3], " "), O_RDONLY);
	if (fd < 0)
		ft_error(ft_strjoin(cub->tmp, "files texture not found\n"), 0);
	if (c == 'N')
		cub->north = ft_strtrim(&cub->tmp[3], " ");
	if (c == 'S')
		cub->south = ft_strtrim(&cub->tmp[3], " ");
	if (c == 'E')
		cub->east = ft_strtrim(&cub->tmp[3], " ");
	if (c == 'W')
		cub->west = ft_strtrim(&cub->tmp[3], " ");
	s = ft_strrchr(&cub->tmp[3], '.');
	if (!s)
		ft_error(" Not '.xpm' extension\n", 0);
	if (ft_strcmp(".xpm", s) != 0)
		ft_error("error: Texture is not an '.xpm' file\n", 1);
	cub->cnt++;
}

void	head_rgb(t_cub *cub, char *tmp, char c)
{
	int	i;

	i = 0;
	cub->cnt++;
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

void	check_read_head(t_cub *cub)
{
	if (cub->rgb_c != 1 || cub->rgb_f != 1)
		ft_error("arguments RGB not enough\n", 0);
	if (!cub->south || !cub->north || !cub->west || !cub->east)
		ft_error("arguments textures not enough\n", 0);
}

void	read_head(t_cub *cub, char **map)
{
	int	i;

	i = -1;
	while (++i < cub->head_map)
	{
		cub->tmp = ft_strtrim(map[i], " ");
		if (cub->tmp[0] == 'C' && cub->tmp[1] == ' ')
			head_rgb(cub, ft_strtrim(&cub->tmp[2], " "), 'C');
		else if (cub->tmp[0] == 'F' && cub->tmp[1] == ' ')
			head_rgb(cub, ft_strtrim(&cub->tmp[2], " "), 'F');
		else if (cub->tmp[0] == 'N' && cub->tmp[1] == 'O' && cub->tmp[2] == ' ')
			head_texture(cub, 'N');
		else if (cub->tmp[0] == 'S' && cub->tmp[1] == 'O' && cub->tmp[2] == ' ')
			head_texture(cub, 'S');
		else if (cub->tmp[0] == 'E' && cub->tmp[1] == 'A' && cub->tmp[2] == ' ')
			head_texture(cub, 'E');
		else if (cub->tmp[0] == 'W' && cub->tmp[1] == 'E' && cub->tmp[2] == ' ')
			head_texture(cub, 'W');
		else if (cub->tmp[0] == '\0')
			i += 1 - 1;
		else
			ft_error("Invalid head_map content\n", 0);
		free(cub->tmp);
	}
	check_read_head(cub);
}
