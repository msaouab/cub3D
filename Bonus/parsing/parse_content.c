/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:02:37 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/05 20:06:29 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	assignement_color(t_cub *cub, char c, unsigned int color)
{
	if (c == 'C')
	{
		cub->celling = color;
		cub->rgb_c += 1;
	}	
	if (c == 'F')
	{
		cub->floor = color;
		cub->rgb_f += 1;
	}
}

void	texture_counter(t_cub *cub, char c)
{
	if (c == 'N')
		cub->ntext++;
	if (c == 'S')
		cub->stext++;
	if (c == 'E')
		cub->etext++;
	if (c == 'W')
		cub->wtext++;
}

void	check_content(t_cub *cub, int i, int j)
{
	int	k;

	k = 0;
	if (cub->body[i][j] == 'N' || cub->body[i][j] == 'S')
	{
		cub->type = cub->body[i][j];
		cub->player++;
	}
	else if (cub->body[i][j] == 'W' || cub->body[i][j] == 'E')
	{
		cub->type = cub->body[i][j];
		cub->player++;
	}
	else if (cub->body[i][j] == ' ' || cub->body[i][j] == '1' \
		|| cub->body[i][j] == '0')
		k++;
	else
		ft_error("you have invalid content\n", 0);
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
