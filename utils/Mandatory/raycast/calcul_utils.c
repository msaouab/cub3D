/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:54:07 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/04 15:54:41 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	distancebetweenpoints(double x1, double y1, double x2, double y2)
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
	return (ray->ra_angle);
}
