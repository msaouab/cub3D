/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqessam <iqessam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:52:23 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/02 12:47:52 by iqessam          ###   ########.fr       */
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
	double	wallstrip_height;
	double	distprojectplane;
	double	perpdist;

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
			my_mlx_pixel_put(ray, ray->ray_id, i, 0x7895B2);
		else
			my_mlx_pixel_put(ray, ray->ray_id, i, 0xF5EFE6);
		i++;
	}
}
