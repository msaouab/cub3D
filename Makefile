# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 09:45:39 by msaouab           #+#    #+#              #
#    Updated: 2022/04/25 23:15:03 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRC = parser/parser.c\

OBJ = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME) clean

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean :
		@rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all