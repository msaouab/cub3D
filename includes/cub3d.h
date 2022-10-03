/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqessam <iqessam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:34:00 by iqessam           #+#    #+#             */
/*   Updated: 2022/10/03 19:58:04 by iqessam          ###   ########.fr       */
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
# include "../utils/get_next_line.h"

# define R_WIDTH 1080
# define R_HEIGHT 720
# define WALL_STRIP 1
# define TILE_SIZE 12
# define TEXTURE_SIZE 12
# define TRANSPARENT 0x0ff000000
# define MAX_VALUE 1e30
# define TRUE 1
# define FALSE 0

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

typedef struct s_cast
{
	int		rayfacedown;
	int		rayfaceup;
	int		rayfaceleft;
	int		rayfaceright;
	int		washitvert;
	double	disctance;
}	t_cast;

typedef struct s_ray
{
	void			*mlx;
	void			*win;
	void			*win2;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				line_length2;
	int				endian2;
	double			posx;
	double			posy;
	double			ra;
	double			ra_angle;
	int				minix;
	int				miniy;
	int				w_minimap;
	int				h_minimap;
	double			dirx;
	double			diry;
	double			xinter;
	double			yinter;
	double			rad;
	double			fov_angle;
	double			num_rays;
	int				cminix;
	int				cminiy;
	double			wallhitx;
	double			wallhity;
	double			distance;
	double			horzwallhitx;
	double			horzwallhity;
	double			vertwallhitx;
	double			vertwallhity;
	unsigned int	*pixel_color;
	int				ray_id;
	int				top_pixel;
	int				bottom_pixel;
	// ---------------Textures-----------------------------
	void 			*north_text;
	void 			*south_text;
	void 			*west_text;
	void 			*east_text;
	int 			font_h;
	int 			font_w;
	char 			*north_adress;
	char 			*south_adress;
	char 			*east_adress;
	char 			*west_adress;
	t_cub			*cub;
	t_move			move;
	t_cast			cast;
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
char	**ft_split(char const *s, char c);
char	*ft_itoa(int b);

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
void	my_mlx_pixel_put(t_ray *ray, int x, int y, unsigned int color);
void	init_ray(t_ray *ray);
void	put_minimap(t_ray *ray);
void	draw_line(t_ray *ray, int color, double x1, double y1);
void	field_vue(t_ray *ray, unsigned int color);
void	put_rays(t_ray *ray, unsigned int color);
int		find_walls(t_ray *ray, int x, int y);
void	projection_walls3d(t_ray *ray);
void	put_celling(t_ray *ray);
void	put_floor(t_ray *ray);
void 	init_texture(t_ray *ray);

#endif