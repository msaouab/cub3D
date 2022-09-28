/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:28:31 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/28 11:33:38 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	dda_algorithm(t_ray *ray, int color, double x1, double y1)
{
	int		k;
	int		dx;
	int		dy;
	int		steps;
	double	xinc;
	double	yinc;
	double	x;
	double	y;

	dx = x1 - ray->posx;
	dy = y1 - ray->posy;
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

double	distanceBetweenPoints(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	facing_ray(t_ray *ray, double ra_angle)
{
	ray->cast.rayfacedown = false;
	ray->cast.rayfaceup = false;
	ray->cast.rayfaceleft = false;
	ray->cast.rayfaceright = false;

	if (ra_angle > 0 && ra_angle < M_PI)
		ray->cast.rayfacedown = true;
	ray->cast.rayfaceup = !ray->cast.rayfacedown;
	if (ra_angle < 0.5 * M_PI || ra_angle > 1.5 * M_PI)
		ray->cast.rayfaceright = true;
	ray->cast.rayfaceleft = !ray->cast.rayfaceright;
	// ray->cast.rayfacedown = ra_angle > 0 && ra_angle < M_PI;
	// ray->cast.rayfaceup = !ray->cast.rayfacedown;
	// ray->cast.rayfaceright = ra_angle < 0.5 * M_PI || ra_angle > 1.5 * M_PI;
	// ray->cast.rayfaceleft = !ray->cast.rayfaceright;
}

void	castray(t_ray *ray, double ra_angle)
{
	double	xinter;
	double	yinter;
	double	xstep;
	double	ystep;
	int		foundhorzwallhit = 0;
	int		foundvertwallhit = 0;

	facing_ray(ray, ra_angle);
	yinter = floor(ray->posy / TILE_SIZE) * TILE_SIZE;
	if (ray->cast.rayfacedown)
		yinter += TILE_SIZE;
	xinter = ray->posx + (yinter - ray->posy) / tan(ra_angle);
	ystep = TILE_SIZE;
	if (ray->cast.rayfaceup)
		ystep *= -1;
	xstep = TILE_SIZE / tan(ra_angle);
	if (ray->cast.rayfaceleft && xstep > 0)
		xstep *= -1;
	if (ray->cast.rayfaceright && xstep < 0)
		xstep *= -1;
	double	nexthorzX = xinter;
	double	nexthorzY = yinter;
	if (ray->cast.rayfaceup)
		nexthorzY--;
	while (nexthorzX >= 0 && nexthorzX <= R_WIDTH / 5 && nexthorzY >= 0 && nexthorzY <= R_HEIGHT / 5)
	{
		if (find_walls(ray, nexthorzX + 6, nexthorzY + 6) == 0)
		{
			foundhorzwallhit = 1;
			ray->horzwallhitx = nexthorzX;
			ray->horzwallhity = nexthorzY;
			break;
		}
		else 
		{
			nexthorzX += xstep;
			nexthorzY += ystep;
		}
	}

	xinter = floor(ray->posx / TILE_SIZE) * TILE_SIZE;
	if (ray->cast.rayfaceright)
		xinter += TILE_SIZE;
	yinter = ray->posy + (xinter - ray->posx) * tan(ra_angle);
	xstep = TILE_SIZE;
	if (ray->cast.rayfaceleft)
		xstep *= -1;
	ystep = TILE_SIZE * tan(ra_angle);
	if (ray->cast.rayfaceup && ystep > 0)
		ystep *= -1;
	if (ray->cast.rayfacedown && ystep < 0)
		ystep *= -1;
	double	nextvertX = xinter;
	double	nextvertY = yinter;
	if (ray->cast.rayfaceleft)
		nextvertX--;
	while (nextvertX >= 0 && nextvertX <= R_WIDTH / 5 && nextvertY >= 0 && nextvertY <= R_HEIGHT / 5)
	{
		if (find_walls(ray, nextvertX + 6, nextvertY + 6) == 0)
		{
			foundvertwallhit = 1;
			ray->vertwallhitx = nextvertX;
			ray->vertwallhity = nextvertY;
			break;
		}
		else 
		{
			nextvertX += xstep;
			nextvertY += ystep;
		}
	}
	double	horzhitdist = (foundhorzwallhit == 1) \
		? distanceBetweenPoints(ray->posx, ray->posy, ray->horzwallhitx, ray->horzwallhity)
		: MAX_VALUE;
	double	verthitdist = (foundvertwallhit == 1) \
		? distanceBetweenPoints(ray->posx, ray->posy, ray->vertwallhitx, ray->vertwallhity)
		: MAX_VALUE;

	double	wallhitx = (horzhitdist < verthitdist) ? ray->horzwallhitx : ray->vertwallhitx;
	double	wallhity = (horzhitdist < verthitdist) ? ray->horzwallhity : ray->vertwallhity;
	// double	disctance = (horzhitdist < verthitdist) ? horzhitdist : verthitdist;
	// double	washitvert = (verthitdist < horzhitdist);;
	dda_algorithm(ray, 0x0fff000, wallhitx, wallhity);
}

		// ray->dirx = ray->posx + cos(ra_angle) * 30;
		// ray->diry = ray->posy + sin(ra_angle) * 30;

void	put_rays(t_ray *ray, unsigned int color)
{
	double	ra_angle;
	int		i;

	(void)color;
	i = 0;
	ra_angle = ray->ra - (ray->fov_angle / 2);
	printf("%f\t||%f\n", ra_angle, ray->ra);
	while (i < ray->num_rays)
	{
		castray(ray, ra_angle);
		// dda_algorithm(ray, 0x0fff000);
		ra_angle += ray->fov_angle / ray->num_rays;
		i++;
	}
}
