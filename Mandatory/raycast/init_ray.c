/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:24:28 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/25 16:38:43 by msaouab          ###   ########.fr       */
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
	ray->w_minimap = R_WIDTH / 5;
	ray->h_minimap = R_HEIGHT / 5;
	ray->xinter = 0;
	ray->yinter = 0;
	ray->rad = M_PI / 180;
	ray->fov_angle = 60 * (ray->rad);
	ray->num_rays = R_WIDTH / WALL_STRIP;
	ray->cminix = ((R_WIDTH / 5) / 2) + 5;
	ray->cminiy = ((R_HEIGHT / 5) / 2) + 5;
	get_first_pos(ray);
	get_first_angle(ray);
}
