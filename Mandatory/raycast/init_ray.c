/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:24:28 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/22 20:55:31 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_first_angle(t_ray *ray)
{
	if (ray->cub->type == 'N')
		ray->ra = 3 * M_PI_2;
	if (ray->cub->type == 'S')
		ray->ra = M_PI_2;
	if (ray->cub->type == 'W')
		ray->ra = M_PI;
	if (ray->cub->type == 'E')
		ray->ra = 0;
}

void	get_first_pos(t_ray *ray)
{
	int	i;
	int	j;

	i = 0;
	while (ray->cub->body[i])
	{
		j = 0;
		while (ray->cub->body[i][j])
		{
			if (ray->cub->body[i][j] == ray->cub->type)
			{
				ray->posx = j * 12;
				ray->posy = i * 12;
			}
			j++;
		}
		i++;
	}
}

void	init_ray(t_ray *ray)
{
	ray->minix = 0;
	ray->miniy = 0;
	ray->move.x = 0;
	ray->move.y = 0;
	ray->xinter = 0;
	ray->yinter = 0;
	ray->angle = M_PI / 180;
	ray->fov_angle = 60 * ray->angle;
	ray->num_rays = ray->fov_angle / WALL_STRIP;
	get_first_pos(ray);
	get_first_angle(ray);
}
