/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_vue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:06:54 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/19 13:23:13 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_player_angle(t_ray *ray)
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

void	cam_left(t_ray *ray)
{
	ray->ra -= 0.05;
	if (ray->ra <= 0)
		ray->ra += 2 * M_PI;
}

void	cam_right(t_ray *ray)
{
	ray->ra += 0.05;
	if (ray->ra >= 2 * M_PI)
		ray->ra -= 2 * M_PI;
}
