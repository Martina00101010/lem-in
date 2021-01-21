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
			draw_full_graph.c \
			xiaolin_wu_algorithm.c \
			open_window.c \
			sdl_destroy.c \
			sdl_loop.c \
			sdl_render.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

INCLUDES = -I includes -I libft/includes
LIBRARIES = -L libft -lft
HEADERS = includes/lem_in.h includes/ft_sdl.h libft/includes/libft.h

DEBUG = -g -ggdb3

CC = gcc

FLAGS = -Wall -Wextra -Werror

FRAME_SDL = -L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2 -lSDL2_image

ifeq ($(OS), Darwin)
INC_SDL = -I frameworks/SDL2.framework/Headers \
			-I frameworks/SDL2_image.framework/Headers \
			-I include_framework 
# FRAME_SDL = -F frameworks -framework SDL2 -rpath frameworks -framework SDL2_image 
endif
ifeq ($(OS), Linux)
INC_SDL = -I /usr/local/include/SDL2 -I include_framework -I /usr/include/SDL2
endif


all: INSTALL_SDL $(PROJECT_BINARY)

$(PROJECT_BINARY): $(OBJ)
	@make -s -C libft
	@$(CC) $(FLAGS) -o $(PROJECT_BINARY) $(SRC) $(INCLUDES) $(LIBRARIES) $(INC_SDL) $(FRAME_SDL)
	@echo "recompiled project binary"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS) $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCLUDES) $(INC_SDL) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

INSTALL_SDL:
	@./pkg_sdl

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
