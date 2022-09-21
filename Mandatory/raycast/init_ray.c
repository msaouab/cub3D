/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:24:28 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/21 21:35:07 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_player_angle(t_ray *ray)
{
	if (ray->cub->type == 'N')
		ray->ra = 3 * M_PI_2;
	if (ray->cub->type == 'S')
		ray->ra = M_PI_2;
	if (ray->cub->type == 'W')
		ray->ra = M_PI;
	if (ray->cub->type == 'E')
		ray->ra = 0;
}

void	first_position(t_ray *ray)
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
				ray->posy = i * 12;
				ray->posx = j * 12;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_ray(t_ray *ray)
{
	ray->ra = 0;
	ray->posx = 0;
	ray->posy = 0;
	first_position(ray);
	get_player_angle(ray);
}
