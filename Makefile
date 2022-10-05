# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 09:45:39 by iqessam           #+#    #+#              #
#    Updated: 2022/10/05 20:28:28 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

NAME_B = Cub3D_Bonus

HEADER = includes/cub3d.h

HEADER_B = includes/cub3d_bonus.h

MLX = -lmlx -framework OpenGL -framework AppKit

CC = gcc

green = `tput setaf 2`

red = `tput setaf 3`

clr = `tput setaf 8`

bold = $(shell tput bold)

ED = \033[0m

CFLAGS = -Wall -Wextra -Werror

SRC =	./Mandatory/parsing/main.c\
		./Mandatory/parsing/ft_parse.c\
		./Mandatory/parsing/parse_head.c\
		./Mandatory/parsing/parse_body.c\
		./Mandatory/parsing/parse_content.c\
		./Mandatory/raycast/raycast.c\
		./Mandatory/raycast/mlx_button.c\
		./Mandatory/raycast/mlx_key.c\
		./Mandatory/raycast/cam_vue.c\
		./Mandatory/raycast/init_ray.c\
		./Mandatory/raycast/raycasting_calcul.c\
		./Mandatory/raycast/calcul_utils.c\
		./Mandatory/raycast/walls_projection.c\
		./Mandatory/raycast/texture.c\
		./Mandatory/raycast/horz_vert_walls.c\
		./utils/errors_file.c\
		./utils/ft_atoi.c\
		./utils/ft_isdigit.c\
		./utils/ft_putchar_fd.c\
		./utils/ft_putstr_fd.c\
		./utils/ft_strcmp.c\
		./utils/ft_strrchr.c\
		./utils/ft_strtrim.c\
		./utils/ft_split.c\
		./utils/ft_itoa.c\
		./utils/sound.c\
		./utils/get_next_line.c\
		./utils/get_next_line_utils.c\

SRC_B =	./Bonus/parsing/main.c\
		./Bonus/parsing/ft_parse.c\
		./Bonus/parsing/parse_head.c\
		./Bonus/parsing/parse_body.c\
		./Bonus/parsing/parse_content.c\
		./Bonus/raycast/raycast.c\
		./Bonus/raycast/mlx_button.c\
		./Bonus/raycast/mlx_key.c\
		./Bonus/raycast/mini_map.c\
		./Bonus/raycast/cam_vue.c\
		./Bonus/raycast/init_ray.c\
		./Bonus/raycast/raycasting_calcul.c\
		./Bonus/raycast/calcul_utils.c\
		./Bonus/raycast/walls_projection.c\
		./Bonus/raycast/texture.c\
		./Bonus/raycast/horz_vert_walls.c\
		./utils/errors_file.c\
		./utils/ft_atoi.c\
		./utils/ft_isdigit.c\
		./utils/ft_putchar_fd.c\
		./utils/ft_putstr_fd.c\
		./utils/ft_strcmp.c\
		./utils/ft_strrchr.c\
		./utils/ft_strtrim.c\
		./utils/ft_split.c\
		./utils/ft_itoa.c\
		./utils/sound.c\
		./utils/get_next_line.c\
		./utils/get_next_line_utils.c\

OBJ = ${SRC:%.c=%.o}

OBJ_B = ${SRC_B:%.c=%.o}

%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "${bold}${clr}.:|	$<		|:.$(green)[OK] ${ED}"

all : $(NAME) clean

bonus : $(NAME_B) clean

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)
	@echo "${bold}${green}.:|$(green)	CREATION LIBRARY	|:. ==> [OK]${ED}"
	@echo "${bold}${green}.:|$(green)		DONE		|:. ==> [OK]${ED}"
	@rm -f */*.o
	@rm -f */*/*.o
	@echo "${bold}$(green).:|${red}	   REMOVE OBJ_FILE	$(green)|:. ==> [OK]${ED}"

$(NAME_B): $(OBJ_B) $(HEADER_B)
	@$(CC) $(CFLAGS) $(OBJ_B) $(MLX) -o $(NAME_B)
	@echo "${bold}${green}.:|$(green)	CREATION LIBRARY	|:. ==> [OK]${ED}"
	@echo "${bold}${green}.:|$(green)		DONE		|:. ==> [OK]${ED}"
	@rm -f */*.o
	@rm -f */*/*.o
	@echo "${bold}$(green).:|${red}	   REMOVE OBJ_FILE	$(green)|:. ==> [OK]${ED}"

clean :
	@rm -f $(OBJ) $(OBJ_B)
	@echo "${bold}$(green).:|${red}	   REMOVE OBJ_FILE	$(green)|:. ==> [OK]${ED}"

fclean : clean
		@rm -f $(NAME) $(NAME_B)
		@echo "${bold}$(green).:|${red}	   REMOVE EXECUTABLE	$(green)|:. ==> [OK]${ED}"

re :  fclean all bonus