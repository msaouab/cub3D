/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:06:44 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/25 16:14:58 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	int		height;
	int		width;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		ceiling;
	int		floor;
	int		bola[255];
	char	**map;
}	t_data;


/*-------------------------------- MINI_UTILS --------------------------------*/
int				ft_error(char *str, int exit_status);
char			*ft_strchr(char *s, int c);
float			f_abs(float n);
int				ft_close(void);

/*-------------------------------- PARSING --------------------------------*/
size_t			ft_strlen(char *str);
char			*ft_strdup(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*get_next_line(int fd);
char			*ft_strtrim(char *s1, char const *set);
void			ft_check_color(t_data *data, char c, char *line, int *cp);
int				ft_isspace(char c);
int				ft_atoi(const char *str);
void			ft_check_texture(t_data *data, char c, char *line, int *cp);
void			count_height(int fd, t_data *data);
void			fill_map(t_data *data, char *filename);
void			free_all(t_data *data, t_all *all);
void			free_bonus(t_all *all);
void			check_walls(t_data *data, int mode);
void			parse_map(int ac, char *filename, t_data *data, int mode);

#endif