/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:34:00 by iqessam           #+#    #+#             */
/*   Updated: 2022/07/16 17:26:00 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "../gnl/get_next_line.h"

// --------------Structs for parsing---------------------

typedef struct s_cub
{
	char	**map;
	char	**tmp_map;
	char	*tmp;
	char	*buff;		
	size_t	tmp_line;
	int		count_line;
	int		fd;
	int		i;
	int		_c;
	int		_f;
	int		_n;
	int		_s;
	int		_e;
	int		_w;
	int		head_map;
}	t_cub;

typedef struct s_mlx
{
}	t_mlx;

// ----------------Utils_functions-----------------------

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char *s1, char *set);
int		ft_strcmp(char *s1, char *s2);
int		ft_error(char *str, int n);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

// ---------------Parsing functions----------------------

int		ft_parsing(t_cub *cub, char *av);
void	read_head(t_cub *cub);
void	parsing_head(t_cub *cub);
void	read_body(t_cub *cub);

// --------------Execution functions---------------------

#endif