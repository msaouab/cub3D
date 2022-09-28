/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:52:23 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/28 20:45:52 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	projection_walls3d(t_ray *ray, int y)
{
	(void)y;
	int		i;
	int		j;
	int		top_pixel;
	int		bottom_pixel;
	int		wallstrip_height;
	double	distprojectplane;
	double	perpdist;

	perpdist = ray->cast.disctance * cos(ray->ra_angle - ray->ra);
	distprojectplane = (R_WIDTH / 2) / tan(ray->fov_angle / 2);
	wallstrip_height = (TILE_SIZE / perpdist) * distprojectplane;
	top_pixel = (R_HEIGHT / 2) - (wallstrip_height / 2);
	if (top_pixel < 0)
		top_pixel = 0;
	bottom_pixel = (R_HEIGHT / 2) + (wallstrip_height / 2);
	if (bottom_pixel > R_HEIGHT)
		bottom_pixel = R_HEIGHT;
	i = top_pixel;
	while (i < bottom_pixel)
	{
		j = 0;
		while(j < R_WIDTH)
		{
			if (ray->cast.washitvert)
				my_mlx_pixel_put(ray, j, i, 0x0ffeeee);
			else
				my_mlx_pixel_put(ray, j, i, 0x0AAAAA);
			j++;	
		}
		i++;
	}
}
