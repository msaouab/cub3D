/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:26:36 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/22 20:49:33 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	xpmfile(t_ray *ray)
{
	ray->img = mlx_new_image(ray->mlx, R_WIDTH, R_HEIGHT);
	if (!ray->img)
		ft_error("mlx_xpm_file_to_image problem", 1);
	ray->addr = mlx_get_data_addr(ray->img, &ray->bits_per_pixel, \
	&ray->line_length, &ray->endian);
	if (!ray->addr)
		ft_error("mlx_get_data_addr problem", 1);
}

void	my_mlx_pixel_put(t_ray *ray, int x, int y, unsigned int color)
{
	char	*dst;

	dst = ray->addr + (y * ray->line_length + x * (ray->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_minimap_windows(t_ray *ray, int pix, unsigned int color)
{
	int	i;
	int	j;

	i = ray->miniy;
	while (i < ray->miniy + pix)
	{
		j = ray->minix;
		while (j < ray->minix + pix)
		{
			my_mlx_pixel_put(ray, j, i, color);
			j++;
		}
		i++;
	}
}

void	put_player_win(t_ray *ray, unsigned int color)
{
	int	i;
	int	j;

	i = ray->posy + 6;
	j = ray->posx + 6;
	my_mlx_pixel_put(ray, j, i, color);
	put_rays(ray, color);
}

void	put_minimap(t_ray *ray)
{
	int	i;
	int	j;

	i = 0;
	ray->miniy = 0;
	while (ray->cub->body[i])
	{
		j = 0;
		while (ray->cub->body[i][j])
		{
			put_minimap_windows(ray, 12, ray->cub->celling);
			if (ray->cub->body[i][j] == '1')
				put_minimap_windows(ray, 10, ray->cub->floor);
			ray->minix += 12;
			j++;
		}
		ray->minix = 0;
		ray->miniy += 12;
		i++;
	}
	put_player_win(ray, 9999);
}
