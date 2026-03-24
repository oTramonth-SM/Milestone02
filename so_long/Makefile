# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmartins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 16:27:24 by zmartins          #+#    #+#              #
#    Updated: 2026/03/24 18:23:43 by zmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = so_long.c\
	free.c\
	map_utils/map.c\
	map_utils/matrix.c\
	map_utils/validation.c\
	game_utils/game.c\
	game_utils/init.c\
	game_utils/position.c\
	game_utils/render.c\

LIBFT = ../libft/libft.a
NAME = so_long
OBJ = $(SRC:.c=.o)

all:
	cd ../mlx && make
	cd ../libft && make
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) ../mlx/libmlx_Linux.a -I./mlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ)
	cd ../mlx && make clean
	cd ../libft && make clean

fclean: clean
	rm -f $(NAME)
	cd ../mlx && make clean
	cd ../libft && make fclean

re: fclean all

.PHONY: all clean fclean re
