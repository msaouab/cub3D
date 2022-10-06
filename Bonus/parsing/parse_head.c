/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqessam <iqessam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:24:57 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/06 16:23:37 by iqessam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	rgb_to_deci(t_cub *cub, char *tmp, char c)
{
	int				i;
	char			**decimal;
	unsigned int	color;

	i = -1;
	color = 0;
	decimal = ft_split(tmp, ',');
	while (++i < 3)
	{
		if (i == 0)
			color += ft_atoi(decimal[i]) * (256 * 256);
		if (i == 1)
			color += ft_atoi(decimal[i]) * 256;
		if (i == 2)
			color += ft_atoi(decimal[i]);
		if (ft_atoi(decimal[i]) > 255 || ft_atoi(decimal[i]) < 0)
			ft_error("RGB Colors Not valid\n", 0);
	}
	assignement_color(cub, c, color);
	ft_free(decimal);
}

void	head_texture(t_cub *cub, char c)
{
	char	*str;
	char	*s;
	int		fd;

	str = ft_strtrim(&cub->tmp[3], " ");
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error(ft_strjoin(cub->tmp, "files texture not found\n"), 0);
	if (c == 'N')
		cub->north = str;
	if (c == 'S')
		cub->south = str;
	if (c == 'E')
		cub->east = str;
	if (c == 'W')
		cub->west = str;
	s = ft_strrchr(&cub->tmp[3], '.');
	if (!s)
		ft_error(" Not '.xpm' extension\n", 0);
	if (ft_strcmp(".xpm", s) != 0)
		ft_error("error: Texture is not an '.xpm' file\n", 1);
	texture_counter(cub, c);
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
	rgb_to_deci(cub, tmp, c);
	free(tmp);
}

void	check_read_head(t_cub *cub)
{
	if (cub->rgb_c != 1 || cub->rgb_f != 1)
		ft_error("Error RGB arguments number incorrect  \n", 0);
	if (!cub->south || !cub->north || !cub->west || !cub->east)
		ft_error("Error texture arguments number incorrect\n", 0);
	if (cub->ntext != 1 || cub->stext != 1 \
		|| cub->etext != 1 || cub->wtext != 1)
		ft_error("Error texture arguments number incorrect\n", 0);
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
