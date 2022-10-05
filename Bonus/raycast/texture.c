/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:43:55 by iqessam           #+#    #+#             */
/*   Updated: 2022/10/05 20:07:08 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	get_adress(t_ray *ray)
{
	ray->adress[0] = (int *)mlx_get_data_addr(ray->north_text, \
	&ray->bits_per_pixel, &ray->line_length2, &ray->endian2);
	ray->adress[1] = (int *)mlx_get_data_addr(ray->south_text, \
	&ray->bits_per_pixel, &ray->line_length2, &ray->endian2);
	ray->adress[2] = (int *)mlx_get_data_addr(ray->west_text, \
	&ray->bits_per_pixel, &ray->line_length2, &ray->endian2);
	ray->adress[3] = (int *)mlx_get_data_addr(ray->east_text, \
	&ray->bits_per_pixel, &ray->line_length2, &ray->endian2);
	if (!ray->adress[0] || !ray->adress[1] || !ray->adress[2] \
	|| !ray->adress[3])
		ft_error("mlx_get_data_addr problem", 1);
}

void	init_texture(t_ray *ray)
{
	ray->north_text = mlx_xpm_file_to_image(ray->mlx, ray->cub->north, \
	&ray->font_w[0], &ray->font_h[0]);
	ray->south_text = mlx_xpm_file_to_image(ray->mlx, ray->cub->south, \
	&ray->font_w[1], &ray->font_h[1]);
	ray->west_text = mlx_xpm_file_to_image(ray->mlx, ray->cub->west, \
	&ray->font_w[2], &ray->font_h[2]);
	ray->east_text = mlx_xpm_file_to_image(ray->mlx, ray->cub->east, \
	&ray->font_w[3], &ray->font_h[3]);
	if (!ray->north_text || !ray->south_text || !ray->east_text \
	|| !ray->west_text)
		ft_error("mlx_xpm_file_to_image problem", 1);
	get_adress(ray);
}
