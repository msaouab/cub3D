/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calcul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:28:31 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/05 20:07:05 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_line(t_ray *ray, int color, double x1, double y1)
{
	int	steps;
	int	k;

	ray->line.dx = x1 - ray->posx;
	ray->line.dy = y1 - ray->posy;
	if (abs(ray->line.dx) > abs(ray->line.dy))
		steps = abs(ray->line.dx);
	else
		steps = abs(ray->line.dy);
	ray->line.xinc = ray->line.dx / (double)steps;
	ray->line.yinc = ray->line.dy / (double)steps;
	ray->line.y = ray->cminiy;
	ray->line.x = ray->cminix;
	k = 0;
	while (k <= steps && ray->line.y >= 0 && ray->line.y < R_HEIGHT / 5 \
	&& ray->line.x >= 0 && ray->line.x < R_WIDTH / 5)
	{
		my_mlx_pixel_put(ray, round(ray->line.x), round(ray->line.y), color);
		ray->line.y += ray->line.yinc;
		ray->line.x += ray->line.xinc;
		k++;
	}
}

void	calcul_dist_with_hitwalls(t_ray *ray, double horzdist, double vertdist)
{
	if (horzdist < vertdist)
		ray->wallhitx = ray->horzwallhitx;
	else
		ray->wallhitx = ray->vertwallhitx;
	if (horzdist < vertdist)
		ray->wallhity = ray->horzwallhity;
	else
		ray->wallhity = ray->vertwallhity;
	if (horzdist < vertdist)
		ray->cast.disctance = horzdist;
	else
		ray->cast.disctance = vertdist;
	ray->cast.washitvert = (vertdist < horzdist);
}

void	calcul_distance(t_ray *ray, int horzwall, int vertwall)
{
	double	horzhitdist;
	double	verthitdist;

	horzhitdist = MAX_VALUE;
	if (horzwall)
		horzhitdist = distancebetweenpoints(ray->posx, ray->posy, \
		ray->horzwallhitx, ray->horzwallhity);
	verthitdist = MAX_VALUE;
	if (vertwall)
		verthitdist = distancebetweenpoints(ray->posx, ray->posy, \
		ray->vertwallhitx, ray->vertwallhity);
	if (verthitdist < horzhitdist)
	{
		ray->wallhitx = ray->vertwallhitx;
		ray->wallhity = ray->vertwallhity;
	}
	else
	{
		ray->wallhitx = ray->horzwallhitx;
		ray->wallhity = ray->horzwallhity;
	}
	calcul_dist_with_hitwalls(ray, horzhitdist, verthitdist);
}

void	castray(t_ray *ray)
{
	int	foundhorzwallhit;
	int	foundvertwallhit;

	foundhorzwallhit = FALSE;
	foundvertwallhit = FALSE;
	facing_ray(ray);
	cast_horizantalrays(ray);
	foundhorzwallhit = walls_horzhit(ray, foundhorzwallhit);
	cast_verticalrays(ray);
	foundvertwallhit = walls_verthit(ray, foundvertwallhit);
	calcul_distance(ray, foundhorzwallhit, foundvertwallhit);
}

void	put_rays(t_ray *ray)
{
	int		i;

	i = 0;
	ray->ra_angle = ray->ra - (ray->fov_angle / 2);
	while (i < ray->num_rays)
	{
		castray(ray);
		ray->ray_id = i;
		projection_walls3d(ray);
		ray->ra_angle += ray->fov_angle / ray->num_rays;
		normalize(ray);
		draw_line(ray, 0x0fff000, ray->wallhitx, ray->wallhity);
		i++;
	}
}
