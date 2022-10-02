/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqessam <iqessam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:58:20 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/02 12:52:18 by iqessam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_cross(void)
{
	exit(0);
	return (0);
}

int	ft_release(int keycode, t_ray *ray)
{
	if (keycode == 0)
		ray->move.x = 0;
	else if (keycode == 1)
		ray->move.y = 0;
	else if (keycode == 2)
		ray->move.x = 0;
	else if (keycode == 13)
		ray->move.y = 0;
	else if (keycode == 53)
		ft_cross();
	else if (keycode == 123)
		ray->move.cam_vue = 0;
	else if (keycode == 124)
		ray->move.cam_vue = 0;
	return (0);
}

int	ft_event(int keycode, t_ray *ray)
{
	if (keycode == 0)
		ray->move.x = 1;
	else if (keycode == 1)
		ray->move.y = -1;
	else if (keycode == 2)
		ray->move.x = -1;
	else if (keycode == 13)
		ray->move.y = 1;
	else if (keycode == 53)
		ft_cross();
	else if (keycode == 123)
		ray->move.cam_vue = 1;
	else if (keycode == 124)
		ray->move.cam_vue = -1;
	return (0);
}

int	ft_frame(t_ray *ray)
{
	if (ray->move.x == 1)
		move_left(ray);
	if (ray->move.y == -1)
		move_down(ray);
	if (ray->move.x == -1)
		move_right(ray);
	if (ray->move.y == 1)
		move_up(ray);
	if (ray->move.cam_vue == 1)
		cam_left(ray);
	if (ray->move.cam_vue == -1)
		cam_right(ray);
	mlx_clear_window(ray->mlx, ray->win);
	put_minimap(ray);
	put_rays(ray, 0xfff000);
	put_minimap(ray);
	mlx_put_image_to_window(ray->mlx, ray->win, ray->img, 0, 0);
	return (0);
}

void	my_mlx_button(t_ray *ray)
{
	mlx_hook(ray->win, 17, (1L << 17), ft_cross, ray);
	mlx_hook(ray->win, 3, 0, ft_release, ray);
	mlx_hook(ray->win, 2, 0, ft_event, ray);
	mlx_loop_hook(ray->mlx, ft_frame, ray);
}
