/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:28:31 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/26 10:20:42 by msaouab          ###   ########.fr       */
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
	xinc = dx / (double)steps + 10;
	yinc = dy / (double)steps + 10;
	y = ray->cminiy;
	x = ray->cminix;
	k = 0;
	while (k <= steps)
	{
		my_mlx_pixel_put(ray, round(x), round(y), color);
		y += yinc;
		x += xinc;
		k++;
	}
}

void	ray_cast(t_ray *ray, int columnId, double ra_angle)
{
	double	ystep;
	double	xstep;
	int		rayfacingup = 0;
	int		rayfacingdown = 0;
	int		rayfacingleft = 0;
	int		rayfacingright = 0;
	double	next_x;
	double	next_y;
	int		vertwallhit = 0;
	// int		horzwallhit = 0;
	double	vertwallhitx = 0;
	double	vertwallhity = 0;

	(void)columnId;
	rayfacingdown = ra_angle > 0 && ra_angle < M_PI;
	rayfacingup = !rayfacingdown;
	rayfacingright = ra_angle < 0.5 * M_PI || ra_angle > 1.5 * M_PI;
	rayfacingleft = !rayfacingright;
	ray->yinter = floor(ray->posy / TILE_SIZE) * TILE_SIZE;
	ray->yinter += rayfacingdown ? TILE_SIZE : 0;
	
	ray->xinter = ray->posx + (ray->yinter - ray->posy) / tan(ra_angle);
	
	xstep = TILE_SIZE;
	xstep *= rayfacingleft ? -1 : 1;
	
	ystep = TILE_SIZE * tan(ra_angle);
	ystep *= (rayfacingup && ystep > 0) ? -1 : 1;
	ystep *= (rayfacingdown && ystep < 0) ? -1 : 1;
	next_x = ray->xinter;
	next_y = ray->yinter;
	if (rayfacingleft)
		next_x--;
	while (next_x >= 0 && next_x <= R_WIDTH && next_y >= 0 && next_y <= R_HEIGHT)
	{
		if (find_walls(ray, next_x, next_y) == 1)
		{
			vertwallhit = 1;
			vertwallhitx = next_x;
			vertwallhity = next_y;
			break;
		}
		else
		{
			next_x += xstep;
			next_y += ystep;
		}
	}
	// my_mlx_pixel_put(ray, vertwallhitx, vertwallhity, 0x0fff0444);
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
		// ray_cast(ray, columnid, ra_angle);
		dda_algorithm(ray, color);
		ra_angle += ray->fov_angle / ray->num_rays;
		i++;
		columnid++;
	}
}
