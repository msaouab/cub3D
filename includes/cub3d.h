/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:34:00 by iqessam           #+#    #+#             */
/*   Updated: 2022/09/18 19:55:20 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../gnl/get_next_line.h"

// --------------Structs for parsing---------------------

typedef struct s_cub
{
	int		count_ln;
	int		head_map;
	char	**body;
	char	*tmp;
	float	celling;
	float	floor;
	char	*south;
	char	*north;
	char	*west;
	char	*east;
	int		len;
	int		ac;
	int		cnt;
	int		rgb_c;
	int		rgb_f;
	int		big_ln;
}	t_cub;

typedef struct s_raycast
{
	t_cub		*cub;
}	t_raycast;

// ----------------Utils_functions-----------------------

void	ft_putstr_fd(char *s, int fd);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char *s1, char *set);
int		ft_strcmp(char *s1, char *s2);
int		ft_error(char *str, int n);
void	ft_free(char **str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

// ---------------Parsing functions----------------------

int		ft_parsing(t_cub *cub, char *av);
void	fill_map(t_cub *cub);
void	read_head(t_cub *cub, char **map);
void	read_body(t_cub *cub, char **map);

// --------------Execution functions---------------------

#endif