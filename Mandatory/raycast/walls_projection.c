/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqessam <iqessam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:52:23 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/04 11:10:24 by iqessam          ###   ########.fr       */
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

int 	converted(char *texel_color)
{
	int	decimal;
	unsigned int tmp;
	
	tmp = *(unsigned int*)texel_color;
	decimal = tmp / 256;
	return (decimal);
}

void	projection_walls3d(t_ray *ray)
{
	int		i;
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
		textureOffsetX *= ray->font_w;
           // calculate texture offset X
        // calculate texture offset Y
        int distanceFromTop = i + (wallstrip_height / 2) - (R_HEIGHT / 2);
        int textureOffsetY = distanceFromTop * ((float)ray->font_h / wallstrip_height);
        // set the color of the wall based on the color from the texture
        // char *texel_color = ray->north_adress + (int)(4 *  ((ray->font_w * textureOffsetY) + textureOffsetX));
		color = ray->north_adress[ray->font_w * textureOffsetY + (int)textureOffsetX];
		// printf("%X\n", *(unsigned int*)texel_color);
		my_mlx_pixel_put(ray, ray->ray_id, i, color);
		i++;
	}
}
