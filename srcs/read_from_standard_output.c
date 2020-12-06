/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_standard_output.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:03:24 by pberge            #+#    #+#             */
/*   Updated: 2020/12/05 20:25:03 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lem-in.h"

/*
** по всему парсеру идёт проверка,
** что гет_нэкст_лайн что-то прочитал, да ещё и без ошибок,
** поэтому вынесу его сюда вместе с проверкой
*/

int		get_next_line_2_0(char **line)
{
    int		num_bytes;

	num_bytes = get_next_line(0, line);
	if (num_bytes < 1)
		end_parser(*line);
	return (num_bytes);
}

/*
** команды
** команды начинаются с '##'
** команды показывают, какие комнаты считать началом и концом пути муравья.
** началом может быть только одна комната, и концом тоже, поэтому
** любые попытки создать ещё одно начало или конец считаются ошибкой.
** лайфхак: похоже, что могут быть и другие команды, кроме ##start и ##end,
** однако какие это команды не указано в задании
*/

char	*execute_command(
	char *line,
	size_t *start_room,
	size_t *end_room,
	size_t index)
{
	while (line[0] == '#' && line[1] == '#')
	{
		if (ft_strcmp(line, "##start") == 0)
		{
			if (*start_room != 0)
				end_parser(line);
			*start_room = index;
		}
		if (ft_strcmp(line, "##end") == 0)
		{
			if (*end_room != 0)
				end_parser(line);
			*end_room = index;
		}
		free(line);
		get_next_line_2_0(&line);
	}
	return (line);
}

/*
** пропускаем строки-комментарии (начинаются с '#'и следующий символ не '#')
*/

char	*skip_comments(char *line/*, t_buffer *buffer*/)
{
	while (line[0] && line[0] == '#' && line[1] != '#')
	{
		// save_line(line, buffer);
		// ft_bzero(line, ft_strlen(line));
		free(line);
		get_next_line_2_0(&line);
	}
    return (line);
}

/*
** проверяем, что первой строкой идёт количество муравьёв на старте
*/

void	first_line_is_int(char *line, int *number_of_ants/*, t_buffer *buffer*/)
{
	int		i;

	i = -1;
	line = skip_comments(line/*, buffer*/);
	while (line[0] && ft_isdigit(line[++i]))
	{
		*number_of_ants = *number_of_ants * 10 + line[i] - '0';
	}
	if (*number_of_ants == 0 || line[i] != '\0')
		end_with_error();
}

/*
** читаем карту.
** сначала могут идти комментарии,
** потом ожидается первая строка с количеством муравьёв,
** следом идут комнаты вперемешку с комментариями и командами
** и в конце записаны связи между комнатами вперемешку только с комметариями
**
** количество муравьёв
** название комнаты-x-y
** комната-комната
*/

void	read_from_standard_output(t_lem_in *lemin)
{
	char		*line;
	// t_buffer	buffer;

	line = ft_strnew(1);
	// ft_bzero(&buffer, sizeof(t_buffer));
	get_next_line_2_0(&line);
	first_line_is_int(line, &lemin->ants_at_start/*, &buffer*/);
	lemin->rooms = (t_room *)malloc(sizeof(t_room) * MAX_ROOMS_NUM);
	lines_with_rooms(lemin->rooms, &lemin->number_of_rooms,
						&lemin->start_room, &lemin->end_room);
	if (lemin->number_of_rooms < 2 || !lemin->start_room || !lemin->end_room)
		end_parser(NULL);
	// t_room *current;
	// current = lemin->rooms;
	// int i = lemin->number_of_rooms + 1;
	// while (--i != 0)
	// {
	// 	printf("%s\n", current->name);
	// 	current += 1;
	// }
	// t_chunk *tmp = buffer.start;
	// while (tmp)
	// {
	// 	ft_putstr(((char *)tmp->chunk));
	// 	tmp = tmp->next;
	// }
	// while (get_next_line(0, &line))
	// {
	// 	// printf("%s\n", line);
	// 	free(line);
	// }
}
