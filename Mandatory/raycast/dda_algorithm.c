/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:28:31 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/21 21:33:30 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	dda_algorithm(t_ray *ray, int color)
// {
// 	int		k;
// 	int		dx;
// 	int		dy;
// 	int		steps;
// 	double	xinc;
// 	double	yinc;
// 	double	x;
// 	double	y;

// 	dx = ray->dirx - ray->posx;
// 	dy = ray->diry - ray->posy;
// 	if (abs(dx) > abs(dy))
// 		steps = abs(dx);
// 	else
// 		steps = abs(dy);
// 	xinc = dx / (double)steps;
// 	yinc = dy / (double)steps;
// 	y = ray->posy;
// 	x = ray->posx;
// 	k = -1;
// 	while (++k <= steps)
// 	{
// 		my_mlx_pixel_put(ray, round(x), round(y), color);
// 		y += yinc;
// 		x += xinc;
// 	}
// }

// void	ray_cast(t_ray *ray, int columnid)
// {
// 	(void)columnid;
// 	ray->yinter = floor(ray->posy / 30) * 30;
// 	ray->xinter = ray->posx + (ray->yinter - ray->posy) / tan(ray->ra);
// }

// void	field_vue(t_ray *ray, unsigned int color)
// {
// 	double	ra_angle;
// 	int		columnid;
// 	int		i;

// 	columnid = 0;
// 	i = 0;
// 	ra_angle = ray->ra - (FOV_ANGLE / 2);
// 	while (i < num_rays)
// 	{
// 		ray->dirx = ray->posx + cos(ra_angle) * 20;
// 		ray->diry = ray->posy + sin(ra_angle) * 20;
// 		ray_cast(ray, columnid);
// 		dda_algorithm(ray, color);
// 		ra_angle += (FOV_ANGLE / num_rays);
// 		i++;
// 		columnid++;
// 	}
// }
