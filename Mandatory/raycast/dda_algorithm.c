/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:28:31 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/01 21:10:49 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_line(t_ray *ray, int color, double x1, double y1)
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
	k = -1;
	while (++k <= steps && y >= 0 && y < R_HEIGHT / 5 && x >= 0 && x < R_WIDTH / 5)
	{
		my_mlx_pixel_put(ray, round(x), round(y), color);
		y += yinc;
		x += xinc;
	}
}

double	distancebetweenpoints(double x1, double y1, double x2, double y2)
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
	double	nexthorzx = xinter;
	double	nexthorzy = yinter;
	ray->horzwallhitx = nexthorzx;
	ray->horzwallhity = nexthorzy;
	if (ray->cast.rayfaceup)
		nexthorzy -= 0.000001;
	while ((int)(nexthorzy / TILE_SIZE) >= 0
		&& (int)(nexthorzy / TILE_SIZE) < ray->cub->ac
		&& (int)(nexthorzx / TILE_SIZE) >= 0
		&& (int)(nexthorzx / TILE_SIZE) < (int)ft_strlen(ray->cub->body[(int)(nexthorzy / TILE_SIZE)]) * TILE_SIZE)
	{
		if (find_walls(ray, nexthorzx, nexthorzy) == 0)
		{
			foundhorzwallhit = TRUE;
			ray->horzwallhitx = nexthorzx;
			ray->horzwallhity = nexthorzy;
			break ;
		}
		else
		{
			nexthorzx += xstep;
			nexthorzy += ystep;
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
	double	nextvertx = xinter;
	double	nextverty = yinter;
	ray->vertwallhitx = nextvertx;
	ray->vertwallhity = nextverty;
	if (ray->cast.rayfaceleft)
		nextvertx -= 0.000001;
	while ((int)(nextverty / TILE_SIZE) >= 0
		&& (int)(nextverty / TILE_SIZE) < ray->cub->ac
		&& (int)(nextvertx / TILE_SIZE) >= 0
		&& (int)(nextvertx / TILE_SIZE) < (int)ft_strlen(ray->cub->body[(int)(nextverty / TILE_SIZE)]) * TILE_SIZE)
	{
		if (find_walls(ray, nextvertx, nextverty) == 0)
		{
			foundvertwallhit = TRUE;
			ray->vertwallhitx = nextvertx;
			ray->vertwallhity = nextverty;
			break ;
		}
		else
		{
			nextvertx += xstep;
			nextverty += ystep;
		}
	}
	double	horzhitdist = (foundhorzwallhit) \
		? distancebetweenpoints(ray->posx, ray->posy, ray->horzwallhitx, ray->horzwallhity)
		: MAX_VALUE;
	double	verthitdist = (foundvertwallhit) \
		? distancebetweenpoints(ray->posx, ray->posy, ray->vertwallhitx, ray->vertwallhity)
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
	wallhitx = (horzhitdist < verthitdist) ? ray->horzwallhitx : ray->vertwallhitx;
	wallhity = (horzhitdist < verthitdist) ? ray->horzwallhity : ray->vertwallhity;
	ray->cast.disctance = (horzhitdist < verthitdist) ? horzhitdist : verthitdist;
	ray->cast.washitvert = (verthitdist < horzhitdist);
	draw_line(ray, 0x0fff000, wallhitx, wallhity);
}

void	put_rays(t_ray *ray, unsigned int color)
{
	int		i;

	(void)color;
	i = 0;
	ray->ra_angle = ray->ra - (ray->fov_angle / 2);
	while (i < ray->num_rays)
	{
		castray(ray);
		ray->ray_id = i;
		put_3drender(ray);
		ray->ra_angle += ray->fov_angle / ray->num_rays;
		normalize(ray);
		i++;
	}
	mlx_clear_window(ray->mlx, ray->win);
}
