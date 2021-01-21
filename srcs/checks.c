/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 11:21:20 by pberge            #+#    #+#             */
/*   Updated: 2020/12/20 11:21:37 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_start_end_exists(t_lem_in *lemin, char *line)
{
	if (lemin->number_of_rooms < 2 ||
		lemin->start_room == NULL ||
		lemin->end_room == NULL ||
		line == NULL)
		end_with_error(line, lemin, NULL);
}

void	check_links_total_number(t_lem_in *lemin, t_link *link)
{
	if (link != NULL && link->next != NULL)
		return ;
	end_with_error(NULL, lemin, link);
}

/*
**  Название комнаты и набор координат (x,y) уникальны для каждой комнаты,
**	поэтому любой дубликат - это ошибка
*/

void	check_duplicate_rooms(t_lem_in *lemin, char *line)
{
	t_room	*room;
	t_room	*tmp;
	short	i;
	short	j;

	i = lemin->number_of_rooms;
	room = lemin->rooms;
	while (--i > 0)
	{
		j = i;
		tmp = room + 1;
		while (--j > -1)
		{
			if (ft_strcmp(room->name, tmp->name) == 0)
				end_with_error(line, lemin, NULL);
			if (room->x == tmp->x && room->y == tmp->y)
				end_with_error(line, lemin, NULL);
			tmp += 1;
		}
		room += 1;
	}
}

short	same_links(t_link *a, t_link *b)
{
	return ((a->one == b->one && a->two == b->two) ||
			(a->one == b->two && a->two == b->one));
}

void	check_duplicate_links(t_lem_in *lemin, t_link *links)
{
	t_link	*tmp;
	t_link	*link;

	link = links;
	while (link->next != NULL)
	{
		tmp = link->next;
		while (tmp)
		{
			if (same_links(link, tmp))
				end_with_error(NULL, lemin, links);
			tmp = tmp->next;
		}
		link = link->next;
	}
}
