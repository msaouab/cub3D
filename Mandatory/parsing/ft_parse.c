/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:43:26 by msaouab           #+#    #+#             */
/*   Updated: 2022/09/19 15:00:17 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_parse(t_cub *cub)
{
	cub->head_map = 0;
	cub->count_ln = 0;
	cub->head_map = 0;
	cub->celling = 0;
	cub->floor = 0;
	cub->player = 0;
	cub->rgb_c = 0;
	cub->rgb_f = 0;
	cub->cnt = 0;
	cub->rgb_c = 0;
	cub->rgb_f = 0;
	cub->ntext = 0;
	cub->stext = 0;
	cub->wtext = 0;
	cub->etext = 0;
}

void	parsing_map(t_cub *cub, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j] && (ft_isdigit(map[i][j]) == 1 || map[i][j] == ' '))
		{
			if (map[i][j] == '1' || map[i][j] == ' ')
			{
				cub->head_map = i;
				break ;
			}
			j++;
		}
		if (cub->head_map == i && i != 0)
			break ;
	}
	read_head(cub, map);
	if (cub->cnt != 6)
		ft_error("error: Error head map\n", 1);
	read_body(cub, map);
}

void	count_line_in_map(t_cub *cub, char *file)
{
	char	*buff;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		cub->count_ln++;
		free (buff);
	}
	close (fd);
}

void	ft_readmap(t_cub *cub, char *file)
{
	char	**map;
	int		fd;
	int		i;

	count_line_in_map(cub, file);
	map = malloc(sizeof(char *) * cub->count_ln + 1);
	if (!map)
		ft_error("map: allocation problem please try again\n", 0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(ft_strjoin(file, " file Not found\n"), 0);
	i = 0;
	while (i < cub->count_ln)
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	parsing_map(cub, map);
}

int	ft_parsing(t_cub *cub, char *av)
{
	char	*s;

	ft_init_parse(cub);
	s = ft_strrchr(av, '.');
	if (!s)
		return (ft_error(" Not '.cub' extension\n", 0));
	if (ft_strcmp(".cub", s) != 0)
		return (ft_error(ft_strjoin(av, " Not '.cub' extension\n"), 0));
	ft_readmap(cub, av);
	return (0);
}
