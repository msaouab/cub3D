/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqessam <iqessam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:52:23 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/04 14:01:13 by iqessam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_celling(t_ray *ray)
{
	int	i;

	i = 0;
	while (i < ray->top_pixel)
	{
		my_mlx_pixel_put(ray, ray->ray_id, i, ray->cub->celling);
		i++;
	}
}

void	put_floor(t_ray *ray)
{
	int	i;

	i = ray->bottom_pixel;
	while (i < R_HEIGHT)
	{
		my_mlx_pixel_put(ray, ray->ray_id, i, ray->cub->floor);
		i++;
	}
}

void	projection_walls3d(t_ray *ray)
{
	int		i;
	int		j = 0;
	int color;
	double	wallstrip_height;
	double	distprojectplane;
	double	perpdist;
	double	textureOffsetX;
	perpdist = ray->cast.disctance * cos(ray->ra_angle - ray->ra);
	distprojectplane = (R_WIDTH / 2.0) / tan(ray->fov_angle / 2.0);
	wallstrip_height = (TILE_SIZE / perpdist) * distprojectplane;
	ray->top_pixel = (R_HEIGHT / 2.0) - (wallstrip_height / 2.0);
	if (ray->top_pixel < 0 || ray->top_pixel > R_HEIGHT)
		ray->top_pixel = 0;
	ray->bottom_pixel = (R_HEIGHT / 2.0) + (wallstrip_height / 2.0);
	if (ray->bottom_pixel > R_HEIGHT || ray->bottom_pixel < 0)
		ray->bottom_pixel = R_HEIGHT;
	i = ray->top_pixel;
	put_celling(ray);
	put_floor(ray);
	while (i < ray->bottom_pixel)
	{
		if (ray->cast.washitvert)
			textureOffsetX = ray->wallhity / TILE_SIZE;
		else
			textureOffsetX = ray->wallhitx / TILE_SIZE;
		textureOffsetX = textureOffsetX - floor(textureOffsetX);
        if (!ray->cast.washitvert && ray->cast.rayfaceup)
			j = 0;
		else if (!ray->cast.washitvert && ray->cast.rayfacedown)
			j = 1;
		else if (ray->cast.washitvert && ray->cast.rayfaceleft)
			j = 2;
		else if (ray->cast.washitvert && ray->cast.rayfaceright)
			j = 3;
		int *adress = ray->adress[j];
		textureOffsetX *= ray->font_w[j];
		int distanceFromTop = i + (wallstrip_height / 2) - (R_HEIGHT / 2);
        int textureOffsetY = distanceFromTop * ((float)ray->font_h[j] / wallstrip_height);
		color = adress[(ray->font_w[j] * textureOffsetY) + (int)textureOffsetX];
		my_mlx_pixel_put(ray, ray->ray_id, i, color);
		i++;
	}
}
