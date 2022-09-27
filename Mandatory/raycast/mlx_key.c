/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:02:37 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/27 20:15:14 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	find_walls(t_ray *ray, int x, int y)
{
	int	i;
	int	j;

	i = floor((y + 6) / TILE_SIZE);
	j = floor((x + 6) / TILE_SIZE);
	if (ray->cub->body[i][j] == '1')
		return (0);
	return (1);
}

void	move_left(t_ray *ray)
{
	double	x;
	double	y;

	x = ray->posx + sin(ray->ra) * 1;
	y = ray->posy - cos(ray->ra) * 1;
	if (find_walls(ray, x, y) == 1)
	{
		ray->posx = x;
		ray->posy = y;
	}
}

void	move_right(t_ray *ray)
{
	double	x;
	double	y;

	x = ray->posx - sin(ray->ra) * 1;
	y = ray->posy + cos(ray->ra) * 1;
	if (find_walls(ray, x, y) == 1)
	{
		ray->posx = x;
		ray->posy = y;
	}
}

void	move_down(t_ray *ray)
{
	double	x;
	double	y;

	x = ray->posx - cos(ray->ra) * 1;
	y = ray->posy - sin(ray->ra) * 1;
	if (find_walls(ray, x, y) == 1)
	{
		ray->posx = x;
		ray->posy = y;
	}
}

void	move_up(t_ray *ray)
{
	double	x;
	double	y;

	x = ray->posx + cos(ray->ra) * 1;
	y = ray->posy + sin(ray->ra) * 1;
	if (find_walls(ray, x, y) == 1)
	{
		ray->posx = x;
		ray->posy = y;
	}
}
