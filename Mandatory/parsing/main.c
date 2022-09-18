/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:39:11 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/18 19:55:06 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **av)
{
	t_raycast	ray;
	t_cub		cub;

	ray.cub = &cub;
	if (argc == 2)
		ft_parsing(&cub, av[1]);
	else
		return (ft_error("Cub3D: Bad Arguments\n", 0));
	ft_error("parsing body done\n", 1);
	return (0);
}
