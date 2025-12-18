# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 18:03:58 by zmartins          #+#    #+#              #
#    Updated: 2025/09/05 16:17:50 by zmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE_FILES = ft_printf.c\
			ft_printer.c\

OBJ =$(SOURCE_FILES:.c=.o)

FLAGZ = -Wall -Werror -Wextra

all: $(NAME)

$(OBJ): %.o: %.c
	cc $(FLAGZ) -c $^ -I . -o $@

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)

.PHONY: all clean fclean re
