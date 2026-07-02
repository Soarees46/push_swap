# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/19 11:05:52 by vaugusto          #+#    #+#              #
#    Updated: 2026/06/29 10:08:45 by vaugusto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =  ft_px.c ft_rrx.c ft_rx.c ft_sx.c \
		ft_simple.c ft_utils.c ft_utils2.c \
		ft_disorder.c main.c ft_utils3.c \
		ft_algo_chooser.c ft_radix.c ft_bench.c

OBJ = $(SRC:.c=.o)

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: printf $(NAME)

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $(NAME)
# 	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@	

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

printf:
	$(MAKE) -C ./ft_printf all