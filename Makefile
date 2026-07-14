# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaugusto <vaugusto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/19 11:05:52 by vaugusto          #+#    #+#              #
#    Updated: 2026/07/14 11:04:09 by vaugusto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g3 -O0

SRC =  ft_px.c ft_rrx.c ft_rx.c ft_sx.c \
		ft_simple.c ft_utils.c ft_utils2.c \
		ft_disorder.c main.c ft_utils3.c \
		ft_algo_chooser.c ft_radix.c ft_bench.c\
		ft_utils4.c ft_error.c

OBJ = $(SRC:.c=.o)

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: printf $(NAME)

debug: CFLAGS += $(DEBUGFLAGS)
debug: re

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