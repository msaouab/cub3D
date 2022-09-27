/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:28:31 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/27 20:29:41 by msaouab          ###   ########.fr       */
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

	dx = ray->foundwallhitx - ray->posx;
	dy = ray->foundwallhity - ray->posy;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xinc = dx / (double)steps;
	yinc = dy / (double)steps;
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

void	castray(t_ray *ray, double ra_angle)
{
	double	xinter;
	double	yinter;
	double	xstep;
	double	ystep;
	// double	foundwallhitX = 0;
	// double	foundwallhitY = 0;
	// double	horswallcolor = 0;
	int		rayfacedown = 0;
	int		rayfaceup = 0;
	int		rayfaceright = 0;
	int		rayfaceleft = 0;
	// double	foundvertwallhit = 0;
	double	foundhorzwallhit = 0;

	rayfacedown = ra_angle > 0 && ra_angle < M_PI;
	rayfaceup = !rayfacedown;

	rayfaceright = ra_angle < 0.5 * M_PI || ra_angle > 1.5 * M_PI;
	rayfaceleft = !rayfaceright;

	yinter = floor(ray->posy / TILE_SIZE) * TILE_SIZE;
	if (rayfacedown)
		yinter += TILE_SIZE;
	xinter = ray->posx + (yinter - ray->posy) / tan(ra_angle);
	ystep = TILE_SIZE;
	if (rayfaceup)
		ystep *= -1;
	xstep = TILE_SIZE / tan(ra_angle);
	if (rayfaceleft && xstep > 0)
		xstep *= -1;
	if (rayfaceright && xstep < 0)
		xstep *= -1;
	double	nexthorzX = xinter;
	double	nexthorzY = yinter;
	if (rayfaceup)
		nexthorzY--;
	while (nexthorzX >= 0 && nexthorzX <= R_WIDTH / 5 && nexthorzY >= 0 && nexthorzY <= R_HEIGHT / 5)
	{
		if (find_walls(ray, nexthorzX, nexthorzY) == 0)
		{
			foundhorzwallhit = 1;
			ray->foundwallhitx = nexthorzX;
			ray->foundwallhity = nexthorzY;
			// dda_algorithm(ray, 0x0fff000);
			break;
		}
		else 
		{
			nexthorzX += xstep;
			nexthorzY += ystep;
		}
	}


	// xinter = floor(ray->posx / TILE_SIZE) * TILE_SIZE;
	// if (rayfaceright)
	// 	xinter += TILE_SIZE;
	// yinter = ray->posy + (xinter - ray->posx) * tan(ra_angle);
	// xstep = TILE_SIZE;
	// if (rayfaceleft)
	// 	xstep *= -1;
	// ystep = TILE_SIZE * tan(ra_angle);
	// if (rayfaceup && ystep > 0)
	// 	ystep *= -1;
	// if (rayfacedown && ystep < 0)
	// 	ystep *= -1;
	// double	nextvertX = xinter;
	// double	nextvertY = yinter;
	// if (rayfaceleft)
	// 	nextvertY--;
	// while (nextvertX >= 0 && nextvertX <= R_WIDTH / 5 && nextvertY >= 0 && nextvertY <= R_HEIGHT / 5)
	// {
	// 	if (find_walls(ray, nextvertX, nextvertY) == 0)
	// 	{
	// 		foundvertwallhit = 1;
	// 		ray->foundwallhitX = nextvertX;
	// 		ray->foundwallhitY = nextvertY;
	// 		// dda_algorithm(ray, 0x0fff000);
	// 		break;
	// 	}
	// 	else 
	// 	{
	// 		nextvertX += xstep;
	// 		nextvertY += ystep;
	// 	}
	// }
	// double	horzhitdist = (foundhorzwallhit == 1) ? \
	// sqrt((ray->posx - ray->posy) * (ray->posx - ray->posy) + (y2 - y1) * (y2 - y1))
}

void	put_rays(t_ray *ray, unsigned int color)
{
	(void)color;
	double	ra_angle;
	int		i;

	i = 0;
	ra_angle = ray->ra;// - (ray->fov_angle / 2);
	// while (i < ray->num_rays)
	// {
		// ray->dirx = ray->posx + cos(ra_angle) * 30;
		// ray->diry = ray->posy + sin(ra_angle) * 30;
		castray(ray, ra_angle);
		dda_algorithm(ray, color);
		// ra_angle += ray->fov_angle / ray->num_rays;
		// i++;
	// }
}
