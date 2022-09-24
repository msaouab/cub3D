/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:28:31 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/24 21:49:36 by msaouab          ###   ########.fr       */
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
	y = ((R_HEIGHT / 5) / 2) + 5;
	x = ((R_WIDTH / 5) / 2) + 5;
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

	(void)columnId;
	if (ra_angle > 0 && ra_angle < M_PI)
		rayfacingdown = 1;
	rayfacingup = !rayfacingdown;
	if (ra_angle > M_PI_2 && ra_angle < 3 * M_PI_2)
		rayfacingright = 1;
	rayfacingleft = !rayfacingright;

	ray->yinter = floor(ray->posy / 12) * 12;
	if (rayfacingdown == 1)
		ray->yinter += TILE_SIZE;
	else
		ray->yinter += 0;
	ray->xinter = ray->posx + (ray->yinter - ray->posy) / tan(ra_angle);
	ystep = TILE_SIZE;
	if (rayfacingup == 1)
		ystep *= -1;
	else
		ystep *= 1;
	xstep = TILE_SIZE / tan(ra_angle);
	if (rayfacingleft == 1 && xstep > 0)
		xstep *= -1;
	else
		xstep *= 1;
	if (rayfacingright == 1 && xstep < 0)
		xstep *= -1;
	else
		xstep *= 1;
	next_x = ray->xinter;
	next_y = ray->yinter;
	if (rayfacingup == 1)
		next_y--;
	int wallhit = 0;
	int wallhitx = 0;
	int wallhity = 0;
	while (1)
	{
		if (find_walls(ray, next_x, next_y))
		{
			wallhit = 1;
			wallhitx = next_x;
			wallhity = next_y;
			my_mlx_pixel_put(ray, wallhitx, wallhity, 0x0ff00);
			break ;
		}
		else
		{
			next_x += xstep;
			next_y += ystep;
		}
	}
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
		ray_cast(ray, columnid, ra_angle);
		dda_algorithm(ray, color);
		ra_angle += ray->fov_angle / ray->num_rays;
		i++;
		columnid++;
	}
}
