/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_vue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:06:54 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/05 20:13:56 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
