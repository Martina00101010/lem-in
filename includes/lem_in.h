/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:36:32 by pberge            #+#    #+#             */
/*   Updated: 2020/12/05 19:20:01 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include "ft_sdl.h"
# include "libft.h"

/*
** ПАРСЕР
*/

# define BUFFER_SIZE		(size_t)8
# define ROOM_NAME_SIZE		(size_t)5
# define MAX_ROOMS_NUM		(size_t)10
# define MAX_SHORT			(short)32767
# define MAX_INT			(int)2147483647
# define START_PATH_LEN		0
# define DRAW				2
# define IMGWIDTH			HEIGHT
# define IMGHEIGHT			HEIGHT
# define GREY				0x505050
# define GREEN				0x00ff00
# define FONT_FILE			"fonts/FreeMono.ttf"
# define FONT_SIZE			21
# define WHI_				(SDL_Color){ 0xff, 0xff, 0xff, 0xff }
# define BLACK_				(SDL_Color){ 0x00, 0x00, 0x00, 0x00 }
# define GREEN_				(SDL_Color){ 0x00, 0xff, 0x00, 0x00 }
# define MAG_				(SDL_Color){ 0xff, 0x00, 0xff, 0x00 }
# define BLUE_				(SDL_Color){ 0x00, 0x00, 0xff, 0x00 }
# define FONT_SHIFT			10

typedef struct	s_line
{
	int	*data;
	int	steep;
	int	c;
}				t_line;

typedef struct	s_linked
{
	char			*data;
	struct s_linked	*next;
	struct s_linked	*prev;
}				t_linked;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_dpoint
{
	double	x;
	double	y;
}				t_dpoint;

/*
** комната
** в комнату можно попасть из комнат entrance,
** а уйти из неё можно в комнаты exit
*/

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	int				ant;
	short			bfs_level;
	short			entrance_count;
	short			exit_count;
	struct s_room	**entrance;
	struct s_room	**exit;
}				t_room;

typedef struct	s_link
{
	t_room			*one;
	t_room			*two;
	struct s_link	*next;
	struct s_link	*prev;
}				t_link;

typedef struct	s_queue
{
	t_room			*room;
	int				bfs;
	struct s_queue	*next;
}				t_queue;

/*
** главная структура проекта
** хранит ссылку на первую комнату, из которой можно попасть во все остальные
** также хранит, сколько муравьев сейчас в первой комнате и последней,
** сколько всего есть комнат,
** какой номер в массиве у первой комнаты и у последней комнаты
*/

typedef struct	s_lem_in
{
	t_sdl		*sdl;
	t_room		*rooms;
	t_room		*rooms_with_ants;
	t_room		*start_room;
	t_room		*end_room;
	t_linked	*contents;
	t_dpoint	max;
	t_dpoint	min;
	int			ants_at_start;
	int			ants_at_finish;
	int			allocated;
	short		number_of_rooms;
	short		largest_bfs;
	char		flag;
	char		move;
	t_dpoint	conv;
}				t_lem_in;

void			read_from_stdout(t_lem_in *lemin);
void			end_lem_in(t_lem_in *lemin);
void			print_error(void);
void			end_with_error(char *line, t_lem_in *lemin, t_link *link);
void			lines_with_rooms(t_lem_in *lemin, char **line);
void			execute_command(char **line, t_lem_in *lemin, t_room *room);
short			skip_comments(char **line, t_lem_in *lemin);
void			check_start_end_exists(t_lem_in *lemin, char *line);
int				get_next_line_2_0(char **line, t_lem_in *lemin);
char			*get_room_name(char **line, short len);
void			lines_with_links(t_lem_in *lemin, char *line, t_link **links);
void			check_duplicate_rooms(t_lem_in *lemin, char *line);
void			build_graph(t_lem_in *lemin, t_link **links);
void			check_links_total_number(t_lem_in *lemin, t_link *link);
void			check_duplicate_links(t_lem_in *lemin, t_link *links);

short			push(t_queue **last, t_room *room);
short			push_by_priority(t_queue **head, t_room *room);
void			pop(t_queue **queue);
short			add_exits_to_queue(t_room *room, t_queue **last);
void			debug_graph(t_lem_in *lemin);
void			debug_queue(t_queue *queue);
void			remove_extra_links(t_link *link);
void			delete_link(t_link *link);
void			debug_path(t_room *room);

int				find_largest_bfs_level(t_room *end);
void			remove_input_forks(t_lem_in *lemin);
void			remove_entrance(t_room *room, t_room *entrance,
									t_lem_in *lemin);
void			remove_exit(t_room *room, t_room *exit, t_lem_in *lemin);
void			remove_other_links(t_room *room, t_room *save,
									t_lem_in *lemin);
short			remove_dead_ends(t_room *room, t_room *end, t_lem_in *lemin);
void			remove_output_forks(t_lem_in *lemin);
int				get_path_len(t_room *room);
void			ready(t_lem_in *lemin);
void			move_ants(t_lem_in *lemin, int *paths, int *ant_number);
void			print_ant_move(char *room_name, int ant_number);
t_linked		*linked_new(char *str);
void			linked_add(t_linked **head, char *str);
void			print_file_contents(t_linked **contents);
void			check_path_to_end_exists(t_lem_in *lemin);
void			add_entrances_to_queue(t_queue **q, t_room *room);

void			line(t_point beg, t_point end, int *data, int colour);
void			draw_full_graph(t_link *link, t_lem_in *lemin);
void			get_first_image(t_lem_in *lemin);
void			sdl_open_game(t_sdl *sdl);
void			sdl_render_paths(t_sdl *sdl);
void			sdl_render_text(t_sdl *sdl, t_room *room, char highlight);
void			sdl_loop(t_lem_in *lemin, t_sdl *sdl, int *paths,
													int *ant_number);
void			draw_best_paths(t_lem_in *lemin);
void			draw_start_end(t_lem_in *lemin, t_sdl *sdl);
void			draw_ant_move(t_room *room, t_lem_in *lemin, t_sdl *sdl);
void			draw_ant_start_move(t_room *room, t_lem_in *lemin, t_sdl *sdl);
int				sdl_listen(t_lem_in *lemin, t_sdl *sdl);
void			sdl_end_lem_in(t_lem_in *lemin);
void			highligh_rooms(t_room *room, t_room *n, t_lem_in *lemin,
								t_sdl *sdl);
void			sdl_set_rect(t_room *room, t_lem_in *lemin, t_sdl *sdl);

#endif
