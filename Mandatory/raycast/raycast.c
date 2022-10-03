/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:44:28 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/03 16:32:27 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	raycast(t_ray *ray)
{
	init_ray(ray);
	ray->mlx = mlx_init();
	xpmfile(ray);
	ray->win = mlx_new_window(ray->mlx, R_WIDTH, R_HEIGHT, "CUB3D");
	put_minimap(ray);
	my_mlx_button(ray);
	sfx_sound(ray);
	mlx_loop(ray->mlx);
}
