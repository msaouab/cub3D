/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqessam <iqessam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:32 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/01 13:39:09 by iqessam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_celling(t_ray *ray)
{
	int	i;

	i = 0;
	while (i < ray->top_pixel)
	{
			my_mlx_pixel_put(ray,ray->ray_id ,i,  ray->cub->celling);
		i++;
	}
}

void	put_floor(t_ray *ray)
{
	int	i;

	i = ray->bottom_pixel;
	while (i < R_HEIGHT)
	{
			my_mlx_pixel_put(ray, ray->ray_id ,i , ray->cub->floor);
		i++;
	}
}

void	put_3drender(t_ray *ray)
{
	// (void)ray;
	projection_walls3d(ray);
}