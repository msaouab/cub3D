/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqessam <iqessam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:43:55 by iqessam           #+#    #+#             */
/*   Updated: 2022/10/03 10:49:41 by iqessam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void 	get_adress(t_ray *ray)
{
	ray->north_adress = mlx_get_data_addr(ray->north_text, &ray->bits_per_pixel, \
	&ray->line_length2, &ray->endian2);
	ray->south_adress = mlx_get_data_addr(ray->south_text, &ray->bits_per_pixel, \
	&ray->line_length2, &ray->endian2);
	ray->west_adress = mlx_get_data_addr(ray->west_text, &ray->bits_per_pixel, \
	&ray->line_length2, &ray->endian2);
	ray->east_adress = mlx_get_data_addr(ray->east_text, &ray->bits_per_pixel, \
	&ray->line_length2, &ray->endian2);
	//to check different textures later
	if (!ray->north_adress || !ray->south_adress || !ray->east_adress ||
	 !ray->west_adress)
	 	ft_error("mlx_get_data_addr problem", 1);
	
}


void 	init_texture(t_ray *ray)
{
	ray->north_text = mlx_xpm_file_to_image(ray->mlx, ray->cub->north, \
	&ray->font_w, &ray->font_h);
	ray->south_text = mlx_xpm_file_to_image(ray->mlx, ray->cub->south, \
	&ray->font_w, &ray->font_h);
	ray->west_text = mlx_xpm_file_to_image(ray->mlx, ray->cub->west, \
	&ray->font_w, &ray->font_h);
	ray->east_text = mlx_xpm_file_to_image(ray->mlx, ray->cub->east, \
	&ray->font_w, &ray->font_h);
	if (!ray->north_text || !ray->south_text || !ray->east_text ||
	 !ray->west_text)
	 	ft_error("mlx_xpm_file_to_image problem", 1);
	get_adress(ray);
}