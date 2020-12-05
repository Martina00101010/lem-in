# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: koparker <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 17:39:07 by koparker          #+#    #+#              #
#    Updated: 2020/03/14 18:45:35 by koparker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WFLAGS = -Wall -Wextra -Werror


OS = $(shell uname -s)
ifeq ($(OS), Darwin)
	MAGENTA = \x1B[35m
	RESET = \x1B[0m
endif
ifeq ($(OS), Linux)
	MAGENTA = \e[35m
	RESET = \e[0m
endif

NAME = libft.a

INCLUDES = -I includes

HDR = includes/libft.h

SRC = ft_2d_strlen.c ft_atoi.c ft_atoi_hex.c ft_atof.c ft_bzero.c \
	ft_free_char_arr.c \
	ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstat.c \
	ft_lstback.c ft_lstdel.c ft_lstdelone.c ft_lstfree_node.c ft_lstinsert_at.c \
	ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstpop_back.c ft_lstpop_front.c \
	ft_lstpush_back.c ft_lstsize.c ft_lsttop.c ft_memalloc.c ft_memccpy.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memcpy_backwards.c ft_memdel.c \
	ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_base.c ft_putchar_fd.c \
	ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_base.c ft_putnbr_fd.c \
	ft_putstr.c ft_putstr_base.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
	ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
	ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c \
	ft_strtrim.c ft_tolower.c ft_toupper.c get_next_line.c \
	ft_pow.c ft_itoa_unsigned.c \
	ft_trim_quotes.c ft_strndup.c ft_isspace.c ft_strnchr.c ft_lst_find.c \

OBJ_DIR = objs

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(OBJ): $(OBJ_DIR)/%.o: %.c $(HDR)
	@mkdir -p $(OBJ_DIR)
	@gcc $(WFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(OBJ_DIR)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(MAGENTA)Libft is ready.$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
