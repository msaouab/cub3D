/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:52:23 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/02 18:28:34 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
			my_mlx_pixel_put(ray, ray->ray_id, i, 5161616);
		else
			my_mlx_pixel_put(ray, ray->ray_id, i, 65165456);
		i++;
	}
}
