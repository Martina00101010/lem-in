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

#include "lem-in.h"

/*
** проверка, что символ имени - буква, цифра или нижнее подчёркивание
*/

int		ft_issymbol(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}

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

/*
** записываем название комнаты.
** название может состоять из букв, цифр и нижнего подчеркивания.
** название комнаты не может начинаться на 'L'
*/

char	*get_room_name(char **line, short len)
{
	short	i;
	char	*name;

	i = -1;
	if (len <= 0 || **line == 'L')
		return (NULL);
	name = ft_strnew(len);
	if (name == NULL)
		return (NULL);
	while (++i < len)
	{
		if (!ft_issymbol(**line))
		{
			free(name);
			return (NULL);
		}
		name[i] = **line;
		(*line)++;
	}
	name[i] = '\0';
	return (name);
}

void	get_room(char **line, t_room *room)
{
	char	*stop;
	short	len;

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
	if (**line != ' ' || room->x <= 0)
		ft_strdel(&room->name);
	(*line)++;
	room->y = get_room_coordinate(line);
	if (**line != '\0' || room->y <= 0)
		ft_strdel(&room->name);
}

/*
** читает построчно файл
** проверяет, что строка записана в формате "name x y"
** где name - название комнаты
**        x - x-координата комнаты
**        y - y-координата комнаты
** всё строго разделено одним пробелом, а в конце идёт перенос строки
*/

void	lines_with_rooms(t_lem_in *lemin, char **line)
{
	t_room	*room;
	char	*to_free;

	*line = NULL;
	lemin->rooms = (t_room *)malloc(sizeof(t_room) * MAX_ROOMS_NUM);
	ft_bzero(lemin->rooms, sizeof(t_room) * MAX_ROOMS_NUM);
	room = lemin->rooms;
	while (get_next_line_2_0(line, lemin) > 0)
	{
		skip_comments(line, lemin);
		if (*line == NULL)
			end_parser(NULL, lemin, NULL);
		execute_command(line, lemin, lemin->rooms + lemin->number_of_rooms);
		to_free = *line;
		get_room(line, room);
		if (room->name == NULL && (*line == NULL || **line != '-'))
			end_parser(to_free, lemin, NULL);
		if (**line == '-')
		{
			*line = to_free;
			return ;
		}
		lemin->number_of_rooms++;
		room += 1;
		free(to_free);
	}
	*line = NULL;
}
