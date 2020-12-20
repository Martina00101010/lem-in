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

int		get_next_line_2_0(char **line, t_lem_in *lemin)
{
    int		num_bytes;

	num_bytes = get_next_line(0, line);
	if (num_bytes == -1)
		end_parser(NULL, lemin, NULL);
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

void	execute_command(char **line, t_lem_in *lemin, t_room *room)
{
	char	*command;

	command = *line;
	while (command[0] == '#' && command[1] == '#')
	{
		if (ft_strcmp(command, "##start") == 0)
		{
			if (lemin->start_room != NULL)
				end_parser(command, lemin, NULL);
			lemin->start_room = room;
		}
		if (ft_strcmp(command, "##end") == 0)
		{
			if (lemin->end_room != NULL)
				end_parser(command, lemin, NULL);
			lemin->end_room = room;
		}
		free(command);
		get_next_line_2_0(line, lemin);
		command = *line;
	}
}

/*
** пропускаем строки-комментарии (начинаются с '#'и следующий символ не '#')
*/

short	skip_comments(char **line, t_lem_in *lemin)
{
	while ((*line)[0] && (*line)[0] == '#' && (*line)[1] != '#')
	{
		free(*line);
		if (get_next_line_2_0(line, lemin) == 0)
			return (0);
	}
    return (1);
}

/*
** проверяем, что первой строкой идёт количество муравьёв на старте
*/

void	first_line_is_int(char **line, int *number_of_ants, t_lem_in *lemin)
{
	int		i;

	i = -1;
	skip_comments(line, lemin);
	while ((*line)[0] && ft_isdigit((*line)[++i]))
	{
		*number_of_ants = *number_of_ants * 10 + (*line)[i] - '0';
	}

	if (*number_of_ants == 0 || (*line)[i] != '\0')
		end_parser(*line, lemin, NULL);
	free(*line);
}

/*
** читаем карту.
** сначала могут идти комментарии,
** потом строка с количеством муравьёв,
** следом комнаты вперемешку с комментариями и командами
** и в конце связи между комнатами вперемешку только с комметариями
**
** количество_муравьёв
** название_комнаты-x-y
** комната-комната
*/

void	read_from_standard_output(t_lem_in *lemin)
{
	char	*line;
	t_link	*links;

	links = NULL;
	line = "";
	if (get_next_line(0, &line) < 1)
		end_with_error();
	first_line_is_int(&line, &lemin->ants_at_start, lemin);
	lines_with_rooms(lemin, &line);
	check_start_end_exists(lemin, line);
	check_duplicate_names(lemin);
	lines_with_links(lemin, line, &links);
	check_duplicate_links(lemin, links);
	build_graph(lemin, &links);
}
