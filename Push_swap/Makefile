# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmartins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 20:02:34 by zmartins          #+#    #+#              #
#    Updated: 2025/12/18 16:39:56 by zmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_FILES = push_swap.c\
			stack_handler.c\

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
