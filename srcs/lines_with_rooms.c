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

char	*get_room_coordinate(int *coord, char *line)
{
	while (ft_isdigit(*line) && *coord >= 0)
		*coord = *coord * 10 + *(line++) - '0';
	return (line);
}

/*
** записываем название комнаты.
** название может состоять из букв, цифр и нижнего подчеркивания.
** лайфхак: генератор создаёт названия до 4 символов,
** поэтому храним названия в массиве на 4 символа и конец строки
*/

char	*get_room_name(char *name, char *line)
{
	int		i;

	i = 0;
	while (ft_issymbol(line[i]))
	{
		name[i] = line[i];
		i++;
	}
	name[i] = '\0';
	return (line + i);
}

/*
** читает построчно файл
** проверяет, что строка записана в формате "name x y"
** где name - название комнаты
**        x - x-координата комнаты
**        y - y-координата комнаты
** всё строго разделено одним пробелом, а в конце идёт перенос строки
*/

char	*lines_with_rooms(
	t_room *room,
	size_t *number_of_rooms,
	size_t *start,
	size_t *end
)
{
	char	*line;
	char	*to_free;

	while (get_next_line_2_0(&line))
	{
		line = skip_comments(line);
		line = execute_command(line, start, end, *number_of_rooms);
		to_free = line;
		line = get_room_name(room->name, line);
		if (*line == '-')
			return (to_free);
		if (*line != ' ')
			end_parser(to_free);
		line = get_room_coordinate(&room->x, ++line);
		if (*line != ' ' || room->x <= 0)
			end_parser(to_free);
		line = get_room_coordinate(&room->y, ++line);
		if (*line != '\0' || room->y <= 0)
			end_parser(line);
		(*number_of_rooms)++;
		room += 1;
		free(to_free);
	}
	return (NULL);
}
