/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:32 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/28 16:34:45 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_celling(t_ray *ray)
{
	int	i;
	int	j;

	i = 0;
	while (i < R_HEIGHT / 2)
	{
		j = 0;
		while (j < R_WIDTH)
		{
			my_mlx_pixel_put(ray, j, i, ray->cub->celling);
			j++;
		}
		i++;
	}
}

void	put_floor(t_ray *ray)
{
	int	i;
	int	j;

	i = R_HEIGHT / 2;
	while (i < R_HEIGHT)
	{
		j = 0;
		while (j < R_WIDTH)
		{
			my_mlx_pixel_put(ray, j, i, ray->cub->floor);
			j++;
		}
		i++;
	}
}

void	put_3drender(t_ray *ray)
{
	put_celling(ray);
	put_floor(ray);
}