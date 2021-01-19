/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_input_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:22:26 by pberge            #+#    #+#             */
/*   Updated: 2021/01/16 14:22:41 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
**	удаляем связь между комнатами
*/

void		remove_link(t_room *room, t_room *delete, t_lem_in *lemin)
{
	remove_entrance(room, delete, lemin);
		debug_graph(lemin);
	remove_exit(delete, room, lemin);
		debug_graph(lemin);
}

short		previous_room_has_fork(t_room *room, t_lem_in *lemin)
{
	t_room	*fork;
	int	i;

	i = -1;
	fork = NULL;
	if (room == lemin->start_room)
		return (0);
	if (room->exit_count > 1)
		return (1);
	while (++i < room->entrance_count)
	{
		if (previous_room_has_fork(room->entrance[i], lemin))
			return (1);
	}
	return (0);
}

static void	remove_forks(t_room *room, t_lem_in *lemin)
{
	t_room	*entrance;
	int		i;

	i = room->entrance_count;
	while (room->entrance_count > 1 && i-- > 0)
	{
		entrance = room->entrance[i];
		if (previous_room_has_fork(entrance, lemin))
			remove_link(room, entrance, lemin);
		else
			remove_other_links(room, entrance, lemin);
	}
}

void		push_exits_to_queue(t_queue **last, t_room *room)
{
	int		i;

	i = -1;
	while (++i < room->exit_count && room->exit[i]->bfs_level != MAX_SHORT)
		push(last, room->exit[i]);
}

void		remove_input_forks(t_lem_in *lemin)
{
	t_queue	*queue;
	t_queue	*last;
	t_room	*room;

	queue = NULL;
	push_exits_to_queue(&queue, lemin->start_room);
	last = queue;
	while (queue != NULL)
	{
		room = queue->room;
		push_exits_to_queue(&last, room);
		if (room->entrance_count > 1)
			remove_forks(room, lemin);
		pop(&queue, &last);
	}
}
