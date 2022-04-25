# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 21:35:46 by msaouab           #+#    #+#              #
#    Updated: 2021/11/27 21:35:49 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h
src = ft_char.c ft_digit.c ft_hex.c ft_printf.c

Obj = $(src:.c=.o)

Cflags = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(Obj)
		gcc $(Cflags) -c $(src)
		ar rc $(NAME) $(Obj)
		ranlib $(NAME)

clean : 
	rm -f *.o

fclean : clean
		@rm -rf $(NAME)

re : fclean all
