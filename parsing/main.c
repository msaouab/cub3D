/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:34:38 by msaouab           #+#    #+#             */
/*   Updated: 2022/07/19 17:54:58 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_cub	cub;

	mlx.cub = &cub;
	if (ac == 2)
		ft_parsing(&cub, av[1]);
	else
		return (ft_error("Cub3D: Bad Arguments\n", 0));
	// mlx_main(&mlx);
	return (0);
}
