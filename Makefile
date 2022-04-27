# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 09:45:39 by msaouab           #+#    #+#              #
#    Updated: 2022/04/27 01:39:05 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC =	main.c\
		parsing/ft_error.c\
		parsing/mini_utils.c\
		parsing/mini_utils2.c\
		parsing/parse_map.c\
		parsing/utils.c\
		parsing/utils2.c\
		parsing/utils3.c\

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