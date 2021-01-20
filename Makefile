# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pberge <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/05 11:59:05 by pberge            #+#    #+#              #
#    Updated: 2020/12/27 15:14:08 by pberge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_BINARY = lem-in
TESTS_BINARY = lemin_unit_tests

SRC_DIR = srcs/
SRC_FILES = main.c \
			read_from_standard_output.c \
			end_lem_in.c \
			lines_with_rooms.c \
			lines_with_links.c \
			checks.c \
			build_graph.c \
			graph_checks.c \
			queue.c \
			get_room_name.c \
			debug_print.c \
			remove_extra_links.c \
			remove_input_forks.c \
			remove_links.c \
			remove_output_forks.c \
			on_start.c \
			go.c \
			prints.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

INCLUDES = -I includes -I libft/includes
LIBRARIES = -L libft -lft
HEADERS = includes/lem_in.h libft/includes/libft.h

DEBUG = -g -ggdb3

CC = gcc
#FLAGS = -Wall -Wextra -Werror

all: $(PROJECT_BINARY)

$(PROJECT_BINARY): $(OBJ)
	@make -s -C libft
#	@$(CC) $(FLAGS) -o $(PROJECT_BINARY) $(OBJ) $(INCLUDES) $(LIBRARIES)
	@$(CC) $(FLAGS) $(DEBUG) -o $(PROJECT_BINARY) $(SRC) $(INCLUDES) $(LIBRARIES)
	@echo "recompiled project binary"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

tests:
	@make -s -C libft
	@$(CC) $(SRC_DIR)/lemin_unit_tests.c -o $(TESTS_BINARY) $(INCLUDES) $(LIBRARIES)
	@./$(TESTS_BINARY)

clean:
	@rm -rf $(OBJ_DIR)*
	@make -s -C libft clean

fclean: clean
	@rm -f $(PROJECT_BINARY)
	@rm -f $(TESTS_BINARY)
	@make -s -C libft fclean

re: fclean all
