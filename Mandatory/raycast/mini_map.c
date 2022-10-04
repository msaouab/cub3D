/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqessam <iqessam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:26:36 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/04 14:07:18 by iqessam          ###   ########.fr       */
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
	init_texture(ray);
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
			if (i >= 0 && i < (R_HEIGHT / 5) && j >= 0 && j < (R_WIDTH / 5))
				my_mlx_pixel_put(ray, j, i, color);
			j++;
		}
		i++;
	}
}

void	fill_minimap(t_ray *ray, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < R_HEIGHT / 5)
	{
		j = 0;
		while (j < R_WIDTH / 5)
		{
			my_mlx_pixel_put(ray, j, i, color);
			j++;
		}
		i++;
	}
}

void	put_minimap(t_ray *ray)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = (ray->posx) - (R_WIDTH / 5 / 2);
	y = (ray->posy) - (R_HEIGHT / 5 / 2);
	fill_minimap(ray, TRANSPARENT);
	while (ray->cub->body[++i])
	{
		j = -1;
		ray->miniy = TILE_SIZE * i - y;
		while (ray->cub->body[i][++j])
		{
			ray->minix = TILE_SIZE * j - x;
			if (ray->cub->body[i][j] == '1')
				put_minimap_windows(ray, TILE_SIZE, 0xffffff);
		}
	}
	my_mlx_pixel_put(ray, ray->cminix, ray->cminiy, 0xffffff);
}
