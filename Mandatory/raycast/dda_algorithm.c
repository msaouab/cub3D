/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:28:31 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/28 20:44:40 by msaouab          ###   ########.fr       */
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

	dx = (x1 + 6)- ray->posx;
	dy = (y1 + 6)- ray->posy;
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

void	facing_ray(t_ray *ray)
{
	ray->cast.rayfacedown = FALSE;
	ray->cast.rayfaceup = FALSE;
	ray->cast.rayfaceleft = FALSE;
	ray->cast.rayfaceright = FALSE;

	if (ray->ra_angle > 0 && ray->ra_angle < M_PI)
		ray->cast.rayfacedown = TRUE;
	ray->cast.rayfaceup = !ray->cast.rayfacedown;
	if (ray->ra_angle < 0.5 * M_PI || ray->ra_angle > 1.5 * M_PI)
		ray->cast.rayfaceright = TRUE;
	ray->cast.rayfaceleft = !ray->cast.rayfaceright;
}

double	normalize(t_ray *ray)
{
	ray->ra_angle = fmod(ray->ra_angle, (2 * M_PI));
	if (ray->ra_angle <= 0)
		ray->ra_angle += (2 * M_PI);
	if (ray->ra_angle >= 2 * M_PI)
		ray->ra_angle -= (2 * M_PI);
	return (ray->ra_angle);
}

void	castray(t_ray *ray)
{
	double	xinter;
	double	yinter;
	double	xstep;
	double	ystep;
	int		foundhorzwallhit = 0;
	int		foundvertwallhit = 0;

	normalize(ray);
	facing_ray(ray);
	yinter = floor(ray->posy / TILE_SIZE) * TILE_SIZE;
	if (ray->cast.rayfacedown)
		yinter += TILE_SIZE;
	xinter = ray->posx + (yinter - ray->posy) / tan(ray->ra_angle);
	ystep = TILE_SIZE;
	if (ray->cast.rayfaceup)
		ystep *= -1;
	xstep = TILE_SIZE / tan(ray->ra_angle);
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
			foundhorzwallhit = TRUE;
			ray->horzwallhitx = nexthorzX;
			ray->horzwallhity = nexthorzY;
			break ;
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
	yinter = ray->posy + (xinter - ray->posx) * tan(ray->ra_angle);
	xstep = TILE_SIZE;
	if (ray->cast.rayfaceleft)
		xstep *= -1;
	ystep = TILE_SIZE * tan(ray->ra_angle);
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
			foundvertwallhit = TRUE;
			ray->vertwallhitx = nextvertX;
			ray->vertwallhity = nextvertY;
			break ;
		}
		else
		{
			nextvertX += xstep;
			nextvertY += ystep;
		}
	}
	double	horzhitdist = (foundhorzwallhit) \
		? distanceBetweenPoints(ray->posx, ray->posy, ray->horzwallhitx, ray->horzwallhity)
		: MAX_VALUE;
	double	verthitdist = (foundvertwallhit) \
		? distanceBetweenPoints(ray->posx, ray->posy, ray->vertwallhitx, ray->vertwallhity)
		: MAX_VALUE;

	double	wallhitx;
	double	wallhity;
	if (verthitdist < horzhitdist)
	{
		wallhitx = ray->vertwallhitx;
		wallhity = ray->vertwallhity;
	}
	else
	{
		wallhitx = ray->horzwallhitx;
		wallhity = ray->horzwallhity;
	}
	// printf("%f\t||%f\n", wallhitx, wallhity);
	wallhitx = (horzhitdist < verthitdist) ? ray->horzwallhitx : ray->vertwallhitx;
	wallhity = (horzhitdist < verthitdist) ? ray->horzwallhity : ray->vertwallhity;
	ray->cast.disctance = (horzhitdist < verthitdist) ? horzhitdist : verthitdist;
	ray->cast.washitvert = (verthitdist < horzhitdist);
	dda_algorithm(ray, 0x0fff000, wallhitx, wallhity);
}

void	put_rays(t_ray *ray, unsigned int color)
{
	int		i;

	(void)color;
	i = 0;
	ray->ra_angle = ray->ra - (ray->fov_angle / 2);
	// normalize(ray);
	while (i < ray->num_rays)
	{
		castray(ray);
		// dda_algorithm(ray, 0x0fff000);
		projection_walls3d(ray, i);
		ray->ra_angle += ray->fov_angle / ray->num_rays;
		// normalize(ray);
		i++;
	}
}
