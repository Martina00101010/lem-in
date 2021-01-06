/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_extra_links.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:44:11 by pberge            #+#    #+#             */
/*   Updated: 2020/12/27 17:44:27 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	remove_room_from_exits(t_room *room, t_room *extra)
{
	short   i;
	short   k;

	k = 0;
	i = 0;
	if (room->exit_count == 1)
	{
		free(room->exit);
		room->exit = NULL;
	}
	(room->exit_count)--;
	while (k < room->exit_count)
	{
		room->exit[k] = room->exit[i];
		if (ft_strcmp(room->exit[i]->name, extra->name) != 0)
			k++;
		i++;
	}
}

short	remove_room_from_graph(t_room *room)
{
	short   i;

	i = -1;
	while (++i < room->entrance_count)
		remove_room_from_exits(room->entrance[i], room);
	room->bfs_level = 0;
	free(room->name);
	room->name = NULL;
	free(room->entrance);
	room->entrance = NULL;
}

short    remove_dead_ends(t_room *room, t_room *end, t_lem_in *lemin)
{
    short   i;

    if (room->bfs_level != MAX_SHORT && room->exit_count == 0)
		return (1);
    i = room->exit_count;
    while (--i > -1)
    {
        if (remove_dead_ends(room->exit[i], end, lemin))
            remove_room_from_graph(room->exit[i]);
    }
	if (room->bfs_level != MAX_SHORT && room->exit_count == 0)
		remove_room_from_graph(room);
	return (0);
}

void    remove_extra_links(t_lem_in *lemin, t_link *link)
{
    t_link  *next;

    while (link != NULL)
    {
        next = link->next;
        delete_link(link);
        link = next;
    }
    remove_dead_ends(lemin->start_room, lemin->end_room, lemin);
}
