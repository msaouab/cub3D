/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:28:31 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/23 10:14:28 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	dda_algorithm(t_ray *ray, int color)
{
	int		k;
	int		dx;
	int		dy;
	int		steps;
	double	xinc;
	double	yinc;
	double	x;
	double	y;

	dx = ray->dirx - ray->posx;
	dy = ray->diry - ray->posy;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xinc = dx / (double)steps;
	yinc = dy / (double)steps;
	y = ray->posy + 5;
	x = ray->posx + 5;
	k = 0;
	while (k <= steps)
	{
		my_mlx_pixel_put(ray, round(x), round(y), color);
		y += yinc;
		x += xinc;
		k++;
	}
}

void	ray_cast(t_ray *ray, int columnId)
{
	(void)columnId;
	ray->yinter = floor(ray->posy / 30) * 30;
	ray->xinter = ray->posx + (ray->yinter - ray->posy) / tan(ray->ra);
}

void	put_rays(t_ray *ray, unsigned int color)
{
	double	ra_angle;
	int		i;
	int		columnid;

	i = 0;
	columnid = 0;
	ra_angle = ray->ra - (ray->fov_angle / 2);
	while (i < ray->num_rays)
	{
		ray->dirx = ray->posx + cos(ra_angle) * 30;
		ray->diry = ray->posy + sin(ra_angle) * 30;
		ray_cast(ray, columnid);
		dda_algorithm(ray, color);
		ra_angle += ray->fov_angle / ray->num_rays;
		i++;
		columnid++;
	}
}
