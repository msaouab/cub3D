# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 16:13:14 by momayaz           #+#    #+#              #
#    Updated: 2022/04/25 22:16:43 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	parsing/mini_utils.c \
		parsing/mini_utils2.c \
		parsing/utils.c \
		parsing/utils2.c \
		parsing/utils3.c \
		parsing/parse_map.c \
		utils/utils.c \
		utils/utils2.c

SRCM = mandatory.c

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC) cub3d.h
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

run: all
	./cub3D maps/man.cub

.PHONY: bonus all re clean fclean