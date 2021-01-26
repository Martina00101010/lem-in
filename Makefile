# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pberge <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/05 11:59:05 by pberge            #+#    #+#              #
#    Updated: 2021/01/26 13:59:39 by pberge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
TESTS_BINARY = lemin_unit_tests

WFLAGS = -Wall -Wextra -Werror

DEBUG = -g -ggdb3

SRC_DIR = srcs

SRCS = main.c \
			read_from_stdout.c \
			end_lem_in.c \
			lines_with_rooms.c \
			lines_with_links.c \
			checks.c \
			build_graph.c \
			queue.c \
			get_room_name.c \
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
			sdl_draw_move.c \

LIBFT = -L libft -lft

OBJ_DIR = objs

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

INCLUDES = -I includes -I libft/includes -I /usr/include/SDL2

HDR = includes/lem_in.h includes/ft_sdl.h libft/includes/libft.h 

OS = $(shell uname -s)

ifeq ($(OS), Darwin)
INC_SDL = -I frameworks/SDL2.framework/Headers \
			-I frameworks/SDL2_image.framework/Headers \
			-I frameworks/SDL2_ttf.framework/Headers \
			-I include_framework
FRAME_SDL = -F frameworks -framework SDL2 -rpath frameworks \
			-framework SDL2_image -framework SDL2_ttf
endif

ifeq ($(OS), Linux)
INC_SDL = -I/usr/local/include/SDL2 -D_REENTRANT
FRAME_SDL = -lSDL2 -lSDL2_ttf \
	-L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags
endif

all: INSTALL_SDL $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling project..."
	@make -s -C libft
	@gcc $(WFLAGS) -o $(NAME) $(OBJ) $(INCLUDES) $(LIBFT) $(INC_SDL) $(FRAME_SDL)

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDR)
	@mkdir -p $(OBJ_DIR)
	@gcc $(INCLUDES) $(INC_SDL) -c $< -o $@

INSTALL_SDL:
	@./pkg_sdl

tests:
	@make -s -C libft
	@$(CC) $(SRC_DIR)/lemin_unit_tests.c -o $(TESTS_BINARY) $(INCLUDES) $(LIBFT)
	@./$(TESTS_BINARY)

clean:
	@rm -rf $(OBJ_DIR)
	@make -s -C libft clean
	@echo "$(BLUE)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -s -C libft fclean
	@echo "$(BLUE)Binary files removed.$(RESET)"

re: fclean all
