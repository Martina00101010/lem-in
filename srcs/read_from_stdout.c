/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_stdout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:03:24 by koparker          #+#    #+#             */
/*   Updated: 2021/01/25 22:16:43 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lem_in.h"

/*
** Enhanced gnl with error check inside
*/

int		get_next_line_2_0(char **line, t_lem_in *lemin)
{
	int		num_bytes;

	num_bytes = get_next_line(0, line);
	if (num_bytes == -1)
		end_with_error(NULL, lemin, NULL);
	return (num_bytes);
}

/*
** Commands:
** 	- start with: '##'
** 	- show which rooms are `start` or `end` (or maybe other)
** 	- there could be only one `start` and one `end`
*/

void	execute_command(char **line, t_lem_in *lemin, t_room *room)
{
	char	*command;

	command = *line;
	if (command[0] == '#' && command[1] == '#')
	{
		linked_add(&lemin->contents, *line);
		if (ft_strcmp(command, "##start") == 0)
		{
			if (lemin->start_room != NULL)
				end_with_error(NULL, lemin, NULL);
			lemin->start_room = room;
		}
		if (ft_strcmp(command, "##end") == 0)
		{
			if (lemin->end_room != NULL)
				end_with_error(NULL, lemin, NULL);
			lemin->end_room = room;
			lemin->end_room->bfs_level = MAX_SHORT;
		}
		if (get_next_line_2_0(line, lemin) == 0)
			end_with_error(NULL, lemin, NULL);
	}
}

/*
** Skip comments (start with '#' and next symbol is not '#')
*/

short	skip_comments(char **line, t_lem_in *lemin)
{
	while ((*line)[0] && (*line)[0] == '#' && (*line)[1] != '#')
	{
		linked_add(&lemin->contents, *line);
		if (get_next_line_2_0(line, lemin) == 0)
			return (0);
	}
	return (1);
}

/*
** Check first line has number of ants (comments do not count)
*/

void	first_line_is_int(char **line, int *number_of_ants, t_lem_in *lemin)
{
	int		i;
	int		check;

	i = -1;
	if (skip_comments(line, lemin) == 0)
		end_with_error(NULL, lemin, NULL);
	linked_add(&lemin->contents, *line);
	while ((*line)[0] && ft_isdigit((*line)[++i]))
	{
		check = *number_of_ants;
		*number_of_ants = *number_of_ants * 10 + (*line)[i] - '0';
		if (check > *number_of_ants)
			end_with_error(NULL, lemin, NULL);
	}
	if (*number_of_ants <= 0 || (*line)[i] != '\0')
		end_with_error(NULL, lemin, NULL);
}

/*
** Read map
** 	- there may be comments at start
** 	- then there should be number of ants
** 	- then -- rooms mixed with commands and comments
** 	- then -- links between rooms mixed with comments
**
** number_of_ants
** room_name x y
** room_from-room_to
*/

void	read_from_stdout(t_lem_in *lemin)
{
	char	*line;
	t_link	*links;

	links = NULL;
	line = "";
	if (get_next_line(0, &line) < 1)
		print_error();
	first_line_is_int(&line, &lemin->ants_at_start, lemin);
	lines_with_rooms(lemin, &line);
	check_start_end_exists(lemin, line);
	check_duplicate_rooms(lemin, line);
	lines_with_links(lemin, line, &links);
	check_duplicate_links(lemin, links);
	if (lemin->flag == DRAW)
		draw_full_graph(links, lemin);
	build_graph(lemin, &links);
	remove_extra_links(links);
	remove_dead_ends(lemin->start_room, lemin->end_room, lemin);
}
