/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqessam <iqessam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:28:31 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/01 13:39:43 by iqessam          ###   ########.fr       */
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

	dx = x1 - ray->posx; // adding 6 may change the ray direction in extreme cases {old x1 + 6}
	dy = y1 - ray->posy; // adding 6 may change the ray direction in extreme cases {old y1 + 6}
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xinc = dx / (double)steps;
	yinc = dy / (double)steps;
	y = ray->cminiy;
	x = ray->cminix;
	k = 0;
	while (k <= steps && y >= 0 && y < R_HEIGHT / 5 && x >= 0 && x < R_WIDTH / 5)
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
	// if (ray->ra_angle >= 2 * M_PI)
	// 	ray->ra_angle -= (2 * M_PI);
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

	// normalize(ray);
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
	ray->horzwallhitx = nexthorzX;
	ray->horzwallhity = nexthorzY;
	if (ray->cast.rayfaceup)
		nexthorzY -= 0.000001;
	while ((int)(nexthorzY / TILE_SIZE) >= 0
		&& (int)(nexthorzY / TILE_SIZE) < ray->cub->ac
		&& (int)(nexthorzX / TILE_SIZE) >= 0
		&& (int)(nexthorzX / TILE_SIZE) < (int)ft_strlen(ray->cub->body[(int)(nexthorzY / TILE_SIZE)]) * TILE_SIZE)//modified : R_WIDTH / 5 AND R_HEIGHT / 5 to explain later 
	{
		if (find_walls(ray, nexthorzX, nexthorzY) == 0)
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
	ray->vertwallhitx = nextvertX;
	ray->vertwallhity = nextvertY;
	if (ray->cast.rayfaceleft)
		nextvertX -= 0.000001;
	while ((int)(nextvertY / TILE_SIZE) >= 0
		&& (int)(nextvertY / TILE_SIZE) < ray->cub->ac
		&& (int)(nextvertX / TILE_SIZE) >= 0
		&& (int)(nextvertX / TILE_SIZE) < (int)ft_strlen(ray->cub->body[(int)(nextvertY / TILE_SIZE)]) * TILE_SIZE)
	{
		if (find_walls(ray, nextvertX, nextvertY) == 0)
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
	// printf("%f\n", (ray->ra_angle / ray->rad));
	// ray->ra_angle = ray->ra;
	// normalize(ray);
	while (i < ray->num_rays)
	{
		// ray->dirx = ray->posx + cos(ray->ra_angle) * TILE_SIZE;
		// ray->diry = ray->posy + sin(ray->ra_angle) * TILE_SIZE;
		castray(ray);
		ray->ray_id = i;
		put_3drender(ray);
		ray->ra_angle += ray->fov_angle / ray->num_rays;
		normalize(ray);
		i++;
	}
	mlx_clear_window(ray->mlx, ray->win);
}
