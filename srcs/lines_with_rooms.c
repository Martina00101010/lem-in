/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_with_rooms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 00:24:54 by koparker          #+#    #+#             */
/*   Updated: 2021/01/18 12:32:45 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Read room's coordinate (`int` >= 0 only)
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

void	skip_comments_and_commands(t_lem_in *lemin, char **line)
{
	if (skip_comments(line, lemin) == 0)
		end_with_error(NULL, lemin, NULL);
	execute_command(line, lemin, lemin->rooms + lemin->number_of_rooms);
	if (skip_comments(line, lemin) == 0)
		end_with_error(NULL, lemin, NULL);
}

/*
** 1. Read file line by line
** 2. Check line format to be: "name x y"
** 	where name is room name,
**		x - x-coordinate of the room,
**		y - y-coordinate of the room;
** 	Contents separeted stricktly by ' ' and at the end: '\n'
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
