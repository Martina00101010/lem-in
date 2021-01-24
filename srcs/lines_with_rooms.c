/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_with_rooms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 00:24:54 by pberge            #+#    #+#             */
/*   Updated: 2020/12/06 12:58:14 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** читаем координату комнаты.
** координата может быть только интом.
** лайфхак: генератор создаёт только положительные координаты,
** даже нули не использует, поэтому неположительные числа считаем невалидными
*/

int		get_room_coordinate(char **line)
{
	int	coord;

	coord = 0;
	while (ft_isdigit(**line) && coord >= 0)
	{
		coord = coord * 10 + **line - '0';
		(*line)++;
	}
	return (coord);
}

void	get_room(char **line, t_room *room)
{
	char	*stop;

	stop = ft_strchr(*line, ' ');
	if (stop == NULL)
	{
		*line = ft_strchr(*line, '-');
		return ;
	}
	room->name = get_room_name(line, stop - *line);
	if (room->name == NULL || **line != ' ')
		return ;
	(*line)++;
	room->x = get_room_coordinate(line);
	if (**line != ' ' || room->x < 0)
		ft_strdel(&room->name);
	(*line)++;
	room->y = get_room_coordinate(line);
	if (**line != '\0' || room->y < 0)
		ft_strdel(&room->name);
}

void	ft_realloc(t_lem_in *lemin, int new_size)
{
	t_room	*realloced;

	realloced = (t_room *)malloc(sizeof(t_room) * new_size);
	ft_memcpy(realloced, lemin->rooms, sizeof(t_room) *
									lemin->number_of_rooms);
	if (lemin->start_room)
		lemin->start_room = realloced + (lemin->start_room - lemin->rooms);
	if (lemin->end_room)
		lemin->end_room = realloced + (lemin->end_room - lemin->rooms);
	free(lemin->rooms);
	lemin->rooms = realloced;
	lemin->allocated = new_size;
}

/*
**	пропускаем комментарии и команды
*/

void	skip_comments_and_commands(t_lem_in *lemin, char **line)
{
	if (skip_comments(line, lemin) == 0)
		end_with_error(NULL, lemin, NULL);
	execute_command(line, lemin, lemin->rooms + lemin->number_of_rooms);
	if (skip_comments(line, lemin) == 0)
		end_with_error(NULL, lemin, NULL);
}

/*
** читает построчно файл
** проверяет, что строка записана в формате "name x y"
** где name - название комнаты
**		x - x-координата комнаты
**		y - y-координата комнаты
** всё строго разделено одним пробелом, а в конце идёт перенос строки
*/

void	lines_with_rooms(t_lem_in *lemin, char **line)
{
	t_room	*room;
	char	*save;

	*line = NULL;
	lemin->rooms = (t_room *)ft_memalloc(sizeof(t_room) * MAX_ROOMS_NUM);
	room = lemin->rooms;
	while (get_next_line_2_0(line, lemin) > 0)
	{
		skip_comments_and_commands(lemin, line);
		save = *line;
		get_room(line, room);
		if (room->name == NULL && (*line == NULL || **line != '-'))
			end_with_error(save, lemin, NULL);
		if (**line == '-')
		{
			*line = save;
			return ;
		}
		linked_add(&lemin->contents, save);
		lemin->number_of_rooms++;
		if (lemin->number_of_rooms + 1 == lemin->allocated)
			ft_realloc(lemin, lemin->allocated * 10);
		room = lemin->rooms + lemin->number_of_rooms;
	}
	*line = NULL;
}
