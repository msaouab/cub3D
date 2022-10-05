/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_vert_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:59:22 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/05 20:06:44 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	walls_horzhit(t_ray *ray, int horzwallhit)
{
	while ((int)(ray->hit.nexthorzy / TILE_SIZE) >= 0 \
		&& (int)(ray->hit.nexthorzy / TILE_SIZE) < ray->cub->ac \
		&& (int)(ray->hit.nexthorzx / TILE_SIZE) >= 0 \
		&& (int)(ray->hit.nexthorzx / TILE_SIZE) < (int)ft_strlen \
		(ray->cub->body[(int)(ray->hit.nexthorzy / TILE_SIZE)]) * TILE_SIZE)
	{
		if (find_walls(ray, ray->hit.nexthorzx, ray->hit.nexthorzy) == 0)
		{
			horzwallhit = TRUE;
			ray->horzwallhitx = ray->hit.nexthorzx;
			ray->horzwallhity = ray->hit.nexthorzy;
			break ;
		}
		else
		{
			ray->hit.nexthorzx += ray->hit.xstep;
			ray->hit.nexthorzy += ray->hit.ystep;
		}
	}
	return (horzwallhit);
}

int	walls_verthit(t_ray *ray, int vertwallhit)
{
	while ((int)(ray->hit.nextverty / TILE_SIZE) >= 0 \
		&& (int)(ray->hit.nextverty / TILE_SIZE) < ray->cub->ac \
		&& (int)(ray->hit.nextvertx / TILE_SIZE) >= 0 \
		&& (int)(ray->hit.nextvertx / TILE_SIZE) < (int)ft_strlen \
		(ray->cub->body[(int)(ray->hit.nextverty / TILE_SIZE)]) * TILE_SIZE)
	{
		if (find_walls(ray, ray->hit.nextvertx, ray->hit.nextverty) == 0)
		{
			vertwallhit = TRUE;
			ray->vertwallhitx = ray->hit.nextvertx;
			ray->vertwallhity = ray->hit.nextverty;
			break ;
		}
		else
		{
			ray->hit.nextvertx += ray->hit.xstep;
			ray->hit.nextverty += ray->hit.ystep;
		}
	}
	return (vertwallhit);
}

void	cast_horizantalrays(t_ray *ray)
{
	double	xinter;
	double	yinter;

	yinter = floor(ray->posy / TILE_SIZE) * TILE_SIZE;
	if (ray->cast.rayfacedown)
		yinter += TILE_SIZE;
	xinter = ray->posx + (yinter - ray->posy) / tan(ray->ra_angle);
	ray->hit.ystep = TILE_SIZE;
	if (ray->cast.rayfaceup)
		ray->hit.ystep *= -1;
	ray->hit.xstep = TILE_SIZE / tan(ray->ra_angle);
	if (ray->cast.rayfaceleft && ray->hit.xstep > 0)
		ray->hit.xstep *= -1;
	if (ray->cast.rayfaceright && ray->hit.xstep < 0)
		ray->hit.xstep *= -1;
	ray->hit.nexthorzx = xinter;
	ray->hit.nexthorzy = yinter;
	ray->horzwallhitx = ray->hit.nexthorzx;
	ray->horzwallhity = ray->hit.nexthorzy;
	if (ray->cast.rayfaceup)
		ray->hit.nexthorzy -= 0.000001;
}

void	cast_verticalrays(t_ray *ray)
{
	double	xinter;
	double	yinter;

	xinter = floor(ray->posx / TILE_SIZE) * TILE_SIZE;
	if (ray->cast.rayfaceright)
		xinter += TILE_SIZE;
	yinter = ray->posy + (xinter - ray->posx) * tan(ray->ra_angle);
	ray->hit.xstep = TILE_SIZE;
	if (ray->cast.rayfaceleft)
		ray->hit.xstep *= -1;
	ray->hit.ystep = TILE_SIZE * tan(ray->ra_angle);
	if (ray->cast.rayfaceup && ray->hit.ystep > 0)
		ray->hit.ystep *= -1;
	if (ray->cast.rayfacedown && ray->hit.ystep < 0)
		ray->hit.ystep *= -1;
	ray->hit.nextvertx = xinter;
	ray->hit.nextverty = yinter;
	ray->vertwallhitx = ray->hit.nextvertx;
	ray->vertwallhity = ray->hit.nextverty;
	if (ray->cast.rayfaceleft)
		ray->hit.nextvertx -= 0.000001;
}
