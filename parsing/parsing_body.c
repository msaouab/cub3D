/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_body.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:03:28 by msaouab           #+#    #+#             */
/*   Updated: 2022/07/17 17:36:28 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_first_last_line(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map[cub->head_map][i])
	{
		while (cub->map[cub->head_map][i] == ' ')
			i++;
		if (cub->map[cub->head_map][i] != '1')
			ft_error("map not valid\n", 0);
		i++;
	}
	i = 0;
	while (cub->map[cub->count_line - 1][i])
	{
		while (cub->map[cub->count_line - 1][i] == ' ')
			i++;
		if (cub->map[cub->count_line - 1][i] != '1')
			ft_error("map not valid\n", 0);
		i++;
	}
}

int	get_max_line(t_cub *cub)
{
	int	i;

	cub->tmp_line = 0;
	i = cub->head_map;
	while (i < cub->count_line)
	{
		if (cub->tmp_line < ft_strlen(cub->map[i]))
			cub->tmp_line = ft_strlen(cub->map[i]);
		i++;
	}
	return (i);
}

int	change_size_map(t_cub *cub)
{
	int		i;
	int		k;
	size_t	j;

	i = get_max_line(cub) - cub->head_map;
	cub->tmp_map = malloc(sizeof(char *) * i);
	if (!cub->tmp_map)
		ft_error("Problem memory try again\n", 0);
	i = cub->head_map - 1;
	k = 0;
	while (++i < cub->count_line)
	{
		j = -1;
		cub->tmp_map[k] = malloc(sizeof(char *) * cub->tmp_line);
		if (!cub->tmp_line)
			ft_error("Problem memory try again\n", 0);
		while (cub->map[i][++j])
			cub->tmp_map[k][j] = cub->map[i][j];
		if (ft_strlen(cub->map[i]) < cub->tmp_line)
			while (j < cub->tmp_line)
				cub->tmp_map[k][j++] = ' ';
		cub->tmp_map[k++][j] = '\0';
	}
	cub->tmp_map[k] = NULL;
	return (k);
}

void	parsing_vertical(t_cub *cub)
{
	int		k;
	int		i;
	size_t	j;

	k = change_size_map(cub);
	j = 0;
	while (j < cub->tmp_line)
	{
		i = 1;
		while (i < k)
		{
			if (i != 1 && cub->tmp_map[i][j] == ' ' && \
				cub->tmp_map[i - 1][j] != '1')
				ft_error("map not valid\n", 0);
			while (i < k - 1 && cub->tmp_map[i][j] == ' ')
				i++;
			if (i != k - 1 && cub->tmp_map[i - 1][j] == ' ' && \
				cub->tmp_map[i][j] != '1')
				ft_error("map not valid\n", 0);
			i++;
		}
		j++;
	}
	check_first_last_line(cub);
}

void	read_body(t_cub *cub)
{
	size_t	j;
	int		i;

	i = cub->head_map;
	while (i < cub->count_line)
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (j != 0 && cub->map[i][j] == ' ' && cub->map[i][j - 1] != '1')
				ft_error("map not valid\n", 0);
			while (cub->map[i][j] == ' ')
				j++;
			if ((cub->map[i][0] != ' ' && cub->map[i][0] != '1') || \
				(cub->map[i][j - 1] == ' ' && cub->map[i][j] != '1') || \
					(cub->map[i][ft_strlen(cub->map[i]) - 1] != '1'))
				ft_error("map not valid\n", 0);
			j++;
		}
		i++;
	}
	parsing_vertical(cub);
}
