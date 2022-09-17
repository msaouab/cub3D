/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:44:43 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/17 21:22:16 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	larger_ln_map(t_cub *cub, char **map)
{
	int	len_1;
	int	len_2;
	int	i;

	i = cub->head_map;
	len_2 = 0;
	while (i < cub->count_ln)
	{
		len_1 = len_2;
		len_1 = ft_strlen(map[i]);
		if (len_1 > len_2)
			len_2 = len_1;
		i++;
	}
	return len_2;
}

void	read_body(t_cub *cub, char **map)
{
	int	len;
	int	i;

	len = cub->count_ln - cub->head_map;
	cub->body = malloc(sizeof(char *) * len);
	if (!cub->body)
		ft_error("cub->body: allocation problem please try again\n", 0);
	len = larger_ln_map(cub, map);
	i = cub->head_map;
	while (i < cub->count_ln)
	{
		cub->body[i] = malloc(sizeof(char *) * len + 1);
		if (!cub->body)
			ft_error("cub->body[i]: allocation problem please try again\n", 0);
		cub->body[i] = map[i];
		i++;
	}
}
