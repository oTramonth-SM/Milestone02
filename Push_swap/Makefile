# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmartins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 20:02:34 by zmartins          #+#    #+#              #
#    Updated: 2026/01/07 17:44:38 by zmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_FILES = push_swap.c\
			main.c\
			utils/stack_handler.c\
			utils/extra_funca.c\

OBJ_FILES = $(SRC_FILES:.c=.o)

FLG = -Wall -Werror -Wextra

$(OBJ_FILES): %.o: %.c
	cc $(FLG) -c $^ -I . -o $@

$(NAME): $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)

.PHONY: all clean fclean re
