/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:02:37 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/21 21:33:58 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_left(t_ray *ray)
{
	double	x;
	double	y;

	x = ray->posx + sin(ray->ra) * 2;
	y = ray->posy - cos(ray->ra) * 2;
		ray->posx = x;
		ray->posy = y;
}

void	move_right(t_ray *ray)
{
	double	x;
	double	y;

	x = ray->posx - sin(ray->ra) * 2;
	y = ray->posy + cos(ray->ra) * 2;
		ray->posx = x;
		ray->posy = y;
}

void	move_down(t_ray *ray)
{
	double	x;
	double	y;

	x = ray->posx - cos(ray->ra) * 2;
	y = ray->posy - sin(ray->ra) * 2;
		ray->posx = x;
		ray->posy = y;
}

void	move_up(t_ray *ray)
{
	double	x;
	double	y;

	x = ray->posx + cos(ray->ra) * 2;
	y = ray->posy + sin(ray->ra) * 2;
		ray->posx = x;
		ray->posy = y;
}
