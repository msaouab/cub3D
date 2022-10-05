/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:44:43 by msaouab           #+#    #+#             */
/*   Updated: 2022/10/05 20:06:25 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	parse_vertical(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	while (j < cub->len)
	{
		if ((cub->body[cub->ac - 1][j] != ' ' \
			&& cub->body[cub->ac - 1][j] != '1') \
			|| (cub->body[0][j] != ' ' && cub->body[0][j] != '1'))
			ft_error("==> The map must be closed/surrounded by walls\n", 0);
		i = 1;
		while (i < cub->ac)
		{
			if (i != 1 && cub->body[i][j] == ' ' && cub->body[i - 1][j] != '1')
				ft_error("The map must be closed/surrounded by walls\n", 0);
			while (i < cub->ac - 1 && cub->body[i][j] == ' ')
				i++;
			if (i != cub->ac - 1 && cub->body[i - 1][j] == ' '\
				&& cub->body[i][j] != '1')
				ft_error("The map must be closed/surrounded by walls\n", 0);
			i++;
		}
		j++;
	}
	parse_content(cub);
}

void	parse_horizantal(t_cub *cub, char **map)
{
	int	len;
	int	i;
	int	j;

	i = cub->head_map;
	while (map[i])
	{
		len = ft_strlen(map[i]) - 1;
		j = 0;
		while (map[i][j])
		{
			if (j != 0 && map[i][j] == ' ' && map[i][j - 1] != '1')
				ft_error("The map must be closed/surrounded by walls\n", 0);
			while (map[i][j] == ' ')
				j++;
			if ((map[i][0] != ' ' && map[i][0] != '1') || \
				(map[i][j - 1] == ' ' && map[i][j] != '1') || \
					(map[i][len] != '1'))
				ft_error("The map must be closed/surrounded by walls\n", 0);
			j++;
		}
		i++;
	}
	parse_vertical(cub);
}

void	larger_ln_map(t_cub *cub, char **map)
{
	int	len;
	int	i;

	i = cub->head_map;
	cub->len = 0;
	while (i < cub->count_ln)
	{
		len = cub->len;
		len = ft_strlen(map[i]);
		if (len > cub->len)
			cub->len = len;
		i++;
	}
}

void	read_body(t_cub *cub, char **map)
{
	int	i;
	int	j;

	cub->ac = cub->count_ln - cub->head_map;
	cub->body = malloc(sizeof(char *) * cub->ac + 1);
	if (!cub->body)
		ft_error("cub->body: allocation problem please try again\n", 0);
	larger_ln_map(cub, map);
	i = 0;
	while (i < (cub->count_ln - cub->head_map))
	{
		cub->body[i] = malloc(sizeof(char *) * cub->len + 1);
		if (!cub->body)
			ft_error("cub->body[i]: allocation problem please try again\n", 0);
		j = -1;
		while (map[cub->head_map + i][++j])
			cub->body[i][j] = map[cub->head_map + i][j];
		while (j < cub->len)
			cub->body[i][j++] = ' ';
		cub->body[i][j] = '\0';
		i++;
	}
	cub->body[i] = NULL;
	parse_horizantal(cub, map);
}
