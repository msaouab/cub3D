/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:34:00 by iqessam           #+#    #+#             */
/*   Updated: 2022/09/19 13:27:52 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../gnl/get_next_line.h"

# define R_WIDTH 1280
# define R_HEIGHT 720
# define M_MAP_W 100
# define M_MAP_H 70

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
	char	type;
	int		player;
	int		len;
	int		ac;
	int		cnt;
	int		rgb_c;
	int		rgb_f;
	int		big_ln;
}	t_cub;

typedef struct s_move
{
	int		x;
	int		y;
	int		cam_vue;
	float	inc_speed;
}	t_move;

// --------------Structs for raycasting-----------------------

typedef struct s_ray
{
	void	*mlx;
	void	*win;
	void	*img;
	int		posx;
	int		posy;
	float	ra;
	t_cub	*cub;
	t_move	move;
}	t_ray;

// ----------------Utils_functions----------------------------

void	ft_putstr_fd(char *s, int fd);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char *s1, char *set);
int		ft_strcmp(char *s1, char *s2);
int		ft_error(char *str, int n);
void	ft_free(char **str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

// ---------------Parsing functions---------------------------

int		ft_parsing(t_cub *cub, char *av);
void	fill_map(t_cub *cub);
void	read_head(t_cub *cub, char **map);
void	read_body(t_cub *cub, char **map);
void	parse_content(t_cub *cub);

// --------------Raycasting functions-------------------------

void	raycast(t_ray *ray);
void	my_mlx_button(t_ray *ray);
void	move_left(t_ray *ray);
void	move_right(t_ray *ray);
void	move_down(t_ray *ray);
void	move_up(t_ray *ray);
void	cam_left(t_ray *ray);
void	cam_right(t_ray *ray);
void	get_player_angle(t_ray *ray);

#endif