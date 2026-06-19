# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/19 11:05:52 by vaugusto          #+#    #+#              #
#    Updated: 2026/06/19 11:55:49 by vaugusto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =  ft_px.c ft_rrx.c ft_rx.c ft_sx.c \
		ft_simple.c ft_utils.c ft_utils2.c \
		ft_disorder.c main.c

OBJ = $(SRC:.c=.o)

all: libft $(NAME) 

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

libft:
	make -C ./libft all