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

#include "lem-in.h"

void	check_start_end_exists(t_lem_in *lemin, char *line)
{
	if (lemin->number_of_rooms < 2 ||
		lemin->start_room == NULL ||
		lemin->end_room == NULL ||
		line == NULL)
		end_parser(line, lemin, NULL);
}

void	check_links_total_number(t_lem_in *lemin, t_link *link)
{
	if (link != NULL && link->next != NULL)
		return ;
	end_parser(NULL, lemin, link);
}

/*
**  Названия комнат уникальны, поэтому любой дубликат - это ошибка
*/

short	check_duplicate_names(t_lem_in *lemin)
{
	t_room  *room;
	t_room  *tmp;
	short   i;
	short   j;

	i = lemin->number_of_rooms;
	room = lemin->rooms;
	while (--i > -1)
	{
		j = i;
		tmp = room + 1;
		while (--j > -1)
		{
			if (ft_strcmp(room->name, tmp->name) == 0)
				return (1);
			if (room->x == tmp->x && room->y == tmp->y)
				return (1);
			tmp += 1;
		}
		room += 1;
	}
	return (0);
}

short	same_links(t_link *a, t_link *b)
{
	return (a->one == b->one && a->two == b->two ||
			a->one == b->two && a->two == b->one);
}

void	check_duplicate_links(t_lem_in *lemin, t_link *links)
{
	t_link	*tmp;
	t_link	*link;

	link = links;
	while (link->next != NULL)
	{
		tmp = link->next;
		if (same_links(link, tmp))
			end_parser(NULL, lemin, links);
		link = link->next;
	}
}
