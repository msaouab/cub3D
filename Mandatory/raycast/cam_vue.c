/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_vue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:06:54 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/04 14:17:05 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_mouse(int x, int y, t_ray *ray)
{
	static int	old_x;

	if (y < 0 || y > R_HEIGHT)
		return (0);
	if (x <= R_WIDTH && x >= 0 && x < old_x)
		ray->ra -= 0.05;
	if (x >= 0 && x <= R_WIDTH && x > old_x)
		ray->ra += 0.05;
	old_x = x;
	if (!(x >= 0 && x <= R_WIDTH))
		old_x = R_WIDTH / 2;
	return (0);
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
