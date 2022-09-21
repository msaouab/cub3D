/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:34:00 by iqessam           #+#    #+#             */
/*   Updated: 2022/09/21 21:32:50 by msaouab          ###   ########.fr       */
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
// # define FOV_ANGLE 60 * (M_PI / 180)
// # define wall_strip 90
// # define num_rays (R_WIDTH / wall_strip)

// --------------Structs for parsing---------------------

typedef struct s_cub
{
	int				count_ln;
	int				head_map;
	char			**body;
	char			*tmp;
	unsigned int	celling;
	unsigned int	floor;
	char			*south;
	char			*north;
	char			*west;
	char			*east;
	char			type;
	int				player;
	int				len;
	int				ac;
	int				cnt;
	int				rgb_c;
	int				rgb_f;
	int				big_ln;
	int				ntext;
	int				stext;
	int				wtext;
	int				etext;
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
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		posx;
	int		posy;
	float	ra;
	int		minix;
	int		miniy;
	double	dirx;
	double	diry;
	double	xinter;
	double	yinter;
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
void	texture_counter(t_cub *cub, char c);

// --------------Raycasting functions-------------------------

void	raycast(t_ray *ray);
void	my_mlx_button(t_ray *ray);
void	move_left(t_ray *ray);
void	move_right(t_ray *ray);
void	move_down(t_ray *ray);
void	move_up(t_ray *ray);
void	cam_left(t_ray *ray);
void	cam_right(t_ray *ray);
void	xpmfile(t_ray *ray);
void	my_mlx_pixel_put(t_ray *ray, int x, int y, int color);
void	ft_init_ray(t_ray *ray);
void	puts_minimap(t_ray *ray);
void	dda_algorithm(t_ray *ray, int color);
void	field_vue(t_ray *ray, unsigned int color);

#endif