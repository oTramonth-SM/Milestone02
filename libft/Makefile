# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmartins <zmartins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 20:52:18 by zmartins          #+#    #+#              #
#    Updated: 2026/03/24 16:34:46 by zmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGZ = -Wall -Wextra -Werror 

SRC = ft_atoi.c\
	ft_calloc.c\
	ft_bzero.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_memchr.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strnstr.c\
	ft_strncmp.c\
	ft_strrchr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strmapi.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_itoa.c\
	ft_putnbr_fd.c\
	ft_strtrim.c\
	ft_striteri.c\
	ft_split.c\

SRC_PRINTF = ft_printer.c\
		ft_printf.c\

SRC_GNL = get_next_line.c\
		get_next_line_utils.c\

BNS_SRC = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstdelon.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstlast.c\
		ft_lstmap.c\
		ft_lstadd_back.c\

TEMPDIR = Objects_dir

OBJ = $(SRC:%.c=$(TEMPDIR)/%.o) $(SRC_PRINTF:%.c=$(TEMPDIR)/%.o) $(SRC_GNL:%.c=$(TEMPDIR)/%.o)

OBJ_BNS = $(BNS_SRC:%.c=$(TEMPDIR)/%.o)

all: $(NAME)
	
$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

$(TEMPDIR):
	@mkdir -p $(TEMPDIR)
$(TEMPDIR)/%.o: %.c | $(TEMPDIR)
	cc $(FLAGZ) -c $< -o $@

ALL = $(OBJ) $(OBJ_BNS)

bonus:
	$(MAKE) $(ALL)

clean:
	rm -rf $(ALL) $(TEMPDIR) 
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
