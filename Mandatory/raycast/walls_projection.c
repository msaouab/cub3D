/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqessam <iqessam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:52:23 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/03 21:49:40 by iqessam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <string.h>

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
int is_pair(t_ray *ray)
{
	if ((ray->ray_id % 8) == 0)
		return (16711680);
	else
		return (1582919);
}


char *deci_to_hexa(long int n)
{
	char *buffer = NULL;
	if (n < 9)
	{
		printf("%ld\n", (n % 16));
			// buffer = ft_itoa(n);
		// else if (n >= 10)
		// 	buffer = strcat(buffer,(n % 10) + 'A');
	}
	else
	{
		deci_to_hexa(n / 16);
		// deci_to_hexa(n % 16);
	}
	return (buffer);
}


int 	converted(char *texel_color)
{
	int	decimal = 0;
	unsigned int tmp = *(unsigned int*)texel_color;
	// printf("%s\n", deci_to_hexa(tmp));
	// printf("%x\n", tmp);
	// exit (0);
	char *buffer = ft_itoa(tmp);
	//  printf("%s\n", buffer);

	decimal += ((ft_atoi(&buffer[0]) * 16) + ft_atoi(&buffer[1]) * (256 * 256)) \
	+ ((ft_atoi(&buffer[2]) * 16) + ft_atoi(&buffer[3]) * 256) \
	+ (ft_atoi(&buffer[4]) * 16 + ft_atoi(&buffer[5])) \
	- (ft_atoi(&buffer[6]) * 16 + ft_atoi(&buffer[7]));
	printf("%d\n", decimal);
	exit (1);
	return (decimal);
}

void	projection_walls3d(t_ray *ray)
{
	int		i;
	double	wallstrip_height;
	double	distprojectplane;
	double	perpdist;
	int 	textureOffsetX;
	perpdist = ray->cast.disctance * cos(ray->ra_angle - ray->ra);
	distprojectplane = (R_WIDTH / 2.0) / tan(ray->fov_angle / 2.0);
	wallstrip_height = (TILE_SIZE / perpdist) * distprojectplane;
	ray->top_pixel = (R_HEIGHT / 2.0) - (wallstrip_height / 2.0);
	if (ray->top_pixel < 0 || ray->top_pixel > R_HEIGHT)
		ray->top_pixel = 0;
	ray->bottom_pixel = (R_HEIGHT / 2.0) + (wallstrip_height / 2.0);
	if (ray->bottom_pixel > R_HEIGHT || ray->bottom_pixel < 0)
		ray->bottom_pixel = R_HEIGHT;
	i = ray->top_pixel;
	put_celling(ray);
	put_floor(ray);
	if (ray->cast.washitvert)
		textureOffsetX = (int)ray->wallhity % TEXTURE_SIZE;
	else
		textureOffsetX = (int)ray->wallhitx % TEXTURE_SIZE;
	while (i < ray->bottom_pixel)
	{
           // calculate texture offset X
        // calculate texture offset Y
        int distanceFromTop = i + (wallstrip_height / 2) - (R_HEIGHT / 2);
        int textureOffsetY = distanceFromTop * ((float)TEXTURE_SIZE / wallstrip_height);
		// printf("%d\n", textureOffsetY);
        // set the color of the wall based on the color from the texture
		// char *dst = ray->north_adress + ((ray->ray_id * ray->line_length2) + i * ((ray->bits_per_pixel / 8)));
        char *texel_color = ray->north_adress + (TEXTURE_SIZE * textureOffsetY) + textureOffsetX;
		// printf("%X\n", *(unsigned int*)texel_color);
		my_mlx_pixel_put(ray, ray->ray_id, i, converted(texel_color));
		// exit (0);
		i++;
	}
}
