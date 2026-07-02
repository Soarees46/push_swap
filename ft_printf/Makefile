# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/28 14:35:54 by vaugusto          #+#    #+#              #
#    Updated: 2026/06/30 21:57:49 by vaugusto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =  ft_printf.c ft_print_c.c ft_print_s.c ft_print_i.c \
		ft_print_hex.c ft_print_p.c ft_print_double.c

OBJ = $(SRC:.c=.o)

all: $(PRINTF) $(NAME) 

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
