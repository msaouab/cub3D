/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqessam <iqessam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:32 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/30 19:14:37 by iqessam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_celling(t_ray *ray)
{
	int	i;

	i = 0;
	while (i < ray->top_pixel)
	{
			my_mlx_pixel_put(ray, ,i,  ray->cub->celling);
		i++;
	}
}

void	put_floor(t_ray *ray)
{
	int	i;

	i = ray->bottom_pixel;
	while (i < R_HEIGHT)
	{
			my_mlx_pixel_put(ray, i, , ray->cub->floor);
		i++;
	}
}

void	put_3drender(t_ray *ray)
{
	projection_walls3d(ray);
	put_celling(ray);
	put_floor(ray);
}