/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:44:28 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/05 20:12:57 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	raycast(t_ray *ray)
{
	init_ray(ray);
	ray->mlx = mlx_init();
	xpmfile(ray);
	ray->win = mlx_new_window(ray->mlx, R_WIDTH, R_HEIGHT, "CUB3D Bonus");
	sfx_sound(ray);
	put_minimap(ray);
	put_rays(ray);
	my_mlx_button(ray);
	mlx_loop(ray->mlx);
}
