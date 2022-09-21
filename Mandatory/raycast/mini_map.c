/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:26:36 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/21 21:34:54 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	xpmfile(t_ray *ray)
{
	ray->img = mlx_new_image(ray->mlx, R_WIDTH, R_HEIGHT);
	if (!ray->img)
		ft_error("mlx_xpm_file_to_image problem", 1);
	ray->addr = mlx_get_data_addr(ray->img, &ray->bits_per_pixel, &ray->line_length, &ray->endian);
	if (!ray->addr)
		ft_error("mlx_get_data_addr problem", 1);
}

void	my_mlx_pixel_put(t_ray *ray, int x, int y, int color)
{
	char	*dst;

	dst = ray->addr + (y * ray->line_length + x * (ray->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_minimap(t_ray *ray, int pixels, unsigned int color)
{
	int	i;
	int	j;

	i = ray->miniy;
	while (i < ray->miniy + pixels)
	{
		j = ray->minix;
		while (j < ray->minix + pixels)
		{
			my_mlx_pixel_put(ray, j, i, color);
			j++;
		}
		i++;
	}
}

void	put_player_minimap(t_ray *ray, int pixels, unsigned int color)
{
	int	i;
	int	j;

	i = ray->posy;
	while (i < (ray->posy + pixels))
	{
		j = ray->posx;
		while (j < (ray->posx + pixels))
		{
			my_mlx_pixel_put(ray, j, i, color);
			j++;
		}
		i++;
	}
	// field_vue(ray, color);
}

void	puts_minimap(t_ray *ray)
{
	int	i;
	int	j;

	i = 0;
	ray->minix = 0;
	ray->miniy = 0;
	while (ray->cub->body[i])
	{
		j = 0;
		while (ray->cub->body[i][j])
		{
			fill_minimap(ray, 12, 10000);
			if (ray->cub->body[i][j] == '1')
				fill_minimap(ray, 10, ray->cub->celling);
			ray->minix += 12;
			j++;
		}
		ray->minix = 0;
		ray->miniy += 12;
		i++;
	}
	put_player_minimap(ray, 10, 99999);
}
