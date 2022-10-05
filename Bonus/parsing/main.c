/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:39:11 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/05 20:06:21 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	main(int argc, char **av)
{
	t_ray	ray;
	t_cub	cub;

	ray.cub = &cub;
	if (argc == 2)
		ft_parsing(&cub, av[1]);
	else
		return (ft_error("Cub3D: Bad Arguments\n", 0));
	raycast(&ray);
	return (0);
}
