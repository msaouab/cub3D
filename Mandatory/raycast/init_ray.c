/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:24:28 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/06 12:19:15 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_ray *ray, int x, int y, unsigned int color)
{
	char	*dst;

	dst = ray->addr + (y * ray->line_length + x * (ray->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	xpmfile(t_ray *ray)
{
	ray->img = mlx_new_image(ray->mlx, R_WIDTH, R_HEIGHT);
	if (!ray->img)
		ft_error("mlx_xpm_file_to_image problem", 1);
	ray->addr = mlx_get_data_addr(ray->img, &ray->bits_per_pixel, \
	&ray->line_length, &ray->endian);
	if (!ray->addr)
		ft_error("mlx_get_data_addr problem", 1);
	init_texture(ray);
}

void	get_first_angle(t_ray *ray)
{
	if (ray->cub->type == 'N')
		ray->ra = 3 * M_PI_2;
	if (ray->cub->type == 'S')
		ray->ra = M_PI_2;
	if (ray->cub->type == 'W')
		ray->ra = M_PI;
	if (ray->cub->type == 'E')
		ray->ra = 2 * M_PI;
}

void	get_first_pos(t_ray *ray)
{
	int	i;
	int	j;

	i = 0;
	while (ray->cub->body[i])
	{
		j = 0;
		while (ray->cub->body[i][j])
		{
			if (ray->cub->body[i][j] == ray->cub->type)
			{
				ray->posx = j * TILE_SIZE + 6;
				ray->posy = i * TILE_SIZE + 6;
			}
			j++;
		}
		i++;
	}
}

void	init_ray(t_ray *ray)
{
	ray->minix = 0;
	ray->miniy = 0;
	ray->move.x = 0;
	ray->move.y = 0;
	ray->w_minimap = R_WIDTH / 5;
	ray->h_minimap = R_HEIGHT / 5;
	ray->xinter = 0;
	ray->yinter = 0;
	ray->rad = M_PI / 180;
	ray->fov_angle = 60 * (ray->rad);
	ray->num_rays = R_WIDTH / WALL_STRIP;
	ray->cminix = ((R_WIDTH / 5) / 2);
	ray->cminiy = ((R_HEIGHT / 5) / 2);
	ray->wallhitx = 0;
	ray->wallhity = 0;
	ray->distance = 0;
	ray->horzwallhitx = 0;
	ray->horzwallhity = 0;
	ray->vertwallhitx = 0;
	ray->vertwallhity = 0;
	ray->ray_id = 0;
	get_first_pos(ray);
	get_first_angle(ray);
}
