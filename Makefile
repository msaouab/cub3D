# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 09:45:39 by msaouab           #+#    #+#              #
#    Updated: 2022/04/26 01:10:02 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC =	parsing/check_clr.c\
		parsing/check_map.c\
		parsing/cub.c\
		parsing/pars_line.c\
		parsing/split.c\
		parsing/utils.c\
		parsing/utils1.c\
		parsing/utils2.c\
		execution/execution.c\

OBJ = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

print = ft_printf/ft_printf.a

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME) clean

$(NAME): $(OBJ)
	@make -C ft_printf
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean :
		@rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)
		@make -C ft_printf fclean

re : fclean all