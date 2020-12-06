# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pberge <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/05 11:59:05 by pberge            #+#    #+#              #
#    Updated: 2020/12/05 19:26:24 by pberge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_BINARY = lem-in

SRC_DIR = srcs/
SRC_FILES = main.c \
			read_from_standard_output.c \
			end_lem_in.c \
			save_line.c \
			lines_with_rooms.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

INCLUDES = -I includes -I libft/includes
LIBRARIES = -L libft -lft
HEADERS = includes/lem-in.h libft/includes/libft.h

DEBUG = -g -ggdb3

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(PROJECT_BINARY)

$(PROJECT_BINARY): $(OBJ)
	@make -s -C libft
#	@$(CC) $(FLAGS) -o $(PROJECT_BINARY) $(OBJ) $(INCLUDES) $(LIBRARIES)
	@$(CC) $(FLAGS) $(DEBUG) -o $(PROJECT_BINARY) $(SRC) $(INCLUDES) $(LIBRARIES)
	echo "recompiled project binary"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

tests:
	@make -C libft
	@$(CC) lemin_unit_tests.c -o lemin_unit_tests $(INCLUDES) $(LIBRARIES) ; ./lemin_unit_tests

clean:
	@rm -rf $(OBJ_DIR)*
	@make -s -C libft clean

fclean: clean
	@rm -f $(PROJECT_BINARY)
	@make -s -C libft fclean

re: fclean all
