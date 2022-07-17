/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:18:38 by msaouab           #+#    #+#             */
/*   Updated: 2022/07/15 12:21:33 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init(t_cub *cub)
{
	cub->head_map = 0;
	cub->_c = 0;
	cub->_f = 0;
	cub->_n = 0;
	cub->_s = 0;
	cub->_e = 0;
	cub->_w = 0;
}

void	parsing_map(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	ft_init(cub);
	while (cub->map[++i])
	{
		j = 0;
		while (cub->map[i][j] && (ft_isdigit(cub->map[i][j]) == 1 ||
			cub->map[i][j] == ' '))
		{
			if (cub->map[i][j] == '1' || cub->map[i][j] == '1')
			{
				cub->head_map = i;
				break ;
			}
			j++;
		}
		if (cub->head_map == i && i != 0)
			break ;
	}
	read_head(cub);
	read_body(cub);
}

void	count_line_in_map(t_cub *cub, char *file)
{
	char	*buff;

	cub->fd = open(file, O_RDONLY);
	if (cub->fd < 0)
		return ;
	cub->count_line = 0;
	while (1)
	{
		buff = get_next_line(cub->fd);
		if (!buff)
			break ;
		cub->count_line++;
		free (buff);
	}
	close (cub->fd);
}

void	ft_readmap(t_cub *cub, char *file)
{
	int	i;
	int	j;

	i = 0;
	count_line_in_map(cub, file);
	cub->fd = open(file, O_RDONLY);
	if (cub->fd < 0)
		return ;
	cub->map = malloc(sizeof(char *) * cub->count_line + 1);
	if (!cub->map)
		return ;
	j = cub->count_line;
	while (j-- > 0)
		cub->map[i++] = get_next_line(cub->fd);
	parsing_map(cub);
}

int	ft_parsing(t_cub *cub, char *av)
{
	char	*s;

	s = ft_strrchr(av, '.');
	if (!s)
		return (ft_error(" Not '.cub' extension\n", 0));
	if (ft_strcmp(".cub", s) != 0)
		return (ft_error(av, 0) && ft_error(" Not '.cub' extension\n", 1));
	ft_readmap(cub, av);
	return (0);
}
