/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:36:32 by pberge            #+#    #+#             */
/*   Updated: 2020/12/05 19:20:01 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
#include "libft.h"

/*
** ПАРСЕР
*/

# define	BUFFER_SIZE		(size_t)8
# define	ROOM_NAME_SIZE	(size_t)5
# define	MAX_ROOMS_NUM	(size_t)5000

typedef struct	s_chunk
{
	char			chunk[BUFFER_SIZE];
	struct s_chunk	*next;
}				t_chunk;

typedef struct	s_buffer
{
	t_chunk	*start;
	t_chunk	*current;
	size_t	cursor;
}				t_buffer;

/*
** комната
** в комнату можно попасть из комнат entrance,
** а уйти из неё можно в комнаты exit
*/

typedef struct	s_room
{
	char			name[ROOM_NAME_SIZE];
	int				x;
	int				y;
	int				ant;
	struct s_room	**entrance;
	struct s_room	**exit;
}				t_room;

/*
** главная структура проекта
** хранит ссылку на первую комнату, из которой можно попасть во все остальные
** также хранит, сколько муравьев сейчас в первой комнате и последней,
** сколько всего есть комнат,
** какой номер в массиве у первой комнаты и у последней комнаты
*/

typedef struct	s_lem_in
{
	t_room		*rooms;
	t_room		*rooms_with_ants;
	int			ants_at_start;
	int			ants_at_finish;
	size_t		number_of_rooms;
	size_t		start_room;
	size_t		end_room;
}				t_lem_in;

void			read_from_standard_output(t_lem_in *lemin);
void			end_with_error(void);
void			end_lem_in(t_lem_in *lemin);
void			end_parser(/*t_buffer *buffer, */char *line);
void			save_line(char *line, t_buffer *buffer);
char			*lines_with_rooms(t_room *rooms, size_t *number_of_rooms,
													size_t *start, size_t *end);
char			*execute_command(char *line, size_t *start_room,
												size_t *end_room, size_t index);
char			*skip_comments(char *line);
int				get_next_line_2_0(char **line);

#endif
