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

#include "lem_in.h"

void	remove_de_from_exits(t_room *room, t_room *extra)
{
	short	i;
	short	k;

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
	if (room->exit_count > 0)
		room->exit[k] = NULL;
}

short	remove_room_from_graph(t_room *dead_end)
{
	short	i;

	i = -1;
	while (++i < dead_end->entrance_count)
		remove_de_from_exits(dead_end->entrance[i], dead_end);
	free(dead_end->name);
	free(dead_end->entrance);
	ft_bzero(dead_end, sizeof(t_room));
}

short	remove_dead_ends(t_room *room, t_room *end, t_lem_in *lemin)
{
	short	i;

	if (room->bfs_level == MAX_SHORT)
		return (0);
	if (room->exit_count == 0)
		return (1);
	i = room->exit_count;
	while (--i > -1)
	{
		if (remove_dead_ends(room->exit[i], end, lemin))
			remove_room_from_graph(room->exit[i]);
	}
	return (room->exit_count == 0 ? 1 : 0);
}

void	remove_extra_links(t_lem_in *lemin, t_link *link)
{
	t_link	*next;

	while (link != NULL)
	{
		next = link->next;
		delete_link(link);
		link = next;
	}
}
