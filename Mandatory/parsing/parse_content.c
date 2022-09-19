/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:02:37 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/19 08:28:37 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_content(t_cub *cub, int i, int j)
{
	int	k;

	k = 0;
	if (cub->body[i][j] == 'N' || cub->body[i][j] == 'S')
		cub->player++;
	else if (cub->body[i][j] == 'W' || cub->body[i][j] == 'E')
		cub->player++;
	else if (cub->body[i][j] == ' ' || cub->body[i][j] == '1' \
		|| cub->body[i][j] == '0')
		k++;
	else
		ft_error("you have invalid content\n", 0);
	cub->type = cub->body[i][j];
}

void	parse_content(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->ac)
	{
		j = 0;
		while (cub->body[i][j])
		{
			check_content(cub, i, j);
			j++;
		}
		i++;
	}
	if (cub->player == 0)
		ft_error("you need a player in your map\n", 0);
	if (cub->player != 1)
		ft_error("you have multi players in your map\n", 0);
}
