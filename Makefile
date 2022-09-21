# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 09:45:39 by iqessam           #+#    #+#              #
#    Updated: 2022/09/21 20:37:15 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

HEADER = includes/cub3d.h

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
		./Mandatory/raycast/mini_map.c\
		./Mandatory/raycast/cam_vue.c\
		./Mandatory/raycast/init_ray.c\
		./Mandatory/raycast/dda_algorithm.c\
		./utils/errors_file.c\
		./utils/ft_atoi.c\
		./utils/ft_isdigit.c\
		./utils/ft_putchar_fd.c\
		./utils/ft_putstr_fd.c\
		./utils/ft_strcmp.c\
		./utils/ft_strrchr.c\
		./utils/ft_strtrim.c\
		./gnl/get_next_line.c\
		./gnl/get_next_line_utils.c\

OBJ = ${SRC:%.c=%.o}

%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "${bold}${clr}.:|	$<		|:.$(green)[OK] ${ED}"

all : $(NAME) clean

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)
	@echo "${bold}${green}.:|$(green)	CREATION LIBRARY	|:. ==> [OK]${ED}"
	@echo "${bold}${green}.:|$(green)		DONE		|:. ==> [OK]${ED}"
	@rm -f */*.o
	@rm -f */*/*.o
	@echo "${bold}$(green).:|${red}	   REMOVE OBJ_FILE	$(green)|:. ==> [OK]${ED}"

clean :
	@rm -f $(OBJ)
	@echo "${bold}$(green).:|${red}	   REMOVE OBJ_FILE	$(green)|:. ==> [OK]${ED}"

fclean : clean
		@rm -f $(NAME)
		@echo "${bold}$(green).:|${red}	   REMOVE EXECUTABLE	$(green)|:. ==> [OK]${ED}"

re :  fclean all