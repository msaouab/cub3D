/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:52:23 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/04 15:31:21 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_celling(t_ray *ray)
{
	int	i;

	i = 0;
	while (i < ray->top_pixel)
	{
		my_mlx_pixel_put(ray, ray->ray_id, i, ray->cub->celling);
		i++;
	}
}

void	put_floor(t_ray *ray)
{
	int	i;

	i = ray->bottom_pixel;
	while (i < R_HEIGHT)
	{
		my_mlx_pixel_put(ray, ray->ray_id, i, ray->cub->floor);
		i++;
	}
}

void	put_texture_walls(t_ray *ray, int i)
{
	int		*tmp_adress;
	int		color;
	int		j;

	j = 0;
	ray->textureoffsetx = ray->wallhitx / TILE_SIZE;
	if (ray->cast.washitvert)
		ray->textureoffsetx = ray->wallhity / TILE_SIZE;
	ray->textureoffsetx -= floor(ray->textureoffsetx);
	if (!ray->cast.washitvert && ray->cast.rayfaceup)
		j = 0;
	else if (!ray->cast.washitvert && ray->cast.rayfacedown)
		j = 1;
	else if (ray->cast.washitvert && ray->cast.rayfaceleft)
		j = 2;
	else if (ray->cast.washitvert && ray->cast.rayfaceright)
		j = 3;
	tmp_adress = ray->adress[j];
	ray->textureoffsetx *= ray->font_w[j];
	ray->distancefromtop = i + (ray->wallstrip / 2) - (R_HEIGHT / 2);
	ray->textureoffsety = ray->distancefromtop * \
	((float)ray->font_h[j] / ray->wallstrip);
	color = tmp_adress[(ray->font_w[j] * ray->textureoffsety) + \
	(int)ray->textureoffsetx];
	my_mlx_pixel_put(ray, ray->ray_id, i, color);
}

void	projection_walls3d(t_ray *ray)
{
	int		i;
	double	distprojectplane;
	double	perpdist;

	perpdist = ray->cast.disctance * cos(ray->ra_angle - ray->ra);
	distprojectplane = (R_WIDTH / 2.0) / tan(ray->fov_angle / 2.0);
	ray->wallstrip = (TILE_SIZE / perpdist) * distprojectplane;
	ray->top_pixel = (R_HEIGHT / 2.0) - (ray->wallstrip / 2.0);
	if (ray->top_pixel < 0 || ray->top_pixel > R_HEIGHT)
		ray->top_pixel = 0;
	ray->bottom_pixel = (R_HEIGHT / 2.0) + (ray->wallstrip / 2.0);
	if (ray->bottom_pixel > R_HEIGHT || ray->bottom_pixel < 0)
		ray->bottom_pixel = R_HEIGHT;
	put_celling(ray);
	put_floor(ray);
	i = ray->top_pixel;
	while (i < ray->bottom_pixel)
	{
		put_texture_walls(ray, i);
		i++;
	}
}
