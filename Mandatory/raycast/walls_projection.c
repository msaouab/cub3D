/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqessam <iqessam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:52:23 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/30 18:56:51 by iqessam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void color_buffer(t_ray *ray)
{
	int x;
	int y;
	
	x = 0;
	ray->pixel_color = (unsigned int *)malloc(sizeof(unsigned int) * (unsigned int)R_WIDTH *
	 (unsigned int)R_HEIGHT);
	while (x < R_WIDTH)
	{
		y = 0;
		while (y < R_HEIGHT)
		{
			ray->pixel_color[(R_WIDTH * y) + x] = 0xFF000000;
			y++;
		}
		x++;
	}
}


void	projection_walls3d(t_ray *ray)
{
	int		i;
	int		wallstrip_height;
	double	distprojectplane;
	double	perpdist;

	perpdist = ray->cast.disctance * cos(ray->ra_angle - ray->ra);
	distprojectplane = (R_WIDTH / 2) / tan(ray->fov_angle / 2);
	wallstrip_height = (TILE_SIZE / perpdist) * distprojectplane;
	ray->top_pixel = (R_HEIGHT / 2) - (wallstrip_height / 2);
	if (ray->top_pixel < 0)
		ray->top_pixel = 0;
	ray->bottom_pixel = (R_HEIGHT / 2) + (wallstrip_height / 2);
	if (ray->bottom_pixel > R_HEIGHT)
		ray->bottom_pixel = R_HEIGHT;
	i = ray->top_pixel;
	while (i < ray->bottom_pixel)
	{
		if (ray->cast.washitvert)
			my_mlx_pixel_put(ray, ray->ray_id, i, 5161616);
		else
			my_mlx_pixel_put(ray, ray->ray_id,i, 65165456);	
		i++;
	}
}