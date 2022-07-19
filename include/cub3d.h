/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:34:00 by iqessam           #+#    #+#             */
/*   Updated: 2022/07/19 18:34:46 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "../gnl/get_next_line.h"
# include "../minilibx_mms_20200219/mlx.h"
# include "../minilibx_opengl_20191021/mlx.h"

// --------------Structs for parsing---------------------

typedef struct s_cub
{
	char		**map;
	char		**tmp_map;
	char		*tmp;
	char		*buff;		
	char		type;
	size_t		tmp_line;
	int			count_line;
	long int	rgb_c;
	long int	rgb_f;
	int			fd;
	int			fd_texture[4];
	int			i;
	int			_c;
	int			_f;
	int			_n;
	int			_s;
	int			_e;
	int			_w;
	int			_d;
	int			_p;
	int			head_map;
}	t_cub;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_cub	*cub;
}	t_mlx;

// ----------------Utils_functions-----------------------

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
void	parse_char(t_cub *cub);
void	rgb_to_hex(t_cub *cub, char *tmp, char c);
void	ft_free(char **str);
// --------------Execution functions---------------------

void	mlx_main(t_mlx *mlx);

#endif