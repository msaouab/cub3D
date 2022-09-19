/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:44:28 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/19 13:39:08 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_ray(t_ray *ray)
{
	ray->ra = 0;
	ray->posx = 0;
	ray->posy = 0;
}

void	raycast(t_ray *ray)
{
	ft_init_ray(ray);
	ray->mlx = mlx_init();
	// min_map(ray);
	ray->win = mlx_new_window(ray->mlx, R_WIDTH, R_HEIGHT, "Cub3D");
	my_mlx_button(ray);
	mlx_loop(ray->mlx);
}
