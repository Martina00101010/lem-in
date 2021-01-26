# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pberge <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/05 11:59:05 by pberge            #+#    #+#              #
#    Updated: 2021/01/26 11:42:24 by pberge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROJECT_BINARY = lem-in
TESTS_BINARY = lemin_unit_tests

SRCS = main.c \
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
			sdl_draw_move.c \

LIBFT = -L libft -lft

OBJ_DIR = objs

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

INCLUDES = -I includes -I libft/includes -I /usr/include/SDL2

HDR = includes/lem_in.h includes/ft_sdl.h libft/includes/libft.h 

ifeq ($(OS), Darwin)
INC_SDL = -I frameworks/SDL2.framework/Headers \
			-I frameworks/SDL2_image.framework/Headers \
			-I include_framework
FRAME_SDL = -F frameworks -framework SDL2 -rpath frameworks \
			-framework SDL2_image
endif
ifeq ($(OS), Linux)
INC_SDL = -I/usr/local/include/SDL2 -D_REENTRANT
FRAME_SDL = -lSDL2 -L framewords/SDL2.framework/SDL2 -lm -lSDL2_image\
	-L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags
endif

all: INSTALL_SDL $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling project..."
	@make -s -C libft
	@$(CC) $(FLAGS) $(DEBUG) -o $(PROJECT_BINARY) $(SRC) $(INCLUDES) $(LIBRARIES) $(INC_SDL) $(FRAME_SDL)
	@#gcc $(WFLAGS) -o $(NAME) $(OBJ) $(INCLUDES) $(LIBFT) $(INC_SDL) $(FRAME_SDL)
	@echo "$(RED)wolf3d is ready.$(RESET)"
	@echo "$(GREEN)*************************************************************"
	@echo "*** Run the project: ./wolf3d [-l] maps/level_1 ***"
	@echo "*************************************************************$(RESET)"

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDR)
	@mkdir -p $(OBJ_DIR)
	@gcc $(WFLAGS) $(INCLUDES) $(INC_SDL) -c $< -o $@

INSTALL_SDL:
	@./pkg_sdl

tests:
	@make -s -C libft
	@$(CC) $(SRC_DIR)/lemin_unit_tests.c -o $(TESTS_BINARY) $(INCLUDES) $(LIBRARIES)
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
